#include <SFML\Window.hpp>

#include "InputController.h"

#include "InputState.h"

using namespace std;
using namespace InsanityEngine;

InputState::InputState(KeyMap &nameCodeMap) {
	// Build the state map
	for (auto name_code_pair : nameCodeMap) {
		this->map[name_code_pair.first] = InputStatus::NONE;
	}
}

InputState::InputState(InputState &inputState) {
	// Build the state map
	for (auto name_code_pair : inputState.map) {
		this->map[name_code_pair.first] = name_code_pair.second;
	}
}

void InputState::updateWithMap(KeyMap &nameCodeMap) {
	// Build the state map
	for (auto name_code_pair : nameCodeMap) {
		bool pressed = sf::Keyboard::isKeyPressed(name_code_pair.second);
		this->map[name_code_pair.first] = pressed ? InputStatus::PRESSED : InputStatus::NONE;
	}
}

InputStatus InputState::getInputStatusForKey(string inputName) {
	return this->map[inputName];
}
