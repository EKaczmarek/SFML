#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class Game {
public:
	sf::RenderWindow okno;
	sf::Texture textura;

	//obiekty do zasygnalizoowania konca gry
	sf::RenderWindow endokno;
	sf::Texture end;
	sf::Sprite picEnd;

	//obiekty do wygrania gry
	sf::RenderWindow winokno;
	sf::Texture wint;
	sf::Sprite picWin;

	sf::Font font;
	sf::Text text;
	Block* one;

	Game() {}
	void runGame();

	//okno: rozmiar, tytu³
	void Window();
	//czcionka do bloków
	void Font();
	//obiekt przechowujacy tablice
	void object();

	//wyswietlanie tablicy pod warunkiem niepustej flagi
	void draw(int = 1);

	//koniec
	bool endGame();
	//wygrana
	bool win();

	void oknoOpt(int state);


	~Game();
};