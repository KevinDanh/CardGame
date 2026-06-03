#include "Deck.h"

#include <iostream>
#include <algorithm>
#include <random>

Deck::Deck(){
    createDeck();
}

void Deck::shuffle(){
    std::cout << "Shuffling Deck..." << "\n";
    std::shuffle(deck_.begin(), deck_.end(), std::mt19937(std::random_device{}()));
}

void Deck::dealOne(Player& player){
    if ( player.handSize() < 5 ){
        player.drawCard(deck_.back());
        deck_.pop_back();
    }
}

void Deck::dealUntilFull(Player& player){
    while ( player.handSize() < 5 ){
        player.drawCard(deck_.back());
        deck_.pop_back();
    }
}

void Deck::printDeck(){
    std::cout << "Printing Deck..." << "\n";
    for (size_t i=0; i < deck_.size(); i++){
        std::cout << deck_[i] << " ";
        if ( i % 10 == 0 ){
            std::cout << "\n";
        }
    }
}

void Deck::createDeck(){
    std::cout << "Creating Deck..." << "\n";
    deck_.reserve(52); // Standard 52-card deck
    constexpr int SUITS = 4; // Heart, Spades, Diamond, Clove
    constexpr int FACE_CARDS = 4; // 10, J, Q, K
    for(int i=0; i < SUITS; i++){
        
        // Add A-9
        for(int i=1; i <= 9; i++){
            deck_.push_back(i);
        }

        // Add 10, J, Q, K
        for(int i=0; i < FACE_CARDS; i++){
            deck_.push_back(10);
        }

        deck_.push_back(i);
    }
}