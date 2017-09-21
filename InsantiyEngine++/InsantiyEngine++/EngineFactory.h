#ifndef __ENGINE_FACTORY_H__
#define __ENGINE_FACTORY_H__

#include <rapidjson\document.h>

#include "ConfigurationData.h"
#include "InsanityEngine.h"

namespace InsanityEngine {

	class InsanityEngineFactory {
		public:
			static InsanityGameEngineRef createEngine(std::string filename);
		private:
			static rapidjson::Document openInputJsonFile(std::string filename);
			static ConfigurationData loadConfigurationData(std::string filename);
	};

}

#endif