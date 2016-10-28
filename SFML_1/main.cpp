#include "Header.h"

	
int main()
{
	srand((unsigned)time(nullptr));

	Game game;
	game.runGame();

	while (game.okno.isOpen())
	{
		sf::Event event;
		while (game.okno.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				game.okno.close();
			}
			while(game.endGame() == false) {
				//check method reduceUD, wigglewiglleUD
				game.one->moves();		
				break;
			}
			if (game.endGame() == true) {
				std::cout << "Koniec gry" << std::endl;
				//game.okno.close();
				game.endokno.create(sf::VideoMode(200, 100), "KONIEC GRY", sf::Style::Default);
				game.endokno.setPosition(sf::Vector2i(100, 100));
			}
			else if (game.win() == true) {
				std::cout << "Wygrana" << std::endl;
				//game.okno.close();
				game.winokno.create(sf::VideoMode(200, 100), "Wygrana", sf::Style::Default);
				game.winokno.setPosition(sf::Vector2i(100, 100));
			}
			game.oknoOpt(1);
		}
	}
	while (game.endokno.isOpen()) {
		game.picEnd.setTexture(game.end);
		game.oknoOpt(0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			game.endokno.close();
	}
	return 0;
}

