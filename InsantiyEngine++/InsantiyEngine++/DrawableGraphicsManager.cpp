#include "GraphicsDataFactory.h"
#include "DrawableGraphicsManager.h"

using namespace InsanityEngine;

DrawableGraphicsManager::DrawableGraphicsManager(GraphicsControllerRef graphicsController) {
	this->graphicsController = graphicsController;
}

DrawableGraphicsManager::~DrawableGraphicsManager() {
	delete this->graphicsController;

	for (int index = 0; index < this->cachedStaticGraphicsData.size(); ++index) {
		delete this->cachedStaticGraphicsData[index];
	}

	for (auto it = this->staticDrawableMap.begin(); it != this->staticDrawableMap.end(); it++) {
		it->second->clear();
		delete it->second;
	}

}

void DrawableGraphicsManager::generateStaticData() {
	for (auto it = this->staticDrawableMap.begin(); it != this->staticDrawableMap.end(); it++) {
		IGraphicsData *graphicsData =  GraphicsDataFactory::buildStaticGraphicsData(it->first, *it->second);
		this->cachedStaticGraphicsData.push_back(graphicsData);
	}
}

void DrawableGraphicsManager::renderDrawableObjects() {
	if (this->cachedStaticGraphicsData.size() == 0) {
		this->generateStaticData();
	}

	this->graphicsController->renderGraphics(this->cachedStaticGraphicsData);
}

void DrawableGraphicsManager::addNewStaticObject(IDrawable *drawableObject, std::string textureKey) {
	if (this->staticDrawableMap.find(textureKey) == this->staticDrawableMap.end()) {
		this->staticDrawableMap[textureKey] = new std::vector<IDrawable*>();
	}

	std::vector<IDrawable*> *drawableObjectList = this->staticDrawableMap[textureKey];
	drawableObjectList->push_back(drawableObject);

	// TODO: we need to optimize this
	this->cachedStaticGraphicsData.clear();
}
