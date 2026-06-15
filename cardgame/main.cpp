#include "CardGame.h"

constexpr int NUM_PLAYERS = 5;
constexpr int MAX_SCORE = 10;

int main() {
    CardGame game(NUM_PLAYERS, MAX_SCORE);
    game.start();
    
    return 0;
}