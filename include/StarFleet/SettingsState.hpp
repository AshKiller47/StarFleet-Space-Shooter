#pragma once

#ifndef STARFLEET_SETTINGSSTATE_HPP
#define STARFLEET_SETTINGSSTATE_HPP

#include "State.hpp"
#include "Label.hpp"
#include "Button.hpp"
#include "Player.hpp"
#include "Container.hpp"
#include <SFML/Graphics/Sprite.hpp>

class SettingsState: public State {
    
    public:
        
        SettingsState(StateStack&, Context);
        
        virtual void draw();
        virtual bool update(sf::Time);
        virtual bool handleEvent(const sf::Event&);
        
    private:
        
        void updateLabels();
        void addButtonLabel(Player::Action, Context, const sf::Vector2f&, const std::string&, float);
        
    private:
        
        sf::Sprite mBackgroundSprite;
        sf::Text mDisplayText;
        
        GUI::Container mGUIContainer;
        GUI::Button *mBackButton;
        
        int mSelectedOption, mBackOption; bool selectedByKey;
        
        std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabels;
        std::array<GUI::Button::Ptr, Player::ActionCount> mBindingButtons;
        
};

#endif