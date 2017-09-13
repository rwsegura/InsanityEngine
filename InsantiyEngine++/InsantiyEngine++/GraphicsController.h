#ifndef __GRAPHICS_CONTROLLER_H__
#define __GRAPHICS_CONTROLLER_H__

#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>

#include "Camera.h"
#include "IGraphicData.h"

namespace InsanityEngine {

	typedef class GraphicsController* GraphicsControllerRef;

	class GraphicsController {
		public:
			GraphicsController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window, sf::Color defaultClearColor);
			~GraphicsController();

			void refreshGraphicsScene();
			void renderGraphics(const std::vector<IGraphicsData *> &graphicsData);
		private:
			std::shared_ptr<Camera> camera;
			sf::Color defaultClearColor;
			std::shared_ptr<sf::RenderWindow> currentWindow;
	};
}

#endif