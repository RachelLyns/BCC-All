#ifndef _PIG_DICE_GAME_H_
#define _PIG_DICE_GAME_H_

/**
 * @file pigdice_game.h
 * @brief Declaration of the GameController class for the Pig Dice game.
 */

#include <string>
#include <iostream>
#include "bot.h"
#include <vector>

/**
 * @class GameController
 * @brief Class that manages the Pig Dice game.
 *
 * The GameController class is responsible for managing all aspects of the Pig Dice game.
 * This includes initialize, render, update, process_events, game_over...
 */

class GameController
{
    std::vector<std::string> playerHistory; ///< History of player actions.
    std::vector<std::string> botHistory;    ///< History of bot actions.

public:
    // Game variables
    std::string turn;        ///< The current player
    std::string dice;        ///< object dice.
    std::string input;       ///< The player's input.
    std::string Status_Game; ///< The current state of the game.
    int Dice_Ac;             ///< The amount of dice rolled.
    int Num_Dice;            ///< The value of the dice.
    int Turn_Score;          ///< The score for the current turn.
    int Score_You;           ///< The score of the player.
    int ControlPass;         ///< Game flow control.
    int Round;               ///< The number of rounds played.
    bool ControlError;       ///< Indicates whether an error occurred.

    void initialize(void);
    void render(void);
    void update(void);
    int random(int min, int max);
    void score_view(int Score_You, int Score_Bot);
    void display_welcome_screen(void);
    void player_menu(std::string input, bool ControlError);
    void log(void);
    void process_events(void);
    bool game_over(void) const;
};

#endif