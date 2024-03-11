#pragma once

#ifndef STARFLEET_GAMEMODESTATE_HPP
#define STARFLEET_GAMEMODESTATE_HPP

#include "State.hpp"
#include "Container.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class GameModeState: public State {
    
    public:
        
        GameModeState(StateStack&, Context);
        
        virtual void draw();
        virtual bool update(sf::Time);
        virtual bool handleEvent(const sf::Event&);
        
    private:
        
        Player &mPlayer;
        
        sf::Sprite mBackgroundSprite;
        sf::Text mDisplayText;
        GUI::Container mGUIContainer;
        
};

#endif