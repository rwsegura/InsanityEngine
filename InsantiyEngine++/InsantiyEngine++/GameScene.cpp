#include "GameObject.h"
#include "GameScene.h"

using namespace InsanityEngine;

GameScene::GameScene() {

}

GameScene::~GameScene() {
	for (auto object : this->objects) {
		delete object;
	}
}

void GameScene::onBeginScene() {
	for (auto object : this->objects) {
		object->onLoad();
	}
}

void GameScene::onUpdateScene() {
	for (auto object : this->objects) {
		object->onUpdate();
	}

	for (auto object : this->objects) {
		object->onLateUpdate();
	}
}

void GameScene::onEndScene() {
	for (auto object : this->objects) {
		object->onUnload();
	}
}
