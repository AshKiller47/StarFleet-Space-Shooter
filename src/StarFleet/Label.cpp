#include "StarFleet/Label.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace GUI {
    
    Label::Label(const std::string &text, const FontHolder &fonts): mText(text, fonts.get(Fonts::Main), 65u) { centerOrigin(mText); }
    
    void Label::setText(const std::string &text) { mText.setString(text); centerOrigin(mText); }
    
    bool Label::isSelectable() const { return false; }
    
    void Label::handleEvent(const sf::Event &event) {}
    
    sf::FloatRect Label::getBounds() const { return mText.getGlobalBounds(); }
    
    void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const { states.transform *= getTransform(); target.draw(mText, states); }
    
}