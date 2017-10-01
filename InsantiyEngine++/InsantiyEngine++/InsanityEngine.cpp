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
	this->window_controller = windowController;
	this->drawable_graphics_manager = drawableGraphicsManager;
}

InsanityGameEngine::~InsanityGameEngine() {
	delete this->input_controller;
	delete this->window_controller;
	delete this->drawable_graphics_manager;
}

void InsanityGameEngine::runEngine() {
	while (this->window_controller->isActive()) {
		this->input_controller->udpateInputState();

		this->window_controller->update();
		this->drawable_graphics_manager->renderDrawableObjects();
		this->sound_controller->cleanSoundEffectList();
	}
}