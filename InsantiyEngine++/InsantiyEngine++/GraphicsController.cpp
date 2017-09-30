/**
* GraphicsController.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include <vector>
#include <SFML\Graphics.hpp>
#include "GraphicsController.h"

using namespace sf;
using namespace std;
using namespace InsanityEngine;

GraphicsController::GraphicsController(
	shared_ptr<Camera> camera,
	shared_ptr<sf::RenderWindow> window,
	Color defaultClearColor
) {
	this->camera = camera;
	this->current_window = window;
	this->default_clear_color = defaultClearColor;
}

GraphicsController::~GraphicsController() {
}

void GraphicsController::refreshGraphicsScene() {
	this->current_window->clear(this->default_clear_color);
}

void GraphicsController::renderGraphics(const vector<IGraphicsData *> &graphicsData) {
	
	for (unsigned int index = 0; index < graphicsData.size(); ++index) {
		graphicsData[index]->render(*this->current_window);
	}

	this->current_window->display();
}