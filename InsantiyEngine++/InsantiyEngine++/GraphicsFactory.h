#ifndef __GRAPHICS_FACTORY_H__
#define __GRAPHICS_FACTORY_H__

#include "DrawableGraphicsManager.h"
#include "GraphicsController.h"
#include "WindowController.h"

namespace InsanityEngine {
	class GraphicsFactory {
		public:
			static WindowControllerRef createWindowController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window);
			static DrawableGraphicsManagerRef createDrawableGraphicsManager(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window);
		private:
			static GraphicsControllerRef createGraphicsController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window);
			
	};
}

#endif
