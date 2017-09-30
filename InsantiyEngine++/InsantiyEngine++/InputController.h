#ifndef __INPUT_CONTROLLER_H__
#define __INPUT_CONTROLLER_H__

#include <map>
#include <memory>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "InputState.h"
#include "Vector2.h"

namespace InsanityEngine {

	typedef class InputController* InputControllerRef;

	class InputController {
		public:
			// Constructor
			InputController(std::shared_ptr<sf::RenderWindow> window, KeyMap nameToKeyCodeMap, MouseMap nameToButtonCodeMap);
			~InputController();

			// Input Control Methods
			bool isKeyHeld(std::string KeyName);
			bool isKeyPressed(std::string KeyName);
			bool isKeyReleased(std::string KeyName);

			// Mouse Position Methods
			RedStd::Vec2i getCurrentMousePosition();

			// LifeCycle Methods
			void udpateInputState();

		private:
			KeyMap name_code_map;
			MouseMap name_moude_map;
			InputState current_state;
			InputState previous_state;
			std::shared_ptr<sf::RenderWindow> current_window;
	};

}

#endif
