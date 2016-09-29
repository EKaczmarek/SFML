#include "Block.h"
#include <string>


void Block::randomShow(sf::RenderWindow & _okno, sf::Sprite & _obraz, sf::Texture _textura) {

	this->posX = (rand() % 4 + 0) * 100;
	this->posY = (rand() % 4 + 0) * 100;
	//this->text.setString(std::to_string(rand() % 2 + 2));
	this->singleBlock = _obraz;

	//this->singleBlock.setPosition(this->posX, this->posY);

	_obraz.setPosition(posX, posY);
	//_okno.clear(sf::Color::Green);
	_okno.draw(_obraz);
	_okno.display();

	//currentPositions.emplace_back(pozX, pozY);*/
}
Block::~Block()
{

}
