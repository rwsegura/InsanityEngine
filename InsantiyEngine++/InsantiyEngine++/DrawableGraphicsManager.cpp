#include "GraphicsDataFactory.h"
#include "DrawableGraphicsManager.h"

using namespace InsanityEngine;

DrawableGraphicsManager::DrawableGraphicsManager(GraphicsControllerRef graphicsController) {
	this->graphicsController = graphicsController;
}

DrawableGraphicsManager::~DrawableGraphicsManager() {
	delete this->graphicsController;

	for (IGraphicsData *data : this->cachedStaticGraphicsData) {
		delete data;
	}

	for (auto staticDrawables : this->staticDrawableMap) {
		staticDrawables.second->clear();
		delete staticDrawables.second;
	}

}

void DrawableGraphicsManager::generateStaticData() {
	for (auto staticDrawables : this->staticDrawableMap) {
		IGraphicsData *graphicsData =  GraphicsDataFactory::buildStaticGraphicsData(
			staticDrawables.first, *(staticDrawables.second)
		);

		this->cachedStaticGraphicsData.push_back(graphicsData);
	}
}

void DrawableGraphicsManager::renderDrawableObjects() {
	if (this->cachedStaticGraphicsData.size() == 0) {
		this->generateStaticData();
	}

	this->graphicsController->renderGraphics(this->cachedStaticGraphicsData);
}

void DrawableGraphicsManager::addNewStaticObject(IDrawable *drawableObject) {
	std::string textureKey = drawableObject->TextureKey();
	if (this->staticDrawableMap.find(textureKey) == this->staticDrawableMap.end()) {
		this->staticDrawableMap[textureKey] = new std::vector<IDrawable*>();
	}

	std::vector<IDrawable*> *drawableObjectList = this->staticDrawableMap[textureKey];
	drawableObjectList->push_back(drawableObject);

	// TODO: we need to optimize this
	this->cachedStaticGraphicsData.clear();
}
