#include "Header.h"
void Block::fullfil(sf::Texture &_textura, sf::Font & font) {
	int i = 0;

for (int a = 0; a < 400; (a += 100)) {
		for (int b = 0; b < 400; (b += 100)) {
			this->allBlocks[i] = new Block;
			this->allBlocks[i]->posX = b;
			this->allBlocks[i]->posY = a;
			this->allBlocks[i]->singleBlock.setTexture(_textura);
			this->allBlocks[i]->empty = true;

			this->allBlocks[i]->text.setFont(font);
			this->allBlocks[i]->text.setCharacterSize(50);
			this->allBlocks[i]->text.setColor(sf::Color::Red);
			this->allBlocks[i]->text.setStyle(sf::Text::Bold);
			this->allBlocks[i]->text.setPosition(100, 100);
			i++;
		}
	}
}

int Block::searchNr() {
	int tab[2]{ 2,4 };
	int a = rand() % 2 + 0;
	return tab[a];
}

void Block::search(int & state) {
	//rand positions from sixteen positions
	if (state == 0) {
		int first = rand() % 16 + 0;
		if (this->allBlocks[first]->empty = true) {
			this->allBlocks[first]->nr = searchNr();
			this->allBlocks[first]->text.setString(std::to_string((this->allBlocks[first]->nr)));
			state = 1;
		}
	}
	else if(state == 1){
		int next = rand() % 16 + 0;

		while (this->allBlocks[next]->empty == false) {
			next = rand() % 16 + 0;
		}

		this->allBlocks[next]->empty = false;
		this->allBlocks[next]->nr = searchNr();
		this->allBlocks[next]->text.setString(std::to_string(this->allBlocks[next]->nr));
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

					this->allBlocks[firstEmpty]->nr = this->allBlocks[(4 * i) + j]->nr;
					this->allBlocks[(4 * i) + j]->nr = 0;
					this->allBlocks[firstEmpty]->text.setString(std::to_string(this->allBlocks[firstEmpty]->nr));
					if (j == 3) {
						if (this->allBlocks[(4 * i) + 1]->empty == true) {
							firstEmpty = (4 * i) + 1;
							continue;
						}
						else if (this->allBlocks[(4 * i) + 2]->empty == true) {
							firstEmpty = (4 * i) + 2;
							continue;
						}
					}
					else if (j == 2) {
						if (this->allBlocks[(4 * i) + 1]->empty == true) {
							firstEmpty = (4 * i) + 1;
							continue;
						}
						else if (this->allBlocks[(4 * i) + 2]->empty == true) {
							firstEmpty = (4 * i) + 2;
							continue;
						}
					}
					else
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
					
					this->allBlocks[firstEmpty]->nr = this->allBlocks[(4 * i) + j]->nr;
					this->allBlocks[firstEmpty]->text.setString(std::to_string(this->allBlocks[firstEmpty]->nr));
					this->allBlocks[(4 * i) + j]->nr = 0;

					if (j == 0) {
						if (this->allBlocks[(4 * i) + 2]->empty == true) {
							firstEmpty = (4 * i) + 2;
							break;
						}
						else if (this->allBlocks[(4 * i) + 1]->empty == true) {
							firstEmpty = (4 * i) + 1;
							continue;
						}
					}
					else if (j == 1) {
						if (this->allBlocks[(4 * i) + 1]->empty == true) {
							firstEmpty = (4 * i) + 1;
							continue;
						}
					}
					else
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


void Block::reduceLeft() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)	{
			switch (j)
			{
			case 0: {
				//je¿eli pozycja 0 jest pe³na
				if (this->allBlocks[(4 * i) + j]->empty == false) {
					//jesli 0 == 1
					if (this->allBlocks[(4 * i) + j]->nr == this->allBlocks[(4 * i) + 1]->nr) {
						this->allBlocks[(4 * i) + j]->nr *= 2;
						this->allBlocks[(4 * i) + j]->text.setString(std::to_string((this->allBlocks[(4 * i) + j]->nr)));
					}
					else
						//jeœli nie szukam dalej czy 1 == 2
						continue;
				}
				break;
			}
			case 1: {
				//je¿eli pozycja 1 jest pe³na
				if (this->allBlocks[(4 * i) + j]->empty == false) {
					//jesli 1 == 2
					if (this->allBlocks[(4 * i) + j]->nr == this->allBlocks[(4 * i) + 2]->nr) {
						this->allBlocks[(4 * i) + j]->nr *= 2;
						this->allBlocks[(4 * i) + j]->text.setString(std::to_string((this->allBlocks[(4 * i) + j]->nr)));
					}
					else
						//jeœli nie szukam dalej czy np 2 == 3
						continue;
				}
				break;
			}
			case 2: {
				//je¿eli pozycja 2 jest pe³na
				if (this->allBlocks[(4 * i) + j]->empty == false) {
					//jesli 1 == 2
					if (this->allBlocks[(4 * i) + j]->nr == this->allBlocks[(4 * i) + 3]->nr) {
						this->allBlocks[(4 * i) + j]->nr *= 2;
						this->allBlocks[(4 * i) + j]->text.setString(std::to_string((this->allBlocks[(4 * i) + j]->nr)));
					}
					else
						//jeœli nie szukam dalej czy np 2 == 3
						continue;
				}
				break;
			}
			default:
				break;
			}
		}
	}
}

void Block::reduceRight() {
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j >= 0; j--) {
			switch (j)
			{
			case 3: {
				//je¿eli pozycja 3 jest pe³na
				if (this->allBlocks[(4 * i) + j]->empty == false) {
					//jesli 3 == 2
					if (this->allBlocks[(4 * i) + j]->nr == this->allBlocks[(4 * i) + 2]->nr) {
						this->allBlocks[(4 * i) + j]->nr *= 2;
						this->allBlocks[(4 * i) + j]->text.setString(std::to_string((this->allBlocks[(4 * i) + j]->nr)));
					}
					else
						//jeœli nie szukam dalej czy 1 == 2
						continue;
				}
				break;
			}
			case 2: {
				//je¿eli pozycja 2 jest pe³na
				if (this->allBlocks[(4 * i) + j]->empty == false) {
					//jesli 2 == 1
					if (this->allBlocks[(4 * i) + j]->nr == this->allBlocks[(4 * i) + 1]->nr) {
						this->allBlocks[(4 * i) + j]->nr *= 2;
						this->allBlocks[(4 * i) + j]->text.setString(std::to_string((this->allBlocks[(4 * i) + j]->nr)));
					}
					else
						//jeœli nie szukam dalej czy np 2 == 3
						continue;
				}
				break;
			}
			case 1: {
				//je¿eli pozycja 1 jest pe³na
				if (this->allBlocks[(4 * i) + j]->empty == false) {
					//jesli 1 == 0
					if (this->allBlocks[(4 * i) + j]->nr == this->allBlocks[(4 * i)]->nr) {
						this->allBlocks[(4 * i) + j]->nr *= 2;
						this->allBlocks[(4 * i) + j]->text.setString(std::to_string((this->allBlocks[(4 * i) + j]->nr)));
					}
					else
						//jeœli nie szukam dalej czy np 2 == 3
						continue;
				}
				break;
			}
			default:
				break;
			}
		}
	}
}

Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
