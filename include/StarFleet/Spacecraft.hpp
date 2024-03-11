#pragma once

#ifndef STARFLEET_SPACECRAFT_HPP
#define STARFLEET_SPACECRAFT_HPP

#include "Entity.hpp"
#include "Command.hpp"
#include "TextNode.hpp"
#include "Projectile.hpp"
#include "ResourceIdentifiers.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Spacecraft: public Entity {
    
    public:
        
        enum Type { Enterprise, Dauntless, Bastion, Anarchy, Carnage, TypeCount };
        
    public:
        
        Spacecraft(Type, const TextureHolder&, const FontHolder&);
        
        void fire();
        void launchMissile();
        void increaseSpread();
        void increaseFireRate();
        void collectMissiles(unsigned int);
        
        void setAttachment();
        void setAcceleration();
        void setAngularSpeed(float);
        void updateSwitchInterval(float);
        void updateRadialVelocity(float);
        
        bool isAllied() const;
        bool isMaster() const;
        bool isShooter() const;
        bool isRestricted() const;
        
        float getAngularSpeed() const;
        float getPickupVelocity() const;
        float getAccelerationFactor() const;
        
        virtual bool isMarkedForRemoval() const;
        virtual float getRadialVelocity() const;
        virtual unsigned int getCategory() const;
        virtual sf::FloatRect getBoundingRect() const;
        
    private:
        
        void updateTexts();
        void updateMovementPattern(sf::Time);
        
        void checkPickupDrop(CommandQueue&);
        void checkProjectileLaunch(sf::Time, CommandQueue&);
        
        void createPickup(SceneNode&, const TextureHolder&) const;
        void createBullets(SceneNode&, const TextureHolder&) const;
        void createProjectile(SceneNode&, const TextureHolder&, Projectile::Type, float, float) const;
        
        virtual void updateAzimuth(sf::Time);
        virtual void updateCurrent(sf::Time, CommandQueue&);
        
        virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
        
    private:
        
        Type mType;
        sf::Sprite mSprite;
        sf::Vector2f mScale;
        
        sf::Clock mClock;
        sf::Time mFireCountDown, mSwitchInterval;
        
        TextNode *mHealthDisplay;
        TextNode *mMissileDisplay;
        
        Command mFireCommand, mMissileCommand, mDropPickupCommand;
        
        std::size_t mDirectionIndex;
        
        int mFireRateLevel, mSpreadLevel, mMissileAmmo;
        float mAngularSpeed, mAccelerationFactor, mPickupVelocity;
        
        bool mIsRestricted, mIsAccelerated, mIsAttached;
        bool mIsFiring, mIsLaunchingMissile, mIsMarkedForRemoval;
        
};

#endif