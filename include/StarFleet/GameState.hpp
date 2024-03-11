#pragma once

#ifndef STARFLEET_GAMESTATE_HPP
#define STARFLEET_GAMESTATE_HPP

#include "State.hpp"
#include "World.hpp"
#include "Player.hpp"

class GameState: public State {
    
    public:
        
        GameState(StateStack&, Context);
        
        virtual void draw();
        virtual bool update(sf::Time);
        virtual bool handleEvent(const sf::Event&);
        
    private:
        
        sf::RenderWindow &mWindow;
        sf::Time mSurvivalTime;
        Player &mPlayer;
        World mWorld;
        
        bool mIsPaused;
        
};

#endif