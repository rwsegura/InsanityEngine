#include <memory>

#include "Camera.h"
#include "GraphicsFactory.h"

#include "EngineFactory.h"

using namespace InsanityEngine;

InsanityGameEngineRef InsanityEngineFactory::createEngine() {
	std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!"));
	sf::View view = window->getDefaultView();
	std::shared_ptr<Camera> camera(new Camera(view));

	return new InsanityGameEngine(
		GraphicsFactory::createWindowController(camera, window),
		GraphicsFactory::createDrawableGraphicsManager(camera, window)
	);
}

