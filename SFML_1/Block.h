#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
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
	//Sprite obiekt obs³uguj¹cy zdarzenia na grafice
	sf::Sprite singleBlock;
public:
	std::vector <Block*>  allBlocks;
	Block() {}
	void search();
	Block* randNew(Block * _object);
	//void Block::randomCreate(int & _flag);
	bool check(Block * _four);
	void setNumber(sf::Text & _text);
	//void Block::showAll(sf::RenderWindow* _okno);
	~Block();
};

