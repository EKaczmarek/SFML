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
	void fullfil(const sf::Texture *_textura, const sf::Text * _text);
	void search(int = 1);
	void moves();

	//void movesLR(std::string s);
	//void movesUD(std::string s);

	void posLR(std::string s);
	bool wigglewiggleLR(const int i, const int j, int & firstE, std::string side);
	void reduceLeft();
	void reduceRight();

	void posUD(std::string s);
	bool wigglewiggleUD(const int i, const int j, int & firstE, std::string side);
	void reduceDown();
	void reduceUp();
	
	~Block();
};

