#ifndef _BOT_H_
#define _BOT_H_

/**
 * @file bot.h
 * @brief Declaration of the Bot class for the Pig Dice game.
 */

#include <string>
#include <iostream>

/**
 * @class Bot
 * @brief Represents the bot player in the Pig Dice game.
 */

class Bot
{
public:
    int Score_Bot; ///< The score of the bot player.

    /**
     * @brief Simulates the bot's decision.
     * @param Score_Bot The current score of the bot.
     * @param Score_You The current score of the human player.
     * @return A decision made by the bot as a string.
     */

    std::string bot_brain(int Score_Bot, int Score_You);
};

#endif