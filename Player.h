#pragma once

#include <string>
#include <vector>

class Player {
public:
    Player(std::string name);

    void drawCard(int card);
    int discardCards();
    void clearHand();

    // Getters
    const std::string name(){ return name_; };
    int handSize(){ return static_cast<int>(cards_.size()); };
    int getHandValue();

private:
    std::string name_;
    std::vector<int> cards_{};
};