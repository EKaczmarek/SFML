#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class Game {
public:
	sf::RenderWindow okno;
	sf::Texture textura;
	sf::Font font;
	sf::Text text;
	Block * one;

	Game() {}
	void runGame();
	virtual void draw(Block * toShow);
	~Game();
};