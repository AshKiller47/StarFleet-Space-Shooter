#include "StarFleet/TitleLoadState.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderWindow.hpp>

TitleLoadState::TitleLoadState(StateStack &stack, Context context): State(stack, context), mLoadingTask(*context.textures, *context.fonts) {
    
    sf::Vector2f viewSize = context.window->getView().getSize();
    
    mLoadingText.setFont(context.fonts->get(Fonts::Main)); mLoadingText.setCharacterSize(75u); mLoadingText.setString("Starting Game...");
    
    centerOrigin(mLoadingText); mLoadingText.setPosition(viewSize.x / 2.f, viewSize.y * 0.35f);
    
    mProgressBarBackground.setOutlineThickness(2.5f);
    mProgressBarBackground.setOutlineColor(sf::Color::White);
    mProgressBarBackground.setFillColor(sf::Color(0, 0, 0, 0));
    mProgressBarBackground.setSize(sf::Vector2f((viewSize.x / 2.f) + 10.f, 30.f));
    mProgressBarBackground.setPosition((viewSize.x * 0.25f) - 5.f, (viewSize.y * 0.75f) - 5.f);
    
    mProgressBar.setSize(sf::Vector2f(0.f, 20.f));
    mProgressBar.setFillColor(sf::Color(100, 100, 100));
    mProgressBar.setPosition(viewSize.x * 0.25f, viewSize.y * 0.75f);
    
    setCompletion(0.f); mLoadingTask.execute();
    
}

void TitleLoadState::setCompletion(float percent) {
    
    if(percent == 1.f) mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * percent - 10.f, mProgressBar.getSize().y));
    
    else mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * percent, mProgressBar.getSize().y));
    
}

void TitleLoadState::draw() {
    
    sf::RenderWindow &window = *getContext().window; window.setView(window.getDefaultView());
    
    window.draw(mLoadingText); window.draw(mProgressBarBackground); window.draw(mProgressBar);
    
}

bool TitleLoadState::update(sf::Time deltaTime) {
    
    if(mLoadingTask.isFinished()) { requestStackPop(); requestStackPush(States::Title); }
    
    else setCompletion(mLoadingTask.getCompletion()); return true;
    
}

bool TitleLoadState::handleEvent(const sf::Event &event) { return true; }