/**
* SoundController.h
* Created By: Robert Segura Date: 9/30/2017
*/

#ifndef __SOUND_CONTROLLER_H__
#define __SOUND_CONTROLLER_H__

#include <map>
#include <list>
#include <SFML\Audio.hpp>

/**
* SoundController.h
* Created By: Robert Segura Date: 9/30/2017
*/

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
			MusicSound *current_music;
			std::map<std::string, SoundEffect*> sfx_map;
			std::list<sf::Sound*> sound_list;

			SoundEffect* _getSoundEffect(std::string filename);

			static const int MAX_SFX_SOUNDS = 200;
	};

}

#endif