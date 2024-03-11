#pragma once

#ifndef STARFLEET_TITLELOADSTATE_HPP
#define STARFLEET_TITLELOADSTATE_HPP

#include "State.hpp"
#include "TitleLoadTask.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class TitleLoadState: public State {
    
    public:
        
        TitleLoadState(StateStack&, Context);
        
        void setCompletion(float);
        
        virtual void draw();
        virtual bool update(sf::Time);
        virtual bool handleEvent(const sf::Event&);
        
    private:
        
        TitleLoadTask mLoadingTask;
        
        sf::Text mLoadingText;
        sf::RectangleShape mProgressBarBackground, mProgressBar;
        
};

#endif