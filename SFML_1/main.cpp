#include <cmath>
#include <iostream>
#include <cstdlib>
#include "Block.h"

/*
void show(std::vector <Block> * allBlocks) {
	for (auto i = allBlocks->begin(); i < allBlocks->end(); i++) {
		std::cout << "Polozenie: " << std::endl
			<< "\t Oœ X : " << i->posX
			<< "\t Oœ Y:" << i->posY << std::endl;
	}
}*/
int main()
{
	//okno fry
	sf::RenderWindow okno(sf::VideoMode(400, 400), "2048", sf::Style::Resize);

	//pojedynczy klocek Texture -- > tylko to rysowania obrazow
	sf::Texture textura;
	textura.loadFromFile("klocek.png");

	//Sprite obiekt obs³uguj¹cy zdarzenia na grafice
	sf::Sprite obraz;
	obraz.setTexture(textura);

	// tablica bloków
	int a = 0;
	Block* one = new Block;

	while (okno.isOpen())
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno.close();
		}

		if (event.type == sf::Event::KeyPressed) {
				one->randomCreate();				
				one->showAll(&okno);
		}		
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (obraz.getPosition().x != 300.0) {
				obraz.move(0.25, 0);
				obraz.setPosition(300, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (obraz.getPosition().x != 0.0) {
				obraz.move(-0.25, 0);
				obraz.setPosition(0, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (obraz.getPosition().y != 0.0) {
				obraz.move(0, -0.25);
				obraz.setPosition(0, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (obraz.getPosition().y != 300.0) {
				obraz.move(0, 0.25);
				obraz.setPosition(0, 300);
			}
		}	*/
		//okno.clear();
		for(auto i = one->allBlocks.begin();
				i < one->allBlocks.end();i++)
		obraz.setPosition(i->posX, i->posY);
		okno.draw(obraz);

		okno.display();

	} 
	return 0;
}