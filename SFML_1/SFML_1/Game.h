#pragma once

class Game {
public:
	Block* blok;

	sf::RenderWindow window;
	sf::Texture pictBlock;
	sf::Font fon;

	sf::RenderWindow windowEnd;
	sf::Texture pictEnd;
	sf::Sprite pEnd;

	sf::RenderWindow windowWin;
	sf::Texture pictWin;
	sf::Sprite pWin;
	int flagEnd, flagWin;
	bool isMove;
	//odpalenie gry
	void run();
	//otwarcie okna
	void wind();
	//otwarcie okna konca
	void windEnd();
	//otwarcie okna wygranej
	void windWin();
	//za³adowanie czcionki
	void font();
	//za³adowanie obrazków
	void pict();
	//wype³nienie tablicy
	void fullTab();
	//wyszukanie pozycji
	void search(int a);
	//wyswietlanie
	void draw(bool block);
	//ruchy
	void moves();
	//wyswietlanie okna
	void display(const sf::RenderWindow & window);

};