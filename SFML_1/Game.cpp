#include "Header.h"

void Game::runGame() {
	//Okno gry
	Window();
	//Czcionka oraz tekstura klocka
	Font();
	//obiekt przechowuj¹cy tablicê oraz parametry gry
	object();
}
void Game::Window() {
	okno.create(sf::VideoMode(400, 400), "2048", sf::Style::Default);
	okno.setPosition(sf::Vector2i(70, 0));
}
void Game::Font() {
	textura.loadFromFile("klocek.png");
	if (!this->font.loadFromFile("arial.ttf"))
		EXIT_FAILURE;
}
void Game::object() {
	one = new Block();

	this->one->fullfil(textura, font);
	this->one->search(0);
	this->one->search(1);

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
	}
	if (a == 16)
		return true;
	else
		return false;
}

Game::~Game() {
	std::cout << "DESTRUKTOR KLASY GAME" << std::endl;
}
