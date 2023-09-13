/**
 * @file pigdice_game.cpp
 * @brief Implementation of the GameController class for the Pig Dice game.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "pigdice_game.h"
#include "dice.h"

Bot bot;
Dice dice_player;

/**
 * @brief Initializes the game state.
 */

void GameController::initialize(void)
{
    bot.Score_Bot = 0;
    ControlPass = 1;
    Score_You = 0;
    Turn_Score = 0;
    Round = 1;
    Dice_Ac = 0;
    Status_Game = "Starting";
    ControlError = false;
    input = "Roll";
}

/**
 * @brief Processes game events.
 */
void GameController::process_events(void)
{
    // handle different game states and user input
    if (Status_Game == "Welcome")
    {
        getline(std::cin, input);
        input = "Roll";
    }
    if (Status_Game == "Enter")
    {
        if (input == "Quit")
        {
            getline(std::cin, input);
            if ((input == "y") || (input == "Y") || (input == "yes") || (input == "Yes") || (input == "YES"))
            {
                Status_Game = "Quiting";
                input = "";
                ControlPass = 0;
            }
            else
            {
                Status_Game = "";
                input = "";
                ControlPass = 2;
            }
        }
        if ((input == "Hold") || (Num_Dice == 1))
        {
            getline(std::cin, input);
            input = "";
        }
    }

    if ((Status_Game == "Input") && (turn == "You"))
    {
        getline(std::cin, input);
        if ((input == "H") || (input == "h") || (input == "hold"))
        {
            input = "Hold";
        }
        else if ((input == "R") || (input == "r") || (input == "roll") || (input == ""))
        {
            input = "Roll";
        }
        else if ((input == "Q") || (input == "q") || (input == "quit"))
        {
            input = "Quit";
        }
    }
    else if ((Status_Game == "Input") && (turn == "Bot"))
    {
        input = bot.bot_brain(bot.Score_Bot, Score_You);
    }
}

/**
 * @brief Updates the game state based on player and bot actions
 */

void GameController::update(void)
{

    if (Status_Game == "Starting")
    {
        if (dice_player.roll_p() == 2)
        {
            turn = "You";
        }
        else
        {
            turn = "Bot";
        }
    }

    if (input != "Hold" && input != "Quit" && input != "Roll" && input != "" && Status_Game != "Quiting")
    {
        ControlError = true;
        ControlPass = 2;
    }

    if (Score_You >= 100)
    {
        Status_Game = "End_Game";
        ControlPass = 0;
        turn = "You";
    }
    else if (bot.Score_Bot >= 100)
    {
        Status_Game = "End_Game";
        ControlPass = 0;
        turn = "Bot";
    }

    if (ControlPass == 1)
    {
        Status_Game = "Welcome";
        ControlPass++;
    }
    else if (ControlPass == 2)
    {
        Status_Game = "Input";
        ControlPass++;
    }
    else if (ControlPass == 3)
    {
        Status_Game = "Comand";
        ControlPass++;
    }
    else if (ControlPass == 4)
    {
        if (input == "Roll")
        {
            Status_Game = "Rolling";
            ControlPass++;
        }
        else if (input == "Hold")
        {
            Status_Game = "Holding";
            ControlPass++;
        }
        else if (input == "Quit")
        {
            Status_Game = "Enter";
            ControlPass = -1;
        }
    }
    else if (ControlPass == 5)
    {
        Status_Game = "Score_Update";
        ControlPass++;
    }
    else if (ControlPass == 6)
    {
        Status_Game = "Enter";
        ControlPass++;
    }
    else if (ControlPass > 6)
    {
        Status_Game = "Transition";
        ControlPass = 2;
        ControlError = false;
        input = "";
        Round++;
    }

    if (Status_Game == "Rolling")
    {
        Num_Dice = dice_player.roll();
        if (Num_Dice == 1)
        {
            dice = "⚀";
            input = "Hold";
            ControlPass = 4;
        }
        else if (Num_Dice == 2)
        {
            dice = "⚁";
        }
        else if (Num_Dice == 3)
        {
            dice = "⚂";
        }
        else if (Num_Dice == 4)
        {
            dice = "⚃";
        }
        else if (Num_Dice == 5)
        {
            dice = "⚄";
        }
        else if (Num_Dice == 6)
        {
            dice = "⚅";
        }
        Dice_Ac++;
    }

    // Hold
    if (Status_Game == "Holding")
    {
        if ((Num_Dice == 1))
        {
            Turn_Score = 0;
            Num_Dice = 0;
        }
        log();

        if (turn == "You" && Status_Game == "Holding")
        {
            Score_You += Turn_Score;
            turn = "Bot";
            Turn_Score = 0;
            Num_Dice = 0;
        }
        else if (turn == "Bot" && Status_Game == "Holding")
        {
            bot.Score_Bot += Turn_Score;
            turn = "You";
            Turn_Score = 0;
            Num_Dice = 0;
        }
    }

    // Update Score
    if (Status_Game == "Score_Update")
    {
        if ((Num_Dice != 1) && (input != "Hold"))
        {
            Turn_Score += Num_Dice;
        }
    }

    if (Status_Game == "Quiting")
    {
        Turn_Score = 0;
        log();
    }
}

