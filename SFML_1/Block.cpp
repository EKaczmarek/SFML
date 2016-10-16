#include "Header.h"
void Block::fullfil(sf::Texture &_textura, sf::Text *_text) {
	int i = 0;
	
	for (int a = 0; a < 400; (a += 100)) {
		for (int b = 0; b < 400; (b += 100)) {
			this->allBlocks[i] = new Block;
			this->allBlocks[i]->posX = b;
			this->allBlocks[i]->posY = a;
			this->allBlocks[i]->singleBlock.setTexture(_textura);
			this->allBlocks[i]->empty = true;
			this->allBlocks[i]->text = *_text;
			i++;
		}
	}
}

std::string  Block::searchNr() {
	std::string tab[2]{ "2","4" };
	int a = rand() % 2 + 0;
	return tab[a];
}

void Block::search(int & state) {

	//rand positions from sixteen positions
	if (state == 0) {
		int first = rand() % 16 + 0;
		this->allBlocks[first]->empty = false;
		this->allBlocks[first]->text.setString(searchNr());
		state = 1;
	}
	else if(state == 1){
		int next = rand() % 16 + 0;
		while (this->allBlocks[next]->empty == false) {
			next = rand() % 16 + 0;
		}
		this->allBlocks[next]->empty = false;
		this->allBlocks[next]->text.setString(searchNr());
	}
}

void Block::changePosLeft() {
	int firstEmpty = -1;
	// wiersze
	for (int i = 0; i < 4; i++){ 
	firstEmpty = -1;
	// pozycje 
		for (int j = 0; j < 4; j++)	{
			if (this->allBlocks[(4 * i) + j]->empty == true) {
				if(firstEmpty == -1)
					firstEmpty = (4 * i) + j;
				continue;
			}
			else {
				if (firstEmpty != -1) {
					this->allBlocks[(4 * i) + j]->empty = true;
					this->allBlocks[firstEmpty]->empty = false;
					if (j == 3) {
						if (this->allBlocks[(4 * i) + 1]->empty == true) {
							firstEmpty = (4 * i) + 1;
							break;
						}
						else if (this->allBlocks[(4 * i) + 2]->empty == true) {
							firstEmpty = (4 * i) + 2;
							break;
						}
					}
					else if (j == 2) {
						if (this->allBlocks[(4 * i) + 1]->empty == true) {
							firstEmpty = (4 * i) + 1;
							break;
						}
					}
					firstEmpty = (4 * i) + j;
				}
				else if (firstEmpty == -1) {
					continue;
				}
				else
					break;
			}
		}
	}
}
void Block::changePosRight() {
	int firstEmpty = -1;
	// wiersze
	for (int i = 0; i < 4; i++) {
		firstEmpty = -1;
		// pozycje 
		for (int j = 3; j >= 0; j--) {
			if (this->allBlocks[(4 * i) + j]->empty == true) {
				if (firstEmpty == -1)
					firstEmpty = (4 * i) + j;
				continue;
			}
			else {
				if (firstEmpty != -1) {
					this->allBlocks[(4 * i) + j]->empty = true;
					this->allBlocks[firstEmpty]->empty = false;
					if (j == 0) {
						if (this->allBlocks[(4 * i) + 1]->empty == true) {
							firstEmpty = (4 * i) + 1;
							break;
						}
						else if (this->allBlocks[(4 * i) + 2]->empty == true) {
							firstEmpty = (4 * i) + 2;
							break;
						}
					}
					else if (j == 1) {
						if (this->allBlocks[(4 * i) + 2]->empty == true) {
							firstEmpty = (4 * i) + 2;
							break;
						}
					}
					firstEmpty = (4 * i) + j;
				}
				else if (firstEmpty == -1) {
					continue;
				}
				else
					break;
			}
		}
	}
}


Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
