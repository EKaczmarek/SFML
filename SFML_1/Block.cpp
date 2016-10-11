#include "Header.h"

void Block::fullfil(sf::Texture &_textura) {
	int i = 0;
	sf::Text temp;
	for (int a = 0; a < 400; (a += 100)) {
		for (int b = 0; b < 400; (b += 100)) {
			this->allBlocks[i] = new Block;
			this->allBlocks[i]->posX = b;
			this->allBlocks[i]->posY = a;
			this->allBlocks[i]->text.setString(searchNr());
			this->allBlocks[i]->text.setColor(sf::Color::Red);
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
	else if(state == 1){
		int next = rand() % 16 + 0;
		while (this->allBlocks[next]->empty == false) {
			next = rand() % 16 + 0;
		}
		this->allBlocks[next]->empty = false;
	}
}
std::string Block::searchNr() {
	std::string tab[2]{ "2","4" };
	int a = rand() % 2 + 0;
	return tab[a];
}
void Block::changePosLeft() {
	
	//algorytm --> moje d¿ewo
	for (int i = 0; i < 4; i++) { //TODO od lewej

		if (this->allBlocks[(4 * i)]->empty == true) { //sciezka e
			if (this->allBlocks[(4 * i) + 1] ->empty == false) {
				this->allBlocks[(4 * i) + 1]->empty = true;
				this->allBlocks[(4 * i)]->empty = false;
			}
			else if (this->allBlocks[(4 * i) + 1]->empty == true) {
				if (this->allBlocks[(4 * i) + 2]->empty == false) {
					this->allBlocks[(4 * i) + 2]->empty = true;
					this->allBlocks[(4 * i) ]->empty = false;
				}
				else if (this->allBlocks[(4 * i) + 2]->empty == true) {
					if (this->allBlocks[(4 * i) + 3]->empty == false) {
						this->allBlocks[(4 * i) + 3]->empty = true;
						this->allBlocks[(4 * i)]->empty = false;
					}
					else {}
				}
			}
		}
		else if (this->allBlocks[(4 * i)]->empty == false) { //sciezka f
			if (this->allBlocks[(4 * i) + 1]->empty == true) {
				if (this->allBlocks[(4 * i) + 2]->empty == false) {
					this->allBlocks[(4 * i) + 2]->empty = true;
					this->allBlocks[(4 * i) + 1]->empty = false;
				}
				else if (this->allBlocks[(4 * i) + 2]->empty == true) {
					if (this->allBlocks[(4 * i) + 3]->empty == false) {
						this->allBlocks[(4 * i) + 3]->empty = true;
						this->allBlocks[(4 * i) + 1]->empty = false;
					}
					else {}
				}
			}
			else if (this->allBlocks[(4 * i) + 1]->empty == false) {
				if (this->allBlocks[(4 * i) + 2]->empty == false) {}
				else if (this->allBlocks[(4 * i) + 2]->empty == true) {
					if (this->allBlocks[(4 * i) + 3]->empty == false) {
						this->allBlocks[(4 * i) + 3]->empty = true;
						this->allBlocks[(4 * i) + 2]->empty = false;
					}
					else if (this->allBlocks[(4 * i) + 3]->empty == true) {}
				}
			}
		}
	}
}
Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
