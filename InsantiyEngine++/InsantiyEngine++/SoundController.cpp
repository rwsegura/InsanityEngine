/**
* SoundController.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include <list>
#include <SFML\Audio.hpp>

#include "MusicSound.h"
#include "SoundController.h"
#include "SoundFactory.h"

using namespace sf;
using namespace std;
using namespace InsanityEngine;

SoundController::SoundController() {
	this->current_music = nullptr;
}

SoundController::~SoundController() {
	this->clearSoundData();
}

void SoundController::clearSoundData() {
	for (Sound* sound : this->sound_list) {
		sound->stop();
		delete sound;
	}

	for (auto sound_data : this->sfx_map) {
		delete sound_data.second;
	}

	this->sfx_map.clear();
	this->current_music->stop();
	delete this->current_music;
}

void SoundController::cleanSoundEffectList() {
	list<Sound*> delete_list;
	for (Sound* sound : this->sound_list) {
		if (sound->getStatus() != SoundSource::Status::Playing) {
			delete_list.push_back(sound);
		}
	}

	for (Sound* sound : delete_list) {
		this->sound_list.remove(sound);
		delete sound;
	}
}

SoundEffect* SoundController::_getSoundEffect(string filename) {
	SoundEffect* sound_effect = this->sfx_map[filename];

	if (sound_effect == nullptr) {
		sound_effect = SoundFactory::BuildSoundEffectFile(filename);
		this->sfx_map[filename] = sound_effect;
	}

	return sound_effect;
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
	if (this->sound_list.size() == SoundController::MAX_SFX_SOUNDS) return;

	SoundEffect* sfx = this->_getSoundEffect(filename);

	Sound* sound = new Sound(sfx->getBuffer());
	sound->setVolume(sfx->getVolume());
	sound->setPitch(sfx->getPitch());
	sound->play();

	sound_list.push_back(sound);
}
