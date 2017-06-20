#include "GraphicsDataFactory.h"

using namespace InsanityEngine;

IGraphicsData* GraphicsDataFactory::buildStaticGraphicsData(std::string textureKey, std::vector<IDrawable> &drawableList) {
	return new TestGraphicData();
}