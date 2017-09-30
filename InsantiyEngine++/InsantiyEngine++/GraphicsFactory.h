/**
* GraphicsFactory.h
* Created By: Robert Segura Date: 9/30/2017
*/


#ifndef __GRAPHICS_FACTORY_H__
#define __GRAPHICS_FACTORY_H__

#include "DrawableGraphicsManager.h"
#include "GraphicsController.h"
#include "WindowController.h"

namespace InsanityEngine {

	class GraphicsFactory {
		public:
			static WindowControllerRef CreateWindowController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window);
			static DrawableGraphicsManagerRef CreateDrawableGraphicsManager(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window);
		private:
			static GraphicsControllerRef CreateGraphicsController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window);
			
	};
}

#endif
