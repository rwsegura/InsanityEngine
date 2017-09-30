/**
* IDrawable.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#ifndef __I_DRAWABLE_H__
#define __I_DRAWABLE_H__

#include <string>

#include "Vector2.h"
#include "Rect.h"

namespace InsanityEngine {

	class IDrawable {
		public:
			// Positional Data
			virtual RedStd::Vec2f position() = 0;
			virtual RedStd::Vec2f rotation() = 0;
			virtual RedStd::Vec2f scale() = 0;

			// Texture Data
			virtual std::string textureKey() = 0;
			virtual RedStd::Rect textureFrame() = 0;
	};

	class TestDrawable : public IDrawable {
		public:
			TestDrawable(float x, float y) {
				this->x = x;
				this->y = y;
			}

			virtual RedStd::Vec2f position() {
				return RedStd::Vec2f(x, y);
			}

			virtual RedStd::Vec2f rotation() {
				return RedStd::Vec2f(0.0f, 0.0f);
			}

			virtual RedStd::Vec2f scale() {
				return RedStd::Vec2f(1.0f, 1.0f);
			}

			virtual RedStd::Rect textureFrame() {
				return RedStd::Rect(30, 0, 40, 40);
			}

			virtual std::string textureKey() {
				return "Test.png";
			}

		private:
			float x, y;
	};

}
#endif