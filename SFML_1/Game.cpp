#include "Header.h"

void Game::runGame() {
	//Okno gry
	Window();
	//Czcionka oraz tekstura klocka
	Font();
	//obiekt przechowuj�cy tablic� blok�w
	//z ich w�a�ciwo�ciami (numerem, pozycj�,
	//informacji o tym czy dana pozycja jest pusta
	//czy pe�na
	object();
}
void Game::Window() {
	okno.create(sf::VideoMode(400, 400), "2048", sf::Style::Default);
	okno.setPosition(sf::Vector2i(70, 0));
}
void Game::Font() {
	if (!this->font.loadFromFile("arial.ttf"))
		EXIT_FAILURE;

	//ustawienie w�a�ciwo�ci czcionki 
	this->text.setFont(font);
	this->text.setCharacterSize(50);
	this->text.setFillColor(sf::Color::Blue);
	this->text.setStyle(sf::Text::Bold);
}
void Game::object() {

	//�adowanie tekstur
	textura.loadFromFile("klocek.png");
	end.loadFromFile("koniec.png");

	//tworzenie obiektu
	one = new Block();

	//textura i text przekazane przez wskaznik do klasy Block
	//dzia�anie na oryginale ze s�owem const 
	//const zabezpieczenie przed zmiana wlasciwosci
	this->one->fullfil(&textura, &text);
	this->one->search(0);
	this->one->search();
}

void Game::draw(int a) {
	if (a == 1) {
		for (auto i : this->one->allBlocks) {
			if (i->empty == false) {
				i->singleBlock.setPosition(i->posX, i->posY);
				okno.draw(i->singleBlock);

				i->text.setPosition(i->posX + 20, i->posY + 20);
				okno.draw(i->text);
			}
		}
	}
	else if (a == 0) {
		endokno.draw(picEnd);
	}
}
bool Game::endGame() {

	int a = 0;
	//sprawdzenie strony lewo <-> prawo
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//warunek aby nie probowac odczytac elementu tablicy kt�ry nie istnieje
			if ((4 * i) + j + 1 < 16) {
				if (this->one->allBlocks[(4 * i) + j]->empty == false &&
					this->one->allBlocks[(4 * i) + j + 1]->empty == false) {
					if (this->one->allBlocks[(4 * i) + j]->nr == this->one->allBlocks[(4 * i) + j + 1]->nr) {
						a++;
					}
					else
						continue;
				}
				else
					break;
			}
			else break;
		}
	}
	int b = 0;
	//sprawdzenie strony g�ra <-> d�
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j += 4) {
			//warunek aby nie probowac odczytac elementu tablicy kt�ry nie istnieje
			if (i + j + 1 < 16) {
				if (this->one->allBlocks[i + j]->empty == false &&
					this->one->allBlocks[i + j + 1]->empty == false) {
					if (this->one->allBlocks[i + j]->nr == this->one->allBlocks[i + j + 1]->nr) {
						b++;
					}
					else
						continue;
				}
				else
					break;
			}
			else break;
		}
	}

	if (a == 12 && b == 12)
		return true;
	else
		return false;

}

void Game::oknoOpt(int state) {
	if (state == 1) {
		this->okno.clear();
		this->draw();
		this->okno.display();
	}
	else if (state == 0) {
		this->endokno.clear();
		this->draw(0);
		this->endokno.display();
	}
}

Game::~Game() {
	std::cout << "DESTRUKTOR KLASY GAME" << std::endl;
}
