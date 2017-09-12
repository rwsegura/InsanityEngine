#include <vector>
#include <SFML\Graphics.hpp>
#include "GraphicsController.h"

using namespace InsanityEngine;

GraphicsController::GraphicsController(sf::RenderWindow &window, sf::Color defaultClearColor) : currentWindow(window) {
	this->defaultClearColor = defaultClearColor;
}

GraphicsController::~GraphicsController() {
}

void GraphicsController::renderGraphics(const std::vector<IGraphicsData *> &graphicsData) {
	this->currentWindow.clear(this->defaultClearColor);

	for (unsigned int index = 0; index < graphicsData.size(); ++index) {
		graphicsData[index]->Render(this->currentWindow);
	}

	this->currentWindow.display();
}