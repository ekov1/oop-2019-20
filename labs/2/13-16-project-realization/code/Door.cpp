#include "Door.hpp"

Door::Door(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Solid(pos, size)
{}
