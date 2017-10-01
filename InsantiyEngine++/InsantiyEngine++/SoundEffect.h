/**
* SoundEffect.h
* Created By: Robert Segura Date: 9/30/2017
*/

#ifndef __SOUND_EFFECT_H__
#define __SOUND_EFFECT_H__

#include <SFML\Audio.hpp>

#include "SoundBase.h"

namespace InsanityEngine {

	class SoundEffect : public SoundBase {
		public:
			SoundEffect(std::string filename);

			sf::SoundBuffer& getBuffer();

		private:
			sf::SoundBuffer buffer;
			
	};

}

#endif
