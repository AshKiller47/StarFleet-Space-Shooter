#include "StarFleet/Application.hpp"
#include "StarFleet/GameState.hpp"
#include "StarFleet/MenuState.hpp"
#include "StarFleet/TitleState.hpp"
#include "StarFleet/PauseState.hpp"
#include "StarFleet/SettingsState.hpp"
#include "StarFleet/GameModeState.hpp"
#include "StarFleet/GameLoadState.hpp"
#include "StarFleet/GameOverState.hpp"
#include "StarFleet/TitleLoadState.hpp"
#include "ResourceHolder.cpp"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application(): mSettings(), mWindow(), mTextures(), mFonts(), mPlayer(),mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer)), 
                            mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0) {
                            
    mSettings.antialiasingLevel = 16; mWindow.create(sf::VideoMode(1920, 1080), "StarFleet", sf::Style::Fullscreen, mSettings);
    
    mFonts.load(Fonts::Main, ".\\files\\fonts\\kenvector_future_thin.ttf");
    mFonts.load(Fonts::Statistics, ".\\files\\fonts\\arial-black.ttf");
    
    mWindow.setVerticalSyncEnabled(true); mWindow.setKeyRepeatEnabled(false);
    
    mStatisticsText.setFont(mFonts.get(Fonts::Statistics)); mStatisticsText.setPosition(5.f, 5.f); mStatisticsText.setCharacterSize(10u);
    
    mIsPaused = false; registerStates(); mStateStack.pushState(States::Title_Load);
    
}

void Application::run() {
    
    sf::Clock clock; sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    while(mWindow.isOpen()) {
        
        sf::Time elapsedTime = clock.restart(); timeSinceLastUpdate += elapsedTime;
        
        while(timeSinceLastUpdate > TimePerFrame) {
            
            processInput(); if(!mIsPaused) update(TimePerFrame); if(mStateStack.isEmpty()) mWindow.close(); timeSinceLastUpdate -= TimePerFrame;
            
        }
        
        updateStatistics(elapsedTime); render();
        
    }
    
}

void Application::render() {
    
    mWindow.clear(); mStateStack.draw();
    
    mWindow.setView(mWindow.getDefaultView()); mWindow.draw(mStatisticsText); mWindow.display();
    
}

void Application::processInput() {
    
    sf::Event event;
    
    while(mWindow.pollEvent(event)) {
        
        mStateStack.handleEvent(event);
        
        switch(event.type) {
            
            case sf::Event::GainedFocus:
                
                mIsPaused = false;
                break;
                
            case sf::Event::LostFocus:
                
                mIsPaused = true;
                break;
                
            case sf::Event::Closed:
                
                mWindow.close();
                break;
                
        }
        
    }
    
}

void Application::registerStates() {
    
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<PauseState>(States::Pause);
    mStateStack.registerState<SettingsState>(States::Settings);
    mStateStack.registerState<GameModeState>(States::Game_Mode);
    mStateStack.registerState<GameLoadState>(States::Game_Load);
    mStateStack.registerState<GameOverState>(States::Game_Over);
    mStateStack.registerState<TitleLoadState>(States::Title_Load);
    
}

void Application::update(sf::Time deltaTime) { mStateStack.update(deltaTime); }

void Application::updateStatistics(sf::Time elapsedTime) {
    
    mStatisticsUpdateTime += elapsedTime; mStatisticsNumFrames++;
    
    if(mStatisticsUpdateTime >= sf::seconds(1.f)) {
        
        mStatisticsText.setString(
            
            "Frames / Second = " + std::to_string(mStatisticsNumFrames) + " fps" + 
            "\nTime / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + " us"
            
        );
        
        mStatisticsUpdateTime -= sf::seconds(1.f); mStatisticsNumFrames = 0;
        
    }
    
}