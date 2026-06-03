#include "CardGame.h"
#include <iostream>
#include <iomanip>

CardGame::CardGame(int numPlayers){
    addPlayers(numPlayers);
    initScores();
};

bool doOnce = false;

void CardGame::start(){
    std::cout << "Game Started" << "\n";

    // Loop phases until Player reaches winner

    while (!gameOver_){
        // Create new Deck
        createDeck();

        // Phase 1: Shuffle Deck
        shuffle();

        // Phase 2: Deal Cards
        deal();

        // Phase 3: Exhange Phase
        exchange();

        // Phase 4: Scoring Phase
        score();

        // Reset Hands
        resetHands();
    }
}

void CardGame::shuffle(){
    std::cout << "Shuffling Deck..." << "\n";
    std::shuffle(deck_.begin(), deck_.end(), std::mt19937(std::random_device{}()));
}

void CardGame::dealOne(Player& player){
    if ( player.handSize() < 5 ){
        player.drawCard(deck_.back());
        deck_.pop_back();
        cardsInPlay_++;
    }
}

void CardGame::dealUntilFull(Player& player){
    while ( player.handSize() < 5 ){
        player.drawCard(deck_.back());
        deck_.pop_back();
        cardsInPlay_++;
    }
}

void CardGame::deal(){
    std::cout << "Dealing cards... " << "\n";
    int expectedCards = 5 * players_.size();
    while ( cardsInPlay_ != expectedCards){
        for ( Player& player : players_){
            dealOne(player);
        }
    }
}

void CardGame::exchange(){
    std::cout << "Exchange Phase... " << "\n";

    for ( Player& player : players_ ){
        int cardsDiscarded = player.discardCards();
        cardsInPlay_ -= cardsDiscarded;
        dealUntilFull(player);
    }
}

void CardGame::initScores(){
    std::cout << "Initializing Scoreboard..." << "\n";
    for ( Player& player : players_ ){
        scores_[player.name()] = 0;
    }
}
void CardGame::score(){
    // Get all hand sizes
    int maxScore = 0;
    for ( Player& player : players_ ){
        maxScore = std::max(maxScore, player.getHandValue());
    }

    std::vector<Player> winners;
    for ( Player& player : players_ ){
        if ( player.getHandValue() == maxScore ){
            winners.push_back(player);
        }
    }

    if ( winners.size() == 1 ) {
        std::cout << winners[0].name() << " won this round!" << "\n";
        scores_[winners[0].name()]++;
    } else {
        std::cout << "Tie occured. No points were scored." << "\n";
    }

    for ( auto& [playerName, score] : scores_ ) {
        if ( score == 5 ) {
            std::cout << "We have a winner!" << "\n";
            std::cout << playerName << " is the champ!!!!" << "\n";
            printScores();
            gameOver_ = true;
        }
    }
}

void CardGame::printDeck(){
    std::cout << "Printing Deck..." << "\n";
    for (size_t i=0; i < deck_.size(); i++){
        std::cout << deck_[i] << " ";
        if ( i % 10 == 0 ){
            std::cout << "\n";
        }
    }
}

void CardGame::addPlayers(int numPlayers){
    std::cout << "Adding Players.." << "\n";
    for(int i=0; i < numPlayers; i++){
        players_.push_back(Player("Player " + std::to_string(i)));
        std::cout << players_[i].name() << " joined the game. \n";
    }
}

void CardGame::createDeck(){
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

void CardGame::resetHands(){
    for ( Player& player : players_ ){
        player.clearHand();
        cardsInPlay_ = 0;
    }
}

void CardGame::printScores(){
    std::cout << std::setw(8) << std::left << "Name" << " | " << "Score" << "\n";
    for(auto& [player, score] : scores_){
        std::cout << player << " : " << score << "\n";
    }
}