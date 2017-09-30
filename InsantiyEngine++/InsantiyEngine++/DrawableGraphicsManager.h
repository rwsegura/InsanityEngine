/**
* DrawableGraphicsManager.h
* Created By: Robert Segura Date: 9/30/2017
*/

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
			DrawableGraphicsManager(GraphicsController *graphicsController);
			~DrawableGraphicsManager();

			void renderDrawableObjects();
			void addNewStaticObject(IDrawable* drawableObject);

		protected:
			DrawableMap static_drawable_map;
			std::vector<IGraphicsData *> cached_static_graphics_data;

			void _generateStaticData();

		private:
			GraphicsController *graphics_controller;
	};

}
#endif