#include "StarFleet/GameOverState.hpp"
#include "StarFleet/Player.hpp"
#include "StarFleet/Button.hpp"
#include "StarFleet/Utility.hpp"
#include "StarFleet/StringHelpers.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cmath>

GameOverState::GameOverState(StateStack &stack, Context context): State(stack, context), mGameOverText(), mSurvivalText(), mSurvivalTime(context.player->getSurvivalTime()), mGUIContainer(*context.window) {
    
    sf::Vector2f windowSize(context.window->getSize()); sf::Font &font = context.fonts->get(Fonts::Main);
    
    mBackgroundShape.setSize(windowSize); mBackgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
    
    mGameOverText.setFont(font); mSurvivalText.setFont(font); int survivalTime = mSurvivalTime.asSeconds();
    
    mGameOverText.setString("Game Over"); mSurvivalText.setString("Survival Time : " + toString(survivalTime / 60) + " m " + toString(survivalTime % 60) + " s");
    
    mGameOverText.setCharacterSize(130u); mSurvivalText.setCharacterSize(100u); centerOrigin(mGameOverText); centerOrigin(mSurvivalText);
    
    mGameOverText.setPosition(windowSize.x / 2.f, windowSize.y * 0.25f); mSurvivalText.setPosition(windowSize.x / 2.f, windowSize.y * 0.45f);
    
    auto replayButton = std::make_shared<GUI::Button>(*context.fonts);
    auto menuButton = std::make_shared<GUI::Button>(*context.fonts);
    auto exitButton = std::make_shared<GUI::Button>(*context.fonts);
    
    replayButton->setPosition(windowSize.x * 0.2f, windowSize.y * 0.7f);
    replayButton->setText("Replay");
    replayButton->setCallback([this] () { requestStackClear(); requestStackPush(States::Game_Load); });
    
    menuButton->setPosition(windowSize.x * 0.5f, windowSize.y * 0.7f);
    menuButton->setText("Main Menu");
    menuButton->setCallback([this] () { requestStackClear(); requestStackPush(States::Menu); });
    
    exitButton->setPosition(windowSize.x * 0.8f, windowSize.y * 0.7f);
    exitButton->setText("Exit");
    exitButton->setCallback([this] () { requestStackClear(); });
    
    mGUIContainer.pack(replayButton); mGUIContainer.pack(menuButton); mGUIContainer.pack(exitButton);
    
}

void GameOverState::draw() {
    
    sf::RenderWindow &window = *getContext().window; window.setView(window.getDefaultView());
    
    window.draw(mBackgroundShape); window.draw(mGameOverText); window.draw(mSurvivalText); window.draw(mGUIContainer);
    
}

bool GameOverState::update(sf::Time deltaTime) { return false; }

bool GameOverState::handleEvent(const sf::Event &event) { mGUIContainer.handleEvent(event); return false; }