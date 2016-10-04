#include <vector>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>


#pragma once


//klasa opisujaca klocek
class Block
{
public:
	int posX;
	int posY;
	sf::Text text;
	sf::Sprite singleBlock;
public:
	std::vector <Block>  allBlocks;
	Block() {}
	void Block::randomCreate();
	bool Block::checkRandom();
	void Block::showAll(sf::RenderWindow* _okno);
	~Block();
};

