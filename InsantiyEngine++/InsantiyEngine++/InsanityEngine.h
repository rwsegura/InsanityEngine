#ifndef __INSANITY_ENGINE_H__
#define __INSANITY_ENGINE_H__

#include "GraphicsController.h"
#include "InputController.h"
#include "NetworkingController.h"
#include "SceneGraphManager.h"
#include "SoundController.h"
#include "WindowController.h"

namespace InsanityEngine {
	typedef class InsanityGameEngine* InsanityGameEngineRef;

	class InsanityGameEngine {
		public:
			InsanityGameEngine(WindowControllerRef windowController, SceneGraphManagerRef sceneGraphManager);
			~InsanityGameEngine();
			void runEngine();
		private:
			SceneGraphManagerRef sceneGraphManager;
			WindowControllerRef windowController;
	};
}

#endif