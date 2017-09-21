#include <memory>
#include <rapidjson\filereadstream.h>
#include <rapidjson\document.h>

#include "Camera.h"
#include "ConfigurationData.h"
#include "InputFactory.h"
#include "GraphicsFactory.h"

#include "EngineFactory.h"

using namespace rapidjson;
using namespace InsanityEngine;

Document InsanityEngineFactory::openInputJsonFile(std::string filename) {
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

ConfigurationData InsanityEngineFactory::loadConfigurationData(std::string filename) {
	Document doc = InsanityEngineFactory::openInputJsonFile(filename);

	ConfigurationData data;
	data.Title = doc["title"].GetString();

	auto resolution_data = doc["resolution"].GetObject();
	data.ResolutionWidth = resolution_data["width"].GetInt();
	data.ResolutionHeight = resolution_data["height"].GetInt();

	auto keyboard_data = doc["keyboard"].GetObject();
	for (auto itr = keyboard_data.MemberBegin(); itr != keyboard_data.MemberEnd(); ++itr) {
		data.KeyboardMap[itr->name.GetString()] = itr->value.GetString();
	}

	auto mouse_data = doc["mouse"].GetObject();
	for (auto itr = mouse_data.MemberBegin(); itr != mouse_data.MemberEnd(); ++itr) {
		data.MouseMap[itr->name.GetString()] = itr->value.GetString();
	}

	return data;
}

InsanityGameEngineRef InsanityEngineFactory::createEngine(std::string filename) {
	ConfigurationData data = InsanityEngineFactory::loadConfigurationData(filename);
	std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(data.ResolutionWidth, data.ResolutionHeight), data.Title));
	sf::View view = window->getDefaultView();
	std::shared_ptr<Camera> camera(new Camera(view));

	return new InsanityGameEngine(
		InputFactory::createInputController(window, data),
		GraphicsFactory::createWindowController(camera, window),
		GraphicsFactory::createDrawableGraphicsManager(camera, window)
	);
}

