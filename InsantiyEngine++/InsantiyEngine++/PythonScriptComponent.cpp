#include <iostream>
#include <pybind11\pybind11.h>
#include "PythonScriptComponent.h"

using namespace InsanityEngine;
namespace py = pybind11;

void PythonScriptComponent::onCreate() {
	try {
		PYBIND11_OVERLOAD_PURE(void, BaseComponent, onCreate, );
	} catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

void PythonScriptComponent::onLoad() {
	try {
		PYBIND11_OVERLOAD_PURE(void, BaseComponent, onLoad,);
	} catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

void PythonScriptComponent::onUnload() {
	try {
		PYBIND11_OVERLOAD_PURE(void, BaseComponent, onUnload,);
	} catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

void PythonScriptComponent::onUpdate() {
	try {
		PYBIND11_OVERLOAD_PURE(void, BaseComponent, onUpdate,);
	} catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

void PythonScriptComponent::onLateUpdate() {
	try {
		PYBIND11_OVERLOAD_PURE(void, BaseComponent, onLateUpdate,);
	} catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}
