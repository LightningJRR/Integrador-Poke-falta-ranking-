#pragma once
#include "Character.h"
#include <vector>
using namespace System::Drawing;

class Pokeball : public Character {
private:
public:
	Pokeball():Character(width, height) {}
	Pokeball(int width, int height) : Character(width, height) {
		x = rand() % 400;
		y = rand() % 300;
		dx = dy = 2;
		idx = 0;
		idy = 0;
	}

	~Pokeball() {}

	Pokeball(int x, int y, int idx, int idy, int dx, int dy):Character(width, height) {
		this->x = x;
		this->y = y;
		this->idx = idx;
		this->idy = idy;
		this->dx = dx;
		this->dy = dy;
	}

	void move(Graphics^ g) {
		if (x + dx <0 || x + dx + width * 1.0 > g->VisibleClipBounds.Width) {
			dx *= -1;
		}
		x += dx;
		idx++;
		if (idx > 2)idx = 0;
	}
};

