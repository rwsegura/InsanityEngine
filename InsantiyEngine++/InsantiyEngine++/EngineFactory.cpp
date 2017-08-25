#include "EngineFactory.h"

using namespace InsanityEngine;

InsanityGameEngineRef InsanityEngineFactory::createEngine(sf::RenderWindow &window) {
	GraphicsControllerRef graphicsController = InsanityEngineFactory::createGraphicsController(window);
	DrawableGraphicsManagerRef sceneGraphManager = InsanityEngineFactory::createDrawableGraphicsManager(graphicsController);

	return new InsanityGameEngine(InsanityEngineFactory::createWindowController(window), sceneGraphManager);
}

DrawableGraphicsManagerRef InsanityEngineFactory::createDrawableGraphicsManager(GraphicsControllerRef graphicsController) {
	return new DrawableGraphicsManager(graphicsController);
}

GraphicsControllerRef InsanityEngineFactory::createGraphicsController(sf::RenderWindow &window) {
	sf::Color defaultColor(100, 149, 255);
	return new GraphicsController(window, defaultColor);
}

WindowControllerRef InsanityEngineFactory::createWindowController(sf::RenderWindow &window) {
	return new WindowController(window);
}