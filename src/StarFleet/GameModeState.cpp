#include "StarFleet/GameModeState.hpp"
#include "StarFleet/Player.hpp"
#include "StarFleet/Button.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderWindow.hpp>

GameModeState::GameModeState(StateStack &stack, Context context): State(stack, context), mPlayer(*context.player), mDisplayText(), mGUIContainer(*context.window) {
    
    sf::Vector2f viewSize = context.window->getView().getSize();
    
    mBackgroundSprite.setTexture(context.textures->get(Textures::Background)); // mBackgroundSprite.setTexture(context.textures->get(Textures::GameModeScreen));
    
    mDisplayText.setFont(context.fonts->get(Fonts::Main)); mDisplayText.setCharacterSize(200u); mDisplayText.setString("GAME MODE");
    
    centerOrigin(mDisplayText); mDisplayText.setPosition(viewSize.x / 2.f, viewSize.y * 0.33f);
    
    auto clutchedButton = std::make_shared<GUI::Button>(*context.fonts);
    auto revvedButton = std::make_shared<GUI::Button>(*context.fonts);
    auto backButton = std::make_shared<GUI::Button>(*context.fonts);
    
    clutchedButton->setPosition(viewSize.x * 0.2f, viewSize.y * 0.7f);
    clutchedButton->setText("Clutched");
    clutchedButton->setCallback([this] () { mPlayer.setGameMode(Player::Classic); requestStackClear(); requestStackPush(States::Game_Load); });
    
    revvedButton->setPosition(viewSize.x * 0.5f, viewSize.y * 0.7f);
    revvedButton->setText("Revved");
    revvedButton->setCallback([this] () { mPlayer.setGameMode(Player::Accelerated); requestStackClear(); requestStackPush(States::Game_Load); });
    
    backButton->setPosition(viewSize.x * 0.8f, viewSize.y * 0.7f);
    backButton->setText("Back");
    backButton->setCallback([this] () { requestStackPop(); });
    
    mGUIContainer.pack(clutchedButton); mGUIContainer.pack(revvedButton); mGUIContainer.pack(backButton);
    
}

void GameModeState::draw() {
    
    sf::RenderWindow &window = *getContext().window; window.setView(window.getDefaultView());
    
    window.draw(mBackgroundSprite); window.draw(mDisplayText); window.draw(mGUIContainer);
    
}

bool GameModeState::update(sf::Time deltaTime) { return true; }

bool GameModeState::handleEvent(const sf::Event &event) { mGUIContainer.handleEvent(event); return false; }