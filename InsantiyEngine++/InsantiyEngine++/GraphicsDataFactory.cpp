/**
* GraphicsDataFactory.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include "GraphicsDataFactory.h"
#include "StaticGraphicsData.h"


using namespace InsanityEngine;

IGraphicsData* GraphicsDataFactory::BuildStaticGraphicsData(std::string textureKey, std::vector<IDrawable*> &drawableList) {
	StaticGrahpicsData *data = new StaticGrahpicsData(textureKey);

	for (IDrawable *drawable : drawableList) {
		data->addNewDrawable(*drawable);
	}

	return data;
}