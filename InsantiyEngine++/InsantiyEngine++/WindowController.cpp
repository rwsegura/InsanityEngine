/**
* WindowController.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Camera.h"
#include "WindowController.h"

using namespace sf;
using namespace std;
using namespace InsanityEngine;

WindowController::WindowController(shared_ptr<Camera> camera, shared_ptr<RenderWindow> window) {
	this->camera = camera;
	this->current_window = window;
}

WindowController::~WindowController() {
}

bool WindowController::isActive() {
	return this->current_window->isOpen();
}

void WindowController::update() {
	if (this->camera->isDirty()) {
		this->camera->applyView(*this->current_window);
	}

	this->_handleEventUpdates();
}

void WindowController::_handleEventUpdates() {
	sf::Event event;
	while (this->current_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) { // TODO: refactor this
			this->current_window->close();
		}
		else if (event.type == sf::Event::Resized) {
			this->camera->resize(event.size.width, event.size.height);
		}
	}
}
