#pragma once

#ifndef STARFLEET_SPRITENODE_HPP
#define STARFLEET_SPRITENODE_HPP

#include "SceneNode.hpp"
#include <SFML/Graphics/Sprite.hpp>

class SpriteNode: public SceneNode {
    
    public:
        
        explicit SpriteNode(const sf::Texture&);
        SpriteNode(const sf::Texture&, const sf::IntRect&);
        
    private:
        
        virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
        
    private:
        
        sf::Sprite mSprite;
        
};

#endif