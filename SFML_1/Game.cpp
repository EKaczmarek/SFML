#include "Header.h"

void Game::runGame() {
	okno.create(sf::VideoMode(400, 400), "2048", sf::Style::Default);
	okno.setPosition(sf::Vector2i(70,0));
	textura.loadFromFile("klocek.png");

	end.loadFromFile("koniec.png");
	picEnd.setTexture(end);

	if (!this->font.loadFromFile("arial.ttf"))
		EXIT_FAILURE;

	one = new Block();
	
	this->one->fullfil(textura, font);
	this->one->search(state);
	this->one->search(state);	
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
