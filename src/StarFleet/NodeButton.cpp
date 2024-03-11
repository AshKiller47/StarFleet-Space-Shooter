#include "StarFleet/NodeButton.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

NodeButton::NodeButton(const sf::Vector2f &buttonSize, const sf::Font &font, const std::string &text): mButton(buttonSize), mButtonText(text, font) {}

void NodeButton::setButtonOrigin(const sf::Vector2f &origin) { mButton.setOrigin(origin); }

void NodeButton::setButtonColor(const sf::Color &rectColor, const sf::Color &textColor) { mButton.setFillColor(rectColor); mButtonText.setFillColor(textColor); }

void NodeButton::setButtonPosition(const sf::Vector2f &rectPosition, const sf::Vector2f &textPosition) { mButton.setPosition(rectPosition); mButtonText.setPosition(textPosition); }

sf::FloatRect NodeButton::getButtonBounds() const { return mButton.getGlobalBounds(); }

void NodeButton::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(mButton, states); target.draw(mButtonText, states); }