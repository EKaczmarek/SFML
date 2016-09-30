#include "Block.h"
#include <string>
#include <iostream>

Block::Block() {}
Block::Block(Block && _block) {

}
void Block::randomShow(sf::RenderWindow & _okno, sf::Sprite & _obraz, sf::Texture _textura) {

	this->posX = 300;// (rand() % 4 + 0) * 100;
	this->posY = 300;// (rand() % 4 + 0) * 100;
	//this->text.setString(std::to_string(rand() % 2 + 2));
	this->singleBlock = _obraz;
//	this->show();

	_obraz.setPosition(posX, posY);
	_okno.draw(_obraz);
	_okno.display();


}
void Block::show() {
	// jak zrobic zeby tutaj byla tablica i zeby przejechac przez nia ca³a for(this)
		std::cout << "Polozenie: " << std::endl << "/t Oœ X : " << this->posX << "/t Oœ Y:" << this->posY << std::endl;
}
Block::~Block()
{

}
