#include "Header.h"


void Game::run() {
	wind();
	pict();
	fullTab();
	font();
	search(1);
}
void Game::pict() {
	pictBlock.loadFromFile("klocek.png");
	pictEnd.loadFromFile("koniec.png");
	pictWin.loadFromFile("winning.png");
}
void Game::wind() {
	window.create(sf::VideoMode(400, 400), "2048", sf::Style::Default);
	window.setPosition(sf::Vector2i(100, 100));
}
void Game::windEnd() {

	windowEnd.create(sf::VideoMode(400, 200), "Koniec gry", sf::Style::Default);
	windowEnd.setPosition(sf::Vector2i(200, 200));
	this->pEnd.setTexture(this->pictEnd);
}
void Game::windWin() {

	windowWin.create(sf::VideoMode(400, 200), "Wygra³eœ!! ;)", sf::Style::Default);
	windowWin.setPosition(sf::Vector2i(200, 200));
	this->pWin.setTexture(this->pictWin);
}
void Game::fullTab() {
	
	//pozycje
	for (int a = 0; a < 16; a++) {
		this->blok = new Block();
	}

	int i = 0;
	for (int k = 0; k < 400; (k += 100)) {
		for (int j = 0; j < 400; (j += 100), i++) {
			this->blok->table[i] = new Block();
			this->blok->table[i]->posX = j;
			this->blok->table[i]->posY = k;
			this->blok->table[i]->bloc.setTexture(this->pictBlock);
			this->blok->table[i]->numb = 0;
			this->blok->table[i]->empty = true;
			this->blok->table[i]->nr.setString(std::to_string(this->blok->table[i]->numb));
		}
	}
}
void Game::font() {
	if (!fon.loadFromFile("arial.ttf"))
		EXIT_FAILURE;
	for (int i = 0; i < 16; i++) {
		this->blok->table[i]->nr.setFont(fon);
		this->blok->table[i]->nr.setColor(sf::Color::Black);
		this->blok->table[i]->nr.setCharacterSize(50);
	}
}
void Game::search(int a) {
	int first; int next;
	if (a == 1) {
		first = rand() % 16;
		if (this->blok->table[first]->empty == true) {
			this->blok->table[first]->empty = false;
			this->blok->table[first]->numb = (rand() % 9) == 8 ? 4 : 2;
			this->blok->table[first]->nr.setString(std::to_string(this->blok->table[first]->numb));
			search(0);
		}
	}
	else {
		next = rand() % 16;
		while (this->blok->table[next]->empty != false) {
			next = rand() % 16;
			if (this->blok->table[next]->empty == true) {
				this->blok->table[next]->empty = false;
				this->blok->table[next]->numb = (rand() % 9) == 8 ? 4 : 2;
				this->blok->table[next]->nr.setString(std::to_string(this->blok->table[next]->numb));
			}
		}
	}
}
void Game::draw(bool block) {
	if (block) {
		for (int i = 0; i < 16; i++) {
			if ((this->blok->table[i]->empty == false) && (this->blok->table[i]->numb >= 2)) {
				this->blok->table[i]->bloc.setPosition(this->blok->table[i]->posX, this->blok->table[i]->posY);
				this->blok->table[i]->nr.setPosition(this->blok->table[i]->posX + 20, this->blok->table[i]->posY + 20);

				window.draw(this->blok->table[i]->bloc);
				window.draw(this->blok->table[i]->nr);
			}
		}
	}
	else
		window.draw(this->pEnd);
}
void Game::moves() {
	if (move::isKeyPressed(move::Up)) {
		this->blok->pos("up");
		search(0);
	}
	if (move::isKeyPressed(move::Down)) {
		this->blok->pos("down");
		search(0);
	}
	if (move::isKeyPressed(move::Left)) {
		this->blok->pos("left");
		search(0);
	}
	if (move::isKeyPressed(move::Right)) {
		this->blok->pos("right");
		search(0);
	}
}
void Game::display(const sf::RenderWindow & window) {
	this->window.clear();
	this->draw(true);
	this->window.display();
}