#include "Header.h"


void Game::runGame() {
	okno.create(sf::VideoMode(400, 400), "2048", sf::Style::Default && sf::Style::Resize);
	textura.loadFromFile("klocek.png");
	font.loadFromFile("arial.ttf");

	//separate Block
	this->one->singleBlock.setTexture(textura);

	//text in Block
	text.setFont(font);
	text.setString(this->one->setNumber(&text));
	text.setCharacterSize(100);
	text.setColor(sf::Color::Red);

	//Table of Blocks
	std::cout << "Rozmiar tablicy: " << this->one->allBlocks.size() << std::endl;
	this->one->search(&text);
	this->one->text.setString(this->one->setNumber(&text));
}

Game::~Game() {
	std::cout << "DESTRUKTOR KLASY GAME" << std::endl;
}
