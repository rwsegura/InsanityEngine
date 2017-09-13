#include <vector>
#include <SFML\Graphics.hpp>
#include "GraphicsController.h"

using namespace std;
using namespace InsanityEngine;

GraphicsController::GraphicsController(shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window, sf::Color defaultClearColor) : currentWindow(window) {
	this->camera = camera;
	this->defaultClearColor = defaultClearColor;
}

GraphicsController::~GraphicsController() {
}

void GraphicsController::refreshGraphicsScene() {
	this->currentWindow->clear(this->defaultClearColor);
}

void GraphicsController::renderGraphics(const vector<IGraphicsData *> &graphicsData) {
	
	for (unsigned int index = 0; index < graphicsData.size(); ++index) {
		graphicsData[index]->Render(*this->currentWindow);
	}

	this->currentWindow->display();
}