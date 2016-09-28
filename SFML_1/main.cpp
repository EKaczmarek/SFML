#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
int main()
{
	sf::RenderWindow okno(sf::VideoMode(400, 400), "2048", sf::Style::Close);
	sf::Clock stoper;

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if(obraz.getPosition().x != 300.0)
					obraz.move(100, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (obraz.getPosition().x != 0.0)
					obraz.move(-100, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (obraz.getPosition().y != 0.0)
					obraz.move(0, -100);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (obraz.getPosition().y != 300.0)
					obraz.move(0, 100);
			}
		}
		okno.clear(sf::Color::Green);
		okno.draw(obraz);
		okno.display();

	} 
	return 0;
}