#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once


//klasa opisujaca klocek
class Block
{
public:
	bool empty;
	int posX; 
	int posY;
	sf::Text text;
	int nr;
	//Sprite obiekt obsługujący zdarzenia na grafice
	sf::Sprite singleBlock;
	std::vector <Block*> allBlocks = std::vector <Block*> (16);

public:
	Block() {}
	void fullfil(const sf::Texture *_textura, const sf::Text * _text);
	void search(int = 1);
	bool wigglewiggle(const int i, const int j, int & firstE);

	void posLR();
	void reduceLeft();
	void reduceRight();

	void changePosDown();
	void reduceDown();

	void changePosUp();
	void reduceUp();
	
	~Block();
};

