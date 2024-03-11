#include "StarFleet/Spacecraft.hpp"
#include "StarFleet/Pickup.hpp"
#include "StarFleet/DataTables.hpp"
#include "StarFleet/CommandQueue.hpp"
#include "StarFleet/Utility.hpp"
#include "StarFleet/StringHelpers.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <cmath>

namespace { const std::vector<SpacecraftData> Table = initializeSpacecraftData(); }

Spacecraft::Spacecraft(Type type, const TextureHolder &textures, const FontHolder &fonts): Entity(Table[type].hitpoints), mType(type), mSprite(textures.get(Table[type].texture)), mFireCountDown(sf::Time::Zero), 
                                                                                           mSwitchInterval(sf::seconds(2.f)), mHealthDisplay(nullptr), mMissileDisplay(nullptr), mFireCommand(), mMissileCommand(), 
                                                                                           mDropPickupCommand(), mDirectionIndex(0), mFireRateLevel(1), mSpreadLevel(1), mMissileAmmo(10), mAngularSpeed(0.f), 
                                                                                           mAccelerationFactor(0.f), mPickupVelocity(-350.f), mIsRestricted(false), mIsAccelerated(false), mIsAttached(true), 
                                                                                           mIsFiring(false), mIsLaunchingMissile(false), mIsMarkedForRemoval(false) {
    if(!isAllied()) mSprite.setRotation(90.f); else mSprite.setRotation(-90.f);
    
    // if(!isAllied() || isMaster()) mSprite.setRotation(90.f); else mSprite.setRotation(-90.f);
    
    if(getCategory() == Category::MasterSpacecraft) mSprite.setScale(sf::Vector2f(0.6f, 0.6f));
    
    else if(getCategory() == Category::AlliedSpacecraft) mSprite.setScale(sf::Vector2f(0.1f, 0.35f));
    
    else mSprite.setScale(sf::Vector2f(0.035f, 0.035f));
    
    mScale = mSprite.getScale(); centerOrigin(mSprite); if(getCategory() == Category::AlliedSpacecraft) setRadialVelocity(0.f); else setRadialVelocity(Table[type].radialVelocity);
    
    mFireCommand.category = Category::SceneSpaceLayer;
    mFireCommand.action = [this, &textures] (SceneNode &node, sf::Time deltaTime) { createBullets(node, textures); };
    
    mMissileCommand.category = Category::SceneSpaceLayer;
    mMissileCommand.action = [this, &textures] (SceneNode &node, sf::Time deltaTime) { createProjectile(node, textures, Projectile::Missile, 17.f, 0.f); };
    
    mDropPickupCommand.category = Category::SceneSpaceLayer;
    mDropPickupCommand.action = [this, &textures] (SceneNode &node, sf::Time deltaTime) { createPickup(node, textures); };
    
    if(getCategory() == Category::PlayerSpacecraft) {
        
        std::unique_ptr<TextNode> missileDisplay(new TextNode(fonts, ""));
        
        missileDisplay->setPosition(47.f, 0.f); missileDisplay->setRotation(toDegree(getAzimuth()) - 90.f); mMissileDisplay = missileDisplay.get(); attachChild(std::move(missileDisplay));
        
    }
    
    std::unique_ptr<TextNode> healthDisplay(new TextNode(fonts, "")); mHealthDisplay = healthDisplay.get(); attachChild(std::move(healthDisplay));
    
    if(getCategory() == Category::MasterSpacecraft) mHealthDisplay->setPosition(0.f, 0.f);
    
    else { if(getCategory() == Category::EnemySpacecraft) mHealthDisplay->setPosition(-37.f, 0.f); else mHealthDisplay->setPosition(34.f, 0.f); mHealthDisplay->setRotation(toDegree(getAzimuth()) - 90.f); }
    
    if(isMaster()) mAngularSpeed = getAngularSpeed(); updateTexts();
    
}

void Spacecraft::fire() { if(Table[mType].fireInterval != sf::Time::Zero) mIsFiring = true; }

void Spacecraft::launchMissile() { if(mMissileAmmo > 0) { mIsLaunchingMissile = true; mMissileAmmo--; } }

