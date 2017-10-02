#include "GameObject.h"

using namespace InsanityEngine;

GameObject::GameObject(GameScene &scene) : currentScene(scene)  {

}

GameObject::~GameObject() {
	for (auto component : this->components) {
		delete component;
	}

	for (auto child : this->children) {
		delete child;
	}
}

void GameObject::onCreate() {
	// Maybe do nothing?
}

void GameObject::onLoad() {
	for (auto component : this->components) {
		component->onLoad();
	}

	for (auto child : this->children) {
		child->onLoad();
	}
}

void GameObject::onUnload() {
	for (auto component : this->components) {
		component->onUnload();
	}

	for (auto child : this->children) {
		child->onUnload();
	}
}

void GameObject::onUpdate() {
	for (auto component : this->components) {
		component->onUpdate();
	}

	for (auto child : this->children) {
		child->onUpdate();
	}
}

void GameObject::onLateUpdate() {
	for (auto component : this->components) {
		component->onLateUpdate();
	}

	for (auto child : this->children) {
		child->onLateUpdate();
	}
}
