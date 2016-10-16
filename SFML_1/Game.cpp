#include "Header.h"

void Game::runGame() {
	okno.create(sf::VideoMode(400, 400), "2048", sf::Style::Default);
	okno.setPosition(sf::Vector2i(70,0));
	textura.loadFromFile("klocek.png");

	if (!this->font.loadFromFile("arial.ttf"))
		EXIT_FAILURE;

	one = new Block();
	this->one->text.setFont(this->font);
	this->one->text.setCharacterSize(50);
	this->one->text.setColor(sf::Color::Red);
	this->one->text.setStyle(sf::Text::Bold);
	this->one->text.setString("2");
	this->one->text.setPosition(100, 100);

	this->one->fullfil(textura, &this->one->text);
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

Game::~Game() {
	std::cout << "DESTRUKTOR KLASY GAME" << std::endl;
}
