#pragma once

#ifndef STARFLEET_PICKUP_HPP
#define STARFLEET_PICKUP_HPP

#include "Entity.hpp"
#include "Spacecraft.hpp"
#include "ResourceIdentifiers.hpp"

class Pickup: public Entity {
    
    public:
        
        enum Type { HealthRefill, MissileRefill, FireRate, FireSpread, TypeCount };
        
    public:
        
        Pickup(Type, const TextureHolder&);
        
        unsigned int getType() const;
        void apply(Spacecraft&) const;
        
        virtual unsigned int getCategory() const;
        virtual sf::FloatRect getBoundingRect() const;
        
    private:
        
        virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
        
    private:
        
        Type mType;
        sf::Sprite mSprite;
        
};

#endif