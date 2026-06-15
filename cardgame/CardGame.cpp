#include "CardGame.h"
#include <iostream>
#include <iomanip>

CardGame::CardGame(int numPlayers, int maxScore){
    maxScore_ = maxScore;
    addPlayers(numPlayers);
    initScores();
};

bool doOnce = false;

void CardGame::start(){
    std::cout << "Game Started" << "\n";

    // Loop phases until Player reaches winner

    while (!gameOver_){
        // Phase 1: Shuffle Deck
        deck_.shuffle();

        // Phase 2: Deal Cards
        deal();

        // Phase 3: Exhange Phase
        exchange();

        // Phase 4: Scoring Phase
        score();

        // Phase 5: Check for winner
        if (gameOver()){
            gameOver_ = true;
        } else {
            // Reset Hands
            reset();
        }
    }
}

void CardGame::deal(){
    std::cout << "Dealing cards... " << "\n";
    int expectedCards = 5 * players_.size();
    while ( cardsInPlay_ != expectedCards){
        for ( Player& player : players_){
            deck_.dealOne(player);
            cardsInPlay_++;
        }
    }
}

void CardGame::exchange(){
    std::cout << "Exchange Phase... " << "\n";

    for ( Player& player : players_ ){
        int cardsDiscarded = player.discardCards();
        cardsInPlay_ -= cardsDiscarded;
        deck_.dealUntilFull(player);
    }
}

void CardGame::initScores(){
    std::cout << "Initializing Scoreboard..." << "\n";
    for ( Player& player : players_ ){
        scores_[player.name()] = 0;
    }
}
void CardGame::score(){
    // Calculate highest hand score
    std::vector<Player> winners;
    int maxScore = 0;
    for ( Player& player : players_ ){
        if (player.getHandValue() > maxScore ){
            maxScore = player.getHandValue();
            winners.clear();
        } 
        if ( player.getHandValue() == maxScore ){
            winners.push_back(player);
        }
    }

    if ( winners.size() > 1 ) {
        std::cout << "Tie occured. No points were scored." << "\n";
    } else {
        std::cout << winners[0].name() << " won this round!" << "\n";
        scores_[winners[0].name()]++;
    }
}

bool CardGame::gameOver(){
     // Determine if player has won the game
    for ( auto& [playerName, score] : scores_ ) {
        if ( score == maxScore_ ) {
            std::cout << "We have a winner!" << "\n";
            std::cout << playerName << " is the champ!!!!" << "\n";
            printScores();
            return true;
        }
    }
    return false;
}

void CardGame::reset(){
    for ( Player& player : players_ ){
        player.clearHand();
    }
    cardsInPlay_ = 0;
    deck_ = Deck();
}

void CardGame::printScores(){
    std::cout << std::setw(8) << std::left << "Name" << " | " << "Score" << "\n";
    for(auto& [player, score] : scores_){
        std::cout << player << " : " << score << "\n";
    }
}

void CardGame::addPlayers(int numPlayers){
    std::cout << "Adding Players.." << "\n";
    for(int i=0; i < numPlayers; i++){
        players_.push_back(Player("Player " + std::to_string(i)));
        std::cout << players_[i].name() << " joined the game. \n";
    }
}