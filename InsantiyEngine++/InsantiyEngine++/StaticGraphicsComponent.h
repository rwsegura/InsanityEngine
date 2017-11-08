#ifndef __STATIC_GRAPHICS_COMPONENT_H__
#define __STATIC_GRAPHICS_COMPONENT_H__

#include "BaseComponent.h"
#include "DrawableGraphicsManager.h"
#include "IDrawable.h"
#include "Rect.h"
#include "Vector2.h"

namespace InsanityEngine {

	class StaticGraphicsComponent : public BaseComponent, IDrawable {
		public:
			StaticGraphicsComponent(
				std::string texture_key, RedStd::Rect texture_rect,
				GameObject &object, InsanityGameEngine &api,
				DrawableGraphicsManager &drawable_manager
			);

			// Lifecycle Functions
			virtual void onCreate();
			virtual void onLoad();
			virtual void onUnload();

			// Update Functions
			virtual void onUpdate();
			virtual void onLateUpdate();

			// IDrawable Methods
			virtual RedStd::Vec2f position();
			virtual RedStd::Vec2f rotation();
			virtual RedStd::Vec2f scale();

			virtual std::string textureKey();
			virtual RedStd::Rect textureFrame();

		protected:
			std::string texture_key;
			RedStd::Rect texture_rectangle;
			DrawableGraphicsManager &drawablemanager;
	};

}

#endif
