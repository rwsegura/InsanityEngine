#ifndef __STATIC_GRAPHICS_DATA_H__
#define __STATIC_GRAPHICS_DATA_H__

#include <SFML\Graphics.hpp>

#include "IDrawable.h"
#include "IGraphicData.h"

namespace InsanityEngine {

	struct StaticTransform {
		sf::Vector2f position;
		sf::Vector2f rotation;
		sf::Vector2f scale;
		sf::IntRect textureFrame;
	};

	class StaticGrahpicsData : public IGraphicsData {
		private:
			std::string textureKey;
			std::vector<StaticTransform> renderData;
			
		public:
			StaticGrahpicsData(std::string textureKey);

			void AddNewDrawable(IDrawable &drawable);
			virtual void Render(sf::RenderTarget &window);
	};

}

#endif