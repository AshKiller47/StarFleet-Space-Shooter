#include "StarFleet/GameLoadState.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderWindow.hpp>

GameLoadState::GameLoadState(StateStack &stack, Context context): State(stack, context), mLoadingTask(*context.textures, *context.fonts) {
    
    sf::Vector2f viewSize = context.window->getView().getSize(); sf::Font &font = context.fonts->get(Fonts::Main);
    
    mLoadingText.setFont(font); mLoadingText.setCharacterSize(75u); mLoadingText.setString("Loading Resources...");
    
    mResourceText.setFont(font); mResourceText.setCharacterSize(25u);
    
    centerOrigin(mLoadingText); mLoadingText.setPosition(viewSize.x / 2.f, viewSize.y * 0.35f);
    
    mResourceText.setPosition(viewSize.x / 2.f, viewSize.y * 0.65f);
    
    mProgressBarBackground.setOutlineThickness(2.5f);
    mProgressBarBackground.setOutlineColor(sf::Color::White);
    mProgressBarBackground.setFillColor(sf::Color(0, 0, 0, 0));
    mProgressBarBackground.setSize(sf::Vector2f((viewSize.x / 2.f) + 10.f, 30.f));
    mProgressBarBackground.setPosition((viewSize.x * 0.25f) - 5.f, (viewSize.y * 0.75f) - 5.f);
    
    mProgressBar.setSize(sf::Vector2f(0.f, 20.f));
    mProgressBar.setFillColor(sf::Color(100, 100, 100));
    mProgressBar.setPosition(viewSize.x * 0.25f, viewSize.y * 0.75f);
    
    setCompletion(std::make_pair(0.f, "")); mLoadingTask.execute();
    
}

void GameLoadState::setCompletion(std::pair<float, std::string> progress) {
    
    if(progress.first == 1.f) { mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * progress.first - 10.f, mProgressBar.getSize().y)); mResourceText.setString(progress.second); }
    
    else { mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * progress.first, mProgressBar.getSize().y)); mResourceText.setString(progress.second); }
    
}

void GameLoadState::draw() {
    
    sf::RenderWindow &window = *getContext().window; window.setView(window.getDefaultView()); centerOrigin(mResourceText);
    
    window.draw(mLoadingText); window.draw(mResourceText); window.draw(mProgressBarBackground); window.draw(mProgressBar);
    
}

bool GameLoadState::update(sf::Time deltaTime) {
    
    if(mLoadingTask.isFinished()) { requestStackPop(); requestStackPush(States::Game); }
    
    else setCompletion(mLoadingTask.getCompletion()); return true;
    
}

bool GameLoadState::handleEvent(const sf::Event &event) { return true; }