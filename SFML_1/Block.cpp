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
void Block::moves() {
	if (move::isKeyPressed(move::Left)) {
		std::cout << "Lewy" << std::endl;
		this->movesLR("left");
		this->search();
	}
	if (move::isKeyPressed(move::Right)) {
		std::cout << "Prawy" << std::endl;
		this->movesLR("right");
		this->search();
	}
	if (move::isKeyPressed(move::Up)) {
		std::cout << "Góra" << std::endl;
		this->posUD("up");
		this->reduceUp();
		this->posUD("up");
		this->search();
	}
	if (move::isKeyPressed(move::Down)) {
		std::cout << "Dó³" << std::endl;
		this->posUD("down");
		this->reduceDown();
		this->posUD("down");
		this->search();
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

void Block::movesLR(std::string s) {
	int firstE = -1;
	int side;

	for (int i = 0; i < 4; i++) {
		//RUCH W LEW¥ STRONÊ
		if (s == "left") {
			side = 1;
			firstE = -1;
			for (int j = 0; j < 3; j++) {
				this->LR(i,j,firstE, side);
			}
		}
		//RUCH W PRAW¥ STRONÊ
		else if (s == "right") {
			side = -1;
			firstE = -1;
			for (int j = 3; j > 0; j--) {
				this->LR(i, j, firstE, side);
			}
		}
	}
}
void Block::LR(int _i, int _j,int & _firstE, int _side){
	//sytuacja gdy dwa obok siebie s¹ pe³ne
	this->theSame(_i, _j, _firstE, _side);
	//sytuacja klocek bardziej na prawo jest pe³ny a ten po lewej pusty
	if (this->allBlocks[(4 * _i) + _j]->empty == true && this->allBlocks[(4 * _i) + _j + _side]->empty == false) {
		//jeœli nie ma przypisanego pierwszego pustego lubb gdy firstE jest bardziej na prawo/lewo ni¿ klocek (4*_i)+_j+_side 
		if (_firstE == -1 || _firstE >= (4 * _i) + _j + _side) {
			//przypisanie wartoœci
			this->allBlocks[(4 * _i) + _j]->nr = this->allBlocks[(4 * _i) + _j + _side]->nr;
			//ustawianie wartoœci jako Spritea
			this->allBlocks[(4 * _i) + _j]->text.setString(std::to_string((this->allBlocks[(4 * _i) + _j]->nr)));
			//wyzerowanie wartoœci na bloku z którego przenoszê
			this->allBlocks[(4 * _i) + _j + _side]->nr = 0;
			//ustawienie flagi dla klocka bardziej po lewej
			this->allBlocks[(4 * _i) + _j]->empty = false;
			//ustawienie flagi dla klocka bardziej po prawej
			this->allBlocks[(4 * _i) + _j + _side]->empty = true;
			_firstE = (4 * _i) + _j + _side;
			this->theSame(_i, _j, _firstE, _side);
		}
		//jeœli jest przypisany jakiœ pusty i jest od bardziej na lewo/prawo ni¿ (4*_i)+_j+_side
		else if (_firstE != -1 && _firstE < (4 * _i) + _j + _side) {
			//przypisanie wartoœci
			this->allBlocks[_firstE]->nr = this->allBlocks[(4 * _i) + _j + _side]->nr;
			//ustawianie wartoœci jako Spritea
			this->allBlocks[_firstE]->text.setString(std::to_string((this->allBlocks[_firstE]->nr)));
			//wyzerowanie wartoœci na bloku z którego przenoszê
			this->allBlocks[(4 * _i) + _j + _side]->nr = 0;
			//ustawienie flagi dla klocka bardziej po lewej
			this->allBlocks[_firstE]->empty = false;
			//ustawienie flagi dla klocka bardziej po prawej
			this->allBlocks[(4 * _i) + _j + _side]->empty = true;
			//ustawienie pierwszego pustego klocka 
			_firstE = (4 * _i) + _j;
			this->theSame(_i, _j, _firstE, _side);

		}
	}
	//sytuacja klocek bardziej na lewo jest pe³ny a ten po prawej pusty
	else if (this->allBlocks[(4 * _i) + _j]->empty == false && this->allBlocks[(4 * _i) + _j + _side]->empty == true) {
		//nic nie rób
	}
	//sytuacja gdy oba obok siebie s¹ puste
	else if (this->allBlocks[(4 * _i) + _j]->empty == true && this->allBlocks[(4 * _i) + _j + _side]->empty == true) {
		if (_firstE == -1)
			//ustawienie pierwszego pustego klocka 
			_firstE = (4 * _i) + _j;
	}
}
void Block::theSame(int _i, int _j, int & _firstE, int _side) {
	if (this->allBlocks[(4 * _i) + _j]->empty == false && this->allBlocks[(4 * _i) + _j + _side]->empty == false) {
		if (this->allBlocks[(4 * _i) + _j]->nr == this->allBlocks[(4 * _i) + _j + _side]->nr) {
			//przypisanie wartoœci
			this->allBlocks[(4 * _i) + _j]->nr *= 2;
			//ustawianie wartoœci jako Spritea
			this->allBlocks[(4 * _i) + _j]->text.setString(std::to_string((this->allBlocks[(4 * _i) + _j]->nr)));
			//wyzerowanie wartoœci na bloku z którego przenoszê
			this->allBlocks[(4 * _i) + _j + _side]->nr = 0;
			//ustawienie flagi dla klocka bardziej po prawej
			this->allBlocks[(4 * _i) + _j + _side]->empty = true;
			//ustawienie pierwszego pustego
			_firstE = (4 * _i) + _j;
		}
	}
}
void Block::posUD(std::string s) {
	int firstEmpty = -1;
	// wiersze
	for (int i = 0; i < 4; i++) {
		firstEmpty = -1;
		// pozycje 
		if (s == "down") {
			for (int j = 12; j >= 0; j -= 4) {
				wigglewiggleUD(i, j, firstEmpty, "down");
			}
		}
		else if (s == "up") {
			for (int j = 0; j < 13; j += 4) {
				wigglewiggleUD(i, j, firstEmpty, "up");
			}
		}
	}
}
bool Block::wigglewiggleUD(const int i, const int j, int & firstE, std::string side) {
	if (this->allBlocks[i + j]->empty == true) {
		if (firstE == -1)
			firstE = i + j;
		return true;
	}
	else {
		if (firstE != -1) {
			this->allBlocks[i + j]->empty = true;
			this->allBlocks[firstE]->empty = false;

			this->allBlocks[firstE]->nr = this->allBlocks[i + j]->nr;
			this->allBlocks[i + j]->nr = 0;
			this->allBlocks[firstE]->text.setString(std::to_string(this->allBlocks[firstE]->nr));

			if (side == "down") {
				if (j == 12) {
					if (this->allBlocks[i + 1]->empty == true) {
						firstE = i + 1;
						return true;
					}
					else if (this->allBlocks[i + 2]->empty == true) {
						firstE = i + 2;
						return true;
					}
				}
				else if (j == 8) {
					if (this->allBlocks[i + 1]->empty == true) {
						firstE = i + 1;
						return true;
					}
					else if (this->allBlocks[i + 2]->empty == true) {
						firstE = i + 2;
						return true;
					}
				}
				else
					firstE = i + j;
			}
			else if (side == "up") {
				if (j == 0) {
					if (this->allBlocks[i + 1]->empty == true) {
						firstE = i + 1;
						return true;
					}
					else if (this->allBlocks[i + 2]->empty == true) {
						firstE = i + 2;
						return true;
					}
				}
				else if (j == 4) {
					if (this->allBlocks[i + 1]->empty == true) {
						firstE = i + 1;
						return true;
					}
					else if (this->allBlocks[i + 2]->empty == true) {
						firstE = i + 2;
						return true;
					}
				}
				else
					firstE = i + j;
			}
			else if (firstE == -1) {
				return true;
			}
			else
				return false;
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
