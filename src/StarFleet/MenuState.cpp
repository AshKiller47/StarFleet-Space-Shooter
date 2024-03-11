#include "StarFleet/MenuState.hpp"
#include "StarFleet/Button.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderWindow.hpp>

MenuState::MenuState(StateStack &stack, Context context): State(stack, context), mDisplayText(), mGUIContainer(*context.window) {
    
    sf::Vector2f viewSize = context.window->getView().getSize();
    
    mBackgroundSprite.setTexture(context.textures->get(Textures::Background)); // mBackgroundSprite.setTexture(context.textures->get(Textures::MenuScreen));
    
    mDisplayText.setFont(context.fonts->get(Fonts::Main)); mDisplayText.setCharacterSize(200u); mDisplayText.setString("STARFLEET");
    
    centerOrigin(mDisplayText); mDisplayText.setPosition(viewSize.x / 2.f, viewSize.y * 0.33f);
    
    auto playButton = std::make_shared<GUI::Button>(*context.fonts);
    auto settingsButton = std::make_shared<GUI::Button>(*context.fonts);
    auto exitButton = std::make_shared<GUI::Button>(*context.fonts);
    
    playButton->setPosition(viewSize.x * 0.2f, viewSize.y * 0.7f);
    playButton->setText("Play");
    playButton->setCallback([this] () { requestStackPush(States::Game_Mode); });
    
    settingsButton->setPosition(viewSize.x * 0.5f, viewSize.y * 0.7f);
    settingsButton->setText("Settings");
    settingsButton->setCallback([this] () { requestStackPush(States::Settings); });
    
    exitButton->setPosition(viewSize.x * 0.8f, viewSize.y * 0.7f);
    exitButton->setText("Exit");
    exitButton->setCallback([this] () { requestStackPop(); });
    
    mGUIContainer.pack(playButton); mGUIContainer.pack(settingsButton); mGUIContainer.pack(exitButton);
    
}

void MenuState::draw() {
    
    sf::RenderWindow &window = *getContext().window; window.setView(window.getDefaultView());
    
    window.draw(mBackgroundSprite); window.draw(mDisplayText); window.draw(mGUIContainer);
    
}

bool MenuState::update(sf::Time deltaTime) { return true; }

bool MenuState::handleEvent(const sf::Event &event) { mGUIContainer.handleEvent(event); return false; }