/**
 * @brief Records player and bot action information during gameplay
 */
void GameController::log(void)
{
    if (turn == "You")
    {
        playerHistory.push_back(std::to_string(Dice_Ac) + " dice rolls produced " + std::to_string(Turn_Score));
    }
    else if (turn == "Bot")
    {
        botHistory.push_back(std::to_string(Dice_Ac) + " dice rolls produced " + std::to_string(Turn_Score));
    }
    Dice_Ac = 0;
}

/**
 * @brief Renders the game interface based on the current state
 */

void GameController::render(void)
{
    if (Status_Game == "Welcome")
    {
        display_welcome_screen();
    }

    if (Status_Game == "Input")
    {
        if (turn == "You")
        {
            player_menu(input, ControlError);
        }
        else
        {
            std::cout << "-------------------------------------------------------" << std::endl;
            std::cout << ">>> The current player is: Machine" << std::endl;
        }
    }

    if (Status_Game == "Comand")
    {
        std::cout << ">>> Requested action: " << input << "\n";
    }

    if (Status_Game == "Rolling")
    {
        std::cout << "    Dice value is " << dice << " (" << Num_Dice << ")\n";
    }

    if (Status_Game == "Quiting")
    {
        if (turn == "You")
        {
            std::cout << "You decided to leave the game!\n";
        }
        else if (turn == "Bot")
        {
            std::cout << "The Bot gave up playing with you, he said it was impossible to play with you!\n";
        }
        score_view(Score_You, bot.Score_Bot);

        std::cout << "\n[[ LOG of ACTIONS during the game ]]\n\n";
        std::cout << "Decisions taken by player \"You\":\n";
        for (const std::string &action : playerHistory)
        {
            std::cout << action << std::endl;
        }

        std::cout << "\nDecisions taken by player \"Machine\":\n";
        for (const std::string &action : botHistory)
        {
            std::cout << action << std::endl;
        }
    }

    if (Status_Game == "Score_Update")
    {
        if (Num_Dice == 1)
        {
            std::cout << "    Ops, got a Pig, holding...\n";
        }
        std::cout << "    The turn total is: " << Turn_Score << "\n";
        if ((input == "Hold") || (Num_Dice == 1))
        {
            score_view(Score_You, bot.Score_Bot);
        }
    }

    if (Status_Game == "Enter")
    {
        if (input == "Quit")
        {
            std::cout << "Do you really want to quit? [y/n] > ";
        }
        if ((input == "Hold"))
        {
            std::cout << "\n>>> Press enter to continue... ";
        }
    }

    if (Status_Game == "End_Game")
    {
        score_view(Score_You, bot.Score_Bot);
        std::cout << "\n>>> THIS WINNER IS: \"" << turn << "\"\n";
        std::cout << "\n[[ LOG of ACTIONS during the game ]]\n\n";
        std::cout << "Decisions taken by player \"You\":\n";
        for (const std::string &action : playerHistory)
        {
            std::cout << action << std::endl;
        }

        std::cout << "\nDecisions taken by player \"Machine\":\n";
        for (const std::string &action : botHistory)
        {
            std::cout << action << std::endl;
        }

        std::cout << "\n---> [ Thanks for playing. See you next time! ] <---\n";
    }
}

