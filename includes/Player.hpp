#pragma once
#include <sstream>
#include <iostream>
#include "Card.hpp"
#include "ACharacter.hpp"

enum class TurnState {
    WaitingForInput,
    CardSelected,
    TurnEnded
};

class Player : public ACharacter {
private:
    TurnState turnState;
public:
    Player(const std::string& name);
    ~Player();

    // Implémentation des méthodes virtuelles pures de ACharacter
    void performSpecialAbility() override;

    //GUI turn method
    void startTurn();
    void processCardSelection(int cardIndex, ACharacter& opponent);
    void endTurn();
    bool isTurnOver();

    //turn method
    void playTurn(ACharacter& opponent) override;

};

