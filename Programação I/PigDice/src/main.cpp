#include "bot.h"
#include "pigdice_game.h"

int main(void)
{
    GameController game;
    // Set up simulation.
    game.initialize();
    // The Game Loop (Architecture)
    while (not game.game_over())
    {
        game.process_events();
        game.update();
        game.render();
    }
}
