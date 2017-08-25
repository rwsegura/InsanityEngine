#ifndef __GRAPHICS_DATA_FACTORY_H__
#define __GRAPHICS_DATA_FACTORY_H__

#include "DrawableGraphicsManager.h"
#include "IDrawable.h"
#include "IGraphicData.h"

namespace InsanityEngine {

	class TestGraphicData : public IGraphicsData {
		public:
			virtual void render(sf::RenderTarget &window) {
				sf::CircleShape shape(100.f);
				shape.setFillColor(sf::Color::Green);
				window.draw(shape);
			}
	};

	class GraphicsDataFactory {
		public:
			static IGraphicsData* buildStaticGraphicsData(std::string textureKey, std::vector<IDrawable*> &drawableList);
	};
}

#endif