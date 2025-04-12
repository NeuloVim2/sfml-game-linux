//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/System/Clock.hpp>
//#include <SFML/Window/Event.hpp>

//#include <imgui-SFML.h>
//#include <imgui.h>

#include "Game.h"

int main() 
{
    std::string title{ "Test title" };
    Game game{ 1280, 760, title };
    game.run();

    return 0;
}