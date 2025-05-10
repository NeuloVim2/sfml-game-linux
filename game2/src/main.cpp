#include "GameEngine.h"
#include "typedefs.h"

int main() 
{
    GameEngine game{};

    game.run();
    game.update();
    // if quit action called - quit
    // game.quit();

    return 0;
}