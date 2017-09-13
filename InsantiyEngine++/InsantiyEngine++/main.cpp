#include <SFML\Graphics.hpp>

#include "EngineFactory.h"
#include "InsanityEngine.h"

using namespace InsanityEngine;

int main() {
	InsanityGameEngineRef engine = InsanityEngineFactory::createEngine();
	engine->runEngine();
	delete engine;
    return 0;
}
