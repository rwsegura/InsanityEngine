#ifndef __CONFIGURATION_DATA_H__
#define __CONFIGURATION_DATA_H__

#include <iostream>
#include <map>

namespace InsanityEngine {

	class ConfigurationData {
		public:
			// General Configuration
			std::string Title;
			
			// Resolution
			int ResolutionWidth;
			int ResolutionHeight;

			// Input Configuration
			std::map<std::string, std::string> KeyboardMap;

	};

}

#endif