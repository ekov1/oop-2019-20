#ifndef __BOT_HPP
#define __BOT_HPP

#include "player.hpp"
#include "ai.hpp"

class Bot : public Player, public AI {
    unsigned difficulty;

public:
    Bot(char const* _name = "<неизвестен бот>", unsigned _score = 0,
        char const* _algo = "<неизвестен алгоритъм>", double _threshold = 1,
        unsigned _diff = 1);

    unsigned getDifficulty() const { return difficulty; }

    void print(std::ostream& os = std::cout) const;
};

#endif