#include "Header.h"

int main() {
	srand((unsigned)time(NULL));

	Game game;
	game.run();


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
					game.display(game.windowEnd);
				}
				else {
					game.display(game.windowWin);

				}
			}
		}
	}



	return 0;
}

