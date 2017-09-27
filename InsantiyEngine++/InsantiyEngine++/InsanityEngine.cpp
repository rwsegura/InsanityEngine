#include <iostream>

#include "InputController.h"
#include "GraphicsController.h"
#include "WindowController.h"

#include "InsanityEngine.h"

using namespace InsanityEngine;

InsanityGameEngine::InsanityGameEngine(
	SoundControllerRef soundController,
	InputControllerRef inputController,
	WindowControllerRef windowController,
	DrawableGraphicsManagerRef drawableGraphicsManager
) {
	this->sound_controller = soundController;
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

		this->windowController->update();
		this->drawableGraphicsManager->renderDrawableObjects();
		this->sound_controller->cleanSoundEffectList();
	}
}