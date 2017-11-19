#ifndef __PYTHON_COMPONENT_H__
#define __PYTHON_COMPONENT_H__

#include "BaseComponent.h"

namespace InsanityEngine {
	class PythonScriptComponent : public BaseComponent {
		public:
			using BaseComponent::BaseComponent;

			// Lifecycle Functions
			virtual void onCreate();
			virtual void onLoad();
			virtual void onUnload();

			// Update Functions
			virtual void onUpdate();
			virtual void onLateUpdate();

		private:
	};

}

#endif
