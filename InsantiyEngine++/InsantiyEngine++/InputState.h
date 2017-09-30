#ifndef __INPUT_STATE_H__
#define __INPUT_STATE_H__

#include <map>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Vector2.h"

namespace InsanityEngine {

	enum InputStatus {
		NONE = 0,
		PRESSED = 1,
	};

	typedef std::map<std::string, sf::Mouse::Button> MouseMap;
	typedef std::map<std::string, sf::Keyboard::Key> KeyMap;
	typedef std::map<std::string, InputStatus> InputStatusMap;

	class InputState {
		public:
			InputState(KeyMap &nameCodeMap);
			InputState(InputState &inputState);

			void updateWithMap(sf::RenderWindow &window, KeyMap &nameCodeMap, MouseMap &nameMouseMap);
			InputStatus getInputStatusForKey(std::string inputName);
			RedStd::Vec2i getMousePosition();

		private:
			InputStatusMap map;
			RedStd::Vec2i mouse_position;
	};

}

#endif