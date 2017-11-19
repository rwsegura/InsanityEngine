#include <pybind11\embed.h>

#include "GameBuilder.h"
#include "ConfigurationData.h"
#include "EngineFactory.h"
#include "GameScene.h"
#include "InsanityEngine.h"

namespace py = pybind11;
using namespace InsanityEngine;

int main() {
	py::scoped_interpreter guard{};

	ConfigurationData data = InsanityEngineFactory::LoadConfigurationData("config.json");
	InsanityGameEngineRef engine = InsanityEngineFactory::CreateEngine(data);

	GameScene* initial_scene = GameBuilder::BuildSceneFromFile(
		data.initialSceneFilename,
		*engine
	);

	engine->setActiveScene(initial_scene);

	engine->runEngine();
	delete engine;
    return 0;
}
