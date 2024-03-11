#include "StarFleet/PauseState.hpp"
#include "StarFleet/Button.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderWindow.hpp>

PauseState::PauseState(StateStack &stack, Context context): State(stack, context), mPausedText(), mGUIContainer(*context.window) {
    
    sf::Vector2f viewSize = context.window->getView().getSize();
    
    mBackgroundShape.setFillColor(sf::Color(0, 0, 0, 150)); mBackgroundShape.setSize(viewSize);
    
    mPausedText.setFont(context.fonts->get(Fonts::Main)); mPausedText.setString("GAME PAUSED");
    
    mPausedText.setCharacterSize(130u); centerOrigin(mPausedText); mPausedText.setPosition(viewSize.x / 2.f, viewSize.y * 0.3f);
    
    auto resumeButton = std::make_shared<GUI::Button>(*context.fonts);
    auto settingsButton = std::make_shared<GUI::Button>(*context.fonts);
    auto menuButton = std::make_shared<GUI::Button>(*context.fonts);
    auto exitButton = std::make_shared<GUI::Button>(*context.fonts);
    
    resumeButton->setPosition(viewSize.x * 0.13f, viewSize.y * 0.7f);
    resumeButton->setText("Resume");
    resumeButton->setCallback([this] () { requestStackPop(); });
    
    settingsButton->setPosition(viewSize.x * (0.13f + 0.74f / 3), viewSize.y * 0.7f);
    settingsButton->setText("Settings");
    settingsButton->setCallback([this] () { requestStackPush(States::Settings); });
    
    menuButton->setPosition(viewSize.x * (0.13f + 2 * 0.74f / 3), viewSize.y * 0.7f);
    menuButton->setText("Main Menu");
    menuButton->setCallback([this] () { requestStackClear(); requestStackPush(States::Menu); });
    
    exitButton->setPosition(viewSize.x * 0.87f, viewSize.y * 0.7f);
    exitButton->setText("Exit");
    exitButton->setCallback([this] () { requestStackClear(); });
    
    mGUIContainer.pack(resumeButton); mGUIContainer.pack(settingsButton); mGUIContainer.pack(menuButton); mGUIContainer.pack(exitButton);
    
}

void PauseState::draw() {
    
    sf::RenderWindow &window = *getContext().window; window.setView(window.getDefaultView());
    
    window.draw(mBackgroundShape); window.draw(mPausedText); window.draw(mGUIContainer);
    
}

bool PauseState::update(sf::Time deltaTime) { return false; }

bool PauseState::handleEvent(const sf::Event &event) {
    
    mGUIContainer.handleEvent(event);
    
    if(event.type == sf::Event::KeyPressed) {
        
        if(event.key.code == sf::Keyboard::Escape) requestStackPop(); else if(event.key.code == sf::Keyboard::BackSpace) { requestStackClear(); requestStackPush(States::Menu); }
        
    }
    
    return false;
    
}