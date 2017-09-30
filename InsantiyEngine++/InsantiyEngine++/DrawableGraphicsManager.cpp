/**
* DrawableGraphicsManager.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include "DrawableGraphicsManager.h"
#include "GraphicsController.h"
#include "GraphicsDataFactory.h"
#include "IDrawable.h"
#include "IGraphicData.h"

using namespace std;
using namespace InsanityEngine;

DrawableGraphicsManager::DrawableGraphicsManager(GraphicsController *graphicsController) {
	this->graphics_controller = graphicsController;
}

DrawableGraphicsManager::~DrawableGraphicsManager() {
	delete this->graphics_controller;

	for (IGraphicsData *data : this->cached_static_graphics_data) {
		delete data;
	}

	for (auto staticDrawables : this->static_drawable_map) {
		staticDrawables.second->clear();
		delete staticDrawables.second;
	}

}

void DrawableGraphicsManager::_generateStaticData() {
	for (auto staticDrawables : this->static_drawable_map) {
		IGraphicsData *graphicsData =  GraphicsDataFactory::BuildStaticGraphicsData(
			staticDrawables.first, *(staticDrawables.second)
		);

		this->cached_static_graphics_data.push_back(graphicsData);
	}
}

void DrawableGraphicsManager::renderDrawableObjects() {
	this->graphics_controller->refreshGraphicsScene();

	if (this->cached_static_graphics_data.size() == 0) {
		this->_generateStaticData();
	}

	this->graphics_controller->renderGraphics(this->cached_static_graphics_data);
}

void DrawableGraphicsManager::addNewStaticObject(IDrawable *drawableObject) {
	string textureKey = drawableObject->textureKey();
	if (this->static_drawable_map.find(textureKey) == this->static_drawable_map.end()) {
		this->static_drawable_map[textureKey] = new std::vector<IDrawable*>();
	}

	vector<IDrawable*> *drawableObjectList = this->static_drawable_map[textureKey];
	drawableObjectList->push_back(drawableObject);

	// TODO: we need to optimize this
	this->cached_static_graphics_data.clear();
}
