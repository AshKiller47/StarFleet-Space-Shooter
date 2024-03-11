#pragma once

#ifndef STARFLEET_ENTITY_HPP
#define STARFLEET_ENTITY_HPP

#include "SceneNode.hpp"

class Entity: public SceneNode {
    
    public:
        
        explicit Entity(int);
        
        // Entity();
        
        void destroy();
        void damage(int);
        void repair(int);
        
        void setRadius(float);
        void setAzimuth(float);
        void setInitialPosition();
        void setRadialVelocity(float);
        
        float getRadius() const;
        int getHitPoints() const;
        
        virtual bool isDestroyed() const;
        virtual float getAzimuth() const;
        virtual float getRadialVelocity() const;
        
    protected:
        
        virtual void updateCurrent(sf::Time, CommandQueue&);
        
        // virtual void updateCurrent(sf::Time, const sf::Vector2f&);
        
    private:
        
        virtual void updateAzimuth(sf::Time);
        
        virtual void currentState();
        virtual void previousState();
        virtual void interpolateCurrent(float);
        
        // virtual float getAzimuth() const = 0;
        
    private:
        
        sf::Vector2f previousPosition, currentPosition;
        
        // sf::Vector2f mScale;
        
        int mHitPoints;
        
        float previousRotation, currentRotation;
        float mRadius, mAzimuth, mRadialVelocity;
        
};

#endif