#include <cmath>
#include <iostream>
#include <cstdlib>
#include "Block.h"

int main()
{
	//okno fry
	sf::RenderWindow okno(sf::VideoMode(400, 400), "2048", sf::Style::Default);

	//pojedynczy klocek Texture -- > tylko to rysowania obrazow
	sf::Texture textura;
	textura.loadFromFile("klocek.png");

	//Sprite obiekt obs³uguj¹cy zdarzenia na grafice
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
		if (event.type == sf::Event::KeyPressed) {
			Block *one = new Block();
			one->randomShow(okno, obraz, textura);
		}		
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
	
		obraz.setPosition(0, 100.0);
		okno.draw(obraz);
		okno.display();

	} 
	return 0;
}