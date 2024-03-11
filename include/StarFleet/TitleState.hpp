#pragma once

#ifndef STARFLEET_TITLESTATE_HPP
#define STARFLEET_TITLESTATE_HPP

#include "State.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class TitleState: public State {
    
    public:
        
        TitleState(StateStack&, Context);
        
        virtual void draw();
        virtual bool update(sf::Time);
        virtual bool handleEvent(const sf::Event&);
        
    private:
        
        sf::Sprite mBackgroundSprite;
        sf::Text mDisplayText, mInstructionText;
        sf::Time mTextEffectTime;
        
        bool mShowText;
        
};

#endif