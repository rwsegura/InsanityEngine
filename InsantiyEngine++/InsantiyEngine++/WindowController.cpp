#include "Camera.h"

#include "WindowController.h"

using namespace InsanityEngine;

WindowController::WindowController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) : currentWindow(window) {
	this->camera = camera;
}

WindowController::~WindowController() {
}

bool WindowController::isActive() {
	return this->currentWindow->isOpen();
}

void WindowController::update() {
	sf::Event event;
    while (this->currentWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) { // TODO: refactor this
           this->currentWindow->close();
        }
	}
}