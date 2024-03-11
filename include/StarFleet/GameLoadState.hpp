#pragma once

#ifndef STARFLEET_GAMELOADSTATE_HPP
#define STARFLEET_GAMELOADSTATE_HPP

#include "State.hpp"
#include "GameLoadTask.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class GameLoadState: public State {
    
    public:
        
        GameLoadState(StateStack&, Context);
        
        void setCompletion(std::pair<float, std::string>);
        
        virtual void draw();
        virtual bool update(sf::Time);
        virtual bool handleEvent(const sf::Event&);
        
    private:
        
        GameLoadTask mLoadingTask;
        
        sf::Text mLoadingText, mResourceText;
        sf::RectangleShape mProgressBarBackground, mProgressBar;
        
};

#endif