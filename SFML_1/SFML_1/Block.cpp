#include "Header.h"
void Block::pos(std::string s) {
	if (s == "down") {
		this->moveDown();
		this->reduceDown();
		this->moveDown();
	}
	if (s == "up") {
		this->moveUp();
		this->reduceUp();
		this->moveUp();
	}
	if (s == "right") {
		this->moveRight();
		this->reduceRight();
		this->moveRight();
	}
	if (s == "left") {
		this->moveLeft();
		this->reduceLeft();
		this->moveLeft();
	}
}

void Block::moveUp() {
	int first;
	for (int j = 0; j < 4; j++) {
		first = -1;
		for (int i = 0; i <= 12; (i += 4)) {
			switch (i) {
			case 0: {
				if (this->table[i + j]->empty == true) {
					first = i + j;
				}
				else {
					break;
				}
				break;
			}
			case 4: {
				if (this->table[i + j]->empty == true) {
					if (first == -1)
						first = i + j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i + j, first);
					}
				}
				break;
			}
			case 8: {
				if (this->table[i + j]->empty == true) {
					if (first == -1)
						first = i + j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i + j, first);
					}
				}
				break;
			}
			case 12: {
				if (this->table[i + j]->empty == true) {
					if (first == -1)
						first = i + j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i + j, first);
					}
				}
				break;
			}
			}
		}
	}

}
void Block::moveDown() {
	int first;
	for (int j = 0; j < 4; j++) {
		first = -1;
		for (int i = 12; i >= 0; (i -= 4)) {
			switch (i) {
			case 12: {
				if (this->table[i + j]->empty == true) {
					first = i + j;
				}
				else {
					break;
				}
				break;
			}
			case 8: {
				if (this->table[i + j]->empty == true) {
					if (first == -1)
						first = i + j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i + j, first);
					}
				}
				break;
			}
			case 4: {
				if (this->table[i + j]->empty == true) {
					if (first == -1)
						first = i + j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i + j, first);
					}
				}
				break;
			}
			case 0: {
				if (this->table[i + j]->empty == true) {
					if (first == -1)
						first = i + j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i + j, first);
					}
				}
				break;
			}
			}
		}
	}
}
void Block::moveRight() {
	int first;
	for (int i = 3; i <= 15; (i += 4)) {
		first = -1;
		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 0: {
				if (this->table[i - j]->empty == true) {
					first = i - j;
				}
				else {
					break;
				}
				break;
			}
			case 1: {
				if (this->table[i - j]->empty == true) {
					if (first == -1)
						first = i - j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i - j, first);
					}
				}
				break;
			}
			case 2: {
				if (this->table[i - j]->empty == true) {
					if (first == -1)
						first = i - j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i - j, first);
					}
				}
				break;
			}
			case 3: {
				if (this->table[i - j]->empty == true) {
					if (first == -1)
						first = i - j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i - j, first);
					}
				}
				break;
			}
			}
		}
	}
}
void Block::moveLeft() {
	int first;
	for (int i = 0; i <= 12; (i += 4)) {
		first = -1;
		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 0: {
				if (this->table[i + j]->empty == true) {
					first = i + j;
				}
				else {
					break;
				}
				break;
			}
			case 1: {
				if (this->table[i + j]->empty == true) {
					if (first == -1)
						first = i + j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i + j, first);
					}
				}
				break;
			}
			case 2: {
				if (this->table[i + j]->empty == true) {
					if (first == -1)
						first = i + j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						moveto(first, i + j, first);
					}
				}
				break;
			}
			case 3: {
				if (this->table[i + j]->empty == true) {
					if (first == -1)
						first = i + j;
					else
						break;
				}
				else {
					if (first == -1)
						break;
					else {
						if (this->table[i + j - 2]->empty == false)
							moveto(first, i + j, first);
						else
							moveto(i + j - 2, i + j, first);

					}
				}
				break;
			}
			}
		}
	}
}

