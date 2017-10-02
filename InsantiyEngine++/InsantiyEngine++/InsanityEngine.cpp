#include <iostream>

#include "InputController.h"
#include "GraphicsController.h"
#include "WindowController.h"

#include "InsanityEngine.h"

using namespace std;
using namespace InsanityEngine;

InsanityGameEngine::InsanityGameEngine(
	SoundControllerRef soundController,
	InputControllerRef inputController,
	WindowControllerRef windowController,
	DrawableGraphicsManagerRef drawableGraphicsManager
) {
	this->sound_controller			= soundController;
	this->input_controller			= inputController;
	this->window_controller			= windowController;
	this->drawable_graphics_manager = drawableGraphicsManager;
}

InsanityGameEngine::~InsanityGameEngine() {
	delete this->input_controller;
	delete this->window_controller;
	delete this->drawable_graphics_manager;
}

void InsanityGameEngine::setActiveScene(GameScene* scene) {
	if (current_scene != nullptr) {
		current_scene->onEndScene();
		delete current_scene;
	}

	current_scene = scene;
	current_scene->onBeginScene();
}

void InsanityGameEngine::_updateControllers() {
	this->input_controller->udpateInputState();
	this->window_controller->update();
	this->drawable_graphics_manager->renderDrawableObjects();
	this->sound_controller->cleanSoundEffectList();
}

void InsanityGameEngine::runEngine() {
	while (this->window_controller->isActive()) {
		this->_updateControllers();
		this->current_scene->onUpdateScene();
	}
}

/*** Engine Api Methods ***/

// Input
bool InsanityGameEngine::isKeyHeld(string keyName) {
	return this->input_controller->isKeyHeld(keyName);
}

bool InsanityGameEngine::isKeyPressed(string keyName) {
	return this->input_controller->isKeyPressed(keyName);
}

bool InsanityGameEngine::isKeyReleased(string keyName) {
	return this->input_controller->isKeyReleased(keyName);
}

RedStd::Vec2i InsanityGameEngine::getCurrentMousePosition() {
	return this->input_controller->getCurrentMousePosition();
}

// Sound
void InsanityGameEngine::playSoundEffect(string filename) {
	this->sound_controller->playSoundEffect(filename);
}

void InsanityGameEngine::playMusic(string filename) {
	this->sound_controller->playMusic(filename);
}
