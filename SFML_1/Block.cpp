#include "Header.h"

void Block::fullfil(sf::Texture &_textura) {
	int i = 0;
	for (int a = 0; a < 400; (a += 100)) {
		for (int b = 0; b < 400; (b += 100)) {
			this->allBlocks[i] = new Block;
			this->allBlocks[i]->posX = b;
			this->allBlocks[i]->posY = a;
			this->allBlocks[i]->singleBlock.setTexture(_textura);
			this->allBlocks[i]->empty = true;
			i++;
		}
	}
}
void Block::search(int & state) {
	//rand positions from sixteen positions
	if (state == 0) {
		int first = 3;//rand() % 16 + 0;
		this->allBlocks[first]->empty = false;
		state = 1;
	}
	else{
		int next = 2;// rand() % 15 + 0;
		while (this->allBlocks[next]->empty == false) {
			next = rand() % 15 + 0;
		}
		this->allBlocks[next]->empty = false;
	}
}
void Block::changePosLeft() {
	//for (int i = 0; i < 4; i++) { //TODO od lewej
	if (this->allBlocks[0]->empty == true) {

	}
	else {

	}
}
Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
