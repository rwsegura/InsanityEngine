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
	this->debug_commands(); // TODO: remove

	if (this->camera->IsDirty()) {
		this->camera->ApplyView(*this->currentWindow);
	}

	this->handle_event_updates();
}

void WindowController::handle_event_updates() {
	sf::Event event;
	while (this->currentWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) { // TODO: refactor this
			this->currentWindow->close();
		}
		else if (event.type == sf::Event::Resized) {
			this->camera->Resize(event.size.width, event.size.height);
		}
	}
}

void WindowController::debug_commands() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->camera->Move(0.1f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->camera->Move(-0.1f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->camera->Move(0.0f, 0.1f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->camera->Move(0.0f, -0.1f);
	}
}