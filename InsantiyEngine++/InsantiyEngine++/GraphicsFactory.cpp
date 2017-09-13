#include "Camera.h"
#include "GraphicsController.h"
#include "DrawableGraphicsManager.h"

#include "GraphicsFactory.h"

using namespace InsanityEngine;

GraphicsControllerRef GraphicsFactory::createGraphicsController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) {
	sf::Color defaultColor(100, 149, 255);
	return new GraphicsController(camera, window, defaultColor);
}

DrawableGraphicsManagerRef GraphicsFactory::createDrawableGraphicsManager(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) {
	GraphicsControllerRef graphics_controller = GraphicsFactory::createGraphicsController(camera, window);
	return new DrawableGraphicsManager(graphics_controller);
}

WindowControllerRef GraphicsFactory::createWindowController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) {
	return new WindowController(camera, window);
}