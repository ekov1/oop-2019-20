#include <iostream>
#include <typeinfo>
#include "player.hpp"
#include "hero.hpp"
#include "superhero.hpp"

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
    Player p = h2;
    std::cout << p;
    Hero& h3 = h2;
    Player* pp = &h3;
    std::cout << (*pp);
    Player& rp = h1;
    std::cout << rp;
    rp = h2; // Player::operator=
    std::cout << rp;
    std::cout << h1;
    h1 = h2; // Hero::operator=
    std::cout << h1;

    Player p2("Катнис Евърдийн", 55);
    Hero h4 = (Hero const&)p2;
    std::cout << h4;
    // !!! pp = &p2;
    Hero* ph = (Hero*)pp;
    std::cout << *ph << std::endl;
}

void testSuperHero() {
    SuperHero sh("Супермен", 60, 5, "летене", 10);
    std::cout << sh;
    sh.usePower();
    std::cout << sh;
    sh.stopUsingPower();
    std::cout << sh;

    SuperHero shdefault;
    std::cout << shdefault;
    shdefault.usePower();
    std::cout << shdefault;
    shdefault.stopUsingPower();
    std::cout << shdefault;

    SuperHero sh2 = sh;
    std::cout << sh2;

    shdefault = sh;
    std::cout << shdefault;
}

Hero* battle(Hero& h1, Hero& h2, unsigned prize = 1) {
    std::cout << "Епична битка между:" << std::endl;
    std::cout << h1 << h2;
    std::cout << "FIGHT!" << std::endl;
    Hero* winner = nullptr;
    if (h1.getLevel() > h2.getLevel())
        winner = &h1;
    else if (h1.getLevel() < h2.getLevel())
        winner = &h2;
    if (winner != nullptr) {
        winner->addPoints(prize);
        std::cout << "Победител е: " << *winner;
    } else
        std::cout << "Няма победител!";
    return winner;
}

void testBattle() {
    Hero gandalf("Гандалф Сивия", 45, 10);
    SuperHero superman("Супермен", 60, 5, "летене", 10);
    Hero* winner = battle(gandalf, superman, 100);
    if (winner != nullptr)
        std::cout << "Слава за " << *winner;
    else
        std::cout << "Нищо, следващия път дано има победител" << std::endl;

    if (typeid(*winner) != typeid(Hero))
        std::cout << "Победителят е повече от герой!" << std::endl;
    else
        std::cout << "Победителят е обикновен герой." << std::endl;


    std::cout << "Супермен си слага наметалото!" << std::endl;
    superman.usePower();
    winner = battle(gandalf, superman, 200);
    if (winner != nullptr)
        std::cout << "Слава за " << *winner;
    else
        std::cout << "Нищо, следващия път дано има победител" << std::endl;
    int x = 3;
    // !!! battle(gandalf, x);
    Player katniss("Катнис Евърдийн", 55);
    std::cout << katniss;
    // !!! battle(gandalf, katniss);
    // !!! battle(gandalf, Player("име", 100));

    std::type_info const& ti = typeid(x);
    std::cout << ti.name() << std::endl;
    std::cout << typeid(1.3).name() << std::endl;
    std::cout << typeid(gandalf).name() << std::endl;
    std::cout << typeid(superman).name() << std::endl;
    std::cout << typeid(winner).name() << std::endl;
    std::cout << typeid(*winner).name() << std::endl;
    if (typeid(*winner) != typeid(Hero))
        std::cout << "Победителят е повече от герой!" << std::endl;
    else
        std::cout << "Победителят е обикновен герой." << std::endl;
}

void testDestructors() {
    for(unsigned i = 0; i < 1E2; i++) {
        const unsigned N = 10;
        // !!! Player* pp = new SuperHero[N];
        // !!! delete[] pp;
        // https://stackoverflow.com/q/6171814
        Player* pp = new SuperHero;
        delete pp;
    }
}

int main() {
    // testPlayer();
    // testHero();
    // testSuperHero();
    // testBattle();
    testDestructors();
    return 0;
}