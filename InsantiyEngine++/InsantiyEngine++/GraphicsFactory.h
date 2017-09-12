#ifndef __GRAPHICS_FACTORY_H__
#define __GRAPHICS_FACTORY_H__

#include "GraphicsController.h"
#include "DrawableGraphicsManager.h"

namespace InsanityEngine {
	class GraphicsFactory {
		public:
			static DrawableGraphicsManagerRef createDrawableGraphicsManager(sf::RenderWindow &window);
		private:
			static GraphicsControllerRef createGraphicsController(sf::RenderWindow &window);
	};
}

#endif
