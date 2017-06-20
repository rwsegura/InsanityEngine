#include "InsanityEngine.h"
#include "GraphicsController.h"
#include "WindowController.h"

using namespace InsanityEngine;

InsanityGameEngine::InsanityGameEngine(WindowControllerRef windowController, SceneGraphManagerRef sceneGraphManager) {
	this->sceneGraphManager = sceneGraphManager;
	this->windowController = windowController;
}

InsanityGameEngine::~InsanityGameEngine() {
	delete this->windowController;
	delete this->sceneGraphManager;
}

void InsanityGameEngine::runEngine() {
	while (this->windowController->isActive()) {
		this->windowController->update();
		this->sceneGraphManager->renderDrawableObjects();
	}
}