#pragma once

#ifndef STARFLEET_PAUSESTATE_HPP
#define STARFLEET_PAUSESTATE_HPP

#include "State.hpp"
#include "Container.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class PauseState: public State {
    
    public:
        
        PauseState(StateStack&, Context);
        
        virtual void draw();
        virtual bool update(sf::Time);
        virtual bool handleEvent(const sf::Event&);
        
    private:
        
        sf::RectangleShape mBackgroundShape;
        sf::Text mPausedText;
        
        GUI::Container mGUIContainer;
        
};

#endif