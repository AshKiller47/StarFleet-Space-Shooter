#include "StarFleet/Utility.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <random>
#include <cmath>

#define PI 3.141592653589793238462643383f

namespace {
    
    std::default_random_engine createRandomEngine() { auto seed = static_cast<unsigned int>(std::time(nullptr)); return std::default_random_engine(seed); }
    
    auto RandomEngine = createRandomEngine();
    
}

void centerOrigin(sf::Sprite &sprite) {
    
    sf::FloatRect bounds = sprite.getLocalBounds();
    
    sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    
}

void centerOrigin(sf::RectangleShape &shape) {
    
    sf::FloatRect bounds = shape.getLocalBounds();
    
    shape.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    
}

void centerOrigin(sf::Text &text) {
    
    sf::FloatRect bounds = text.getLocalBounds();
    
    text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    
}

float toDegree(float radian) { return 180.f / PI * radian; }

float toRadian(float degree) { return PI / 180.f * degree; }

int randomInt(int exclusiveMax) { std::uniform_int_distribution<> distr(0, exclusiveMax - 1); return distr(RandomEngine); }