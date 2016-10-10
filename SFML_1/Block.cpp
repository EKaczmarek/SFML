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
		int first = 3;// rand() % 16 + 0;
		this->allBlocks[first]->empty = false;
		state = 1;
	}
	else if(state == 1){
		int next = 1;// rand() % 15 + 0;
		while (this->allBlocks[next]->empty == false) {
			next = 3;
		}
		this->allBlocks[next]->empty = false;
	}
}
void Block::changePosLeft() {
	
	//for (int i = 0; i < 4; i++) { //TODO od lewej
	//algorytm --> moje d¿ewo
	if (this->allBlocks[0]->empty == true) { //sciezka e
		if (this->allBlocks[1]->empty == false) {
			this->allBlocks[1]->empty = true;
			this->allBlocks[0]->empty = false;
		}
		else if (this->allBlocks[1]->empty == true) {
			if (this->allBlocks[2]->empty = false) {
				this->allBlocks[2]->empty = true;
				this->allBlocks[0]->empty = false;
			}
			else if (this->allBlocks[2]->empty = true) {
				if (this->allBlocks[3]->empty = false) {
					this->allBlocks[3]->empty = true;
					this->allBlocks[0]->empty = false;
				}
				else {}
			}
		}
	}
	else if (this->allBlocks[0]->empty == false) { //sciezka f
		if (this->allBlocks[1]->empty == true) {
			if (this->allBlocks[2]->empty == false) {
				this->allBlocks[2]->empty = true;
				this->allBlocks[1]->empty = false;
			}
			else if (this->allBlocks[2]->empty == true) {
				if (this->allBlocks[3]->empty == false) {
					this->allBlocks[3]->empty = true;
					this->allBlocks[1]->empty = false;
				}
				else {}
			}
		}
		else if (this->allBlocks[1]->empty == false) {
			if(this->allBlocks[2]->empty == false){}
			else if (this->allBlocks[2]->empty == true) {
				if (this->allBlocks[3]->empty == false) {
					this->allBlocks[3]->empty = true;
					this->allBlocks[2]->empty = false;
				}
				else if (this->allBlocks[3]->empty == true) {}
			}
		}
	}
	
}
Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
