#include <SFML\Graphics.hpp>

#include "EngineFactory.h"
#include "InsanityEngine.h"

using namespace InsanityEngine;

int main() {
	sf::RenderWindow window(sf::VideoMode(200,200), "SFML works!");

	InsanityGameEngineRef engine = InsanityEngineFactory::createEngine(window);
	engine->runEngine();
	delete engine;
    return 0;
}
