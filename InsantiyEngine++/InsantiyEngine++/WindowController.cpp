#include "WindowController.h"

using namespace InsanityEngine;

WindowController::WindowController(sf::RenderWindow &window) : currentWindow(window) {
}

WindowController::~WindowController() {
}

bool WindowController::isActive() {
	return this->currentWindow.isOpen();
}

void WindowController::update() {
	sf::Event event;
    while (this->currentWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) { // TODO: refactor this
           this->currentWindow.close();
        }
	}
}