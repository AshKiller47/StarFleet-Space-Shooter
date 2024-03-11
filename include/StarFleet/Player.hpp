#pragma once

#ifndef STARFLEET_PLAYER_HPP
#define STARFLEET_PLAYER_HPP

#include "Command.hpp"
#include <SFML/Window/Event.hpp>
#include <map>

struct CommandQueue;

class Player {
    
    public:
        
        enum Action { DextroRotation, LevoRotation, RadialIn, RadialOut, OrbitalAcceleration, AttachDetach, Fire, LaunchMissile, ActionCount };
        
        enum GameMode { Classic, Accelerated };
        
    public:
        
        Player();
        
        void handleRealTimeInput(CommandQueue&);
        void handleEvent(const sf::Event&, CommandQueue&);
        
        void setGameMode(GameMode);
        void setSurvivalTime(sf::Time);
        void assignKey(Action, sf::Keyboard::Key);
        
        GameMode getGameMode() const;
        sf::Time getSurvivalTime() const;
        sf::Keyboard::Key getAssignedKey(Action) const;
        
    private:
        
        void initializeAction();
        
        static bool isRealTimeAction(Action);
        
    private:
        
        GameMode mGameMode;
        sf::Time mSurvivalTime;
        
        std::map<Action, Command> mActionBinding;
        std::map<sf::Keyboard::Key, Action> mKeyBinding;
        
};

#endif