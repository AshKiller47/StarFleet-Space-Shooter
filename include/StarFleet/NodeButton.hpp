#pragma once

#ifndef STARFLEET_NODEBUTTON_HPP
#define STARFLEET_NODEBUTTON_HPP

#include "SceneNode.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class NodeButton: public SceneNode {
    
    public:
        
        explicit NodeButton(const sf::Vector2f&, const sf::Font&, const std::string&);
        
        void setButtonOrigin(const sf::Vector2f&);
        void setButtonColor(const sf::Color&, const sf::Color&);
        void setButtonPosition(const sf::Vector2f&, const sf::Vector2f&);
        
        sf::FloatRect getButtonBounds() const;
        
    private:
        
        virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
        
    private:
        
        sf::RectangleShape mButton;
        sf::Text mButtonText;
        
};

#endif