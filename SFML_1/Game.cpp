#include "Header.h"

void Game::runGame() {
	okno.create(sf::VideoMode(400, 400), "2048", sf::Style::Default);
	okno.setPosition(sf::Vector2i(70,0));
	textura.loadFromFile("klocek.png");
	font.loadFromFile("arial.ttf");

	text.setFont(font);
	text.setCharacterSize(30);
	text.setColor(sf::Color::Green);
	text.setString(searchNr());

	one = new Block();
	this->one->fullfil(textura);
	this->one->search(state);
	this->draw();
}
void Game::draw() {
	for (auto i : this->one->allBlocks) {
		if (i->empty == false) {
			i->singleBlock.setPosition(i->posX, i->posY);
			okno.draw(i->singleBlock);

			i->text.setPosition(i->posX, i->posY);
			okno.draw(i->text);
		}
	}
}

std::string  Game::searchNr() {
	std::string tab[2]{ "2","4" };
	int a = rand() % 2 + 0;
	return tab[a];
}
Game::~Game() {
	std::cout << "DESTRUKTOR KLASY GAME" << std::endl;
}
