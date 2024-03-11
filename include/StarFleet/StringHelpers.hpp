#pragma once

#ifndef STARFLEET_STRINGHELPERS_HPP
#define STARFLEET_STRINGHELPERS_HPP

#include <SFML/Window/Keyboard.hpp>
#include <sstream>

template<typename T> std::string toString(const T&);

std::string toString(sf::Keyboard::Key);

#include "StringHelpers.inl"

#endif