#include <vector>
#include <SFML/Graphics.hpp>

#pragma once
//klasa opisujaca klocek
class Block
{
	int posX;
	int posY;
	sf::Text text;
	sf::Sprite singleBlock;
public:
	Block() {}
	void randomShow(sf::RenderWindow & _okno, sf::Sprite & _obraz, sf::Texture _textura);
	~Block();
};

