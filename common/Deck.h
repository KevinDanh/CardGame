#include "Player.h"

#include <vector> 
#include <unordered_map>

class Deck {
public:
    Deck();
    void shuffle();
    void dealOne(Player& player);
    void dealUntilFull(Player& player);
    void printDeck();
    void createDeck();

private:
    std::vector<int> deck_;
};