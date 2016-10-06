#include "Block.h"
#include <string>
#include <iostream>

void Block::search() {
	srand(time(NULL));
	if (this->allBlocks.size() == 0) {
		Block* two = new Block();
		this->allBlocks.emplace_back(this->randNew(two));
		
		std::cout << "Rozmiar tablicy: " << this->allBlocks.size() << std::endl;

		Block* three = new Block();
		this->randNew(three);
			while (three->posX == two->posX &&
				three->posY == two->posY) {
				this->randNew(three);
			}
			this->allBlocks.emplace_back(three);
			
			std::cout << "Rozmiar tablicy: " << this->allBlocks.size() << std::endl;

	}

	else {
		Block* four = new Block();
		this->randNew(four);
		while (this->check(four) == false) {
			this->randNew(four);
		}
		this->allBlocks.emplace_back(four);
	}
}
Block* Block::randNew(Block * _object) {
		_object->posX = (rand() % 4 + 0) * 100;
		_object->posY = (rand() % 4 + 0) * 100;
	return _object;
}
bool Block::check(Block * _four) {
	int a = 0;
		for (auto i : allBlocks) {
			a++;
			if (i->posX != _four->posX &&
				i->posY != _four->posY)
				continue;
			else if (i->posX == _four->posX &&
				i->posY == _four->posY)
				return false;
			if (a == allBlocks.size())
				return true;
		}
}
void Block::setNumber(sf::Text & _text) {
	_text = this->text;
}
/*void Block::randomCreate(int & _flag) {
	srand(time(NULL));
	this->posX = (rand() % 4 + 0) * 100;
	this->posY = (rand() % 4 + 0) * 100;
					 //this->text = _text;

	while (this->checkRandom() == false) {
		this->posX = (rand() % 4 + 0) * 100;
		this->posY = (rand() % 4 + 0) * 100;	
	}
	if (allBlocks.size() < 16) {
		allBlocks.emplace_back(*this);
		_flag = 1;
	}
	else
		std::cout << "Koniec gry" << std::endl;
}*/

/*
void Block::showAll(sf::RenderWindow* _okno) {

	for (auto i = this->allBlocks.begin(); i < this->allBlocks.end(); i++) {
		i->singleBlock.setPosition(i->posX, i->posY);
		_okno->draw(this->singleBlock);
		_okno->display();
	}
}*/

Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
