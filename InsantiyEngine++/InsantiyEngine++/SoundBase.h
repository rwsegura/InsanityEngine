/**
* SoundBase.h
* Created By: Robert Segura Date: 9/30/2017
*/

#ifndef __SOUND_BASE_CONTROLLER_H__
#define __SOUND_BASE_CONTROLLER_H__

#include <SFML\Audio.hpp>

namespace InsanityEngine {

	class SoundBase {
		public:
			SoundBase(std::string filename, float volume, float pitch, bool loop);

			std::string getFilename();
			float getVolume();
			float getPitch();

		protected:
			bool loop;
			float volume, pitch;
			std::string filename;
	};

}

#endif