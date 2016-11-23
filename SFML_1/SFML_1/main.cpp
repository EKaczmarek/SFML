#include "Header.h"

int main() {
	srand((unsigned)time(NULL));

	Game game;
	game.run();

	game.flagEnd = 0;
	game.flagWin = 0;

	while (game.window.isOpen() || game.windowEnd.isOpen() || game.windowEnd.isOpen()) {
		sf::Event event;
		while (game.window.pollEvent(event)) {
			if (event.type = sf::Event::Closed)
				game.window.close();

			if (game.blok->end() == false) {
				game.moves();
				game.display(game.window);
			}
			else {
				if (game.blok->end() == true) {
					if (game.flagEnd == 0) {
						game.windEnd();
						game.flagEnd = 1;
					}
					else 
						game.display(game.windowEnd);
				}
				else {
					if (game.flagWin == 0) {
						game.windWin();
						game.flagWin = 1;
					}
					game.display(game.windowWin);
				}
			}
		}
	}



	return 0;
}

