#include "StarFleet/SettingsState.hpp"
#include "StarFleet/StringHelpers.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderWindow.hpp>

SettingsState::SettingsState(StateStack &stack, Context context): State(stack, context), mDisplayText(), mGUIContainer(*context.window), selectedByKey(false) {
    
    sf::Vector2f viewSize = context.window->getView().getSize(); std::string offset = "       ";
    
    mBackgroundSprite.setTexture(context.textures->get(Textures::Background)); // mBackgroundSprite.setTexture(context.textures->get(Textures::SettingsScreen));
    
    mDisplayText.setFont(context.fonts->get(Fonts::Main)); mDisplayText.setCharacterSize(120u); mDisplayText.setString("SETTINGS");
    
    centerOrigin(mDisplayText); mDisplayText.setPosition(viewSize.x * 0.8f, viewSize.y * 0.37f);
    
    addButtonLabel(Player::DextroRotation, context, viewSize, "Dextro Rotation", 200.f);
    addButtonLabel(Player::LevoRotation, context, viewSize, "Levo Rotation", 600.f);
    addButtonLabel(Player::RadialOut, context, viewSize, "Radial Out", 1000.f);
    addButtonLabel(Player::RadialIn, context, viewSize, "Radial In", 1400.f);
    addButtonLabel(Player::OrbitalAcceleration, context, viewSize, offset + "Orbital\nAcceleration", 1800.f);
    addButtonLabel(Player::AttachDetach, context, viewSize, "Attach Detach", 2200.f);
    addButtonLabel(Player::Fire, context, viewSize, "Fire", 2600.f);
    addButtonLabel(Player::LaunchMissile, context, viewSize, "Launch Missile", 3000.f);
    
    updateLabels();
    
    auto backButton = std::make_shared<GUI::Button>(*context.fonts);
    
    backButton->setPosition(viewSize.x * 0.8f, viewSize.y * 0.7f);
    backButton->setText("Back");
    backButton->setCallback(std::bind(&SettingsState::requestStackPop, this));
    
    mGUIContainer.pack(backButton); mBackButton = backButton.get(); mSelectedOption = mGUIContainer.selectedOption(); mBackOption = mGUIContainer.finalOption();
    
}

void SettingsState::draw() {
    
    sf::RenderWindow &window = *getContext().window; window.setView(window.getDefaultView());
    
    window.draw(mBackgroundSprite); window.draw(mDisplayText); window.draw(mGUIContainer);
    
}

bool SettingsState::update(sf::Time deltaTime) { return true; }

