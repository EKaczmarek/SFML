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
	//Block(int _posX, int posY, sf::Text _text, sf::Sprite _singleBlock) :
		//posX(_posX), posY(posY), text(_text), singleBlock(_singleBlock) {}
	void randomShow(sf::RenderWindow & _okno, sf::Sprite & _obraz, sf::Texture _textura);
	~Block();
};

