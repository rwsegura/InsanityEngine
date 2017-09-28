#include "Rect.h"

using namespace RedStd;

Rect::Rect(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

bool Rect::Interescts(Rect &rect) {
	// TODO: Later for collision
	return false;
}
