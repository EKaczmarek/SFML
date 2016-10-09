#include "Header.h"

void Block::fullfil(sf::Texture &_textura) {
	int i = 0;
	for (int a = 0; a < 400; (a += 100)) {
		for (int b = 0; b < 400; (b += 100)) {
			this->allBlocks[i] = new Block;
			this->allBlocks[i]->posX = a;
			this->allBlocks[i]->posY = b;
			this->allBlocks[i]->singleBlock.setTexture(_textura);
			this->allBlocks[i]->empty = true;
			i++;
		}
	}
}
void Block::search(int & state) {
	//rand positions from sixteen positions
	if (state == 0) {
		int first = rand() % 16 + 0;
		this->allBlocks[first]->empty = false;
		state = 1;
	}
	else{
		int next = rand() % 15 + 0;
		while (this->allBlocks[next]->empty == false) {
			next = rand() % 15 + 0;
		}
		this->allBlocks[next]->empty = false;
	}
}
void Block::changePosLeft() {
	for (int i = 0; i < 16; i++) {
		if (this->allBlocks[i]->empty == false) {
			this->findLeftest((ceil(i/4)));
		}
	}
}
int Block::findLeftest(int m) {
	int j = 0;
	int min = fmin(this->allBlocks[j*m]->posX, fmin(this->allBlocks[(j + 1)*m]->posX,
					fmin(this->allBlocks[(j + 2)*m]->posX, this->allBlocks[(j + 3)*m]->posX)));
	return min;
}
Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
