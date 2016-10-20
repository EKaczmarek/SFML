#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class Game {
public:
	sf::RenderWindow okno;
	sf::Texture textura;

	sf::Texture end;
	sf::Sprite picEnd;

	sf::Font font;
	sf::Text text;
	Block* one;

	Game() {}
	void runGame();

	void Window();
	void Font();
	void object();

	void draw();
	bool endGame();

	~Game();
};