#include "GraphicsDataFactory.h"
#include "SceneGraphManager.h"

using namespace InsanityEngine;

SceneGraphManager::SceneGraphManager(GraphicsControllerRef graphicsController) {
	this->graphicsController = graphicsController;
}

SceneGraphManager::~SceneGraphManager() {
	delete this->graphicsController;

	for (int index = 0; index < this->cachedStaticGraphicsData.size(); ++index) {
		delete this->cachedStaticGraphicsData[index];
	}

	for (auto it = this->staticDrawableMap.begin(); it != this->staticDrawableMap.end(); it++) {
		it->second->clear();
		delete it->second;
	}

}

void SceneGraphManager::generateStaticData() {
	for (auto it = this->staticDrawableMap.begin(); it != this->staticDrawableMap.end(); it++) {
		IGraphicsData *graphicsData =  GraphicsDataFactory::buildStaticGraphicsData(it->first, *it->second);
		this->cachedStaticGraphicsData.push_back(graphicsData);
	}
}

void SceneGraphManager::renderDrawableObjects() {
	if (this->cachedStaticGraphicsData.size() == 0) {
		this->generateStaticData();
	}

	this->graphicsController->renderGraphics(this->cachedStaticGraphicsData);
}

void SceneGraphManager::addNewStaticObject(IDrawable *drawableObject, std::string textureKey) {
	if (this->staticDrawableMap.find(textureKey) == this->staticDrawableMap.end()) {
		this->staticDrawableMap[textureKey] = new std::vector<IDrawable*>();
	}

	std::vector<IDrawable*> *drawableObjectList = this->staticDrawableMap[textureKey];
	drawableObjectList->push_back(drawableObject);

	// TODO: we need to optimize this
	this->cachedStaticGraphicsData.clear();
}
