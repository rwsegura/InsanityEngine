#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <vector>

#include "BaseComponent.h"
#include "Transform.h"

namespace InsanityEngine {

	class GameScene;

	class GameObject {
		public:
			GameObject(GameScene &scene);
			~GameObject();

			// Lifecycle Functions
			void onCreate();
			void onLoad();
			void onUnload();

			// Update Functions
			void onUpdate();
			void onLateUpdate();

		private:
			Transform transform;
			std::vector<GameObject*> children;
			std::vector<BaseComponent*> components;

			GameScene &currentScene;
	};

}

#endif
