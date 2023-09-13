/**
 * @file bot.cpp
 * @brief Implementation of the Bot class for the Pig Dice game.
 */

#include <iostream>
#include <string>
#include "bot.h"

/**
 * @brief Function that represents the "intelligence" of the bot in the game.
 * This function decides the bot's action based on its strategy.
 * @return The action chosen by the bot ("Roll" or "Hold").
 */

std::string Bot::bot_brain(int Score_Bot, int Score_You)
{
    int diferenca = Score_Bot - Score_You;
    static int rolls = 0;

    if (rolls >= 5) {
        rolls = 0; 
        return "Hold";
    }
    if (diferenca > 20) {
        if (rolls < 3) {
            rolls++;
            return "Roll";
        }
    }
    if (diferenca < 5) {
        if (rolls < 3) {
            rolls++;
            return "Roll";
        }
    }
    if (diferenca < 0) {
        if (rolls < 6) {
            rolls++;
            return "Roll";
        }
    }
    rolls = 0;
    return "Hold";
}