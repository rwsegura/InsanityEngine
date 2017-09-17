#include <iostream>

#include "InputController.h"
#include "GraphicsController.h"
#include "WindowController.h"

#include "InsanityEngine.h"

using namespace InsanityEngine;

InsanityGameEngine::InsanityGameEngine(
	InputControllerRef inputController,
	WindowControllerRef windowController,
	DrawableGraphicsManagerRef drawableGraphicsManager
) {
	this->input_controller = inputController;
	this->drawableGraphicsManager = drawableGraphicsManager;
	this->windowController = windowController;
}

InsanityGameEngine::~InsanityGameEngine() {
	delete this->input_controller;
	delete this->windowController;
	delete this->drawableGraphicsManager;
}

void InsanityGameEngine::runEngine() {
	while (this->windowController->isActive()) {
		this->input_controller->udpateInputState();

		// DEBUG
		if (this->input_controller->isKeyPressed("TEST")) {
			std::cout << "INPUT IS PRESSED" << std::endl;
		} else if (this->input_controller->isKeyHeld("TEST")) {
			std::cout << "INPUT IS HELDED" << std::endl;
		} else if (this->input_controller->isKeyReleased("TEST")) {
			std::cout << "INPUT IS RELEASED" << std::endl;
		}

		this->windowController->update();
		this->drawableGraphicsManager->renderDrawableObjects();
	}
}