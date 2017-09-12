#ifndef __ENGINE_FACTORY_H__
#define __ENGINE_FACTORY_H__

#include "GraphicsController.h"
#include "InsanityEngine.h"
#include "DrawableGraphicsManager.h"
#include "WindowController.h"

namespace InsanityEngine {

	class InsanityEngineFactory {
		public:
			static InsanityGameEngineRef createEngine(sf::RenderWindow &window);
		private:
			
			static WindowControllerRef createWindowController(sf::RenderWindow &window);
	};

}

#endif