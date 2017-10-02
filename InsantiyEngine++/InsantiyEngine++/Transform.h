/**
* StaticGraphicsData.h
* Created By: Robert Segura Date: 9/30/2017
*/

#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Vector2.h"

using namespace RedStd;

namespace InsanityEngine {

	struct Transform {
		Vec2f position;
		Vec2f rotation;
		Vec2f scale;
	};
}

#endif
