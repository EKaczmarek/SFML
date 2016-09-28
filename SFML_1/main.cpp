#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{

	srand(time(NULL));

	float pozX, pozY = 0.0;
	//std::vector <float,float> currentPositions;

	sf::RenderWindow okno(sf::VideoMode(400, 400), "2048", sf::Style::Close);
	//pojedynczy klocek 
	sf::Texture textura;
	textura.loadFromFile("klocek.png");

	sf::Sprite obraz;
	obraz.setTexture(textura);


	while (okno.isOpen())
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno.close();
		}
		/*if (event.type == sf::Event::KeyPressed) {

			pozX = rand() % 4 + 0;
			pozY = rand() % 4 + 0;
			okno.draw(obraz);
			obraz.setPosition(pozX*100, pozY*100);

			currentPositions.emplace_back(pozX, pozY);
	}*/

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (obraz.getPosition().x != 300.0)
				obraz.move(0.25, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (obraz.getPosition().x != 0.0)
				obraz.move(-0.25, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (obraz.getPosition().y != 0.0)
				obraz.move(0, -0.25);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (obraz.getPosition().y != 300.0)
				obraz.move(0, 0.25);
		}
	

		okno.clear(sf::Color::Green);
		okno.draw(obraz);
		okno.display();

	} 
	return 0;
}