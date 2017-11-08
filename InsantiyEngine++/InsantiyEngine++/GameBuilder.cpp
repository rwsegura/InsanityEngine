#include <iostream>
#include <rapidjson\filereadstream.h>
#include <rapidjson\document.h>

#include "GameBuilder.h"
#include "GameObject.h"
#include "GameScene.h"
#include "InsanityEngine.h"
#include "StaticGraphicsComponent.h"
#include "Transform.h"
#include "Vector2.h"

using namespace std;
using namespace rapidjson;
using namespace InsanityEngine;

GameScene* GameBuilder::BuildSceneFromFile(string filename, InsanityGameEngine &api) {
	GameSceneData scene_data = GameBuilder::LoadSceneDataFromFile(filename);

	GameScene* new_scene = new GameScene();
	new_scene->name = scene_data.name;

	for (auto object_data : scene_data.objectData) {
		GameObject *object = GameBuilder::BuildGameObject(*new_scene, object_data, api);
		new_scene->objects.push_back(object);
	}

	return new_scene;
}

GameObject* GameBuilder::BuildGameObject(
	GameScene &scene, 
	GameObjectData &data,
	InsanityGameEngine &api
) {
	GameObject *gameobject = new GameObject(scene);
	gameobject->transform = data.transform;

	for (auto child_data : data.children) {
		GameObject *child = GameBuilder::BuildGameObject(scene, child_data, api);
		gameobject->children.push_back(child);
	}

	for (auto component : data.components) {
		BaseComponent *base_component = GameBuilder::BuildComponent(*gameobject, component, api);
		gameobject->components.push_back(base_component);
	}

	return gameobject;
}

BaseComponent* GameBuilder::BuildComponent(
	GameObject &object,
	GameComponentData &data,
	InsanityGameEngine &api
) {
	string type = data.component_data["Type"];
	if (strcmp(type.c_str(), "StaticGraphicsComponent") == 0) {
		string tex_key = data.component_data["Texture"];
		int rectX = std::stoi(data.component_data["RectX"]);
		int rectY = std::stoi(data.component_data["RectY"]);
		int rectW = std::stoi(data.component_data["RectW"]);
		int rectH = std::stoi(data.component_data["RectH"]);
		return new StaticGraphicsComponent(
			tex_key, RedStd::Rect(rectX, rectY, rectW, rectH),
			object, api, *api.drawable_graphics_manager
		);
	} else if (strcmp(type.c_str(), "PythonComponent") == 0) {
		return nullptr;
	}

	// TODO: Implement Code Here
	return nullptr;
}

// GAME SCENE DATA BUILDER
Document GameBuilder::OpenInputJsonFile(std::string filename) {
	FILE *fp;
	fopen_s(&fp, filename.c_str(), "rb");
	if (!fp) {
		std::cout << "Unable to Open Input File." << std::endl;
		perror(filename.c_str());
	}

	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	Document doc;
	doc.ParseStream(is);

	fclose(fp);

	return doc;
}

GameSceneData GameBuilder::LoadSceneDataFromFile(std::string filename) {
	Document doc = GameBuilder::OpenInputJsonFile(filename);

	GameSceneData data;
	data.name = doc["Name"].GetString();

	auto gameobjects = doc["GameObjects"].GetArray();
	for (unsigned int index = 0; index < gameobjects.Size(); index++) {
		data.objectData.push_back(
			GameBuilder::LoadGameObjectData(gameobjects[index])
		);
	}

	return data;
}

GameObjectData GameBuilder::LoadGameObjectData(Value &object_data) {
	GameObjectData data;
	data.name = object_data["Name"].GetString();

	Value transform_data = object_data["Transform"].GetObject();
	
	Value position_data	= transform_data["Position"].GetObject();
	data.transform.position = Vec2f(
		position_data["X"].GetFloat(),
		position_data["Y"].GetFloat()
	);

	Value rotation_data = transform_data["Rotation"].GetObject();
	data.transform.rotation = Vec2f(
		rotation_data["X"].GetFloat(),
		rotation_data["Y"].GetFloat()
	);

	Value scale_data = transform_data["Scale"].GetObject();
	data.transform.scale = Vec2f(
		scale_data["X"].GetFloat(),
		scale_data["Y"].GetFloat()
	);

	auto components = object_data["Components"].GetArray();
	for (unsigned int index = 0; index < components.Size(); index++) {
		data.components.push_back(
			GameBuilder::LoadGameComponentData(components[index])
		);
	}

	auto children = object_data["Children"].GetArray();
	for (unsigned int index = 0; index < children.Size(); index++) {
		data.children.push_back(
			GameBuilder::LoadGameObjectData(children[index])
		);
	}

	return data;
}

GameComponentData GameBuilder::LoadGameComponentData(Value &component_data) {
	GameComponentData data;

	for (auto itr = component_data.MemberBegin(); itr != component_data.MemberEnd(); ++itr) {
		data.component_data[itr->name.GetString()] = itr->value.GetString();
	}

	return data;
}
