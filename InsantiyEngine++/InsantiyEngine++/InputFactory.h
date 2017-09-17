#ifndef __INPUT_FACTORY_H__
#define __INPUT_FACTORY_H__

#include <rapidjson\document.h>

#include "InputController.h"

namespace InsanityEngine {

	class InputFactory {
		public:
			static InputControllerRef createInputController(std::string inputFilename);

		private:
			static rapidjson::Document openInputJsonFile(std::string filename);

			// Creates a Character -> sf::Key mapping
			static KeyMap create_map();
	};

}

#endif