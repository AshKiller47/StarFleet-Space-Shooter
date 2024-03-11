#pragma once

#ifndef STARFLEET_PROJECTILE_HPP
#define STARFLEET_PROJECTILE_HPP

#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Projectile: public Entity {
    
    public:
        
        enum Type { AlliedBullet, EnemyBullet, Missile, TypeCount };
        
    public:
        
        Projectile(Type, const TextureHolder&);
        
        void guideTowards(float, float);
        
        bool isGuided() const;
        int getDamage() const;
        
        virtual float getRadialVelocity() const;
        virtual unsigned int getCategory() const;
        virtual sf::FloatRect getBoundingRect() const;
        
    private:
        
        virtual void updateCurrent(sf::Time, CommandQueue&);
        virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
        
    private:
        
        Type mType;
        sf::Sprite mSprite;
        
        float mAzimuth;
        
};

#endif