#include "Block.h"
#include <string>
#include <iostream>

Block::Block(int _posX, int _posY, sf::Text _text, sf::Sprite _singleBlock) {
	this->posX = _posX;
	this->posY = _posY;
	this->text = _text;
	this->singleBlock = _singleBlock;
}
void Block::randomShow(sf::RenderWindow & _okno, sf::Sprite & _obraz, sf::Texture _textura, int _flag) {

	std::vector<Block> blocks; //I need to considder where this vector should be created 

	this->posX = 300;// (rand() % 4 + 0) * 100;
	this->posY = 300;// (rand() % 4 + 0) * 100;
	//this->text.setString(std::to_string(rand() % 2 + 2)) = "2";
	this->singleBlock = _obraz;
//	this->show();

	//blocks.emplace_back(300,300,2,_obraz);

	_obraz.setPosition(posX, posY);
	_okno.draw(_obraz);
	_okno.display();


}
void Block::show() {
	// how to obtain availability of vector here
		std::cout << "Polozenie: " << std::endl << "/t Oœ X : " << this->posX << "/t Oœ Y:" << this->posY << std::endl;
}
Block::~Block()
{

}
