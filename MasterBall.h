#pragma once
#include "Character.h"
#include "Pikachu.h"
#include <vector>
using namespace System::Drawing;
using namespace std;
class MasterBall: public Character {
private:
	int contChoque;
public:
	MasterBall() :Character(width, height) {}
	MasterBall(int width, int height) : Character(width, height) {
		x = rand() % 400;
		y = 0;
		dx = dy = 4;
		idx = 0;
		idy = 0;
		contChoque = 0;
	}

	MasterBall(int x, int y, int idx, int idy, int dx, int dy) :Character(width, height) {
		this->x = x;
		this->y = y;
		this->idx = idx;
		this->idy = idy;
		this->dx = dx;
		this->dy = dy;
	}

	~MasterBall() {}

	int getContChoque(){
		return contChoque;
	}


	void move(Graphics^ g, vector<Pikachu*>pika) {
		if (x + dx <0 || x + dx + width * 1.0 > g->VisibleClipBounds.Width) {
				dx *= -1;
				contChoque++;
		}
		if (y + dy < 0 || y + dy + height * 1.0 > g->VisibleClipBounds.Height) {
				dy *= -1;
				contChoque++;
		}
		x += dx;
		y += dy;
		if (contChoque > 3) contChoque = 0;
		idx++;
		if (idx > 2)idx = 0;
	}
};



