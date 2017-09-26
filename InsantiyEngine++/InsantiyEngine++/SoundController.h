#ifndef __SOUND_CONTROLLER_H__
#define __SOUND_CONTROLLER_H__

#include <SFML\Audio.hpp>

#include "MusicSound.h"

namespace InsanityEngine {

	typedef class SoundController* SoundControllerRef;

	class SoundController {
		public:
			SoundController();
			~SoundController();

			void playSoundEffect(std::string filename);
			void playMusic(std::string filename);

		private:
			bool is_muted;
			MusicSound *current_music;
	};

}

#endif