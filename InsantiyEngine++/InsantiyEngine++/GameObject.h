#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <vector>

#include "BaseComponent.h"
#include "Transform.h"

namespace InsanityEngine {

	class BaseComponent;
	class GameScene;

	class GameObject {
		friend class GameBuilder;

		public:
			GameObject(GameScene &scene);
			~GameObject();

			Transform& getTransform();

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
			//GameObject &parent;
	};

}

#endif
