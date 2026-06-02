#include "CardGame.h"

constexpr int NUM_PLAYERS = 5;

int main() {
    CardGame game(NUM_PLAYERS);
    game.start();
    
    return 0;
}