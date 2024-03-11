#pragma once

#ifndef STARFLEET_BUTTON_HPP
#define STARFLEET_BUTTON_HPP

#include "Component.hpp"
#include "ResourceIdentifiers.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <functional>

namespace GUI {
    
    class Button: public Component {
        
        public:
            
            typedef std::shared_ptr<Button> Ptr;
            typedef std::function<void()> Callback;
            
        public:
            
            Button(const FontHolder&);
            
            void setToggle(bool);
            void setCallback(Callback);
            void setText(const std::string&);
            
            virtual void select();
            virtual void deselect();
            virtual void activate();
            virtual void deactivate();
            
            virtual void handleEvent(const sf::Event&);
            
            virtual bool isSelectable() const;
            virtual sf::FloatRect getBounds() const;
            
        private:
            
            void draw(sf::RenderTarget&, sf::RenderStates) const;
            void alterButton(const sf::Color&, float rectSize = 0.f, int charSize = 0u);
            
        private:
            
            Callback mCallback;
            
            sf::RectangleShape mButtonBackground;
            sf::Text mText;
            
            bool mIsToggle;
            
    };
    
}

#endif