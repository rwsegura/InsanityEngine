#ifndef __ENGINE_FACTORY_H__
#define __ENGINE_FACTORY_H__

#include <rapidjson\document.h>

#include "ConfigurationData.h"
#include "InsanityEngine.h"

namespace InsanityEngine {

	class InsanityEngineFactory {
		public:
			static InsanityGameEngineRef CreateEngine(ConfigurationData &data);
			static ConfigurationData LoadConfigurationData(std::string filename);
		private:
			static rapidjson::Document OpenInputJsonFile(std::string filename);
	};

}

#endif