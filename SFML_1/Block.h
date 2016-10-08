#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

//klasa opisujaca klocek
class Block
{
public:
	int posX;
	int posY;
	sf::Text text;
	//Sprite obiekt obs³uguj¹cy zdarzenia na grafice
	sf::Sprite singleBlock;
	
public:
	std::vector <Block>  allBlocks [16];
	Block() {}

	void search(sf::Text & _text);
	Block* randNew(Block * _object);
	bool check(Block * _four);
	std::string setNumber();
	int findMin(int _Y);
	bool Block::checkBeside(int _posX, int _posY);
	~Block();
};

