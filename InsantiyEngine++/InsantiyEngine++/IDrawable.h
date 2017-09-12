#ifndef __I_DRAWABLE_H__
#define __I_DRAWABLE_H__

#include <string>

#include "Vector2.h"

namespace InsanityEngine {

	class IDrawable {
		public:
			// Positional Data
			virtual RedStd::Vec2f Position() = 0;
			virtual RedStd::Vec2f Rotation() = 0;
			virtual RedStd::Vec2f Scale() = 0;

			// Texture Data
			virtual std::string TextureKey() = 0;
			virtual RedStd::Vec2f TextureFrame() = 0;
	};

	class TestDrawable : public IDrawable {
		public:
			virtual RedStd::Vec2f Position() {
				return RedStd::Vec2f(0.0f, 0.0f);
			}

			virtual RedStd::Vec2f Rotation() {
				return RedStd::Vec2f(0.0f, 0.0f);
			}

			virtual RedStd::Vec2f Scale() {
				return RedStd::Vec2f(1.0f, 1.0f);
			}

			virtual RedStd::Vec2f TextureFrame() {
				return RedStd::Vec2f(1.0f, 1.0f);
			}

			virtual std::string TextureKey() {
				return "Test";
			}
	};

}
#endif