#include "Header.h"

//szukanie nowej pozycji i wk³adanie na liste
void Block::search(sf::Text* _text) {
	if (this->allBlocks.size() == 0) {
		Block* two = new Block();
		two->setNumber(_text);
		this->allBlocks.emplace_back(this->randNew(two));
		
		std::cout << "Rozmiar tablicy: " << this->allBlocks.size() << std::endl;

		Block* three = new Block();
		this->randNew(three);
			while (three->posX == two->posX &&
				three->posY == two->posY) {
				this->randNew(three);
			}
			three->setNumber(_text);
			this->allBlocks.emplace_back(three);
			
			std::cout << "Rozmiar tablicy: " << this->allBlocks.size() << std::endl;
	}
	else {
		Block* four = new Block();
		this->randNew(four);
		while (this->check(four) == false) {
			this->randNew(four);
		}
		four->setNumber(_text);
		this->allBlocks.emplace_back(four);
	}
}

//szukanie nowej pozycji z puli
Block* Block::randNew(Block * _object) {
		_object->posX = (rand() % 4 + 0) * 100; // od 0 w³¹cznie so 4 
		_object->posY = (rand() % 4 + 0) * 100;
	return _object;
}

//sprawdzenie czy nie ma w tablicy bloku o danej pozycji
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

//losowanie z puli numeru 2 lub 4
std::string Block::setNumber(sf::Text * _text) {
	std::string tab[2]{ "2","4" };
	int temp = rand() % 1 + 0;
	//this->text.setString(tab[temp]);
	return tab[temp];
} 

Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
