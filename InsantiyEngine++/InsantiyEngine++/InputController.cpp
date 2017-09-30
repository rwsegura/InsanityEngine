/**
* InputController.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Vector2.h"

#include "InputController.h"

using namespace std;
using namespace RedStd;
using namespace InsanityEngine;

InputController::InputController(std::shared_ptr<sf::RenderWindow> window, KeyMap nameToKeyCodeMap, MouseMap nameToButtonCodeMap)
	: current_state(nameToKeyCodeMap), previous_state(nameToKeyCodeMap) {
	this->current_window = window;
	this->name_code_map = nameToKeyCodeMap;
	this->name_moude_map = nameToButtonCodeMap;
}

InputController::~InputController() {
}

bool InputController::isKeyHeld(string key) {
	return this->previous_state.getInputStatusForKey(key) == InputStatus::PRESSED &&
		this->current_state.getInputStatusForKey(key) == InputStatus::PRESSED;
}

bool InputController::isKeyPressed(string key) {
	return this->current_state.getInputStatusForKey(key) == InputStatus::PRESSED &&
		this->previous_state.getInputStatusForKey(key) == InputStatus::NONE;
}

bool InputController::isKeyReleased(string key) {
	return this->previous_state.getInputStatusForKey(key) == InputStatus::PRESSED &&
		this->current_state.getInputStatusForKey(key) == InputStatus::NONE;
}

Vec2i InputController::getCurrentMousePosition() {
	return this->current_state.getMousePosition();
}

void InputController::udpateInputState() {
	this->previous_state = this->current_state;
	this->current_state.updateWithMap(*this->current_window, this->name_code_map, this->name_moude_map);
}
