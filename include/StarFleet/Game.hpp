#pragma once

#ifndef STARFLEET_GAME_HPP
#define STARFLEET_GAME_HPP

#include "World.hpp"
#include "Player.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
// #include <SFML/Window/Mouse.hpp>

class Game {
    
    public:
        
        Game();
        void run();
        
    private:
        
        void render();
        void processEvents();
        void update(sf::Time);
        void updateStatistics(sf::Time);
        
        // void mouseHover(sf::Vector2i);
        // void closeWindow(sf::Mouse::Button, sf::Vector2i);
        
    private:
        
        static const sf::Time TimePerFrame;
        
        sf::ContextSettings mSettings;
        sf::RenderWindow mWindow;
        
        TextureHolder mTextures;
        FontHolder mFonts;
        Player mPlayer;
        World mWorld;
        
        sf::Text mStatisticsText;
        sf::Time mStatisticsUpdateTime;
        
        // sf::Cursor mCursorArrow, mCursorHand;
        
        std::size_t mStatisticsNumFrames;
        
        bool mIsPaused;
        
};

#endif