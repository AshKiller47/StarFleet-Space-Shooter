#include "StarFleet/World.hpp"
#include "StarFleet/Pickup.hpp"
#include "StarFleet/Utility.hpp"
#include "StarFleet/SpriteNode.hpp"
#include "ResourceHolder.cpp"
#include <cmath>

World::World(sf::RenderWindow &window, TextureHolder &textures, FontHolder &fonts): mWindow(window), mWorldView(window.getDefaultView()), mWorldBounds(0.f, 0.f, mWorldView.getSize().x, mWorldView.getSize().y), 
                                                                                    mTextures(textures), mFonts(fonts), mGameMode(Classic), mSceneGraph(), mMasterSpacecraft(nullptr), mPlayerSpacecraft_1(nullptr), 
                                                                                    mPlayerSpacecraft_2(nullptr), mAlliedSpacecraft_1(nullptr), mAlliedSpacecraft_2(nullptr), mRadius(235.f), mPickupVelocity(0.f), 
                                                                                    mIsAccelerated(false), aliveEnemyCheck(true), mWindowCenter(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f), 
                                                                                    mActiveEnemies(), mEnemySpawnPoints(), mSceneLayers() {
    mWindow.setVerticalSyncEnabled(true); mWorldView.setCenter(mWindowCenter);
    
    buildScene();
    
}

void World::draw() { mWindow.setView(mWorldView); mWindow.draw(mSceneGraph); }

void World::update(sf::Time deltaTime) {
    
    destroyEntitiesOutsideView(); guideMissiles(); while(!mCommandQueue.isEmpty()) mSceneGraph.onCommand(mCommandQueue.pop(), deltaTime);
    
    if(mIsAccelerated) accelerateWorld(); handleCollisions(); handleMasterCollision(); mSceneGraph.removeWrecks(); spawnShooters(); spawnWreckers(),
    
    mSceneGraph.update(deltaTime, mCommandQueue); checkAliveEnemies(); if(!aliveEnemyCheck && mEnemySpawnPoints.empty()) addEnemies(); aliveEnemyCheck = false;
    
    // mSceneGraph.update(deltaTime, mWindowCenter);
    
}

void World::setGameMode(Player::GameMode mode) { mGameMode = (GameMode)mode; mIsAccelerated = mGameMode == Accelerated; }

void World::interpolate(float alpha) {
    
    mWorldView.setCenter(alpha * currentView + (1.f - alpha) * previousView); // mMasterSpacecraft->interpolate(alpha);
    
    mPlayerSpacecraft_1->interpolate(alpha); mPlayerSpacecraft_2->interpolate(alpha); mAlliedSpacecraft_1->interpolate(alpha); mAlliedSpacecraft_2->interpolate(alpha);
    
}

void World::saveCurrentState() {
    
    currentView = mWorldView.getCenter(); // mMasterSpacecraft->saveCurrentState();
    
    mPlayerSpacecraft_1->saveCurrentState(); mPlayerSpacecraft_2->saveCurrentState(); mAlliedSpacecraft_1->saveCurrentState(); mAlliedSpacecraft_2->saveCurrentState();
    
}

void World::savePreviousState() {
    
    previousView = currentView; // mMasterSpacecraft->savePreviousState();
    
    mPlayerSpacecraft_1->savePreviousState(); mPlayerSpacecraft_2->savePreviousState(); mAlliedSpacecraft_1->savePreviousState(); mAlliedSpacecraft_2->savePreviousState();
    
}

bool World::hasAliveMaster() { if(mMasterSpacecraft && mMasterSpacecraft->isDestroyed()) mMasterSpacecraft = nullptr; return mMasterSpacecraft; }

bool World::hasAlivePlayer() {
    
    if(mPlayerSpacecraft_1 && mPlayerSpacecraft_1->isDestroyed()) mPlayerSpacecraft_1 = nullptr;
    if(mPlayerSpacecraft_2 && mPlayerSpacecraft_2->isDestroyed()) mPlayerSpacecraft_2 = nullptr;
    if(mAlliedSpacecraft_1 && mAlliedSpacecraft_1->isDestroyed()) mAlliedSpacecraft_1 = nullptr;
    if(mAlliedSpacecraft_2 && mAlliedSpacecraft_2->isDestroyed()) mAlliedSpacecraft_2 = nullptr;
    
    return mPlayerSpacecraft_1 || mPlayerSpacecraft_2 || mAlliedSpacecraft_1 || mAlliedSpacecraft_2;
    
}

