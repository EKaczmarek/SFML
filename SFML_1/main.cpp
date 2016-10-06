#include <cmath>
#include <iostream>
#include <cstdlib>
#include "Block.h"
#include "Font.hpp"


int main()
{
	//okno fry
	sf::RenderWindow okno(sf::VideoMode(400, 400), "2048", sf::Style::Titlebar && sf::Style::Default);

	//pojedynczy klocek Texture -- > tylko to rysowania obrazow
	sf::Texture textura;
	if (!textura.loadFromFile("klocek.png"))
		return EXIT_FAILURE;
	textura.loadFromFile("klocek.png");

	
	//stworzenie obiektu one klasy Block
	// w której wektor obiektów klasy Block
	Block* one = new Block;
	one->singleBlock.setTexture(textura);


	std::cout << "Rozmiar tablicy: " << one->allBlocks.size() << std::endl;
	one->search();

	while (okno.isOpen())
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno.close();
			}		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				for(auto i: one->allBlocks){
					if (i->posX != 300.0) {
						i->singleBlock.move(1, 1);
						i->singleBlock.setPosition(300, 0);
						okno.display();
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				for (auto i : one->allBlocks) {
					if (i->posX != 0.0) {
						one->singleBlock.move(-0.25, 0);
						one->singleBlock.setPosition(0, 0);
						okno.display();
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				for (auto i : one->allBlocks) {
					if (i->posY != 0.0) {
						one->singleBlock.move(0, -0.25);
						one->singleBlock.setPosition(0, 0);
						okno.display();
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				for (auto i : one->allBlocks) {
					if (i->posY != 300.0) {
						one->singleBlock.move(0, 0.25);
						one->singleBlock.setPosition(0, 300);
						okno.display();
					}
				}
			}

		sf::Font font;
		if (!font.loadFromFile("arial.ttf"))
			return EXIT_FAILURE;

		okno.clear(sf::Color::Black);
	
		sf::Text text;
		text.setFont(font);
		text.setString("H");
		text.setCharacterSize(100);
		text.setColor(sf::Color::Red);

		for (auto i = one->allBlocks.begin();
				i < one->allBlocks.end(); i++) {
				one->singleBlock.setPosition((*i)->posX, (*i)->posY);
				okno.draw(one->singleBlock);
				(*i)->text = text;
				(*i)->text.setPosition((*i)->posX+10, (*i)->posY-10);
				okno.draw((*i)->text);
			//	okno.draw(one->text);
			}
			//okno.draw(one->singleBlock);
		//	okno.draw(text);
			okno.display();

	}
	return 0;
}


/*if (event.type == sf::Event::KeyPressed) {
one->randomCreate(flag);
one->showAll(&okno);
}*/

/*for (auto i = one->allBlocks.begin();
i < one->allBlocks.end(); i++) {
flag = 0;
obraz.setPosition(i->posX, i->posY);
okno.draw(obraz);
okno.display();
}
}*/