void Spacecraft::increaseSpread() { if(mSpreadLevel < 3) mSpreadLevel++; }

void Spacecraft::increaseFireRate() { if(mFireRateLevel < 10) mFireRateLevel++; }

void Spacecraft::collectMissiles(unsigned int count) { mMissileAmmo += count; }

void Spacecraft::setAttachment() { if(mIsAttached) mIsAttached = false; else mIsAttached = true; }

void Spacecraft::setAcceleration() { mIsAccelerated = true; }

void Spacecraft::setAngularSpeed(float angularSpeed) { if(mIsAttached) mAngularSpeed += angularSpeed; }

void Spacecraft::updateSwitchInterval(float accelerationFactor) { mSwitchInterval = sf::seconds(2.f / accelerationFactor); }

void Spacecraft::updateRadialVelocity(float accelerationFactor) { setRadialVelocity(getRadialVelocity() * accelerationFactor); }

bool Spacecraft::isAllied() const { return mType == Dauntless || mType == Bastion; }

bool Spacecraft::isMaster() const { return mType == Enterprise; }

bool Spacecraft::isShooter() const { return mType == Dauntless || mType == Carnage; }

bool Spacecraft::isRestricted() const { return mIsRestricted; }

float Spacecraft::getAngularSpeed() const { return Table[mType].angularSpeed; }

float Spacecraft::getPickupVelocity() const { return mPickupVelocity; }

float Spacecraft::getAccelerationFactor() const { return 1.f + mAccelerationFactor * 2.f; }

bool Spacecraft::isMarkedForRemoval() const { return mIsMarkedForRemoval; }

float Spacecraft::getRadialVelocity() const { return Table[mType].radialVelocity; }

unsigned int Spacecraft::getCategory() const {
    
    if(isMaster()) return Category::MasterSpacecraft;
    
    else if(isAllied() && isShooter()) return Category::PlayerSpacecraft;
    
    else if(isAllied() && !isShooter()) return Category::AlliedSpacecraft;
    
    else return Category::EnemySpacecraft;
    
}

sf::FloatRect Spacecraft::getBoundingRect() const { return getWorldTransform().transformRect(mSprite.getGlobalBounds()); }

void Spacecraft::updateTexts() {
    
    mHealthDisplay->setString(toString(getHitPoints()) + " HP");
    
    if(mMissileDisplay) { if(mMissileAmmo == 0) mMissileDisplay->setString(""); else mMissileDisplay->setString("M: " + toString(mMissileAmmo)); }
    
}

void Spacecraft::updateMovementPattern(sf::Time deltaTime) {
    
    const std::vector<RadialDirection> &radialDirections = Table[mType].radialDirections; const std::vector<AngularDirection> &angularDirections = Table[mType].angularDirections;
    
    if(!radialDirections.empty() && mIsRestricted && mDirectionIndex < radialDirections.size() && getRadius() <= radialDirections[mDirectionIndex].radius) {
        
        setAzimuth(getAzimuth() + toRadian(radialDirections[mDirectionIndex].azimuth)); mDirectionIndex++;
        
    }
    
    else if(!angularDirections.empty() && mIsRestricted) {
        
        sf::Time elapsedTime = mClock.getElapsedTime();
        
        if(elapsedTime >= mSwitchInterval) {
            
            setAzimuth(getAzimuth() + toRadian(angularDirections[mDirectionIndex].azimuth)); mDirectionIndex = (mDirectionIndex + 1) % angularDirections.size(); mClock.restart();
            
        }
        
    }
    
}

void Spacecraft::checkPickupDrop(CommandQueue &commands) { if(!isAllied() && !isMaster() && randomInt(3) == 0) commands.push(mDropPickupCommand); }

void Spacecraft::checkProjectileLaunch(sf::Time deltaTime, CommandQueue &commands) {
    
    if(!isAllied() && !isMaster()) fire();
    
    if(mIsFiring && mFireCountDown <= sf::Time::Zero) {
        
        commands.push(mFireCommand); mFireCountDown += Table[mType].fireInterval / (mFireRateLevel * 10.f); mIsFiring = false;
        
    }
    
    else if(mFireCountDown > sf::Time::Zero) { mFireCountDown -= deltaTime; mIsFiring = false; }
    
    if(mIsLaunchingMissile) { commands.push(mMissileCommand); mIsLaunchingMissile = false; }
    
}

