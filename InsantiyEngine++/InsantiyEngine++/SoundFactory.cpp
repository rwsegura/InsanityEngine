#include "MusicSound.h"
#include "SoundController.h"
#include "SoundFactory.h"

using namespace std;
using namespace InsanityEngine;

SoundControllerRef SoundFactory::BuildSoundController() {
	return new SoundController();
}

MusicSound* SoundFactory::BuildMusicFile(string filename) {
	return new MusicSound(filename);
}
