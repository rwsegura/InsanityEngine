/**
* GraphicsDataFactory.h
* Created By: Robert Segura Date: 9/30/2017
*/

#ifndef __GRAPHICS_DATA_FACTORY_H__
#define __GRAPHICS_DATA_FACTORY_H__

#include "DrawableGraphicsManager.h"
#include "IDrawable.h"
#include "IGraphicData.h"

namespace InsanityEngine {

	class GraphicsDataFactory {
		public:
			static IGraphicsData* BuildStaticGraphicsData(std::string textureKey, std::vector<IDrawable*> &drawableList);
	};
}

#endif