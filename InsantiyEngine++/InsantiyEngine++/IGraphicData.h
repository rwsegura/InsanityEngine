/**
* IGraphicData.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#ifndef __I_GRAPHICS_DATA_H__
#define __I_GRAPHICS_DATA_H__

#include <SFML\Graphics.hpp>

namespace InsanityEngine {
	
	class IGraphicsData {
		public:
			virtual void render(sf::RenderTarget &window) = 0;
	};

}

#endif