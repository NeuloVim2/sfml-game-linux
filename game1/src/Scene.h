#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <unordered_map>
#include <cstdint>
#include <iostream>

#include "typedefs.h"
#include "Components.hpp"
#include "EntityManager.h"


class Scene {
public:
	enum Type {
		main_menu,
		level_one,
	};

private:
	Type m_sceneType{};
	std::shared_ptr<sf::RenderWindow> m_window{};
	std::shared_ptr<EntityManager> m_entities{};

	bool m_paused{ false };
	bool m_running { false };

	void sMovement();
	void sUserInput();
	void sEnemySpawner();
	void sCollision();
	void sRender();

public:
	Scene(Type sceneType, std::shared_ptr<sf::RenderWindow> window = nullptr, std::shared_ptr<EntityManager> eM = nullptr)
		: m_sceneType{ sceneType }
		, m_window { window }
		, m_entities { eM}
	{
		std::cout << "Scene constructor is called" << std::endl;

		std::cout << "window address " << window.get() << std::endl;
		std::cout << "m_window address " << m_window.get() << std::endl;
	};

	Scene() = default;
	~Scene() 
	{
		std::cout << "Scene destructor is called" << std::endl;
	};

	void setUp();

	void run();

};

#endif
