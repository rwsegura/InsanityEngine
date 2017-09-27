#ifndef __SOUND_CONTROLLER_H__
#define __SOUND_CONTROLLER_H__

#include <map>
#include <list>
#include <SFML\Audio.hpp>

#include "MusicSound.h"
#include "SoundEffect.h"

namespace InsanityEngine {

	typedef class SoundController* SoundControllerRef;

	class SoundController {
		public:
			SoundController();
			~SoundController();

			void playSoundEffect(std::string filename);
			void playMusic(std::string filename);
			
			void clearSoundData();
			void cleanSoundEffectList();

		private:
			bool is_muted;
			std::map<std::string, SoundEffect*> sfx_map;

			MusicSound *current_music;
			std::list<sf::Sound*> sound_list;

			SoundEffect* getSoundEffect(std::string filename);

			static const int MAX_SFX_SOUNDS = 200;
	};

}

#endif