void Block::reduceUp() {
	int a = -1;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i <= 12; (i += 4)) {
			switch (i) {
			case 0: {
				if (this->table[i + j]->empty == false && this->table[i + j + 4]->empty == false) {
					if (this->table[i + j]->numb == this->table[i + j + 4]->numb) {
						reduce(i + j, i + j + 4);
						if (this->table[i + j + 8]->empty == false) {
							moveto(i + j + 4, i + j + 8, a);
							if (this->table[i + j + 12]->empty == false) {
								moveto(i + j + 8, i + j + 12, a);
								if (this->table[i + j + 4]->numb == this->table[i + j + 8]->numb) {
									reduce(i + j + 4, i + j + 8);
								}
							}
							else break;
						}
						else break;
					}
					else {
						if (this->table[i + j + 4]->numb == this->table[i + j + 8]->numb) {
							reduce(i + j + 4, i + j + 8);
							if (this->table[i + j + 12]->empty == false) {
								moveto(i + j + 8, i + j + 12, a);
							}
							else break;
						}
					}
				}
				break;
			}
			case 4: {
				if (this->table[i + j]->empty == false && this->table[i + j + 4]->empty == false) {
					if (this->table[i + j]->numb == this->table[i + j + 4]->numb) {
						reduce(i + j, i + j + 4);
						if (this->table[i + j + 8]->empty == false)
							moveto(i + j + 4, i + j + 8, a);
						else break;
					}
					else {
						if (this->table[i + j + 4]->empty == false && this->table[i + j + 8]->empty == false) {
							if (this->table[i + j + 4]->numb == this->table[i + j + 8]->numb) {
								reduce(i + j + 4, i + j + 8);
							}
							else break;
						}
						else break;
					}
				}
				else break;

				break;
			}
			}
		}
	}
}
void Block::reduceDown() {
	int a = -1;
	for (int j = 0; j < 4; j++) {
		for (int i = 12; i >= 0; (i -= 4)) {
			switch (i) {
			case 12: {
				if (this->table[i + j]->empty == false && this->table[i + j - 4]->empty == false) {
					if (this->table[i + j]->numb == this->table[i + j - 4]->numb) {
						reduce(i + j, i + j - 4);
						if (this->table[i + j - 8]->empty == false) {
							moveto(i + j - 4, i + j - 8, a);
							if (this->table[i + j - 12]->empty == false) {
								moveto(i + j - 8, i + j - 12, a);
								if (this->table[i + j - 4]->numb == this->table[i + j - 8]->numb) {
									reduce(i + j - 4, i + j - 8);
								}
							}
							else break;
						}
						else break;
					}
					else {
						if (this->table[i + j - 4]->numb == this->table[i + j - 8]->numb) {
							reduce(i + j - 4, i + j - 8);
							if (this->table[i + j - 12]->empty == false) {
								moveto(i + j - 8, i + j - 12, a);
							}
							else break;
						}
					}
				}
				break;
			}
			case 8: {
				if (this->table[i + j]->empty == false && this->table[i + j - 4]->empty == false) {
					if (this->table[i + j]->numb == this->table[i + j - 4]->numb) {
						reduce(i + j, i + j - 4);
						if (this->table[i + j - 8]->empty == false)
							moveto(i + j - 4, i + j - 8, a);
						else break;
					}
					else {
						if (this->table[i + j - 4]->empty == false && this->table[i + j - 8]->empty == false) {
							if (this->table[i + j - 4]->numb == this->table[i + j - 8]->numb) {
								reduce(i + j - 4, i + j - 8);
							}
							else break;
						}
						else break;
					}
				}
				else break;

				break;
			}
			}
		}
	}

}
void Block::reduceRight() {

	int a = -1;
	for (int i = 3; i <= 15; (i += 4)) {
		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 0: {
				if (this->table[i - j]->empty == false && this->table[i - j - 1]->empty == false) {
					if (this->table[i - j]->numb == this->table[i - j - 1]->numb) {
						reduce(i - j, i - j - 1);
						if (this->table[i - j - 2]->empty == false) {
							moveto(i - j - 1, i - j - 2, a);
							if (this->table[i - j - 3]->empty == false) {
								moveto(i - j - 2, i - j - 3, a);
								if (this->table[i - j - 1]->numb == this->table[i - j - 2]->numb) {
									reduce(i - j - 1, i - j - 2);
								}
							}
							else break;
						}
						else break;
					}
					else {
						if (this->table[i - j - 1]->numb == this->table[i - j - 2]->numb) {
							reduce(i - j - 1, i - j - 2);
							if (this->table[i - j - 3]->empty == false) {
								moveto(i - j - 2, i - j - 3, a);
							}
							else break;
						}
					}
				}
				break;
			}
			case 1: {
				if (this->table[i - j]->empty == false && this->table[i - j - 1]->empty == false) {
					if (this->table[i - j]->numb == this->table[i - j - 1]->numb) {
						reduce(i - j, i - j - 1);
						if (this->table[i - j - 2]->empty == false)
							moveto(i - j - 1, i - j - 2, a);
						else break;
					}
					else {
						if (this->table[i - j - 1]->empty == false && this->table[i - j - 2]->empty == false) {
							if (this->table[i - j - 1]->numb == this->table[i - j - 2]->numb) {
								reduce(i - j - 1, i - j - 2);
							}
							else break;
						}
						else break;
					}
				}
				else break;

				break;
			}
			}
		}
	}
}
void Block::reduceLeft() {
	int a = -1;
	for (int i = 0; i <= 12; (i += 4)) {
		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 3: {
				if (this->table[i + j]->empty == false && this->table[i + j - 1]->empty == false) {
					if (this->table[i + j]->numb == this->table[i + j - 1]->numb) {
						reduce(i + j, i + j - 1);
						if (this->table[i + j - 2]->empty == false) {
							moveto(i + j - 1, i + j - 2, a);
							if (this->table[i + j - 3]->empty == false) {
								moveto(i + j - 2, i + j - 3, a);
								if (this->table[i + j - 1]->numb == this->table[i + j - 2]->numb) {
									reduce(i + j - 1, i + j - 2);
								}
							}
							else break;
						}
						else break;
					}
					else {
						if (this->table[i + j - 1]->numb == this->table[i + j - 2]->numb) {
							reduce(i + j - 1, i + j - 2);
							if (this->table[i + j - 3]->empty == false) {
								moveto(i + j - 2, i + j - 3, a);
							}
							else break;
						}
					}
				}
				break;
			}
			case 1: {
				if (this->table[i + j]->empty == false && this->table[i + j - 1]->empty == false) {
					if (this->table[i + j]->numb == this->table[i + j - 1]->numb) {
						reduce(i + j, i + j - 1);
						if (this->table[i + j]->empty == false)
							moveto(i + j - 1, i + j, a);
						else break;
					}
					else {
						if (this->table[i + j + 1]->empty == false && this->table[i + j]->empty == false) {
							if (this->table[i + j + 1]->numb == this->table[i + j]->numb) {
								reduce(i + j, i + j + 1);
							}
							else break;
						}
						else break;
					}
				}
				else break;

				break;
			}
			}
		}
	}
}