sf::Time World::playerSurvivalTime() { return mWorldClock.restart(); }

CommandQueue& World::getCommandQueue() { return mCommandQueue; }

void World::addEnemies() {
    
    addEnemy(Spacecraft::Anarchy, 700.f, 115.f);
    addEnemy(Spacecraft::Anarchy, 700.f, 90.f);
    addEnemy(Spacecraft::Anarchy, 700.f, 65.f);
    addEnemy(Spacecraft::Anarchy, 700.f, -65.f);
    addEnemy(Spacecraft::Anarchy, 700.f, -90.f);
    addEnemy(Spacecraft::Anarchy, 700.f, -115.f);
    addEnemy(Spacecraft::Anarchy, 700.f, 115.f);
    addEnemy(Spacecraft::Anarchy, 700.f, 90.f);
    addEnemy(Spacecraft::Anarchy, 700.f, 65.f);
    addEnemy(Spacecraft::Anarchy, 700.f, -65.f);
    addEnemy(Spacecraft::Anarchy, 700.f, -90.f);
    addEnemy(Spacecraft::Anarchy, 700.f, -115.f);
    
    addEnemy(Spacecraft::Carnage, 1100.f, -30.f);
    addEnemy(Spacecraft::Carnage, 1100.f, -15.f);
    addEnemy(Spacecraft::Carnage, 1100.f, 0.f);
    addEnemy(Spacecraft::Carnage, 1100.f, 15.f);
    addEnemy(Spacecraft::Carnage, 1100.f, 30.f);
    addEnemy(Spacecraft::Carnage, 1100.f, 150.f);
    addEnemy(Spacecraft::Carnage, 1100.f, 165.f);
    addEnemy(Spacecraft::Carnage, 1100.f, 180.f);
    addEnemy(Spacecraft::Carnage, 1100.f, 195.f);
    addEnemy(Spacecraft::Carnage, 1100.f, 210.f);
    
    // mEnemyClock.restart();
    
}

void World::buildScene() {
    
    for(std::size_t i = 0; i < LayerCount; i++) {
        
        Category::Type category = (i == Space) ? Category::SceneSpaceLayer : Category::None;
        
        SceneNode::Ptr layer(new SceneNode(category)); mSceneLayers[i] = layer.get(); mSceneGraph.attachChild(std::move(layer));
        
    }
    
    sf::Texture &texture = mTextures.get(Textures::Space); texture.setRepeated(true); sf::IntRect textureRect(mWorldBounds);
    
    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    
    backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top); mSceneLayers[Background]->attachChild(std::move(backgroundSprite));
    
    std::unique_ptr<Spacecraft> masterSpacecraft(new Spacecraft(Spacecraft::Enterprise, mTextures, mFonts)); mMasterSpacecraft = masterSpacecraft.get();
    
    mMasterSpacecraft->setRadius(0.f); mMasterSpacecraft->setAzimuth(toRadian(0.f)); mMasterSpacecraft->setWindowCenter(mWindowCenter); mMasterSpacecraft->setInitialPosition();
    
    mSceneLayers[Space]->attachChild(std::move(std::move(masterSpacecraft)));
    
    std::unique_ptr<Spacecraft> playerSpacecraft_1(new Spacecraft(Spacecraft::Dauntless, mTextures, mFonts)); mPlayerSpacecraft_1 = playerSpacecraft_1.get();
    
    mPlayerSpacecraft_1->setRadius(mRadius); mPlayerSpacecraft_1->setAzimuth(toRadian(0.f)); mPlayerSpacecraft_1->setWindowCenter(mWindowCenter); mPlayerSpacecraft_1->setInitialPosition();
    
    mSceneLayers[Space]->attachChild(std::move(std::move(playerSpacecraft_1)));
    
    std::unique_ptr<Spacecraft> playerSpacecraft_2(new Spacecraft(Spacecraft::Dauntless, mTextures, mFonts)); mPlayerSpacecraft_2 = playerSpacecraft_2.get();
    
    mPlayerSpacecraft_2->setRadius(mRadius); mPlayerSpacecraft_2->setAzimuth(toRadian(180.f)); mPlayerSpacecraft_2->setWindowCenter(mWindowCenter); mPlayerSpacecraft_2->setInitialPosition();
    
    mSceneLayers[Space]->attachChild(std::move(std::move(playerSpacecraft_2)));
    
    std::unique_ptr<Spacecraft> alliedSpacecraft_1(new Spacecraft(Spacecraft::Bastion, mTextures, mFonts)); mAlliedSpacecraft_1 = alliedSpacecraft_1.get();
    
    mAlliedSpacecraft_1->setRadius(mRadius); mAlliedSpacecraft_1->setAzimuth(mPlayerSpacecraft_1->getAzimuth() + toRadian(90.f)); mAlliedSpacecraft_1->setWindowCenter(mWindowCenter);
    
    mAlliedSpacecraft_1->setInitialPosition(); mSceneLayers[Space]->attachChild(std::move(std::move(alliedSpacecraft_1)));
    
    std::unique_ptr<Spacecraft> alliedSpacecraft_2(new Spacecraft(Spacecraft::Bastion, mTextures, mFonts)); mAlliedSpacecraft_2 = alliedSpacecraft_2.get();
    
    mAlliedSpacecraft_2->setRadius(mRadius); mAlliedSpacecraft_2->setAzimuth(mPlayerSpacecraft_2->getAzimuth() + toRadian(90.f)); mAlliedSpacecraft_2->setWindowCenter(mWindowCenter);
    
    mAlliedSpacecraft_2->setInitialPosition(); mSceneLayers[Space]->attachChild(std::move(std::move(alliedSpacecraft_2)));
    
    mPickupVelocity = mMasterSpacecraft->getPickupVelocity(); addEnemies(); mWorldClock.restart(); // addEscortSpacecraft(); addCloseButton();
    
}

