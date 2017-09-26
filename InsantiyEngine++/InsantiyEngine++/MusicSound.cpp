#include "MusicSound.h"
#include "SoundBase.h"

using namespace sf;
using namespace std;
using namespace InsanityEngine;

MusicSound::MusicSound(string filename) : MusicSound(filename, false) {

}

MusicSound::MusicSound(string filename, bool loop) : SoundBase(filename, 100, 100, loop) {
	music.openFromFile(filename);
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
