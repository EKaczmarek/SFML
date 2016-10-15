#include "Header.h"
void Block::fullfil(sf::Texture &_textura) {
	int i = 0;

	sf::Text _text;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		EXIT_FAILURE;
	_text.setFont(font);
	_text.setCharacterSize(30);
	_text.setColor(sf::Color::Red);
	_text.setStyle(sf::Text::Bold);

	for (int a = 0; a < 400; (a += 100)) {
		for (int b = 0; b < 400; (b += 100)) {
			this->allBlocks[i] = new Block;
			this->allBlocks[i]->posX = b;
			this->allBlocks[i]->posY = a;

			this->allBlocks[i]->singleBlock.setTexture(_textura);
			this->allBlocks[i]->text = _text;
			this->allBlocks[i]->text.setString((searchNr()));

			this->allBlocks[i]->empty = true;

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
					if (j == 3)
						if (this->allBlocks[(4 * i) + 2]->empty == true) {
							firstEmpty = (4 * i) + 2;
							break;
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

}


Block::~Block(){
	std::cout << "DESTRUKTOR KLASY BLOCK" << std::endl;
}
