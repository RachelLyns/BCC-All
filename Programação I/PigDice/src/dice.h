#ifndef _DICEH
#define _DICEH

/**
 * @file dice.h
 * @brief Declaration of the Dice class to simulate a dice in the Pig Dice game.
 */

#include <iostream>

/**
 * @class Dice
 * @brief Represents a die in the Pig Dice game.
 *
 * The Dice class simulates a dice that can be rolled to generate random numbers.
 */

class Dice
{
public:
    Dice(); /// class constructor.

    int roll(); /// roll dice

    int roll_p(); /// select player
};

#endif