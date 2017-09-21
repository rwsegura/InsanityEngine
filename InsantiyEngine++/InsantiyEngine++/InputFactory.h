#ifndef __INPUT_FACTORY_H__
#define __INPUT_FACTORY_H__

#include "ConfigurationData.h"
#include "InputController.h"

namespace InsanityEngine {

	class InputFactory {
		public:
			static InputControllerRef createInputController(ConfigurationData &data);

		private:
			// Creates a Character -> sf::Key mapping
			static KeyMap create_map();
	};

}

#endif