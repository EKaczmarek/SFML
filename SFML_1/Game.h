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
	int state = 0;


	Game() {}
	void runGame();	
	void draw();
	bool endGame();

	~Game();
};