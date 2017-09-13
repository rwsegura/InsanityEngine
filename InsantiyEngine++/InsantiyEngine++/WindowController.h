#ifndef __WINDOW_CONTROLLER_H__
#define __WINDOW_CONTROLLER_H__

#include <memory>

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Camera.h"

namespace InsanityEngine {
	typedef class WindowController* WindowControllerRef;

	class WindowController {
		public:
			WindowController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window);
			~WindowController();
			bool isActive();
			void update();
		private:
			std::shared_ptr<Camera> camera;
			std::shared_ptr<sf::RenderWindow> currentWindow;
	};
}

#endif