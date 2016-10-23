#include "Header.h"

	
int main()
{
	srand((unsigned)time(nullptr));

	Game game;
	game.runGame();
	
	while (game.okno.isOpen())
	{
		sf::Event event;
		while (game.okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				game.okno.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				game.one->posLR("left");
				game.one->reduceLeft();
				game.one->posLR("left");
				game.one->search();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				game.one->posLR("right");
				game.one->reduceRight();
				game.one->posLR("right");
				game.one->search();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				game.one->changePosUp();
				game.one->reduceUp();
				game.one->changePosUp();
				game.one->search();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				game.one->changePosDown();
				game.one->reduceDown();
				game.one->changePosDown();
				game.one->search();

			}
			else if (game.endGame() == true) {
				game.okno.close();
				game.endokno.create(sf::VideoMode(200, 100), "KONIEC GRY", sf::Style::Default);
				game.endokno.setPosition(sf::Vector2i(100, 100));

			}

			game.okno.clear();
			game.draw();
			game.okno.display();
		}
	}
	while (game.endokno.isOpen()) {
		game.picEnd.setTexture(game.end);
					game.endokno.clear();
					game.endokno.draw(game.picEnd);
					game.endokno.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				game.endokno.close();
	} 

	return 0;
}

