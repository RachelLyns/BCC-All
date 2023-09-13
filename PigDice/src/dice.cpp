/**
 * @file dice.cpp
 * @brief Implementation of the Dice class for simulating a die in the Pig Dice game.
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "dice.h"

/**
 * @brief Dice class constructor.
 * Creates a Dice object.
 */

Dice::Dice()
{
    srand(static_cast<unsigned int>(time(nullptr)));
}

/**
 * @brief Simulates the dice roll and returns a random number between 1 and 6.
 * @return The result of the dice roll.
 */
int Dice::roll()
{
    return rand() % 6 + 1;
}

/**
 * @brief Choose between 1 and 2 to select the player who will start
 * @return The result of the dice roll.
 */

int Dice::roll_p()
{
    return rand() % 2 + 1;
}