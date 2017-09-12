#include "EngineFactory.h"
#include "GraphicsFactory.h"
#include "GraphicsDataFactory.h"
#include "IDrawable.h"

using namespace InsanityEngine;

/**
TestDrawable *draw = new TestDrawable();
sceneGraphManager->addNewStaticObject(draw);
*/

InsanityGameEngineRef InsanityEngineFactory::createEngine(sf::RenderWindow &window) {
	return new InsanityGameEngine(
		InsanityEngineFactory::createWindowController(window),
		GraphicsFactory::createDrawableGraphicsManager(window)
	);
}

WindowControllerRef InsanityEngineFactory::createWindowController(sf::RenderWindow &window) {
	return new WindowController(window);
}