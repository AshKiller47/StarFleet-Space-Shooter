#pragma once

#ifndef STARFLEET_MENUSTATE_HPP
#define STARFLEET_MENUSTATE_HPP

#include "State.hpp"
#include "Container.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class MenuState: public State {
    
    public:
        
        MenuState(StateStack&, Context);
        
        virtual void draw();
        virtual bool update(sf::Time);
        virtual bool handleEvent(const sf::Event&);
        
    private:
        
        sf::Sprite mBackgroundSprite;
        sf::Text mDisplayText;
        GUI::Container mGUIContainer;
        
};

#endif