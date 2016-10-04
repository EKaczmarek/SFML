#include "Block.h"
#include <string>
#include <iostream>


void Block::randomCreate() {
	srand(time(NULL));
	this->posX = (rand() % 4 + 0) * 100;
	this->posY = (rand() % 4 + 0) * 100;
					 //this->text = _text;

	while (this->checkRandom() == false) {
		this->posX = (rand() % 4 + 0) * 100;
		this->posY = (rand() % 4 + 0) * 100;	
	}
	if (allBlocks.size() < 16)
		allBlocks.emplace_back(*this);
	else
		std::cout << "Koniec gry" << std::endl;
}
bool Block::checkRandom() {	
	int a = 0;
	if (this->allBlocks.empty() == false) {
		for (auto i : allBlocks) {
			a++;
			if (i.posX != this->posX &&
				i.posY != this->posY)
				continue;
			else if (i.posX == this->posX &&
				i.posY == this->posY)
				return false;
			if (a == allBlocks.size())
				return true;
		}
	}
	else
		return true;

}

void Block::showAll(sf::RenderWindow* _okno) {

	for (auto i = this->allBlocks.begin(); i < this->allBlocks.end(); i++) {
		i->singleBlock.setPosition(i->posX, i->posY);
		_okno->draw(this->singleBlock);
		_okno->display();
	}
}



Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
