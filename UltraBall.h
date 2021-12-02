#pragma once
#include "Character.h"
using namespace System::Drawing;

class UltraBall : public Character {

public:
	UltraBall():Character(width,height) {}
	UltraBall(int width, int height) : Character(width, height) {
		x = rand() % 400;
		y = 0;
		dx = dy = 3;
		idx = 0;
		idy = 0;
	}

	UltraBall(int x, int y, int idx, int idy, int dx, int dy) :Character(width, height) {
		this->x = x;
		this->y = y;
		this->idx = idx;
		this->idy = idy;
		this->dx = dx;
		this->dy = dy;
	}

	~UltraBall() {}


	void move(Graphics^ g) {
		if (x + dx <0 || x + dx + width * 1.0 > g->VisibleClipBounds.Width) {
			dx *= -1;
		}
		if (y + dy < 0 || y + dy + height * 1.0 > g->VisibleClipBounds.Height) {
			dy *= -1;
		}
		x += dx;
		y += dy;
		idx++;
		if (idx > 2)idx = 0;
	}
};


