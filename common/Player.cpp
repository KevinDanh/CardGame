#include "Player.h"
#include <iostream>
#include <algorithm>

Player::Player(std::string name){
    name_ = name;
}

void Player::drawCard(int card){
    cards_.push_back(card);
    std::cout << name() << " drew a card. They now have " << std::to_string(handSize()) << " cards." << "\n";
}

int Player::discardCards(){
    int numDiscardedCards = 0;
    std::cout << name() << "'s turn to discard." << "\n";
    // Sort cards in decending order before discarding
    std::sort(cards_.begin(), cards_.end(), [](int a, int b){
        return a > b;
    });
    
    while (!cards_.empty() && cards_.back() < 7){
        #ifdef DEBUG
            std::cout << name() << " discarded " << std::to_string(cards_.back()) << "\n";
        #endif
        cards_.pop_back();
        std::cout << name() << " discarded a card. They now have " << std::to_string(handSize()) << " cards." << "\n";
        numDiscardedCards++;
    }
    return numDiscardedCards;
}

void Player::clearHand(){
    #ifdef DEBUG
        std::cout << name() << "emptied their hands" << "\n";
    #endif
    cards_.clear();
}

int Player::getHandValue(){
    int handValue = 0;
    for ( int card : cards_ ){
        handValue += card;
    }
    return handValue;
}