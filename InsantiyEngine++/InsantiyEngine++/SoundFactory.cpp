#include "MusicSound.h"
#include "SoundController.h"
#include "SoundEffect.h"
#include "SoundFactory.h"

using namespace std;
using namespace InsanityEngine;

SoundControllerRef SoundFactory::BuildSoundController() {
	return new SoundController();
}

MusicSound* SoundFactory::BuildMusicFile(string filename) {
	return new MusicSound(filename);
}

SoundEffect* SoundFactory::BuildSoundEffectFile(string filename) {
	return new SoundEffect(filename);
}
