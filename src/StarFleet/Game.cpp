#include "StarFleet/Game.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Window/Event.hpp>

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game(): mSettings(), mWindow(), mPlayer(), mWorld(mWindow, mTextures, mFonts), mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0) {
    
    mSettings.antialiasingLevel = 16; mWindow.create(sf::VideoMode(1920, 1080), "StarFleet", sf::Style::Fullscreen, mSettings);
    
    mFonts.load(Fonts::Statistics, ".\\files\\fonts\\arial-black.ttf");
    
    mWindow.setKeyRepeatEnabled(false);
    
    mStatisticsText.setCharacterSize(10u); mStatisticsText.setPosition(5.f, 5.f); mStatisticsText.setFont(mFonts.get(Fonts::Statistics));
    
    mIsPaused = false; // mCursorArrow.loadFromSystem(sf::Cursor::Arrow); mCursorHand.loadFromSystem(sf::Cursor::Hand);
    
}

void Game::run() {
    
    sf::Clock clock; sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    while(mWindow.isOpen()) {
        
        processEvents(); sf::Time elapsedTime = clock.restart(); timeSinceLastUpdate += elapsedTime;
        
        while(timeSinceLastUpdate > TimePerFrame) {
            
            processEvents(); if(!mIsPaused) update(TimePerFrame); timeSinceLastUpdate -= TimePerFrame;
            
        }
        
        updateStatistics(elapsedTime); render();
        
    }
    
}

void Game::render() {
    
    mWindow.clear(); mWorld.draw();
    
    mWindow.setView(mWindow.getDefaultView()); mWindow.draw(mStatisticsText); mWindow.display();
    
}

void Game::processEvents() {
    
    CommandQueue &commands = mWorld.getCommandQueue(); sf::Event event;
    
    while(mWindow.pollEvent(event)) { mPlayer.handleEvent(event, commands); if(event.type == sf::Event::GainedFocus) mIsPaused = false; else if(event.type == sf::Event::LostFocus) mIsPaused = true; }
    
    mPlayer.handleRealTimeInput(commands);
    
}

void Game::update(sf::Time deltaTime) { mWorld.update(deltaTime); }

void Game::updateStatistics(sf::Time elapsedTime) {
    
    mStatisticsUpdateTime += elapsedTime; mStatisticsNumFrames++;
    
    if(mStatisticsUpdateTime >= sf::seconds(1.f)) {
        
        mStatisticsText.setString(
            
            "Frames / Second = " + std::to_string(mStatisticsNumFrames) + " fps" + 
            "\nTime / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + " us"
            
        );
        
        mStatisticsUpdateTime -= sf::seconds(1.f); mStatisticsNumFrames = 0;
        
    }
    
}

/* void Game::run() {
    
    sf::Clock clock; sf::Time timeSinceLastUpdate = sf::Time::Zero; mWorld.saveCurrentState(); mWorld.savePreviousState();
    
    while(mWindow.isOpen()) {
        
        mWorld.savePreviousState(); sf::Time elapsedTime = clock.restart(); timeSinceLastUpdate += elapsedTime;
        
        while(timeSinceLastUpdate > TimePerFrame) { processEvents(); if(!mIsPaused) update(TimePerFrame); mWorld.saveCurrentState(); timeSinceLastUpdate -= TimePerFrame; }
        
        float alpha = timeSinceLastUpdate / TimePerFrame; mWorld.interpolate(alpha); updateStatistics(elapsedTime); render();
        
    }
    
} */

/* void Game::processEvents() {
    
    CommandQueue &commands = mWorld.getCommandQueue(); sf::Event event;
    
    while(mWindow.pollEvent(event)) {
        
        mPlayer.handleEvent(event, commands);
        
        switch(event.type) {
            
            case sf::Event::GainedFocus:
                
                mIsPaused = false;
                break;
                
            case sf::Event::LostFocus:
                
                mIsPaused = true;
                break;
                
            case sf::Event::MouseMoved:
                
                mouseHover(sf::Mouse::getPosition(mWindow));
                break;
                
            case sf::Event::MouseButtonPressed:
                
                closeWindow(event.mouseButton.button, sf::Mouse::getPosition());
                break;
                
        }
        
    }
    
    mPlayer.handleRealTimeInput(commands);
    
} */

/* void Game::mouseHover(sf::Vector2i mousePosition) {
    
    NodeButton &mCloseButton = mWorld.getButtonReference(); sf::FloatRect exitBounds = mCloseButton.getButtonBounds();
    
    if(mousePosition.x >= exitBounds.left && mousePosition.x <= exitBounds.left + exitBounds.width && mousePosition.y >= exitBounds.top && mousePosition.y <= exitBounds.top + exitBounds.height) {
        
        mCloseButton.setButtonColor(sf::Color::White, sf::Color::Black); mWindow.setMouseCursor(mCursorHand);
        
    }
    
    else { mCloseButton.setButtonColor(sf::Color::Red, sf::Color::White); mWindow.setMouseCursor(mCursorArrow); }
    
} */

/* void Game::closeWindow(sf::Mouse::Button mouseButton, sf::Vector2i mousePosition) {
    
    NodeButton &mCloseButton = mWorld.getButtonReference(); sf::FloatRect exitBounds = mCloseButton.getButtonBounds();
    
    if(mousePosition.x >= exitBounds.left && mousePosition.x <= exitBounds.left + exitBounds.width && mousePosition.y >= exitBounds.top && mousePosition.y <= exitBounds.top + exitBounds.height) {
        
        if(mouseButton == sf::Mouse::Left) mWindow.close();
        
    }
    
} */