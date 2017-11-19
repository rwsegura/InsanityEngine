#include "GameObject.h"
#include "StaticGraphicsComponent.h"

using namespace std;
using namespace RedStd;
using namespace InsanityEngine;

StaticGraphicsComponent::StaticGraphicsComponent(
	string texture_key,
	Rect texture_rect,
	GameObject &object,
	InsanityGameEngine &api,
	DrawableGraphicsManager &drawable_manager
) : BaseComponent(object, api), drawablemanager(drawable_manager) {
	
	this->texture_key = texture_key;
	this->texture_rectangle = texture_rect;
}

void StaticGraphicsComponent::onLoad() {
	this->drawablemanager.addNewStaticObject(this);
}

Vec2f StaticGraphicsComponent::position() {
	return this->gameobject.getTransform().position;
}

Vec2f StaticGraphicsComponent::rotation() {
	return this->gameobject.getTransform().rotation;
}

Vec2f StaticGraphicsComponent::scale() {
	return this->gameobject.getTransform().scale;
}

string StaticGraphicsComponent::textureKey() {
	return this->texture_key;
}

Rect StaticGraphicsComponent::textureFrame() {
	return this->texture_rectangle;
}

// Empty Methods
void StaticGraphicsComponent::onCreate() {}
void StaticGraphicsComponent::onUnload() {}
void StaticGraphicsComponent::onUpdate() {}
void StaticGraphicsComponent::onLateUpdate() {}
