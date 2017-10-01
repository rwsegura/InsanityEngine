/**
* SoundBase.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include "SoundBase.h"

using namespace std;
using namespace InsanityEngine;

SoundBase::SoundBase(string filename, float volume, float pitch, bool loop) {
	this->filename = filename;
	this->volume = volume;
	this->pitch = pitch;
	this->loop = loop;
}

string SoundBase::getFilename() {
	return this->filename;
}

float SoundBase::getVolume() {
	return this->volume;
}

float SoundBase::getPitch() {
	return this->pitch;
}
