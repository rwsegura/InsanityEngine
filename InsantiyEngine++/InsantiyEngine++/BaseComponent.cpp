#include "BaseComponent.h"
#include "GameObject.h"
#include "InsanityEngine.h"

using namespace InsanityEngine;

BaseComponent::BaseComponent(GameObject &object, InsanityGameEngine &api)
	: gameobject(object), insanityapi(api) {

}

GameObject& BaseComponent::getGameObject() {
	return this->gameobject;
}

InsanityGameEngine& BaseComponent::getApi() {
	return this->insanityapi;
}