void World::spawnShooters() {
    
    while(mEnemySpawnPoints.back().type == Spacecraft::Carnage) {
        
        SpawnPoint spawn = mEnemySpawnPoints.back();
        
        std::unique_ptr<Spacecraft> enemy(new Spacecraft(spawn.type, mTextures, mFonts));
        
        enemy->setRadius(spawn.radius); enemy->setAzimuth(toRadian(spawn.azimuth)); enemy->setWindowCenter(mWindowCenter);
        
        mSceneLayers[Space]->attachChild(std::move(enemy)); mEnemySpawnPoints.pop_back(); mEnemyClock.restart();
        
    }
    
}

void World::spawnWreckers() {
    
    sf::Time elapsedTime = mEnemyClock.getElapsedTime();
    
    if(elapsedTime >= sf::seconds(3.f) && mEnemySpawnPoints.back().type == Spacecraft::Anarchy) {
        
        SpawnPoint spawn = mEnemySpawnPoints.back();
        
        std::unique_ptr<Spacecraft> enemy(new Spacecraft(spawn.type, mTextures, mFonts));
        
        enemy->setRadius(spawn.radius); enemy->setAzimuth(toRadian(spawn.azimuth)); enemy->setWindowCenter(mWindowCenter);
        
        mSceneLayers[Space]->attachChild(std::move(enemy)); mEnemySpawnPoints.pop_back(); mEnemyClock.restart();
        
    }
    
}

void World::guideMissiles() {
    
    Command enemyCollector; enemyCollector.category = Category::EnemySpacecraft;
    
    enemyCollector.action = derivedAction<Spacecraft>([this] (Spacecraft &enemy, sf::Time deltaTime) {
        
        if(!enemy.isDestroyed()) mActiveEnemies.push_back(&enemy);
        
    });
    
    Command missileGuider; missileGuider.category = Category::AlliedProjectile;
    
    missileGuider.action = derivedAction<Projectile>([this] (Projectile &missile, sf::Time deltaTime) {
        
        if(!missile.isGuided()) return;
        
        float minAzimuth = std::numeric_limits<float>::max(); Spacecraft *closestEnemy = nullptr;
        
        for(Spacecraft *enemy: mActiveEnemies) {
            
            float enemyAzimuth = angularDistance(missile, *enemy); if(enemyAzimuth < minAzimuth) { closestEnemy = enemy; minAzimuth = enemyAzimuth; }
            
        }
        
        if(closestEnemy) missile.guideTowards(closestEnemy->getAzimuth(), minAzimuth);
        
    });
    
    mCommandQueue.push(enemyCollector); mCommandQueue.push(missileGuider); mActiveEnemies.clear();
    
}

