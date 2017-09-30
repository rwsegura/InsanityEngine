#ifndef __INPUT_FACTORY_H__
#define __INPUT_FACTORY_H__

#include "ConfigurationData.h"
#include "InputController.h"
#include "InputState.h"

namespace InsanityEngine {

	class InputFactory {
		public:
			static InputControllerRef createInputController(std::shared_ptr<sf::RenderWindow> window, ConfigurationData &data);

		private:
			// Creates a Character -> sf::Key mapping
			static KeyMap CreateMap();
			static MouseMap CreateMouseMap();
	};

}

#endif