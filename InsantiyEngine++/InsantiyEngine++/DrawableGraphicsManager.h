#ifndef __SCENE_GRAPH_MANAGER_H__
#define __SCENE_GRAPH_MANAGER_H__

#include <map>
#include <string>
#include <vector>

#include "GraphicsController.h"
#include "IDrawable.h"
#include "IGraphicData.h"

namespace InsanityEngine {

	typedef std::map<std::string, std::vector<IDrawable*>*> DrawableMap;

	typedef class DrawableGraphicsManager* DrawableGraphicsManagerRef;

	class DrawableGraphicsManager {
		public:
			DrawableGraphicsManager(GraphicsControllerRef graphicsController);
			~DrawableGraphicsManager();

			void renderDrawableObjects();
			void addNewStaticObject(IDrawable* drawableObject, std::string textureKey);

		protected:
			DrawableMap staticDrawableMap;
			std::vector<IGraphicsData *> cachedStaticGraphicsData;

			void generateStaticData();

		private:
			GraphicsControllerRef graphicsController;
	};

}
#endif