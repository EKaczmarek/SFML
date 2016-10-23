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

	textura.loadFromFile("klocek.png");
	end.loadFromFile("koniec.png");

	one = new Block();

	//textura i text przekazane przez wskaznik do klasy Block
	//dzia³anie na oryginale ze s³owem const 
	//const zabezpieczenie przed zmiana wlasciwosci
	this->one->fullfil(&textura, &text);
	this->one->search(0);
	this->one->search();
}

void Game::draw() {
	for (auto i : this->one->allBlocks) {
		if (i->empty == false) {
			i->singleBlock.setPosition(i->posX, i->posY);
			okno.draw(i->singleBlock);

			i->text.setPosition(i->posX + 20, i->posY + 20);
			okno.draw(i->text);
		}
	}
}
bool Game::endGame() {
	int a = 0;
	for (int i = 0; i < 16; i++) {
		if (this->one->allBlocks[i]->empty == false)
			a++;
		else continue;
	}
	if (a == 16)
		return true;
	else
		return false;
}

Game::~Game() {
	std::cout << "DESTRUKTOR KLASY GAME" << std::endl;
}
