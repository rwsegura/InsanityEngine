#ifndef __ENGINE_FACTORY_H__
#define __ENGINE_FACTORY_H__

#include "InsanityEngine.h"

namespace InsanityEngine {

	class InsanityEngineFactory {
		public:
			static InsanityGameEngineRef createEngine();
	};

}

#endif