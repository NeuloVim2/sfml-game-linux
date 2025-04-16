#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <unordered_map>
#include <cstdint>
#include <iostream>

#include "./typedefs.h"
#include "./components.hpp"
#include "./ComponentManager.h"


class Scene {
public:
	enum Type {
		main_menu,
		level_one,
	};

private:
	Type m_sceneType{};
	std::shared_ptr<sf::RenderWindow> m_window{};

	ComponentManager cm{};

public:
	Scene(Type sceneType, std::shared_ptr<sf::RenderWindow> window = nullptr)
		: m_sceneType{ sceneType }
		, m_window { window }
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
