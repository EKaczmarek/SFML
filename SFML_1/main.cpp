#include "Header.h"

	
int main()
{
	srand((unsigned)time(nullptr));

	Game game;
	game.runGame();
	enum sf::Keyboard::{ Left, Right, Up} e 
	sf::Keyboard e;
	switch (e)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
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
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				for (int i = 0; i < 100000; i++);
				game.one->changePosRight();
				game.one->search(a);

			}
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				game.one->search(a);

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				game.one->search(a);

			}*/
		}
		game.okno.clear();
		game.draw();
		game.okno.display();
	}
	
	return 0;
}

