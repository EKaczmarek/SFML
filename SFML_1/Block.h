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
	//Sprite obiekt obs³uguj¹cy zdarzenia na grafice
	sf::Sprite singleBlock;
	std::vector <Block*> allBlocks = std::vector <Block*> (16);
	
public:
	Block() {}
	void fullfil(sf::Texture &_textura);
	void search(int & state);
	void changePosLeft();
	int findLeftest(int m);
	~Block();
};

