#include "Header.h"


void Game::runGame() {
	okno.create(sf::VideoMode(400, 400), "2048", sf::Style::Default && sf::Style::Resize);
	textura.loadFromFile("klocek.png");
	font.loadFromFile("arial.ttf");

	//text in Block
	text.setFont(font);
	text.setCharacterSize(100);
	text.setColor(sf::Color::Green);

	one = new Block;
	//Table of Blocks
	std::cout << "Rozmiar tablicy: " << one->allBlocks->size() << std::endl;
	this->one->search(text);
	//separate Block
	this->one->singleBlock.setTexture(textura);
}
void Game::draw(Block * toShow) {

	//ustawienie pozycji
	toShow->singleBlock = this->one->singleBlock;
	toShow->singleBlock.setPosition(toShow->posX, toShow->posY);
	toShow->text.setPosition(toShow->posX - 5, toShow->posY);

	//wyœwietlenie
	this->okno.draw(toShow->singleBlock);
	this->okno.draw(toShow->text);

}

Game::~Game() {
	std::cout << "DESTRUKTOR KLASY GAME" << std::endl;
}
