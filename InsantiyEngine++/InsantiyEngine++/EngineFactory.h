#ifndef __ENGINE_FACTORY_H__
#define __ENGINE_FACTORY_H__

#include "GraphicsController.h"
#include "InsanityEngine.h"
#include "SceneGraphManager.h"
#include "WindowController.h"

namespace InsanityEngine {

	class InsanityEngineFactory {
		public:
			static InsanityGameEngineRef createEngine(sf::RenderWindow &window);
		private:
			static SceneGraphManagerRef createSceneGraphManager(GraphicsControllerRef graphicController);
			static GraphicsControllerRef createGraphicsController(sf::RenderWindow &window);
			static WindowControllerRef createWindowController(sf::RenderWindow &window);
	};

}

#endif