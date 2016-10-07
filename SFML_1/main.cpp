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
			if (event.type == sf::Event::Closed)
				game.okno.close();
			}		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			for(auto i: game.one->allBlocks){
					if (i->posX == 300.0) {
						i->posX = 300;
						i->singleBlock.setPosition(i->posX, i->posY);
					}
					else if(i->posX == 200){
						///
					}
				}

			//one->search();

			}/*
			 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				for (auto i : one->allBlocks) {
					if (i->posX != 0.0) {
						//i->singleBlock.move(-0.25, 0);
						i->posX = 0;
						//i->singleBlock.setPosition(i->posX, i->posY);
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				for (auto i : one->allBlocks) {
					if (i->posY != 0.0) {
						one->search();
						//i->singleBlock.move(0, -0.25);
						i->posY = 0;
					//	i->singleBlock.setPosition(i->posX, i->posY);
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				one->search();
				for (auto i : one->allBlocks) {
					if (i->posY != 300.0) {
						one->search();
						//i->singleBlock.move(0, 0.25);
						i->posY = 300;
					//	i->singleBlock.setPosition(i->posX, i->posY);
					}
				}
			}		*/

		game.okno.clear(sf::Color::Red);

		for (auto i = game.one->allBlocks.begin();
			i < game.one->allBlocks.end(); i++) {
				game.draw(*i);
		}
		game.okno.display();

	}
	return 0;
}

