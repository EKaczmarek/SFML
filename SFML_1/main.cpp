#include "Header.h"

	
int main()
{
	srand((unsigned)time(nullptr));

	Game game;
	game.runGame();
	
	int a = 1;
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
				game.one->search(a);	
				game.one->reduceLeft();
				game.one->changePosLeft();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				for (int i = 0; i < 100000; i++);
				game.one->changePosRight();
				game.one->search(a);
				game.one->reduceRight();
				game.one->changePosRight();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				for (int i = 0; i < 100000; i++);
				game.one->changePosUp();
				game.one->search(a);
				game.one->reduceUp();
				game.one->changePosUp();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				for (int i = 0; i < 100000; i++);
				game.one->changePosDown();
				game.one->search(a);
				game.one->reduceDown();
				game.one->changePosDown();

			}
			if (game.endGame() == true){
				game.okno.close();

		//		game.okno.draw(game.picEnd);
			}
		}
		game.okno.clear();
		game.draw();
		game.okno.display();
	}
	
	return 0;
}

