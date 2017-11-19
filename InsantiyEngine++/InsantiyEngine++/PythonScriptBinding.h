#ifndef __PYTHON_SCRIPT_BINDING_H__
#define __PYTHON_SCRIPT_BINDING_H__

#include <pybind11\embed.h>
#include <pybind11\pybind11.h>

#include "GameObject.h"
#include "InsanityEngine.h"
#include "BaseComponent.h"
#include "PythonScriptComponent.h"

namespace py = pybind11;
using namespace InsanityEngine;

PYBIND11_EMBEDDED_MODULE(insanity_api, mod) {
	py::class_<InsanityGameEngine, std::unique_ptr<InsanityGameEngine, py::nodelete>>(mod, "InsanityGameEngine")
		.def(py::init<SoundControllerRef, InputControllerRef, WindowControllerRef, DrawableGraphicsManagerRef>());

	py::class_<GameObject, std::unique_ptr<GameObject, py::nodelete>>(mod, "GameObject")
		.def(py::init<GameScene &>());

	py::class_<BaseComponent, PythonScriptComponent>(mod, "ScriptComponent")
		.def(py::init<GameObject &, InsanityGameEngine &>())
		.def("onCreate", &BaseComponent::onCreate)
		.def("onLoad", &BaseComponent::onLoad)
		.def("onUnload", &BaseComponent::onUnload)
		.def("onUpdate", &BaseComponent::onUpdate)
		.def("onLateUpdate", &BaseComponent::onLateUpdate);
}

#endif
