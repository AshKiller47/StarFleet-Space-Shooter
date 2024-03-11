#pragma once

#ifndef STARFLEET_TEXTNODE_HPP
#define STARFLEET_TEXTNODE_HPP

#include "SceneNode.hpp"
#include "ResourceIdentifiers.hpp"
#include <SFML/Graphics/Text.hpp>

class TextNode: public SceneNode {
    
    public:
        
        explicit TextNode(const FontHolder&, const std::string&);
        void setString(const std::string&);
        
    private:
        
        virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
        
    private:
        
        sf::Text mText;
        
};

#endif