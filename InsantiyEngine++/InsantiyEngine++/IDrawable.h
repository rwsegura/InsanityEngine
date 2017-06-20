#ifndef __I_DRAWABLE_H__
#define __I_DRAWABLE_H__

#include <string>

namespace InsanityEngine {

	class IDrawable {
		public:
			virtual std::string getTextureKey() = 0;

	};

	class TestDrawable : public IDrawable {
		public:
			virtual std::string getTextureKey() {
				return "Test";
			}
	};

}
#endif