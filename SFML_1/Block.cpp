#include "Header.h"

void Block::fullfil(const sf::Texture *_textura,const sf::Text * _text) {
int i = 0;
for (int a = 0; a < 400; (a += 100)) {
		for (int b = 0; b < 400; (b += 100), i++) {
			this->allBlocks[i] = new Block;
			//ustawienia domyslnych pozycji, textury i flagi
			this->allBlocks[i]->posX = b;
			this->allBlocks[i]->posY = a;
			this->allBlocks[i]->singleBlock.setTexture(*_textura);
			this->allBlocks[i]->empty = true;

			//przypisanie w³aœciwoœci z klasy Game
			//do kazdego obiektu klasy Block
			this->allBlocks[i]->text = *_text;  
		}
	}
}

void Block::search(int state) {
	//rand positions from sixteen positions
	if (state == 0) {
		int first = rand() % 16;
		if (this->allBlocks[first]->empty = true) {
			this->allBlocks[first]->empty = false;
										//losowanie z 9 liczb, jesli 8 to 4, pozosta³e to 2
			this->allBlocks[first]->nr = (rand() % 9) == 8 ? 4 : 2;
			this->allBlocks[first]->text.setString(std::to_string((this->allBlocks[first]->nr)));
		}
	}
	else if(state == 1){
		int next = rand() % 16;

		while (this->allBlocks[next]->empty == false) {
			next = rand() % 16;
		}
		this->allBlocks[next]->empty = false;
		this->allBlocks[next]->nr = (rand() % 2) ? 4 : 2;
		this->allBlocks[next]->text.setString(std::to_string(this->allBlocks[next]->nr));
	}
}
void Block::posLR(std::string s) {
	int firstE = -1;
	// wiersze
	for (int i = 0; i < 4; i++) {
		firstE = -1;
		// pozycje 
		for (int j = 3; j >= 0; j--) {
			if (wigglewiggle(i, j, firstE, s))
				continue;
			else
				break;
		}
	}
}

bool Block::wigglewiggle(const int i, const int j, int & firstE, std::string side) {
	if (this->allBlocks[(4 * i) + j]->empty == true) {
		if (firstE == -1)
			firstE = (4 * i) + j;
		return true;
	}
	else {
		if (firstE != -1) {
			this->allBlocks[(4 * i) + j]->empty = true;
			this->allBlocks[firstE]->empty = false;

			this->allBlocks[firstE]->nr = this->allBlocks[(4 * i) + j]->nr;
			this->allBlocks[firstE]->text.setString(std::to_string(this->allBlocks[firstE]->nr));
			this->allBlocks[(4 * i) + j]->nr = 0;

			if (side == "right") {
				if (j == 0) {
					if (this->allBlocks[(4 * i) + 2]->empty == true) {
						firstE = (4 * i) + 2;
						return false;
					}
					else if (this->allBlocks[(4 * i) + 1]->empty == true) {
						firstE = (4 * i) + 1;
						return true;
					}
				}
				else if (j == 1) {
					if (this->allBlocks[(4 * i) + 1]->empty == true) {
						firstE = (4 * i) + 1;
						return true;
					}
				}
				else
					firstE = (4 * i) + j;
			}
			else if (side == "left") {
				if (j == 3) {
					if (this->allBlocks[(4 * i) + 1]->empty == true) {
						firstE = (4 * i) + 1;
						return false;
					}
					else if (this->allBlocks[(4 * i) + 2]->empty == true) {
						firstE = (4 * i) + 2;
						return true;
					}
				}
				else if (j == 2) {
					if (this->allBlocks[(4 * i) + 1]->empty == true) {
						firstE = (4 * i) + 1;
						return true;
					}
					else if (this->allBlocks[(4 * i) + 2]->empty == true) {
						firstE = (4 * i) + 2;
						return true;
					}
				}
				else
					firstE = (4 * i) + j;
			}
		}
		else if (firstE == -1) {
			return true;
		}
		else
			return false;
	}
}

