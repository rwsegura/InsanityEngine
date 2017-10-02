#include "ConfigurationData.h"
#include "EngineFactory.h"
#include "GameBuilder.h"
#include "GameScene.h"
#include "InsanityEngine.h"

using namespace InsanityEngine;

int main() {
	ConfigurationData data = InsanityEngineFactory::LoadConfigurationData("config.json");
	InsanityGameEngineRef engine = InsanityEngineFactory::CreateEngine(data);

	GameScene* initial_scene = GameBuilder::BuildSceneFromFile(data.initialSceneFilename, engine);
	engine->setActiveScene(initial_scene);

	engine->runEngine();
	delete engine;
    return 0;
}
