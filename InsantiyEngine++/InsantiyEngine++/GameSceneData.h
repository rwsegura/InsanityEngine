#ifndef __GAME_SCENE_DATA_H__
#define __GAME_SCENE_DATA_H__

#include <map>
#include <vector>

#include "Transform.h"

namespace InsanityEngine {

	struct GameComponentData {
		public:
			std::map<std::string, std::string> component_data;
	};

	struct GameObjectData {
		public:
			std::string name;
			Transform transform;
			std::vector<GameComponentData> components;
			std::vector<GameObjectData> children;
	};

	struct GameSceneData {
		public:
			std::string name;
			std::vector<GameObjectData> objectData;
	};

}

#endif
