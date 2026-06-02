#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <iostream>

struct Player {
public:
    Player(std::string name): name_(name) {};

    void drawCard(int card){
        cards_.push_back(card);
        #ifdef DEBUG
            std::cout << name() << " drew a card. They now have " << std::to_string(handSize()) << " cards." << "\n";
        #endif
    }

    int discardCards(){
        int numDiscardedCards = 0;
        std::cout << name() << "'s turn to discard." << "\n";
        // Sort cards in decendinbefore discarding
        std::sort(cards_.begin(), cards_.end(), [](int a, int b){
            return a > b;
       });
       
       while (!cards_.empty() && cards_.back() < 7){
            #ifdef DEBUG
                std::cout << name() << " discarded " << std::to_string(cards_.back()) << "\n";
            #endif
            std::cout << name() << " discarded a card. They now have " << std::to_string(handSize()) << " cards." << "\n";
            cards_.pop_back();
            numDiscardedCards++;
       }
       return numDiscardedCards;
    }

    void clearHand(){
        #ifdef DEBUG
            std::cout << name() << "emptied their hands" << "\n";
        #endif
        cards_.clear();
    }

    std::string name() const {
        return name_;
    }

    int handSize(){
        return cards_.size();
    }

    int handValue(){
        int handValue = 0;
        for ( int card : cards_ ){
            handValue += card;
        }
        return handValue;
    }

private:
    std::string name_;
    std::vector<int> cards_{};
};

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