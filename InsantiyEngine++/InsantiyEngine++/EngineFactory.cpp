#include "EngineFactory.h"

using namespace InsanityEngine;

InsanityGameEngineRef InsanityEngineFactory::createEngine(sf::RenderWindow &window) {
	GraphicsControllerRef graphicsController = InsanityEngineFactory::createGraphicsController(window);
	SceneGraphManagerRef sceneGraphManager = InsanityEngineFactory::createSceneGraphManager(graphicsController);

	return new InsanityGameEngine(InsanityEngineFactory::createWindowController(window), sceneGraphManager);
}

SceneGraphManagerRef InsanityEngineFactory::createSceneGraphManager(GraphicsControllerRef graphicsController) {
	return new SceneGraphManager(graphicsController);
}

GraphicsControllerRef InsanityEngineFactory::createGraphicsController(sf::RenderWindow &window) {
	sf::Color defaultColor(100, 149, 255);
	return new GraphicsController(window, defaultColor);
}

WindowControllerRef InsanityEngineFactory::createWindowController(sf::RenderWindow &window) {
	return new WindowController(window);
}