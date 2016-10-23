#include "Header.h"

	
int main()
{
	srand((unsigned)time(nullptr));

	Game game;
	game.runGame();
	
	while (game.okno.isOpen())
	{
		sf::Event event;
		while (game.okno.pollEvent(event)){
				if (event.type == sf::Event::Closed) {
					game.okno.close();
				}
				if (move::isKeyPressed(move::Left) || move::isKeyPressed(move::Right) ||
					move::isKeyPressed(move::Up) || move::isKeyPressed(move::Down)) {
					game.one->moves();
				}
				else if (game.endGame() == true) {
					game.okno.close();
					game.endokno.create(sf::VideoMode(200, 100), "KONIEC GRY", sf::Style::Default);
					game.endokno.setPosition(sf::Vector2i(100, 100));
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

