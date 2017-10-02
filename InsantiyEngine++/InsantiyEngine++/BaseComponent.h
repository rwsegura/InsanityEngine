#ifndef __BASE_COMPONENT_H__
#define __BASE_COMPONENT_H__

#include <vector>

#include "GameObject.h"

namespace InsanityEngine {

	class GameObject; // Forward Declaration
	class InsanityGameEngine;

	class BaseComponent {
		public:
			// Lifecycle Functions
			virtual void onCreate() = 0;
			virtual void onLoad() = 0;
			virtual void onUnload() = 0;

			// Update Functions
			virtual void onUpdate() = 0;
			virtual void onLateUpdate() = 0;
			
		protected:
			GameObject &gameobject;
			InsanityGameEngine &insanityapi;

	};

}

#endif

