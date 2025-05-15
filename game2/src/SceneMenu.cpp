#include "SceneMenu.h"

void SceneMenu::sDoAction(Action& action)
{
	if (action.phase() == Action::Phase::START)
		switch (action.name())
		{
			case Action::Name::UP:
				std::cout << "UP actoin started" << std::endl;
				break;
			case Action::Name::DOWN:
				std::cout << "DOWN actoin started" << std::endl;
				break;
			case Action::Name::QUIT:
				std::cout << "QUIT actoin started" << std::endl;
                m_gameEngine->window().close();
				break;
		};

	if (action.phase() == Action::Phase::END)
		switch (action.name())
		{
			case Action::Name::UP:
				std::cout << "UP actoin ended" << std::endl;
				break;
			case Action::Name::DOWN:
				std::cout << "DOWN actoin ended" << std::endl;
				break;
		};
}

}

void SceneMenu::init()
{
	registerKeyboardAction(sf::Keyboard::Scan::W,		Action::UP);
	registerKeyboardAction(sf::Keyboard::Scan::S,		Action::DOWN);
	registerKeyboardAction(sf::Keyboard::Scan::Enter,	Action::PLAY);
	registerKeyboardAction(sf::Keyboard::Scan::Escape,	Action::QUIT);
}
