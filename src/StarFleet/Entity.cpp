#include "StarFleet/Entity.hpp"
#include "StarFleet/Utility.hpp"
// #include <cassert>
#include <cmath>

Entity::Entity(int hitpoints): mHitPoints(hitpoints), mRadius(0.f), mAzimuth(0.f), mRadialVelocity(0.f) {}

void Entity::destroy() { mHitPoints = 0; }

void Entity::damage(int points) { mHitPoints -= points; }

void Entity::repair(int points) { mHitPoints += points; }

void Entity::setRadius(float radius) { mRadius = radius; }

void Entity::setAzimuth(float azimuth) { mAzimuth = azimuth; }

void Entity::setInitialPosition() {
    
    sf::Vector2f windowCenter = getWindowCenter(); setRotation(toDegree(mAzimuth)); setPosition(windowCenter.x - mRadius * std::cos(mAzimuth), windowCenter.y - mRadius * std::sin(mAzimuth));
    
}

void Entity::setRadialVelocity(float velocity) { mRadialVelocity = velocity; }

float Entity::getRadius() const { return mRadius; }

int Entity::getHitPoints() const { return mHitPoints; }

bool Entity::isDestroyed() const { return mHitPoints <= 0; }

float Entity::getAzimuth() const { return mAzimuth; }

float Entity::getRadialVelocity() const { return mRadialVelocity; }

void Entity::updateCurrent(sf::Time deltaTime, CommandQueue &commands) {
    
    sf::Vector2f windowCenter = getWindowCenter(); mRadius += mRadialVelocity * deltaTime.asSeconds();
    
    if(getCategory() == Category::AlliedSpacecraft) { if(mRadius > 310.f) mRadius = 310.f; else if(mRadius < 235.f) mRadius = 235.f; }
    
    setRotation(toDegree(mAzimuth)); setPosition(windowCenter.x - mRadius * std::cos(mAzimuth), windowCenter.y - mRadius * std::sin(mAzimuth));
    
}

void Entity::updateAzimuth(sf::Time deltaTime) {}

void Entity::currentState() { currentPosition = getPosition(); currentRotation = getRotation(); }

void Entity::previousState() { previousPosition = currentPosition; previousRotation = currentRotation; }

void Entity::interpolateCurrent(float alpha) {
    
    setPosition(alpha * currentPosition + (1.f - alpha) * previousPosition);
    
    if(currentRotation < 90.f && previousRotation > 270.f) setRotation(alpha * (currentRotation + 360.f) + (1.f - alpha) * previousRotation);
    
    else if(currentRotation > 270.f && previousRotation < 90.f) setRotation(alpha * currentRotation + (1.f - alpha) * (previousRotation + 360.f));
    
    else setRotation(alpha * currentRotation + (1.f - alpha) * previousRotation);
    
}

// void Entity::damage(int points) { assert(points > 0); mHitPoints -= points; }

// void Entity::repair(int points) { assert(points > 0); mHitPoints += points; }

// Entity::Entity(): mScale(getScale()), mRadius(235.f), mRadialVelocity(0.f) {}

// void Entity::setRadialVelocity(float velocity) { mRadialVelocity += velocity; }

/* void Entity::updateCurrent(sf::Time deltaTime, const sf::Vector2f &windowCenter) {
    
    if(mRadialVelocity > 0.f && mRadius < 310.f) { setScale(mScale); mRadius += mRadialVelocity * deltaTime.asSeconds(); }
    
    else if(mRadialVelocity < 0.f && mRadius > 235.f) { setScale(-mScale.x, mScale.y); mRadius += mRadialVelocity * deltaTime.asSeconds(); }
    
    if(mRadius > 310.f) mRadius = 310.f; else if(mRadius < 235.f) mRadius = 235.f; updateAzimuth(deltaTime);
    
    const float mAzimuth = getAzimuth(); setRotation(toDegree(mAzimuth)); // setRotation(180.f * mAzimuth / M_PI);
    
    setPosition(windowCenter.x - mRadius * std::cos(mAzimuth), windowCenter.y - mRadius * std::sin(mAzimuth)); mRadialVelocity = 0.f;
    
} */