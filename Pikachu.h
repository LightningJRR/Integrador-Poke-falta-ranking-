#pragma once
#include "Character.h"
using namespace System::Drawing;

class Pikachu : public Character {
public:
	Pikachu() :Character(width, height) {}
	Pikachu(int width, int height) : Character(width, height) {
		x = rand()%321;
		y = 100;
		dx = dy = rand()%10+1;
		idx = 0;
		idy = 0;
	}

	Pikachu(int x, int y, int idx, int idy, int dx, int dy) : Character(width, height) {
		this->x=x;
		this->y=y;
		this->idx = idx;
		this->idy = idy;
		this->dx=dx;
		this->dy=dy;
	}

	~Pikachu() {}

	void move(Graphics^ g) {
		if (x + dx <0 || x + dx + width * 1.0 > g->VisibleClipBounds.Width) {
			idy = 1;
			dx *= -1;
		}
		if (y + dy < 0 || y + dy + height * 1.0 > g->VisibleClipBounds.Height) {
			idy = 3;
			dy *= -1;
		}
		x += dx;
		y += dy;
		idx++;
		if (idx > 3)idx = 0;
	}
};
