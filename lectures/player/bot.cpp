#include "bot.hpp"

Bot::Bot(char const* _name, unsigned _score,
        char const* _algo, double _threshold,
        unsigned _diff) :
        Player(_name, _score), AI(_algo, _threshold), difficulty(_diff) {}

void Bot::print(std::ostream& os) const {
    Player::print(os);
    os << " и е бот с трудност " << getDifficulty() << " с ";
    AI::print(os);
}