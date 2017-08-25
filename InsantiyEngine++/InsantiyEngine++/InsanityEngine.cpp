#include "InsanityEngine.h"
#include "GraphicsController.h"
#include "WindowController.h"

using namespace InsanityEngine;

InsanityGameEngine::InsanityGameEngine(WindowControllerRef windowController, DrawableGraphicsManagerRef drawableGraphicsManager) {
	this->drawableGraphicsManager = drawableGraphicsManager;
	this->windowController = windowController;
}

InsanityGameEngine::~InsanityGameEngine() {
	delete this->windowController;
	delete this->drawableGraphicsManager;
}

void InsanityGameEngine::runEngine() {
	while (this->windowController->isActive()) {
		this->windowController->update();
		this->drawableGraphicsManager->renderDrawableObjects();
	}
}