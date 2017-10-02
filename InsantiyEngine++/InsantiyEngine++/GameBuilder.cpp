#include <rapidjson\filereadstream.h>
#include <rapidjson\document.h>

#include "GameBuilder.h"
#include "GameObject.h"
#include "GameScene.h"
#include "InsanityEngine.h"
#include "Transform.h"
#include "Vector2.h"

using namespace std;
using namespace rapidjson;
using namespace InsanityEngine;

GameScene* GameBuilder::BuildSceneFromFile(string filename, InsanityGameEngineRef api) {
	GameScene* new_scene = new GameScene();

	GameSceneData scene_data = GameBuilder::LoadSceneDataFromFile(filename);


	return new_scene;
}

GameObject* GameBuilder::BuildGameObject(InsanityGameEngineRef api) {
	return nullptr;
}

BaseComponent* GameBuilder::BuildComponent(InsanityGameEngineRef api) {
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