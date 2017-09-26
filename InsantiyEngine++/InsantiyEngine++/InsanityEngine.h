#ifndef __INSANITY_ENGINE_H__
#define __INSANITY_ENGINE_H__

#include "GraphicsController.h"
#include "InputController.h"
#include "NetworkingController.h"
#include "DrawableGraphicsManager.h"
#include "SoundController.h"
#include "WindowController.h"

namespace InsanityEngine {
	typedef class InsanityGameEngine* InsanityGameEngineRef;

	class InsanityGameEngine {
		public:
			InsanityGameEngine(
				SoundControllerRef soundController,
				InputControllerRef inputController,
				WindowControllerRef windowController,
				DrawableGraphicsManagerRef drawableGraphicsManager
			);

			~InsanityGameEngine();
			void runEngine();
		private:
			DrawableGraphicsManagerRef drawableGraphicsManager;
			WindowControllerRef windowController;
			InputControllerRef input_controller;
			SoundControllerRef sound_controller;
	};
}

#endif