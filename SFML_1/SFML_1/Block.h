#include <SFML/Graphics.hpp>

#pragma once


//klasa opisujaca klocek
class Block {
public:

	int posX;
	int posY;
	bool empty;

	int numb;
	sf::Text nr;
	sf::Sprite bloc;

	//RUCHY
	//lewo
	//dó³
public:
	std::vector  <Block*> table
		= std::vector <Block*>(16);
	void pos(std::string s);

	void reduceLeft();
	void moveLeft();

	void reduceRight();
	void moveRight();

	void reduceUp();
	void moveUp();

	void reduceDown();
	void moveDown();

	void moveto(int finalPos, int initPos, int & _first);
	void reduce(int finalBlock, int initBlock);
	//void reduceDown();
	bool end();
	bool win();
};

