#include "SoundBase.h"

using namespace std;
using namespace InsanityEngine;

SoundBase::SoundBase(string filename, int volume, int pitch, bool loop) {
	this->filename = filename;
	this->volume = volume;
	this->pitch = pitch;
	this->loop = loop;
}

string SoundBase::getFilename() {
	return this->filename;
}
