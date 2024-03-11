#include "StarFleet/TitleState.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderWindow.hpp>

TitleState::TitleState(StateStack &stack, Context context): State(stack, context), mDisplayText(), mInstructionText(), mTextEffectTime(sf::Time::Zero), mShowText(true) {
    
    mBackgroundSprite.setTexture(context.textures->get(Textures::Background));
    
    mDisplayText.setFont(context.fonts->get(Fonts::Main)); mDisplayText.setCharacterSize(225u); mDisplayText.setString("STARFLEET"); centerOrigin(mDisplayText);
    
    mInstructionText.setFont(context.fonts->get(Fonts::Main)); mInstructionText.setCharacterSize(30u); mInstructionText.setString("PRESS [Space] TO CONTINUE"); centerOrigin(mInstructionText);
    
    sf::Vector2f viewSize = context.window->getView().getSize(); mDisplayText.setPosition(viewSize.x / 2.f, viewSize.y * 0.4f); mInstructionText.setPosition(viewSize.x / 2.f, viewSize.y * 0.9f);
    
}

void TitleState::draw() { sf::RenderWindow &window = *getContext().window; window.draw(mBackgroundSprite); window.draw(mDisplayText); if(mShowText) window.draw(mInstructionText); }

bool TitleState::update(sf::Time deltaTime) {
    
    mTextEffectTime += deltaTime; if(mTextEffectTime >= sf::seconds(0.7f)) { mShowText = !mShowText; mTextEffectTime = sf::Time::Zero; }
    
    return true;
    
}

bool TitleState::handleEvent(const sf::Event &event) {
    
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) { requestStackPop(); requestStackPush(States::Menu); }
    
    return true;
    
}

/* TitleState::TitleState(StateStack &stack, Context context): State(stack, context), mText(), mTextEffectTime(sf::Time::Zero), mShowText(true) {
    
    mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
    
    mText.setFont(context.fonts->get(Fonts::Main)); mText.setCharacterSize(30u); mText.setString("PRESS [Space] TO CONTINUE"); centerOrigin(mText);
    
    sf::Vector2f viewSize = context.window->getView().getSize(); mText.setPosition(viewSize.x / 2.f, viewSize.y * 0.9f);
    
} */