#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "Player.h"
#include "Deck.h"

class CardGame {
public:
    CardGame(int numPlayers, int maxScore);
    ~CardGame() = default;

    void start();
    void deal();
    void exchange();
    void initScores();
    void score();
    void reset();
    void printScores();
    bool gameOver();

private:
    int maxScore_;
    bool gameOver_ = false;
    int cardsInPlay_ = 0;
    Deck deck_;
    std::vector<Player> players_;
    std::unordered_map<std::string, int> scores_;

    void addPlayers(int numPlayers);
};