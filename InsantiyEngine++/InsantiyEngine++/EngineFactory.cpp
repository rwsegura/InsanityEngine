#include <memory>
#include <rapidjson\filereadstream.h>
#include <rapidjson\document.h>

#include "Camera.h"
#include "ConfigurationData.h"
#include "EngineFactory.h"
#include "GraphicsFactory.h"
#include "InputFactory.h"
#include "SoundFactory.h"

using namespace sf;
using namespace std;
using namespace rapidjson;
using namespace InsanityEngine;

InsanityGameEngineRef InsanityEngineFactory::CreateEngine(ConfigurationData &data) {
	shared_ptr<sf::RenderWindow> window(new RenderWindow(VideoMode(data.resolutionWidth, data.resolutionHeight), data.title));
	View view = window->getDefaultView();
	shared_ptr<Camera> camera(new Camera(view));

	return new InsanityGameEngine(
		SoundFactory::BuildSoundController(),
		InputFactory::createInputController(window, data),
		GraphicsFactory::CreateWindowController(camera, window),
		GraphicsFactory::CreateDrawableGraphicsManager(camera, window)
	);
}

Document InsanityEngineFactory::OpenInputJsonFile(string filename) {
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

ConfigurationData InsanityEngineFactory::LoadConfigurationData(string filename) {
	Document doc = InsanityEngineFactory::OpenInputJsonFile(filename);

	ConfigurationData data;
	data.title = doc["title"].GetString();
	data.initialSceneFilename = doc["initial_scane"].GetString();

	auto resolution_data = doc["resolution"].GetObject();
	data.resolutionWidth = resolution_data["width"].GetInt();
	data.resolutionHeight = resolution_data["height"].GetInt();

	auto keyboard_data = doc["keyboard"].GetObject();
	for (auto itr = keyboard_data.MemberBegin(); itr != keyboard_data.MemberEnd(); ++itr) {
		data.keyboardMap[itr->name.GetString()] = itr->value.GetString();
	}

	auto mouse_data = doc["mouse"].GetObject();
	for (auto itr = mouse_data.MemberBegin(); itr != mouse_data.MemberEnd(); ++itr) {
		data.mouseMap[itr->name.GetString()] = itr->value.GetString();
	}

	return data;
}
