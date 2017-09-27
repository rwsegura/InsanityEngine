#include "MusicSound.h"
#include "SoundBase.h"

using namespace sf;
using namespace std;
using namespace InsanityEngine;

MusicSound::MusicSound(string filename) : MusicSound(filename, false) {

}

MusicSound::MusicSound(string filename, bool loop) : SoundBase(filename, 100.0f, 1.0f, loop) {
	music.openFromFile(filename);
	music.setVolume(this->volume);
	music.setPitch(this->pitch);
	music.setLoop(this->loop);
}

void MusicSound::play() {
	if (music.getStatus() != SoundSource::Status::Playing) {
		music.play();
	}
}

void MusicSound::pause() {
	if (music.getStatus() != SoundSource::Status::Paused) {
		music.pause();
	}
}

void MusicSound::stop() {
	if (music.getStatus() != SoundSource::Status::Stopped) {
		music.stop();
	}
}
