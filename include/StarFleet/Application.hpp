#pragma once

#ifndef STARFLEET_APPLICATION_HPP
#define STARFLEET_APPLICATION_HPP

#include "Player.hpp"
#include "StateStack.hpp"
#include "ResourceHolder.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class Application {
    
    public:
        
        Application();
        void run();
        
    private:
        
        void render();
        void processInput();
        void registerStates();
        void update(sf::Time);
        void updateStatistics(sf::Time);
        
    private:
        
        static const sf::Time TimePerFrame;
        
        sf::ContextSettings mSettings;
        sf::RenderWindow mWindow;
        TextureHolder mTextures;
        FontHolder mFonts;
        Player mPlayer;
        
        StateStack mStateStack;
        
        sf::Text mStatisticsText;
        sf::Time mStatisticsUpdateTime;
        
        std::size_t mStatisticsNumFrames;
        
        bool mIsPaused;
        
};

#endif