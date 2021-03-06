/**
* GraphicsFactory.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include "Camera.h"
#include "DrawableGraphicsManager.h"
#include "GraphicsController.h"
#include "GraphicsFactory.h"
#include "IDrawable.h"

using namespace InsanityEngine;

GraphicsControllerRef GraphicsFactory::CreateGraphicsController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) {
	sf::Color defaultColor(100, 149, 255);
	return new GraphicsController(camera, window, defaultColor);
}

DrawableGraphicsManagerRef GraphicsFactory::CreateDrawableGraphicsManager(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) {
	GraphicsControllerRef graphics_controller = GraphicsFactory::CreateGraphicsController(camera, window);
	return new DrawableGraphicsManager(graphics_controller);
}

WindowControllerRef GraphicsFactory::CreateWindowController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) {
	return new WindowController(camera, window);
}