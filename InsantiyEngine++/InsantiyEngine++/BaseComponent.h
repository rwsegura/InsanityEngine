#ifndef __BASE_COMPONENT_H__
#define __BASE_COMPONENT_H__

#include <vector>

namespace InsanityEngine {

	class GameObject; // Forward Declaration
	class InsanityGameEngine;

	class BaseComponent {
		public:
			BaseComponent(GameObject &object, InsanityGameEngine &api);

			// Lifecycle Functions
			virtual void onCreate() = 0;
			virtual void onLoad() = 0;
			virtual void onUnload() = 0;

			// Update Functions
			virtual void onUpdate() = 0;
			virtual void onLateUpdate() = 0;

			GameObject& getGameObject();
			InsanityGameEngine& getApi();
			
		protected:
			GameObject &gameobject;
			InsanityGameEngine &insanityapi;

	};

	class NullComponent : public BaseComponent {
		public:
			NullComponent(GameObject &object, InsanityGameEngine &api) : BaseComponent(object, api) {

			}

			virtual void onCreate() { }
			virtual void onLoad() { }
			virtual void onUnload() { }

			// Update Functions
			virtual void onUpdate() { }
			virtual void onLateUpdate() { }
	};

}

#endif

