#ifndef __WINDOW_CONTROLLER_H__
#define __WINDOW_CONTROLLER_H__

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

namespace InsanityEngine {
	typedef class WindowController* WindowControllerRef;

	class WindowController {
		public:
			WindowController(sf::RenderWindow &window);
			~WindowController();
			bool isActive();
			void update();
		private:
			sf::RenderWindow &currentWindow;
	};
}

#endif