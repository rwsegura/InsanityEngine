#ifndef __GAME_BUILDER_H__
#define __GAME_BUILDER_H__

#include <rapidjson\document.h>

#include "GameScene.h"
#include "GameSceneData.h"
#include "InsanityEngine.h"

namespace InsanityEngine {

	class GameBuilder {
		public:
			static GameScene* BuildSceneFromFile(std::string filename, InsanityGameEngineRef api);

		private:
			static GameObject* BuildGameObject(InsanityGameEngineRef api);
			static BaseComponent* BuildComponent(InsanityGameEngineRef api);

			// Data Builders
			static GameSceneData LoadSceneDataFromFile(std::string filename);
			static GameObjectData LoadGameObjectData(rapidjson::Value &object_data);
			static GameComponentData LoadGameComponentData(rapidjson::Value &component_data);

			static rapidjson::Document OpenInputJsonFile(std::string filename);
	};

}

#endif
