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
	//Sprite obiekt obsługujący zdarzenia na grafice
	sf::Sprite singleBlock;
	
public:
	std::vector <Block*>  allBlocks;
	Block() {}

	void search(sf::Text & _text);
	Block* randNew(Block * _object);
	bool check(Block * _four);
	std::string setNumber();

	~Block();
};