void Block::moveto(int finalPos, int initPos, int & _first) {
	this->table[finalPos]->empty = false;
	this->table[initPos]->empty = true;

	this->table[finalPos]->numb = this->table[initPos]->numb;
	this->table[initPos]->numb = 0;

	this->table[finalPos]->nr.setString(std::to_string(this->table[finalPos]->numb));
	this->table[initPos]->nr.setString(std::to_string(this->table[initPos]->numb));
	if (_first != -1)
		_first = initPos;

}
void Block::reduce(int finalBlock, int initBlock) {
	this->table[finalBlock]->empty = false;
	this->table[initBlock]->empty = true;

	this->table[finalBlock]->numb *= 2;
	this->table[finalBlock]->nr.setString(std::to_string(this->table[finalBlock]->numb));

	this->table[initBlock]->numb = 0;
	this->table[initBlock]->nr.setString(std::to_string(this->table[initBlock]->numb));

}
bool Block::end() {
	int all = 0;
	bool zmiennaLR = true;
	bool zmiennaUD = true;

	//sprawdzenie czy nie ma takich samych prawo-lewo
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if ((this->table[(4 * i) + j]->numb == this->table[(4 * i) + j + 4]->numb)
				&& (this->table[(4 * i) + j]->empty == false)
				&& (this->table[(4 * i) + j + 4]->empty == false))
				zmiennaLR = false;
		}
	}
	//sprawdzenie czy nie ma takich samych góra-dó³
	for (int i = 0; i <= 12; (i += 4)) {
		for (int j = 0; j < 3; j++) {
			if ((this->table[i + j]->numb == this->table[i + j + 1]->numb)
				&& (this->table[i + j]->empty == false)
				&& (this->table[i + j + 1]->empty == false))
				zmiennaUD = false;
		}
	}
	//sprawdzenie czy wszystkie pola s¹ pe³na
	for (int i = 0; i < 16; i++) {
		if (this->table[i]->empty == false)
			all++;
	}

	if (all == 16 && zmiennaUD == true && zmiennaLR == true)
		return true; //tak koniec gry
	else
		return false;
}
bool Block::win() {
	bool win = false;
	for (auto i : this->table) {
		if (i->numb == 2048) {
			win = true;
		}
	}
	if (win) return true;
	else return false;
}