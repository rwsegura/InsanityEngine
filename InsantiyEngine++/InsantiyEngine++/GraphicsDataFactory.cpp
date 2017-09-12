#include "StaticGraphicsData.h"

#include "GraphicsDataFactory.h"

using namespace InsanityEngine;

IGraphicsData* GraphicsDataFactory::buildStaticGraphicsData(std::string textureKey, std::vector<IDrawable*> &drawableList) {
	StaticGrahpicsData *data = new StaticGrahpicsData(textureKey);

	for (IDrawable *drawable : drawableList) {
		data->AddNewDrawable(*drawable);
	}

	return data;
}