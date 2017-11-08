#ifndef __INSANITY_ENGINE_H__
#define __INSANITY_ENGINE_H__

#include "DrawableGraphicsManager.h"
#include "GameScene.h"
#include "GraphicsController.h"
#include "InputController.h"
#include "NetworkingController.h"
#include "SoundController.h"
#include "Vector2.h"
#include "WindowController.h"

namespace InsanityEngine {
	typedef class InsanityGameEngine* InsanityGameEngineRef;

	class InsanityGameEngine {
		friend class GameBuilder;

		public:
			InsanityGameEngine(
				SoundControllerRef soundController,
				InputControllerRef inputController,
				WindowControllerRef windowController,
				DrawableGraphicsManagerRef drawableGraphicsManager
			);

			~InsanityGameEngine();

			// Engine Methods
			void setActiveScene(GameScene* scene);
			void runEngine();

			////////////////////////
			// Engine Api Methods
			////////////////////////

			// Input
			bool isKeyHeld(std::string KeyName);
			bool isKeyPressed(std::string KeyName);
			bool isKeyReleased(std::string KeyName);
			RedStd::Vec2i getCurrentMousePosition();

			// Sound
			void playSoundEffect(std::string filename);
			void playMusic(std::string filename);

		private:
			GameScene *current_scene;

			// Controller Classes
			DrawableGraphicsManagerRef drawable_graphics_manager;
			WindowControllerRef window_controller;
			InputControllerRef input_controller;
			SoundControllerRef sound_controller;

			void _updateControllers();
	};
}

#endif