/**
* Camera.h
* Created By: Robert Segura Date: 9/30/2017
*/

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SFML\Graphics.hpp>

namespace InsanityEngine {
	class Camera {
		public:
			Camera(sf::View &view);
			~Camera();

			void applyView(sf::RenderWindow &window);

			bool isDirty();

			void move(float x, float y);
			void resize(int width, int height);

		private:
			bool view_needs_update;
			sf::View current_view;
	};
}

#endif
