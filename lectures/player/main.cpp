#include <iostream>
#include "player.hpp"
#include "hero.hpp"

void anonymousPrint(Player p) {
    p.setName("Анонимен");
    p.print();
}

void testPlayer() {
    Player p1("Гандалф Сивия", 45);
    Player p2;
    p2 = p1;
    p1.print();
    p2.setName("Гандалф Белия");
    p1.print();
    p2.print();
    anonymousPrint(p2);
    p2.print();
    Player("Соник таралежът", 100).print();
    // !!! delete p1.getName();
    // !!! p1.~Player();
}

void testHero() {
    Hero h1;
    Hero h2("Гандалф Сивия", 45, 10);
    std::cout << h1;
    std::cout << h2;
}

int main() {
    // testPlayer();
    testHero();
    return 0;
}