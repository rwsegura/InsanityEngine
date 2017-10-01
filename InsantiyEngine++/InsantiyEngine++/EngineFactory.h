#ifndef __ENGINE_FACTORY_H__
#define __ENGINE_FACTORY_H__

#include <rapidjson\document.h>

#include "ConfigurationData.h"
#include "InsanityEngine.h"

namespace InsanityEngine {

	class InsanityEngineFactory {
		public:
			static InsanityGameEngineRef CreateEngine(std::string filename);
		private:
			static rapidjson::Document OpenInputJsonFile(std::string filename);
			static ConfigurationData LoadConfigurationData(std::string filename);
	};

}

#endif