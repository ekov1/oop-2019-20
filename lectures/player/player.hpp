#ifndef __PLAYER_HPP
#define __PLAYER_HPP

class Player {
    char* name;
    unsigned score;
public:

    Player(char const* n = "<неизвестен>", unsigned s = 0);

    char const* getName() const { return name; }
/*
    char* opponentName = opponent.getName();
    strcpy(opponentName, "PWNED!!@1!");
*/

    unsigned getScore() const { return score; }

    void setName(char const* n);

    void print() const;
};

#endif