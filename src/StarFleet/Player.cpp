#include "StarFleet/Player.hpp"
#include "StarFleet/Spacecraft.hpp"
#include "StarFleet/CommandQueue.hpp"

struct SpacecraftRotator {
    
    SpacecraftRotator(float speed): angularSpeed(speed) {}
    
    void operator() (Spacecraft &spacecraft, sf::Time deltaTime) const { spacecraft.setAngularSpeed(angularSpeed * spacecraft.getAngularSpeed()); }
    
    float angularSpeed;
    
};

struct SpacecraftExtender {
    
    SpacecraftExtender(float velocity): radialVelocity(velocity) {}
    
    void operator() (Spacecraft &spacecraft, sf::Time deltaTime) const { spacecraft.setRadialVelocity(radialVelocity * spacecraft.getRadialVelocity()); }
    
    float radialVelocity;
    
};

Player::Player(): mGameMode(Classic), mSurvivalTime(sf::Time::Zero) {
    
    mKeyBinding[sf::Keyboard::Up] = RadialOut;
    mKeyBinding[sf::Keyboard::Down] = RadialIn;
    mKeyBinding[sf::Keyboard::Left] = LevoRotation;
    mKeyBinding[sf::Keyboard::Right] = DextroRotation;
    mKeyBinding[sf::Keyboard::X] = OrbitalAcceleration;
    mKeyBinding[sf::Keyboard::Return] = AttachDetach;
    mKeyBinding[sf::Keyboard::Space] = Fire;
    mKeyBinding[sf::Keyboard::Z] = LaunchMissile;
    
    initializeAction();
    
    mActionBinding[RadialOut].category = Category::AlliedSpacecraft;
    mActionBinding[RadialIn].category = Category::AlliedSpacecraft;
    mActionBinding[LevoRotation].category = Category::PlayerSpacecraft | Category::AlliedSpacecraft;
    mActionBinding[DextroRotation].category = Category::PlayerSpacecraft | Category::AlliedSpacecraft;
    mActionBinding[OrbitalAcceleration].category = Category::PlayerSpacecraft;
    mActionBinding[AttachDetach].category = Category::AlliedSpacecraft;
    mActionBinding[Fire].category = Category::PlayerSpacecraft;
    mActionBinding[LaunchMissile].category = Category::PlayerSpacecraft;
    
}

void Player::handleRealTimeInput(CommandQueue &commands) { for(auto pair: mKeyBinding) if(sf::Keyboard::isKeyPressed(pair.first) && isRealTimeAction(pair.second)) commands.push(mActionBinding[pair.second]); }

void Player::handleEvent(const sf::Event &event, CommandQueue &commands) {
    
    if(event.type == sf::Event::KeyPressed) { auto found = mKeyBinding.find(event.key.code); if(found != mKeyBinding.end() && !isRealTimeAction(found->second)) commands.push(mActionBinding[found->second]); }
    
}

void Player::setGameMode(GameMode mode) { mGameMode = mode; }

void Player::setSurvivalTime(sf::Time survivalTime) { mSurvivalTime = survivalTime; }

void Player::assignKey(Action action, sf::Keyboard::Key key) {
    
    for(auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); ) { if(itr->second == action) mKeyBinding.erase(itr++); else ++itr; }
    
    mKeyBinding[key] = action;
    
}

sf::Time Player::getSurvivalTime() const { return mSurvivalTime; }

sf::Keyboard::Key Player::getAssignedKey(Action action) const {
    
    for(auto pair: mKeyBinding) if(pair.second == action) return pair.first; return sf::Keyboard::Unknown;
    
}

Player::GameMode Player::getGameMode() const { return mGameMode; }

void Player::initializeAction() {
    
    mActionBinding[RadialOut].action = derivedAction<Spacecraft>(SpacecraftExtender(1.f));
    mActionBinding[RadialIn].action = derivedAction<Spacecraft>(SpacecraftExtender(-1.f));
    mActionBinding[LevoRotation].action = derivedAction<Spacecraft>(SpacecraftRotator(-1.f));
    mActionBinding[DextroRotation].action = derivedAction<Spacecraft>(SpacecraftRotator(1.f));
    
    // mActionBinding[OrbitalAcceleration].action = derivedAction<Spacecraft>(SpacecraftAccelerator());
    // mActionBinding[AttachDetach].action = derivedAction<Spacecraft>(SpacecraftLinker());
    
    mActionBinding[OrbitalAcceleration].action = derivedAction<Spacecraft>([] (Spacecraft &spacecraft, sf::Time deltaTime) { spacecraft.setAcceleration(); });
    mActionBinding[AttachDetach].action = derivedAction<Spacecraft>([] (Spacecraft &spacecraft, sf::Time deltaTime) { spacecraft.setAttachment(); });
    mActionBinding[Fire].action = derivedAction<Spacecraft>([] (Spacecraft &spacecraft, sf::Time deltaTime) { spacecraft.fire(); });
    mActionBinding[LaunchMissile].action = derivedAction<Spacecraft>([] (Spacecraft &spacecraft, sf::Time deltaTime) { spacecraft.launchMissile(); });
    
}

bool Player::isRealTimeAction(Action action) {
    
    switch(action) {
        
        case DextroRotation:
        case LevoRotation:
        case RadialIn:
        case RadialOut:
        case OrbitalAcceleration:
        case Fire:
            
            return true;
            
        default: return false;
        
    }
    
}

// struct SpacecraftAccelerator { void operator() (Spacecraft &spacecraft, sf::Time deltaTime) const { spacecraft.setAcceleration(); } };

// struct SpacecraftLinker { void operator() (Spacecraft &spacecraft, sf::Time deltaTime) const { spacecraft.setAttachment(); } };