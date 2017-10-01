/**
* SoundFactory.h
* Created By: Robert Segura Date: 9/30/2017
*/

#ifndef __SOUND_FACTORY_CONTROLLER_H__
#define __SOUND_FACTORY_CONTROLLER_H__

#include <SFML\Audio.hpp>

#include "MusicSound.h"
#include "SoundController.h"
#include "SoundEffect.h"

namespace InsanityEngine {

	class SoundFactory {
		public:
			static SoundControllerRef BuildSoundController();
			static MusicSound* BuildMusicFile(std::string filename);
			static SoundEffect* BuildSoundEffectFile(std::string filename);
	};

}

#endif