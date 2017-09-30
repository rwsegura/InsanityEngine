/**
* StaticGraphicsData.h
* Created By: Robert Segura Date: 9/30/2017
*/

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
		public:
			StaticGrahpicsData(std::string textureKey);

			void addNewDrawable(IDrawable &drawable);
			virtual void render(sf::RenderTarget &window);

		private:
			std::string texture_key;
			std::vector<StaticTransform> render_data;
	};

}

#endif