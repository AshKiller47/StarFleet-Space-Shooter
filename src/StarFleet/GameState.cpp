#include "StarFleet/GameState.hpp"

GameState::GameState(StateStack &stack, Context context): State(stack, context), mWindow(*context.window), mSurvivalTime(sf::Time::Zero), mPlayer(*context.player), 
                                                          mWorld(*context.window, *context.textures, *context.fonts), mIsPaused(false) {
    mWindow.setMouseCursorVisible(false);
    mWorld.setGameMode(mPlayer.getGameMode());
    
}

void GameState::draw() { mWorld.draw(); }

bool GameState::update(sf::Time deltaTime) {
    
    if(mIsPaused) { mWindow.setMouseCursorVisible(false); mWorld.playerSurvivalTime(); mIsPaused = false; }
    
    CommandQueue &commands = mWorld.getCommandQueue(); mPlayer.handleRealTimeInput(commands); mWorld.update(deltaTime);
    
    if(!mWorld.hasAlivePlayer() || !mWorld.hasAliveMaster()) {
        
        mSurvivalTime += mWorld.playerSurvivalTime(); mPlayer.setSurvivalTime(mSurvivalTime); mWindow.setMouseCursorVisible(true); requestStackPush(States::Game_Over);
        
    }
    
    return true;
    
}

bool GameState::handleEvent(const sf::Event &event) {
    
    CommandQueue &commands = mWorld.getCommandQueue(); mPlayer.handleEvent(event, commands);
    
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        
        mSurvivalTime += mWorld.playerSurvivalTime(); mWindow.setMouseCursorVisible(true); mIsPaused = true; requestStackPush(States::Pause);
        
    }
    
    mPlayer.handleRealTimeInput(commands); return true;
    
}