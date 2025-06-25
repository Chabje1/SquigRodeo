#pragma once

#include <random>
#include <set>
#include <vector>

#include "Bestiary.hpp"
#include "CharacterList.hpp"
#include "InitiativeEntry.hpp"
#include "Party.hpp"

namespace squigrodeo {
constexpr std::size_t MAX_MESSAGE_HISTORY_SIZE = 24;
constexpr std::size_t MAX_MESSAGE_SIZE = 200;

class CompanionApp {
   public:
    CompanionApp(bool gmFlag);

    void renderMainMode();

    void sendMessage();

    int rollDice();

   private:
    bool isGM;
    CharacterList characterList;
    Bestiary bestiary;
    Viewable* focusedViewable;
    std::set<InitiativeEntry> combatInitative;

    Party party;

    // Chat
    std::array<char[MAX_MESSAGE_SIZE], MAX_MESSAGE_HISTORY_SIZE> chatMessages;
    std::size_t chatMessageHead = 0;

    char tempMessageBuffer[MAX_MESSAGE_SIZE] = {0};

    // Dice Roller
    int diceNumber = 0;
    int difficultyNumber = 0;
    std::random_device randomDevice;
    std::mt19937 engine;
    std::uniform_int_distribution<int> d6Distribution;
};
}  // namespace squigrodeo