void Spacecraft::createPickup(SceneNode &node, const TextureHolder &textures) const {
    
    auto type = static_cast<Pickup::Type>(randomInt(Pickup::TypeCount)); std::unique_ptr<Pickup> pickup(new Pickup(type, textures));
    
    pickup->setRadialVelocity(mPickupVelocity); pickup->setAzimuth(getAzimuth());
    
    pickup->setRadius(getRadius()); pickup->setWindowCenter(getWindowCenter()); node.attachChild(std::move(pickup));
    
}

void Spacecraft::createBullets(SceneNode &node, const TextureHolder &textures) const {
    
    if(isAllied()) {
        
        Projectile::Type type = Projectile::AlliedBullet;
        
        switch(mSpreadLevel) {
            
            case 1:
                
                createProjectile(node, textures, type, 4.f, 0.f);
                break;
                
            case 2:
                
                createProjectile(node, textures, type, 7.f, 2.f);
                createProjectile(node, textures, type, 4.f, 0.f);
                createProjectile(node, textures, type, 7.f, -2.f);
                break;
                
            case 3:
                
                createProjectile(node, textures, type, 10.f, 4.f);
                createProjectile(node, textures, type, 7.f, 2.f);
                createProjectile(node, textures, type, 4.f, 0.f);
                createProjectile(node, textures, type, 7.f, -2.f);
                createProjectile(node, textures, type, 10.f, -4.f);
                break;
                
        }
        
    }
    
    else { Projectile::Type type = Projectile::EnemyBullet; createProjectile(node, textures, type, 15.f, 0.f); }
    
}

void Spacecraft::createProjectile(SceneNode &node, const TextureHolder &textures, Projectile::Type type, float radialOffset, float azimuthalOffset) const {
    
    std::unique_ptr<Projectile> projectile(new Projectile(type, textures)); float sign = isAllied() ? 1.f : -1.f;
    
    projectile->setRadialVelocity(projectile->getRadialVelocity() * sign); projectile->setAzimuth(getAzimuth() + toRadian(azimuthalOffset));
    
    projectile->setRadius(getRadius() + radialOffset); projectile->setWindowCenter(getWindowCenter()); node.attachChild(std::move(projectile));
    
}

void Spacecraft::updateAzimuth(sf::Time deltaTime) {
    
    // mAngularSpeed += 2.f * deltaTime.asSeconds(); if(mAngularSpeed < -0.05 || mAngularSpeed > 0.05) setAzimuth(getAzimuth() + mAngularSpeed * deltaTime.asSeconds());
    
    if(mIsAccelerated && mAccelerationFactor < 1.f) mAccelerationFactor += 1.f * deltaTime.asSeconds();
    
    else if(!mIsAccelerated && mAccelerationFactor > 0.f) mAccelerationFactor -= 0.1f * deltaTime.asSeconds();
    
    setAzimuth(getAzimuth() + mAngularSpeed * (1.f + mAccelerationFactor) * deltaTime.asSeconds());
    
    if(!isMaster()) mAngularSpeed = 0.f; mIsAccelerated = false;
    
}

void Spacecraft::updateCurrent(sf::Time deltaTime, CommandQueue &commands) {
    
    if(isDestroyed()) { checkPickupDrop(commands); mIsMarkedForRemoval = true; } checkProjectileLaunch(deltaTime, commands);
    
    if(isAllied() || isMaster()) updateAzimuth(deltaTime); updateMovementPattern(deltaTime); updateTexts(); Entity::updateCurrent(deltaTime, commands);
    
    if(getCategory() == Category::AlliedSpacecraft) { mSprite.setScale(mScale.x * (1.f + (getRadius() - 235.f) / 40.f), mScale.y); }
    
    if(isAllied()) setRadialVelocity(0.f); if(mIsRestricted) return;
    
    if(getRadius() <= 650.f) { mIsRestricted = true; if(!isAllied() && isShooter()) { setRadialVelocity(0.f); setRadius(650.f); mClock.restart(); } }
    
}

void Spacecraft::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(mSprite, states); }