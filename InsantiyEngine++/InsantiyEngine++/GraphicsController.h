#ifndef __GRAPHICS_CONTROLLER_H__
#define __GRAPHICS_CONTROLLER_H__

#include <vector>
#include <SFML\Graphics.hpp>
#include "IGraphicData.h"

namespace InsanityEngine {

	typedef class GraphicsController* GraphicsControllerRef;

	class GraphicsController {
		public:
			GraphicsController(sf::RenderWindow &window, sf::Color defaultClearColor);
			~GraphicsController();
			void renderGraphics(const std::vector<IGraphicsData *> &graphicsData);
		private:
			sf::Color defaultClearColor;
			sf::RenderWindow &currentWindow;
	};
}

#endif