void World::accelerateWorld() {
    
    Command accelerateEnemy; accelerateEnemy.category = Category::EnemySpacecraft;
    
    accelerateEnemy.action = derivedAction<Spacecraft>([this] (Spacecraft &enemy, sf::Time deltaTime) {
        
        float accelerationFactor = 1.f;
        
        if(mPlayerSpacecraft_1) accelerationFactor = mPlayerSpacecraft_1->getAccelerationFactor();
        
        else if(mPlayerSpacecraft_2) accelerationFactor = mPlayerSpacecraft_2->getAccelerationFactor();
        
        if(enemy.isShooter()) { enemy.updateSwitchInterval(accelerationFactor); if(enemy.isRestricted()) return; }
        
        enemy.updateRadialVelocity(accelerationFactor);
        
    });
    
    Command acceleratePickup; acceleratePickup.category = Category::Pickup;
    
    acceleratePickup.action = derivedAction<Pickup>([this] (Pickup &pickup, sf::Time deltaTime) {
        
        float accelerationFactor = 1.f;
        
        if(mPlayerSpacecraft_1) accelerationFactor = mPlayerSpacecraft_1->getAccelerationFactor();
        
        else if(mPlayerSpacecraft_2) accelerationFactor = mPlayerSpacecraft_2->getAccelerationFactor();
        
        pickup.setRadialVelocity(mPickupVelocity * accelerationFactor);
        
    });
    
    mCommandQueue.push(accelerateEnemy); mCommandQueue.push(acceleratePickup);
    
}

void World::handleCollisions() {
    
    std::set<SceneNode::Pair> collisionPairs; mSceneGraph.checkSceneCollision(mSceneGraph, collisionPairs);
    
    for(SceneNode::Pair pair: collisionPairs) {
        
        if(matchesCategories(pair, Category::DefenderSpacecraft, Category::EnemySpacecraft)) {
            
            auto &spacecraft = static_cast<Spacecraft&>(*pair.first), &enemy = static_cast<Spacecraft&>(*pair.second);
            
            if(!enemy.isDestroyed()) { spacecraft.damage(enemy.getHitPoints()); enemy.destroy(); }
            
        }
        
        else if(matchesCategories(pair, Category::DefenderSpacecraft, Category::Pickup)) {
            
            auto &spacecraft = static_cast<Spacecraft&>(*pair.first); auto &pickup = static_cast<Pickup&>(*pair.second);
            
            if(spacecraft.getCategory() == Category::PlayerSpacecraft) pickup.apply(spacecraft);
            
            else if(pickup.getType() == Pickup::HealthRefill) pickup.apply(spacecraft);
            
            else {
                
                if(!mPlayerSpacecraft_1 && !mPlayerSpacecraft_2) { pickup.destroy(); return; }
                
                else if(!mPlayerSpacecraft_1) pickup.apply(*mPlayerSpacecraft_2);
                
                else if(!mPlayerSpacecraft_2) pickup.apply(*mPlayerSpacecraft_1);
                
                else if(randomInt(2) == 0) pickup.apply(*mPlayerSpacecraft_1);
                
                else pickup.apply(*mPlayerSpacecraft_2);
                
            }
            
            pickup.destroy();
            
        }
        
        else if(matchesCategories(pair, Category::DefenderSpacecraft, Category::EnemyProjectile) || matchesCategories(pair, Category::EnemySpacecraft, Category::AlliedProjectile)) {
            
            auto &spacecraft = static_cast<Spacecraft&>(*pair.first); auto &projectile = static_cast<Projectile&>(*pair.second);
            
            spacecraft.damage(projectile.getDamage()); projectile.destroy();
            
        }
        
    }
    
}

