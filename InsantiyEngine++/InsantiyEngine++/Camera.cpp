/**
* Camera.cpp
* Created By: Robert Segura Date: 9/30/2017
*/

#include <SFML\Graphics.hpp>

#include "Camera.h"

using namespace InsanityEngine;

Camera::Camera(sf::View &view) : current_view(view) {
	this->view_needs_update = false;
}

Camera::~Camera() {
}

void Camera::applyView(sf::RenderWindow &window) {
	window.setView(this->current_view);
	this->view_needs_update = false;
}

bool Camera::isDirty() {
	return this->view_needs_update;
}

void Camera::move(float x, float y) {
	this->current_view.move(x, y);
	this->view_needs_update = true;
}

void Camera::resize(int width, int height) {
	this->current_view.setSize(width, height);
	this->view_needs_update = true;
}