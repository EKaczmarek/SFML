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
			if (event.type == sf::Event::Closed){
				game.okno.close();
			}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					for (int i = 0; i < 100000; i++);
					game.one->changePosLeft();
					game.one->reduceLeft();
					game.one->changePosLeft();
					game.one->search();

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					for (int i = 0; i < 100000; i++);
					game.one->changePosRight();
					game.one->reduceRight();
					game.one->changePosRight();
					game.one->search();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					for (int i = 0; i < 100000; i++);
					game.one->changePosUp();
					game.one->reduceUp();
					game.one->changePosUp();
					game.one->search();

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					for (int i = 0; i < 100000; i++);
					game.one->changePosDown();
					game.one->reduceDown();
					game.one->changePosDown();
					game.one->search();

				}
				if (game.endGame() == true){
				game.endokno.create(sf::VideoMode(200, 200), "KONIEC GRY", sf::Style::Default);
				game.endokno.setPosition(sf::Vector2i(100, 100));

				game.end.loadFromFile("koniec.png");
				game.picEnd.setTexture(game.end);
				game.endokno.draw(game.picEnd);
				game.okno.close();
				
			}
		}
		game.okno.clear();
		game.draw();
		game.okno.display();


	}
	
	return 0;
}

