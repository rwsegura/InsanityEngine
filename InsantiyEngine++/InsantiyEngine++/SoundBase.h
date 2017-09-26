#ifndef __SOUND_BASE_CONTROLLER_H__
#define __SOUND_BASE_CONTROLLER_H__

#include <SFML\Audio.hpp>

namespace InsanityEngine {

	class SoundBase {
		public:
			SoundBase(std::string filename, int volume, int pitch, bool loop);

			std::string getFilename();

			// Abstract Methods
			virtual void play() = 0;
			virtual void pause() = 0;
			virtual void stop() = 0;

		protected:
			bool loop;
			int volume, pitch;
			std::string filename;
	};

}

#endif