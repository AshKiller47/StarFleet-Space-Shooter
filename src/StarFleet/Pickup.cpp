#include "StarFleet/Pickup.hpp"
#include "StarFleet/DataTables.hpp"
#include "StarFleet/Utility.hpp"
#include "ResourceHolder.cpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace { std::vector<PickupData> Table = initializePickupData(); }

Pickup::Pickup(Pickup::Type type, const TextureHolder &textures): Entity(1), mType(type), mSprite(textures.get(Table[type].texture)) {
    
    setScale(sf::Vector2f(0.8f, 0.8f)); centerOrigin(mSprite);
    
}

unsigned int Pickup::getType() const { return mType; }

void Pickup::apply(Spacecraft &player) const { Table[mType].action(player); }

unsigned int Pickup::getCategory() const { return Category::Pickup; }

sf::FloatRect Pickup::getBoundingRect() const { return getWorldTransform().transformRect(mSprite.getGlobalBounds()); }

void Pickup::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(mSprite, states); }