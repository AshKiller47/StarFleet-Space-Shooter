#pragma once

#ifndef STARFLEET_LABEL_HPP
#define STARFLEET_LABEL_HPP

#include "Component.hpp"
#include "ResourceIdentifiers.hpp"
#include <SFML/Graphics/Text.hpp>
#include <memory>

namespace GUI {
    
    class Label: public Component {
        
        public:
            
            typedef std::shared_ptr<Label> Ptr;
            
        public:
            
            Label(const std::string&, const FontHolder&);
            
            void setText(const std::string&);
            
            virtual bool isSelectable() const;
            virtual void handleEvent(const sf::Event&);
            
        private:
            
            virtual sf::FloatRect getBounds() const;
            void draw(sf::RenderTarget&, sf::RenderStates) const;
            
        private:
            
            sf::Text mText;
            
    };
    
}

#endif