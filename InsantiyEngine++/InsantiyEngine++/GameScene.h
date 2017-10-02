#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <vector>

#include "GameObject.h"

namespace InsanityEngine {

	class GameScene {
		friend class GameBuilder;

		public:
			GameScene();
			~GameScene();

			// Scene LifeCycle Functions
			void onBeginScene();
			void onUpdateScene();
			void onEndScene();

		protected:
			std::string name;
			std::vector<GameObject*> objects;
	};

}

#endif
#pragma once
