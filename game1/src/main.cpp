#include "Game.h"
#include "typedefs.h"

int main() 
{
    std::string title{ "Test title" };
    Game game{ HEIGHT, WIDTH, title };
    game.init();
    game.run();

    return 0;
}