void Block::changePosDown() {
	int firstEmpty = -1;
	// wiersze
	for (int i = 0; i < 4; i++) {
		firstEmpty = -1;
		// pozycje 
		for (int j = 12; j >= 0; j-=4) {
			if (this->allBlocks[i + j]->empty == true) {
				if (firstEmpty == -1)
					firstEmpty = i + j;
				continue;
			}
			else {
				if (firstEmpty != -1) {
					this->allBlocks[i + j]->empty = true;
					this->allBlocks[firstEmpty]->empty = false;

					this->allBlocks[firstEmpty]->nr = this->allBlocks[i + j]->nr;
					this->allBlocks[i + j]->nr = 0;
					this->allBlocks[firstEmpty]->text.setString(std::to_string(this->allBlocks[firstEmpty]->nr));
					if (j == 12) {
						if (this->allBlocks[i + 1]->empty == true) {
							firstEmpty = i + 1;
							continue;
						}
						else if (this->allBlocks[i + 2]->empty == true) {
							firstEmpty = i + 2;
							continue;
						}
					}
					else if (j == 8) {
						if (this->allBlocks[i + 1]->empty == true) {
							firstEmpty = i + 1;
							continue;
						}
						else if (this->allBlocks[i + 2]->empty == true) {
							firstEmpty =i + 2;
							continue;
						}
					}
					else
						firstEmpty = i + j;
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
void Block::changePosUp() {
	int firstEmpty = -1;
	// wiersze
	for (int i = 0; i < 4; i++) {
		firstEmpty = -1;
		// pozycje 
		for (int j = 0; j < 13; j += 4) {
			if (this->allBlocks[i + j]->empty == true) {
				if (firstEmpty == -1)
					firstEmpty = i + j;
				continue;
			}
			else {
				if (firstEmpty != -1) {
					this->allBlocks[i + j]->empty = true;
					this->allBlocks[firstEmpty]->empty = false;

					this->allBlocks[firstEmpty]->nr = this->allBlocks[i + j]->nr;
					this->allBlocks[i + j]->nr = 0;
					this->allBlocks[firstEmpty]->text.setString(std::to_string(this->allBlocks[firstEmpty]->nr));
					if (j == 0) {
						if (this->allBlocks[i + 1]->empty == true) {
							firstEmpty = i + 1;
							continue;
						}
						else if (this->allBlocks[i + 2]->empty == true) {
							firstEmpty = i + 2;
							continue;
						}
					}
					else if (j == 4) {
						if (this->allBlocks[i + 1]->empty == true) {
							firstEmpty = i + 1;
							continue;
						}
						else if (this->allBlocks[i + 2]->empty == true) {
							firstEmpty = i + 2;
							continue;
						}
					}
					else
						firstEmpty = i + j;
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
						this->allBlocks[(4 * i) + 1]->nr = 0;
						this->allBlocks[(4 * i) + 1]->empty = true;
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
						this->allBlocks[(4 * i) + 2]->nr = 0;
						this->allBlocks[(4 * i) + 2]->empty = true;
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
						this->allBlocks[(4 * i) + 3]->nr = 0;
						this->allBlocks[(4 * i) + 3]->empty = true;

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
						this->allBlocks[(4 * i) + 2]->nr = 0;
						this->allBlocks[(4 * i) + 2]->empty = true;
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
						this->allBlocks[(4 * i) + 1]->nr = 0;
						this->allBlocks[(4 * i) + 1]->empty = true;

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
						this->allBlocks[(4 * i)]->nr = 0;
						this->allBlocks[(4 * i)]->empty = true;

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
void Block::reduceDown() {
	for (int i = 0; i < 4; i++) {
		for (int j = 12; j > 0; j-=4) {
			switch (j)
			{
			case 12: {
				//je¿eli pozycja 12 jest pe³na
				if (this->allBlocks[i + j]->empty == false) {
					//jesli 12 == 8
					if (this->allBlocks[i + j]->nr == this->allBlocks[i + 8]->nr) {
						this->allBlocks[i + j]->nr *= 2;
						this->allBlocks[i + j]->text.setString(std::to_string((this->allBlocks[i + j]->nr)));
						this->allBlocks[i + 8]->nr = 0;
						this->allBlocks[i + 8]->empty = true;

					}
					else
						//jeœli nie szukam dalej czy 1 == 2
						continue;
				}
				break;
			}
			case 8: {
				//je¿eli pozycja 8 jest pe³na
				if (this->allBlocks[i + j]->empty == false) {
					//jesli 8 == 4
					if (this->allBlocks[i + j]->nr == this->allBlocks[i + 4]->nr) {
						this->allBlocks[i + j]->nr *= 2;
						this->allBlocks[i + j]->text.setString(std::to_string((this->allBlocks[i + j]->nr)));
						this->allBlocks[i + 4]->nr = 0;
						this->allBlocks[i + 4]->empty = true;
					}
					else
						//jeœli nie szukam dalej czy np 2 == 3
						continue;
				}
				break;
			}
			case 4: {
				//je¿eli pozycja 4 jest pe³na
				if (this->allBlocks[i + j]->empty == false) {
					//jesli 4 == 0
					if (this->allBlocks[i + j]->nr == this->allBlocks[i]->nr) {
						this->allBlocks[i + j]->nr *= 2;
						this->allBlocks[i + j]->text.setString(std::to_string((this->allBlocks[i + j]->nr)));
						this->allBlocks[i]->nr = 0;
						this->allBlocks[i]->empty = true;
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
void Block::reduceUp() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j += 4) {
			switch (j)
			{
			case 0: {
				//je¿eli pozycja 12 jest pe³na
				if (this->allBlocks[i + j]->empty == false) {
					//jesli 12 == 8
					if (this->allBlocks[i + j]->nr == this->allBlocks[i + 4]->nr) {
						this->allBlocks[i + j]->nr *= 2;
						this->allBlocks[i + j]->text.setString(std::to_string((this->allBlocks[i + j]->nr)));
						this->allBlocks[i + 4]->nr = 0;
						this->allBlocks[i + 4]->empty = true;
					}
					else
						//jeœli nie szukam dalej czy 1 == 2
						continue;
				}
				break;
			}
			case 4: {
				//je¿eli pozycja 8 jest pe³na
				if (this->allBlocks[i + j]->empty == false) {
					//jesli 8 == 4
					if (this->allBlocks[i + j]->nr == this->allBlocks[i + 8]->nr) {
						this->allBlocks[i + j]->nr *= 2;
						this->allBlocks[i + j]->text.setString(std::to_string((this->allBlocks[i + j]->nr)));
						this->allBlocks[i + 8]->nr = 0;
						this->allBlocks[i + 8]->empty = true;
					}
					else
						//jeœli nie szukam dalej czy np 2 == 3
						continue;
				}
				break;
			}
			case 8: {
				//je¿eli pozycja 4 jest pe³na
				if (this->allBlocks[i + j]->empty == false) {
					//jesli 4 == 0
					if (this->allBlocks[i + j]->nr == this->allBlocks[i + 12]->nr) {
						this->allBlocks[i + j]->nr *= 2;
						this->allBlocks[i + j]->text.setString(std::to_string((this->allBlocks[i + j]->nr)));
						this->allBlocks[i + 12]->nr = 0;
						this->allBlocks[i + 12]->empty = true;
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
