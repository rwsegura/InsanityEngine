#include "InputController.h"

using namespace std;
using namespace InsanityEngine;

InputController::InputController(KeyMap nameToKeyCodeMap) 
	: current_state(nameToKeyCodeMap), previous_state(nameToKeyCodeMap){
	this->name_code_map = nameToKeyCodeMap;
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

void InputController::udpateInputState() {
	this->previous_state = this->current_state;
	this->current_state.updateWithMap(this->name_code_map);
}
