#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <unordered_map>
#include <cstdint>
#include <iostream>

#include "typedefs.h"
#include "Components.hpp"
#include "EntityManager.h"
#include "ConfigParser.h"


class Scene {
public:
	enum Type {
		main_menu,
		level_one,
	};

private:
	Type m_sceneType{};
	sf::RenderWindow& m_window;
	EntityManager& m_entities;
	ConfigParser& m_config;

	bool m_paused{ false };
	bool m_running { false };

	void spawnPlayer();
	void spawnEnemy();
	void spawnBullet();

	void sMovement();
	void sUserInput();
	void sEnemySpawner();
	void sCollision();
	void sRender();

public:
	Scene(Type sceneType, sf::RenderWindow& window, EntityManager& eM, ConfigParser& config)
		: m_sceneType{ sceneType }
		, m_window { window }
		, m_entities { eM }
		, m_config { config }
	{
		std::cout << "Scene constructor is called" << std::endl;

		std::cout << "window address " << &window << std::endl;
		std::cout << "m_window address " << &m_window << std::endl;
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
