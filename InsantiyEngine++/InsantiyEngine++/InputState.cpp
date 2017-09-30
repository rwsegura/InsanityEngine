#include <SFML\Window.hpp>

#include "InputController.h"
#include "Vector2.h"

#include "InputState.h"

using namespace std;
using namespace RedStd;
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

	this->mouse_position.x = inputState.mouse_position.x;
	this->mouse_position.y = inputState.mouse_position.y;
}

void InputState::updateWithMap(sf::RenderWindow &window, KeyMap &nameCodeMap, MouseMap &nameMouseMap) {
	for (auto name_code_pair : nameCodeMap) {
		bool pressed = sf::Keyboard::isKeyPressed(name_code_pair.second);
		this->map[name_code_pair.first] = pressed ? InputStatus::PRESSED : InputStatus::NONE;
	}

	for (auto name_mouse_pair : nameMouseMap) {
		bool pressed = sf::Mouse::isButtonPressed(name_mouse_pair.second);
		this->map[name_mouse_pair.first] = pressed ? InputStatus::PRESSED : InputStatus::NONE;
	}

	sf::Vector2i localPostion = sf::Mouse::getPosition(window);
	this->mouse_position.x = localPostion.x;
	this->mouse_position.y = localPostion.y;
}

InputStatus InputState::getInputStatusForKey(string inputName) {
	return this->map[inputName];
}

Vec2i InputState::getMousePosition() {
	return this->mouse_position;
}
