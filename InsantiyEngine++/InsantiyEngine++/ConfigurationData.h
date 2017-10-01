#ifndef __CONFIGURATION_DATA_H__
#define __CONFIGURATION_DATA_H__

#include <iostream>
#include <map>

namespace InsanityEngine {

	class ConfigurationData {
		public:
			// General Configuration
			std::string title;
			
			// Resolution
			int resolutionWidth;
			int resolutionHeight;

			// Input Configuration
			std::map<std::string, std::string> keyboardMap;
			std::map<std::string, std::string> mouseMap;

	};

}

#endif