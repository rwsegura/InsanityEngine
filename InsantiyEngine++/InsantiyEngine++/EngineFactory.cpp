#include <memory>

#include "Camera.h"
#include "GraphicsFactory.h"
#include "IDrawable.h"

#include "EngineFactory.h"

using namespace InsanityEngine;

/**
TestDrawable *draw = new TestDrawable();
sceneGraphManager->addNewStaticObject(draw);
*/

InsanityGameEngineRef InsanityEngineFactory::createEngine() {
	std::shared_ptr<Camera> camera(new Camera());
	std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!"));

	return new InsanityGameEngine(
		GraphicsFactory::createWindowController(camera, window),
		GraphicsFactory::createDrawableGraphicsManager(camera, window)
	);
}

