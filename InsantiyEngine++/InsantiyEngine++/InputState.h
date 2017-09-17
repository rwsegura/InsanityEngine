#ifndef __INPUT_STATE_H__
#define __INPUT_STATE_H__

#include <map>
#include <SFML\Window.hpp>

namespace InsanityEngine {

	enum InputStatus {
		NONE = 0,
		PRESSED = 1,
	};

	typedef std::map<std::string, sf::Keyboard::Key> KeyMap;
	typedef std::map<std::string, InputStatus> InputStatusMap;

	class InputState {
		public:
			InputState(KeyMap &nameCodeMap);
			InputState(InputState &inputState);

			void updateWithMap(KeyMap &nameCodeMap);
			InputStatus getInputStatusForKey(std::string inputName);

		private:
			InputStatusMap map;
	};

}

#endif