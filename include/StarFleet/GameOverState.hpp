#pragma once

#ifndef STARFLEET_GAMEOVERSTATE_HPP
#define STARFLEET_GAMEOVERSTATE_HPP

#include "State.hpp"
#include "Container.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class GameOverState: public State {
    
    public:
        
        GameOverState(StateStack&, Context);
        
        virtual void draw();
        virtual bool update(sf::Time);
        virtual bool handleEvent(const sf::Event&);
        
    private:
        
        sf::RectangleShape mBackgroundShape;
        sf::Text mGameOverText, mSurvivalText;
        sf::Time mSurvivalTime;
        
        GUI::Container mGUIContainer;
        
};

#endif