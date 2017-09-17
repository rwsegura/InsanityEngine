#include "Camera.h"
#include "GraphicsController.h"
#include "DrawableGraphicsManager.h"

#include "GraphicsFactory.h"

#include "IDrawable.h"

using namespace InsanityEngine;

GraphicsControllerRef GraphicsFactory::createGraphicsController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) {
	sf::Color defaultColor(100, 149, 255);
	return new GraphicsController(camera, window, defaultColor);
}

DrawableGraphicsManagerRef GraphicsFactory::createDrawableGraphicsManager(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) {
	GraphicsControllerRef graphics_controller = GraphicsFactory::createGraphicsController(camera, window);
	auto drawableManager =  new DrawableGraphicsManager(graphics_controller);


	// TEST CODE START

	TestDrawable *drawable = new TestDrawable(0.0f, 0.0f);
	TestDrawable *draw2 = new TestDrawable(100.0f, 100.0f);
	drawableManager->addNewStaticObject(drawable);
	drawableManager->addNewStaticObject(draw2);

	// TEST CODE END
	return drawableManager;
}

WindowControllerRef GraphicsFactory::createWindowController(std::shared_ptr<Camera> camera, std::shared_ptr<sf::RenderWindow> window) {
	return new WindowController(camera, window);
}