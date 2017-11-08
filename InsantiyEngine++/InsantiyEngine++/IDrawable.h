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

}
#endif