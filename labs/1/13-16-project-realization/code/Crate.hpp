#pragma once

#include "Solid.hpp"
#include "Game.hpp"
#include "PhysicsObj.hpp"
#include "Pushable.hpp"

/**
 * Class representing a box object that can be pushed around
 */
class Crate : public Solid, public PhysicsObj, public Pushable
{
/// Implements the polymorphic BigFour
public:
    Crate(const sf::Vector2f& pos, const sf::Vector2f& size = { Game::BLOCK_SIZE , Game::BLOCK_SIZE });
    Crate(const Crate& other) = default;
    Crate& operator=(const Crate& other) = default;
    virtual ~Crate() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new Crate(*this); }

    /**
     * Polymorphic method that runs every frame and applies PhysicsObj::update()
     * as well as moving the Crate with the current m_hspd and m_vspd
     */
    virtual void update() override;
};
