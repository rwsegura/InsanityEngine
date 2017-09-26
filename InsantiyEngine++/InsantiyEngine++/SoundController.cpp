#include "MusicSound.h"
#include "SoundController.h"
#include "SoundFactory.h"

using namespace std;
using namespace InsanityEngine;

SoundController::SoundController() {
	this->current_music = nullptr;
}

SoundController::~SoundController() {
	delete this->current_music;
}

void SoundController::playMusic(string filename) {
	if (this->current_music == nullptr) {
		this->current_music = SoundFactory::BuildMusicFile(filename);
	} else if (filename != this->current_music->getFilename()) {
		delete this->current_music;
		this->current_music = SoundFactory::BuildMusicFile(filename);
	}

	this->current_music->play();
}

void SoundController::playSoundEffect(string filename) {

}