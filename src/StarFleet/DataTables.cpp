#include "StarFleet/DataTables.hpp"
#include "StarFleet/Spacecraft.hpp"
#include "StarFleet/Projectile.hpp"
#include "StarFleet/Pickup.hpp"

std::vector<SpacecraftData> initializeSpacecraftData() {
    
    std::vector<SpacecraftData> data(Spacecraft::TypeCount);
    
    data[Spacecraft::Enterprise].angularSpeed = 0.25f;
    data[Spacecraft::Enterprise].radialVelocity = 0.f;
    data[Spacecraft::Enterprise].hitpoints = 100000;
    data[Spacecraft::Enterprise].texture = Textures::Enterprise;
    data[Spacecraft::Enterprise].fireInterval = sf::Time::Zero;
    
    data[Spacecraft::Dauntless].angularSpeed = 6.f;
    data[Spacecraft::Dauntless].radialVelocity = 0.f;
    data[Spacecraft::Dauntless].hitpoints = 25000;
    data[Spacecraft::Dauntless].texture = Textures::Dauntless;
    data[Spacecraft::Dauntless].fireInterval = sf::seconds(0.5f);
    
    data[Spacecraft::Bastion].angularSpeed = 6.f;
    data[Spacecraft::Bastion].radialVelocity = 300.f;
    data[Spacecraft::Bastion].hitpoints = 50000;
    data[Spacecraft::Bastion].texture = Textures::Bastion;
    data[Spacecraft::Bastion].fireInterval = sf::Time::Zero;
    
    data[Spacecraft::Anarchy].angularSpeed = 0.f;
    data[Spacecraft::Anarchy].radialVelocity = -150.f;
    data[Spacecraft::Anarchy].hitpoints = 200;
    data[Spacecraft::Anarchy].texture = Textures::Anarchy;
    data[Spacecraft::Anarchy].fireInterval = sf::Time::Zero;
    data[Spacecraft::Anarchy].radialDirections.push_back(RadialDirection(360.f, -90.f));
    
    data[Spacecraft::Carnage].angularSpeed = 0.f;
    data[Spacecraft::Carnage].radialVelocity = -300.f;
    data[Spacecraft::Carnage].hitpoints = 400;
    data[Spacecraft::Carnage].texture = Textures::Carnage;
    data[Spacecraft::Carnage].fireInterval = sf::seconds(0.5f);
    data[Spacecraft::Carnage].angularDirections.push_back(AngularDirection(15.f));
    data[Spacecraft::Carnage].angularDirections.push_back(AngularDirection(-15.f));
    data[Spacecraft::Carnage].angularDirections.push_back(AngularDirection(-15.f));
    data[Spacecraft::Carnage].angularDirections.push_back(AngularDirection(15.f));
    
    return data;
    
};

std::vector<ProjectileData> initializeProjectileData() {
    
    std::vector<ProjectileData> data(Projectile::TypeCount);
    
    data[Projectile::AlliedBullet].radialVelocity = 2000.f;
    data[Projectile::AlliedBullet].damage = 20;
    data[Projectile::AlliedBullet].texture = Textures::AlliedBullet;
    
    data[Projectile::EnemyBullet].radialVelocity = 2000.f;
    data[Projectile::EnemyBullet].damage = 10;
    data[Projectile::EnemyBullet].texture = Textures::EnemyBullet;
    
    data[Projectile::Missile].radialVelocity = 1000.f;
    data[Projectile::Missile].damage = 400;
    data[Projectile::Missile].texture = Textures::Missile;
    
    return data;
    
};

std::vector<PickupData> initializePickupData() {
    
    std::vector<PickupData> data(Pickup::TypeCount);
    
    data[Pickup::HealthRefill].texture = Textures::HealthRefill;
    data[Pickup::HealthRefill].action = [] (Spacecraft &spacecraft) { spacecraft.repair(1000); };
    
    data[Pickup::MissileRefill].texture = Textures::MissileRefill;
    data[Pickup::MissileRefill].action = [] (Spacecraft &spacecraft) { spacecraft.collectMissiles(5); };
    
    data[Pickup::FireRate].texture = Textures::FireRate;
    data[Pickup::FireRate].action = [] (Spacecraft &spacecraft) { spacecraft.increaseFireRate(); };
    
    data[Pickup::FireSpread].texture = Textures::FireSpread;
    data[Pickup::FireSpread].action = [] (Spacecraft &spacecraft) { spacecraft.increaseSpread(); };
    
    return data;
    
}