bool SettingsState::handleEvent(const sf::Event &event) {
    
    sf::Vector2f viewSize = (*getContext().window).getView().getSize(); sf::Vector2i mousePosition = sf::Mouse::getPosition(*getContext().window);
    
    if(!mGUIContainer.hasActivation() && event.type == sf::Event::MouseWheelScrolled && mousePosition.x < viewSize.x * 0.65f) {
        
        float offset; bool flag = false;
        
        for(std::size_t i = 0; i < Player::ActionCount; i++) { mBindingButtons[i]->move(0.f, event.mouseWheelScroll.delta * 50.f); mBindingLabels[i]->move(0.f, event.mouseWheelScroll.delta * 50.f); }
        
        if(event.mouseWheelScroll.delta > 0 && mBindingButtons[0]->getPosition().y > 200.f) { offset = 200.f - mBindingButtons[0]->getPosition().y; flag = true; }
        
        if(event.mouseWheelScroll.delta < 0 && mBindingButtons[Player::ActionCount - 1]->getPosition().y < viewSize.y - 200.f) {
            
            offset = viewSize.y - (200.f + mBindingButtons[Player::ActionCount - 1]->getPosition().y); flag = true;
            
        }
        
        if(flag) for(std::size_t i = 0; i < Player::ActionCount; i++) { mBindingButtons[i]->move(0.f, offset); mBindingLabels[i]->move(0.f, offset); }
        
        return false;
        
    }
    
    {
        float offset; bool flag = false;
        
        for(std::size_t i = 0; i < Player::ActionCount; i++) {
            
            if(mBindingButtons[i]->isActive() || (mBindingButtons[i]->isSelected() && selectedByKey)) {
                
                if(mBindingButtons[i]->getPosition().y < 200.f) { offset  = 200.f - mBindingButtons[i]->getPosition().y; selectedByKey = false; flag = true; }
                
                if(mBindingButtons[i]->getPosition().y > viewSize.y - 200.f) { offset = viewSize.y - (200.f + mBindingButtons[i]->getPosition().y); selectedByKey = false; flag = true; }
                
                break;
                
            }
            
        }
        
        if(flag) for(std::size_t i = 0; i < Player::ActionCount; i++) { mBindingButtons[i]->move(0.f, offset); mBindingLabels[i]->move(0.f, offset); }
        
    }
    
    bool isKeyBinding = false;
    
    for(std::size_t action = 0; action < Player::ActionCount; action++) {
        
        if(mBindingButtons[action]->isActive()) {
            
            isKeyBinding = true;
            
            if(event.type == sf::Event::KeyPressed) {
                
                if(event.key.code == sf::Keyboard::Escape) mBindingButtons[action]->deactivate();
                
                else { getContext().player->assignKey(static_cast<Player::Action>(action), event.key.code); mBindingButtons[action]->deactivate(); }
                
            }
            
            break;
            
        }
        
    }
    
    if(isKeyBinding) updateLabels();
    
    else if(event.type == sf::Event::KeyPressed) {
        
        if(event.key.code == sf::Keyboard::Up && !mBackButton->isSelected()) {
            
            mSelectedOption = mGUIContainer.previousOption(); if(mBackButton->isSelected()) mSelectedOption = mGUIContainer.nextOption(); selectedByKey = true; return false;
            
        }
        
        if(event.key.code == sf::Keyboard::Down && !mBackButton->isSelected()) {
            
            mSelectedOption = mGUIContainer.nextOption(); if(mBackButton->isSelected()) mSelectedOption = mGUIContainer.previousOption(); selectedByKey = true; return false;
            
        }
        
        if(event.key.code == sf::Keyboard::Left) { if(mBackButton->isSelected()) mGUIContainer.selectOption(mSelectedOption); selectedByKey = true; return false; }
        
        if(event.key.code == sf::Keyboard::Right) { if(!mBackButton->isSelected()) mGUIContainer.selectOption(mBackOption); return false; }
        
        if(event.key.code == sf::Keyboard::BackSpace) { requestStackPop(); return false; }
        
    }
    
    if(!isKeyBinding) mGUIContainer.handleEvent(event); if(!mBackButton->isSelected()) mSelectedOption = mGUIContainer.selectedOption();
    
    selectedByKey = false; return false;
    
}

void SettingsState::updateLabels() {
    
    Player &player = *getContext().player;
    
    for(std::size_t i = 0; i < Player::ActionCount; i++) { sf::Keyboard::Key key = player.getAssignedKey(static_cast<Player::Action>(i)); mBindingButtons[i]->setText(toString(key)); }
    
}

void SettingsState::addButtonLabel(Player::Action action, Context context, const sf::Vector2f &viewSize, const std::string &text, float y) {
    
    mBindingButtons[action] = std::make_shared<GUI::Button>(*context.fonts);
    
    mBindingButtons[action]->setPosition(viewSize.x * 0.5f, y); mBindingButtons[action]->setToggle(true);
    
    mBindingLabels[action] = std::make_shared<GUI::Label>(text, *context.fonts); mBindingLabels[action]->setPosition(viewSize.x * 0.2f, y);
    
    mGUIContainer.pack(mBindingButtons[action]); mGUIContainer.pack(mBindingLabels[action]);
    
}