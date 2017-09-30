/**
* StaticGraphicsData.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include "IDrawable.h"
#include "Rect.h"
#include "Vector2.h"

#include "StaticGraphicsData.h"

using namespace std;
using namespace InsanityEngine;

StaticGrahpicsData::StaticGrahpicsData(string textureKey) {
	this->texture_key = textureKey;
	this->render_data = vector<StaticTransform>();
}

void StaticGrahpicsData::addNewDrawable(IDrawable &drawable) {
	StaticTransform transform;

	// Convert Position
	RedStd::Vec2f pos = drawable.position();
	transform.position = sf::Vector2f(pos.x, pos.y);

	// Convert Rotation
	RedStd::Vec2f rot = drawable.rotation();
	transform.rotation = sf::Vector2f(rot.x, rot.y);

	// Convert Scale
	RedStd::Vec2f scale = drawable.scale();
	transform.scale = sf::Vector2f(scale.x, scale.y);

	// Convert Frame
	RedStd::Rect frame = drawable.textureFrame();
	transform.textureFrame = sf::IntRect(frame.x, frame.y, frame.width, frame.height);

	this->render_data.push_back(transform);
}

void StaticGrahpicsData::render(sf::RenderTarget &window) {
	sf::Texture texture;
	texture.loadFromFile(this->texture_key);

	if (texture.getSize().x == 0) {
		// Create a Texture and Set the Pixels
		texture.create(50, 50);

		// Update a texture from an array of pixels
		sf::Uint8* pixels = new sf::Uint8[50 * 50 * 4];
		texture.update(pixels);

		delete pixels; // clean up memory
	}

	for (StaticTransform transform : this->render_data) {
		sf::Sprite sprite(texture);

		sprite.setTextureRect(transform.textureFrame);
		sprite.setPosition(transform.position);
		sprite.setScale(transform.scale);

		window.draw(sprite);
	}
}