#pragma once

#ifndef STARFLEET_UTILITY_HPP
#define STARFLEET_UTILITY_HPP

#include <SFML/System/Vector2.hpp>

namespace sf { class Sprite; class RectangleShape; class Text; }

void centerOrigin(sf::Sprite&);
void centerOrigin(sf::RectangleShape&);
void centerOrigin(sf::Text&);

float toDegree(float);
float toRadian(float);

int randomInt(int);

#endif