void World::handleMasterCollision() {
    
    Command spacecraftCollider; spacecraftCollider.category = Category::EnemySpacecraft;
    
    spacecraftCollider.action = derivedAction<Spacecraft>([this] (Spacecraft &spacecraft, sf::Time deltaTime) {
        
        if(!spacecraft.isDestroyed() && spacecraft.getRadius() < mRadius - 55.f) { mMasterSpacecraft->damage(spacecraft.getHitPoints()); spacecraft.destroy(); }
        
    });
    
    Command pickupCollider; pickupCollider.category = Category::Pickup;
    
    pickupCollider.action = derivedAction<Pickup>([this] (Pickup &pickup, sf::Time deltaTime) {
        
        if(pickup.getRadius() < mRadius - 55.f) {
            
            if(pickup.getType() == Pickup::HealthRefill) pickup.apply(*mMasterSpacecraft);
            
            else {
                
                if(!mPlayerSpacecraft_1 && !mPlayerSpacecraft_2) { pickup.destroy(); return; }
                
                else if(!mPlayerSpacecraft_1) pickup.apply(*mPlayerSpacecraft_2);
                
                else if(!mPlayerSpacecraft_2) pickup.apply(*mPlayerSpacecraft_1);
                
                else if(randomInt(2) == 0) pickup.apply(*mPlayerSpacecraft_1);
                
                else pickup.apply(*mPlayerSpacecraft_2);
                
            }
            
            pickup.destroy();
            
        }
        
    });
    
    Command projectileCollider; projectileCollider.category = Category::EnemyProjectile;
    
    projectileCollider.action = derivedAction<Projectile>([this] (Projectile &projectile, sf::Time deltaTime) {
        
        if(projectile.getRadius() < mRadius - 45.f) { mMasterSpacecraft->damage(projectile.getDamage()); projectile.destroy(); }
        
    });
    
    mCommandQueue.push(spacecraftCollider); mCommandQueue.push(pickupCollider); mCommandQueue.push(projectileCollider);
    
}

void World::checkAliveEnemies() {
    
    Command command; command.category = Category::EnemySpacecraft;
    
    command.action = derivedAction<Spacecraft>([this] (Spacecraft &enemy, sf::Time deltaTime) { if(!enemy.isDestroyed()) aliveEnemyCheck = true; });
    
    mCommandQueue.push(command);
    
}

void World::destroyEntitiesOutsideView() {
    
    Command command; command.category = Category::AlliedProjectile;
    
    command.action = derivedAction<Projectile>([this] (Projectile &projectile, sf::Time deltaTime) {
        
        if(!getViewBounds().intersects(projectile.getBoundingRect())) projectile.destroy();
        
    });
    
    mCommandQueue.push(command);
    
}

void World::addEnemy(Spacecraft::Type type, float radius, float azimuth) { SpawnPoint spawn(type, radius, azimuth); mEnemySpawnPoints.push_back(spawn); }

sf::FloatRect World::getViewBounds() const { return sf::FloatRect(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize()); }

bool matchesCategories(SceneNode::Pair &colliders, Category::Type type_1, Category::Type type_2) {
    
    unsigned int category_1 = colliders.first->getCategory(), category_2 = colliders.second->getCategory();
    
    if(type_1 & category_1 && type_2 & category_2) return true;
    
    else if(type_1 & category_2 && type_2 & category_1) { std::swap(colliders.first, colliders.second); return true; }
    
    else return false;
    
}

// NodeButton& World::getButtonReference() { return *mCloseButton; }

/* void World::addCloseButton() {
    
    std::unique_ptr<NodeButton> closeButton(new NodeButton(sf::Vector2f(40.f, 40.f), mFonts.get(Fonts::Statistics), "X")); mCloseButton = closeButton.get();
    
    mCloseButton->setButtonOrigin(sf::Vector2f(40.f, 0.f)); mCloseButton->setButtonPosition(sf::Vector2f(mWindow.getSize().x, 0.f), sf::Vector2f(1888.f, 2.f));
    
    mCloseButton->setButtonColor(sf::Color::Red, sf::Color::White); mSceneLayers[Static]->attachChild(std::move(closeButton));
    
} */

/* void World::addEscortSpacecraft() {
    
    std::unique_ptr<Spacecraft> escortSpacecraft_1(new Spacecraft(Spacecraft::Bastion, mTextures, mFonts)); escortSpacecraft_1->setRadius(mRadius);
    
    escortSpacecraft_1->setAzimuth(mPlayerSpacecraft_1->getAzimuth() + toRadian(90.f)); escortSpacecraft_1->setWindowCenter(mWindowCenter); escortSpacecraft_1->setInitialPosition();
    
    mPlayerSpacecraft_1->attachChild(std::move(escortSpacecraft_1));
    
    std::unique_ptr<Spacecraft> escortSpacecraft_2(new Spacecraft(Spacecraft::Bastion, mTextures, mFonts)); escortSpacecraft_2->setRadius(mRadius);
    
    escortSpacecraft_2->setAzimuth(mPlayerSpacecraft_2->getAzimuth() + toRadian(90.f)); escortSpacecraft_2->setWindowCenter(mWindowCenter); escortSpacecraft_2->setInitialPosition();
    
    mPlayerSpacecraft_2->attachChild(std::move(escortSpacecraft_2));
    
} */