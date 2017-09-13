#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SFML\Graphics.hpp>

namespace InsanityEngine {
	class Camera {
		public:
			Camera(sf::View &view);
			~Camera();

			void ApplyView(sf::RenderWindow &window);

			bool IsDirty();

			void Move(float x, float y);
			void Resize(int width, int height);

		private:
			bool view_needs_update;
			sf::View current_view;
	};
}

#endif
