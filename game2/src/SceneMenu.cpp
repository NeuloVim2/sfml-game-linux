#include "SceneMenu.h"

void SceneMenu::sDoAction(Action& action)
{
}

void SceneMenu::init()
{
	registerKeyboardAction(sf::Keyboard::Scan::W,		Action::UP);
	registerKeyboardAction(sf::Keyboard::Scan::S,		Action::DOWN);
	registerKeyboardAction(sf::Keyboard::Scan::Enter,	Action::PLAY);
	registerKeyboardAction(sf::Keyboard::Scan::Escape,	Action::QUIT);
}
