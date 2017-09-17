#ifndef __INPUT_CONTROLLER_H__
#define __INPUT_CONTROLLER_H__

#include <map>
#include <SFML\Window.hpp>

#include "InputState.h"

namespace InsanityEngine {

	typedef std::map<std::string, sf::Keyboard::Key> KeyMap;
	typedef class InputController* InputControllerRef;

	class InputController {
		public:
			// Constructor
			InputController(KeyMap nameToKeyCodeMap);
			~InputController();

			// Input Control Methods
			bool isKeyHeld(std::string KeyName);
			bool isKeyPressed(std::string KeyName);
			bool isKeyReleased(std::string KeyName);

			// LifeCycle Methods
			void udpateInputState();

		private:
			KeyMap name_code_map;
			InputState current_state;
			InputState previous_state;
	};

}

#endif
