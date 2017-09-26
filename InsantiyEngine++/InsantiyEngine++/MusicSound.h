#ifndef __MUSIC_SOUND_CONTROLLER_H__
#define __MUSIC_SOUND_CONTROLLER_H__

#include <SFML\Audio.hpp>

#include "SoundBase.h"

namespace InsanityEngine {

	class MusicSound : public SoundBase {
		public:
			MusicSound(std::string filename);
			MusicSound(std::string filename, bool loop);

			virtual void play();
			virtual void pause();
			virtual void stop();

		private:
			sf::Music music;
	};

}

#endif