/**
 * @brief Displays the welcome screen and game rules
 */

void GameController::display_welcome_screen(void)
{
    std::cout << "\n";
    std::cout << "                      ---> Welcome to the Pig Dice game (v 1.1) <---\n";
    std::cout << "                             -copyright DIMAp/UFRN 2022-\n\n";
    std::cout << "  The object of the jeopardy dice game Pig is to be the first player to reach 100 points.\n";
    std::cout << "  Each player's turn consists of repeatedly rolling a die. After each roll, the player is\n";
    std::cout << "  faced with two choices: roll again, or hold (decline to roll again).\n";
    std::cout << "        • If the player rolls a 1, the player scores nothing and it becomes the opponent's turn.\n";
    std::cout << "        • If the player rolls a number other than 1, the number is added to the player's turn\n";
    std::cout << "          total and the player's turn continues.\n";
    std::cout << "        • If the player holds, the turn total, the sum of the rolls during the turn, is added\n";
    std::cout << "          to the player's score, and it becomes the opponent's turn.\n";

    std::cout << ">>> The players of the game are: \"You\" & \"Machine\"\n";
    if (turn == "You")
    {
        std::cout << ">>> The player who will start the game is \"You\"\n";
    }
    else
    {
        std::cout << ">>> The player who will start the game is \"Machine\"\n";
    }
    std::cout << "    Press <Enter> to start the match.\n";
}

/**
 * @brief Displays the player menu and error messages.
 * @param input player input.
 * @param ControlError Indicates whether an error occurred.
 */

void GameController::player_menu(std::string input, bool ControlError)
{
    std::cout << "\n\n-------------------------------------------------------" << std::endl;
    std::cout << ">>> The current player is: You" << std::endl;
    std::cout << "\nCommands syntax:" << std::endl;
    std::cout << "  <Enter>       -> ROLL the dice." << std::endl;
    std::cout << "  'r' + <Enter> -> ROLL the dice." << std::endl;
    std::cout << "  'h' + <Enter> -> HOLD (add turn total and pass turn over)." << std::endl;
    std::cout << "  'q' + <Enter> -> quit the match (no winner)." << std::endl;
    if (ControlError)
    {
        std::cout << "\n\n'" << input << "' It's an invalid command, try again\n";
    }
    std::cout << "\nEnter command > ";
}

/**
 * @brief Displays the game score.
 * @param Score_You player score.
 * @param Score_Bot "Machine" player score.
 */

void GameController::score_view(int Score_You, int Score_Bot)
{
    std::cout << "┌───────────────────────┐\n";
    std::cout << "│      Score Board      │\n";
    std::cout << "├───────────┬───────────┤\n";
    std::cout << "│" << std::setw(11) << "You"
              << "│" << std::setw(11) << Score_You << "│\n";
    std::cout << "│" << std::setw(11) << "Machine"
              << "│" << std::setw(11) << Score_Bot << "│\n";
    std::cout << "└───────────┴───────────┘\n\n";
}

/**
 * @brief Verifica se o jogo terminou.
 * @return true if the game ends, false otherwise.
 */

bool GameController::game_over(void) const
{
    if ((Status_Game == "End_Game") || (Status_Game == "Quiting"))
    {
        return true;
    }
    else
    {
        return false;
    }
}