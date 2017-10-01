/**
* SoundEffect.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include "SoundEffect.h"

using namespace sf;
using namespace std;
using namespace InsanityEngine;

SoundEffect::SoundEffect(string filename) : SoundBase(filename, 100.0f, 1.0f, false) {
	this->buffer.loadFromFile(this->filename);
}

sf::SoundBuffer& SoundEffect::getBuffer() {
	return this->buffer;
}
