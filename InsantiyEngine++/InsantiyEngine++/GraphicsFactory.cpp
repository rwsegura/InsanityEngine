#include "GraphicsController.h"
#include "DrawableGraphicsManager.h"

#include "GraphicsFactory.h"

using namespace InsanityEngine;

GraphicsControllerRef GraphicsFactory::createGraphicsController(sf::RenderWindow &window) {
	sf::Color defaultColor(100, 149, 255);
	return new GraphicsController(window, defaultColor);
}

DrawableGraphicsManagerRef GraphicsFactory::createDrawableGraphicsManager(sf::RenderWindow &window) {
	GraphicsControllerRef graphics_controller = GraphicsFactory::createGraphicsController(window);
	return new DrawableGraphicsManager(graphics_controller);
}