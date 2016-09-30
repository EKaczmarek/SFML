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
	Block(int _posX, int _posY, sf::Text _text, sf::Sprite _singleBlock);
	void randomShow(sf::RenderWindow & _okno, sf::Sprite & _obraz, sf::Texture _textura, int _flag);
	void show();
	~Block();
};

