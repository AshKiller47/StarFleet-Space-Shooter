#include "StarFleet/Projectile.hpp"
#include "StarFleet/DataTables.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderTarget.hpp>
// #include <cassert>
#include <cmath>

namespace { const std::vector<ProjectileData> Table = initializeProjectileData(); }

Projectile::Projectile(Type type, const TextureHolder &textures): Entity(1), mType(type), mSprite(textures.get(Table[type].texture)), mAzimuth(0.f) {
    
    if(mType == EnemyBullet) mSprite.setRotation(90.f); else mSprite.setRotation(-90.f);
    
    if(type == Missile) setScale(sf::Vector2f(0.35f, 0.35f)); else setScale(sf::Vector2f(0.2f, 0.2f)); centerOrigin(mSprite);
    
}

void Projectile::guideTowards(float targetAzimuth, float azimuth) {
    
    mAzimuth = toDegree(getAzimuth()); targetAzimuth = toDegree(targetAzimuth); // assert(isGuided());
    
    while(mAzimuth < 0.f) mAzimuth += 360.f; while(mAzimuth > 360.f) mAzimuth -= 360.f; while(targetAzimuth < 0.f) targetAzimuth += 360.f;
    
    if(std::abs(mAzimuth - targetAzimuth) > 180.f) { if(mAzimuth > targetAzimuth) targetAzimuth += 360.f; else mAzimuth += 360.f; }
    
    if(mAzimuth > targetAzimuth) mAzimuth = azimuth; else mAzimuth = -azimuth;
    
}

bool Projectile::isGuided() const { return mType == Missile; }

int Projectile::getDamage() const { return Table[mType].damage; }

float Projectile::getRadialVelocity() const { return Table[mType].radialVelocity; }

unsigned int Projectile::getCategory() const { if(mType == EnemyBullet) return Category::EnemyProjectile; else return Category::AlliedProjectile; }

sf::FloatRect Projectile::getBoundingRect() const { return getWorldTransform().transformRect(mSprite.getGlobalBounds()); }

void Projectile::updateCurrent(sf::Time deltaTime, CommandQueue &commands) {
    
    if(isGuided()) {
        
        const float rate = 6.f; float azimuth = getAzimuth(), deviation = rate * deltaTime.asSeconds();
        
        if(mAzimuth > 0.f) { if(mAzimuth - deviation > 0.f) azimuth -= deviation; else azimuth -= mAzimuth; }
        
        else { if(mAzimuth + deviation < 0.f) azimuth += deviation; else azimuth -= mAzimuth; }
        
        setAzimuth(azimuth);
        
    }
    
    Entity::updateCurrent(deltaTime, commands);
    
}

void Projectile::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(mSprite, states); }