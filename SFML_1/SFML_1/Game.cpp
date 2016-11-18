#include "Header.h"

void Game::runGame() {
	//Okno gry
	Window();

	//Czcionka oraz tekstura klocka
	Font();

	//obiekt przechowuj¹cy tablicê bloków
	//z ich w³aœciwoœciami (numerem, pozycj¹,
	//informacji o tym czy dana pozycja jest pusta
	//czy pe³na
	object();
}
void Game::Window() {
	okno.create(sf::VideoMode(400, 400), "2048", sf::Style::Default);
	okno.setPosition(sf::Vector2i(70, 0));
}
void Game::Font() {
	if (!this->font.loadFromFile("arial.ttf"))
		EXIT_FAILURE;

	//ustawienie w³aœciwoœci czcionki 
	this->text.setFont(font);
	this->text.setCharacterSize(50);
	this->text.setFillColor(sf::Color::Blue);
	this->text.setStyle(sf::Text::Bold);
}
void Game::object() {

	//³adowanie tekstur
	textura.loadFromFile("klocek.png");
	end.loadFromFile("koniec.png");
	wint.loadFromFile("winning.png");

	//tworzenie obiektu
	one = new Block();

	//textura i text przekazane przez wskaznik do klasy Block
	//dzia³anie na oryginale ze s³owem const 
	//const zabezpieczenie przed zmiana wlasciwosci
	this->one->fullfil(&textura, &text);
	this->one->search(0);
	this->one->search();
}

void Game::draw(int a) {
	if (a == 1) {
		for (auto i : this->one->allBlocks) {
			if (i->empty == false && i->nr >= 2) {
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

	int flag = 0;
	for (int k = 0; k < 16; k++) {
		if (this->one->allBlocks[k]->empty == false)
			flag++;
	}

	int movesLR = 0; // lewo<-> prawo brak ruchów - true
					 //sprawdzenie strony lewo <-> prawo
	//wiersze
	for (int i = 0; i < 4; i++) {
		//pozycje
		for (int j = 0; j < 4; j++) {
			//warunek aby nie probowac odczytac elementu tablicy który nie istnieje
			if ((4 * i) + j + 1 < 16) {
				if ((this->one->allBlocks[(4 * i) + j]->empty == false && this->one->allBlocks[(4 * i) + j + 1]->empty == false) && 
					(this->one->allBlocks[(4 * i) + j]->nr == this->one->allBlocks[(4 * i) + j + 1]->nr))
						movesLR++;
			}
		}
	}

	// góra <-> dó³ brak ruchów - true
	int movesUD = 0;
	//sprawdzenie strony góra <-> dó³
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 9; j += 4) {
			//warunek aby nie probowac odczytac elementu tablicy który nie istnieje
			if (i + j + 4 < 16) {
				if ((this->one->allBlocks[i + j]->empty == false && this->one->allBlocks[i + j + 4]->empty == false) &&
					(this->one->allBlocks[i + j]->nr == this->one->allBlocks[i + j + 4]->nr))
						movesUD++;
				
			}
		}
	}

	std::cout << "movesUD = " << movesUD
		<< "\t movesLR = " << movesLR
		<< "\t flag = " << flag << std::endl;

	if (movesUD == 0 && movesLR == 0 && flag == 16)
		return true;
	else
		return false;
}
bool Game::win() {
	for (int i = 0; i < 16; i++) {
		if (this->one->allBlocks[i]->nr == 2048)
			return true;
		else
			return false;
	}
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
