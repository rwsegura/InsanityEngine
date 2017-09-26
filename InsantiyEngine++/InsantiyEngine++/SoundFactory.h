#ifndef __SOUND_FACTORY_CONTROLLER_H__
#define __SOUND_FACTORY_CONTROLLER_H__

#include <SFML\Audio.hpp>

#include "MusicSound.h"
#include "SoundController.h"

namespace InsanityEngine {

	class SoundFactory {
		public:
			static SoundControllerRef BuildSoundController();
			static MusicSound* BuildMusicFile(std::string filename);
	};

}

#endif