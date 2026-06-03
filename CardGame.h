#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <iostream>

#include "Player.h"

class CardGame {
public:
    CardGame(int numPlayers);
    ~CardGame() = default;

    void start();
    void shuffle();
    void dealOne(Player& player);
    void dealUntilFull(Player& player);
    void deal();
    void exchange();
    void initScores();
    void score();
    void printDeck();
    void resetHands();
    void printScores();

private:
    bool gameOver_ = false;
    std::vector<Player> players_;
    std::vector<int> deck_;
    int cardsInPlay_ = 0;
    std::unordered_map<std::string, int> scores_;

    void createDeck();
    void addPlayers(int numPlayers);
};