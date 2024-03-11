#pragma once

#ifndef STARFLEET_DATATABLES_HPP
#define STARFLEET_DATATABLES_HPP

#include "ResourceIdentifiers.hpp"
#include <SFML/System/Time.hpp>
#include <functional>
#include <vector>

class Spacecraft;

struct RadialDirection {
    
    RadialDirection(float radius, float azimuth): radius(radius), azimuth(azimuth) {}
    
    float radius, azimuth;
    
};

struct AngularDirection {
    
    AngularDirection(float azimuth): azimuth(azimuth) {}
    
    float azimuth;
    
};

struct SpacecraftData {
    
    float angularSpeed, radialVelocity; int hitpoints; Textures::ID texture; sf::Time fireInterval;
    
    std::vector<RadialDirection> radialDirections; std::vector<AngularDirection> angularDirections;
    
};

struct ProjectileData { float radialVelocity; int damage; Textures::ID texture; };

struct PickupData { std::function<void(Spacecraft&)> action; Textures::ID texture; };

std::vector<SpacecraftData> initializeSpacecraftData();
std::vector<ProjectileData> initializeProjectileData();
std::vector<PickupData> initializePickupData();

#endif