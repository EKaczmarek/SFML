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
	//Sprite obiekt obs³uguj¹cy zdarzenia na grafice
	sf::Sprite singleBlock;
	std::vector <Block*> allBlocks = std::vector <Block*> (16);
	
public:
	Block() {}
	void fullfil(sf::Texture &_textura, sf::Text *_text);
	void search(int & state);
	int searchNr();
	void changePosLeft();
	void changePosRight();
	//void changePosUp();
	//void changePosDown();
	//void reduceLeft();

	~Block();
};

