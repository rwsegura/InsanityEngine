#include "IDrawable.h"

#include "StaticGraphicsData.h"

using namespace std;
using namespace InsanityEngine;

StaticGrahpicsData::StaticGrahpicsData(string textureKey) {
	this->textureKey = textureKey;
	this->renderData = vector<StaticTransform>();
}

void StaticGrahpicsData::AddNewDrawable(IDrawable &drawable) {
	StaticTransform transform;

	// Convert Position
	RedStd::Vec2f pos = drawable.Position();
	transform.position = sf::Vector2f(pos.x, pos.y);

	// Convert Rotation
	RedStd::Vec2f rot = drawable.Rotation();
	transform.rotation = sf::Vector2f(rot.x, rot.y);

	// Convert Scale
	RedStd::Vec2f scale = drawable.Scale();
	transform.scale = sf::Vector2f(scale.x, scale.y);

	// Convert Frame
	//RedStd::Vec2f frame = drawable.TextureFrame();
	//transform.textureFrame = sf::Vector2f(frame.x, frame.y);

	this->renderData.push_back(transform);
}

void StaticGrahpicsData::Render(sf::RenderTarget &window) {
	sf::Texture texture;
	texture.loadFromFile(this->textureKey);

	if (texture.getSize().x == 0) {
		// Create a Texture and Set the Pixels
		texture.create(50, 50);

		// Update a texture from an array of pixels
		sf::Uint8* pixels = new sf::Uint8[50 * 50 * 4];
		texture.update(pixels);
	}

	for (StaticTransform transform : this->renderData) {
		sf::Sprite sprite(texture);

		sprite.setPosition(transform.position);
		sprite.setScale(transform.scale);

		window.draw(sprite);
	}
}