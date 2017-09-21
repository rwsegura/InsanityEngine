#include <cstdio>
#include <iostream>

#include "ConfigurationData.h"
#include "InputController.h"
#include "InputFactory.h"

using namespace InsanityEngine;

InputController* InputFactory::createInputController(ConfigurationData &data) {
	KeyMap name_code_map;
	KeyMap key_code_map = InputFactory::create_map();

	for (auto itr = data.KeyboardMap.begin(); itr != data.KeyboardMap.end(); ++itr) {
		sf::Keyboard::Key key = key_code_map[itr->second];
		name_code_map[itr->first] = key;
	}

	return new InputController(name_code_map);
}

KeyMap InputFactory::create_map() {
	KeyMap map;

	// Character Map to SFML Keycodes
	map["A"] = sf::Keyboard::A;
	map["B"] = sf::Keyboard::B;
	map["C"] = sf::Keyboard::C;
	map["D"] = sf::Keyboard::D;
	map["E"] = sf::Keyboard::E;
	map["F"] = sf::Keyboard::F;
	map["G"] = sf::Keyboard::G;
	map["H"] = sf::Keyboard::H;
	map["I"] = sf::Keyboard::I;
	map["J"] = sf::Keyboard::J;
	map["K"] = sf::Keyboard::K;
	map["L"] = sf::Keyboard::L;
	map["M"] = sf::Keyboard::M;
	map["N"] = sf::Keyboard::N;
	map["O"] = sf::Keyboard::O;
	map["P"] = sf::Keyboard::P;
	map["Q"] = sf::Keyboard::Q;
	map["R"] = sf::Keyboard::R;
	map["S"] = sf::Keyboard::S;
	map["T"] = sf::Keyboard::T;
	map["U"] = sf::Keyboard::U;
	map["V"] = sf::Keyboard::V;
	map["W"] = sf::Keyboard::W;
	map["X"] = sf::Keyboard::X;
	map["Y"] = sf::Keyboard::Y;
	map["Z"] = sf::Keyboard::Z;

	/*
	TODO: Map these
	Num0,         ///< The 0 key
	Num1,         ///< The 1 key
	Num2,         ///< The 2 key
	Num3,         ///< The 3 key
	Num4,         ///< The 4 key
	Num5,         ///< The 5 key
	Num6,         ///< The 6 key
	Num7,         ///< The 7 key
	Num8,         ///< The 8 key
	Num9,         ///< The 9 key
	Escape,       ///< The Escape key
	LControl,     ///< The left Control key
	LShift,       ///< The left Shift key
	LAlt,         ///< The left Alt key
	LSystem,      ///< The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
	RControl,     ///< The right Control key
	RShift,       ///< The right Shift key
	RAlt,         ///< The right Alt key
	RSystem,      ///< The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
	Menu,         ///< The Menu key
	LBracket,     ///< The [ key
	RBracket,     ///< The ] key
	SemiColon,    ///< The ; key
	Comma,        ///< The , key
	Period,       ///< The . key
	Quote,        ///< The ' key
	Slash,        ///< The / key
	BackSlash,    ///< The \ key
	Tilde,        ///< The ~ key
	Equal,        ///< The = key
	Dash,         ///< The - key
	Space,        ///< The Space key
	Return,       ///< The Return key
	BackSpace,    ///< The Backspace key
	Tab,          ///< The Tabulation key
	PageUp,       ///< The Page up key
	PageDown,     ///< The Page down key
	End,          ///< The End key
	Home,         ///< The Home key
	Insert,       ///< The Insert key
	Delete,       ///< The Delete key
	Add,          ///< The + key
	Subtract,     ///< The - key
	Multiply,     ///< The * key
	Divide,       ///< The / key
	Left,         ///< Left arrow
	Right,        ///< Right arrow
	Up,           ///< Up arrow
	Down,         ///< Down arrow
	Numpad0,      ///< The numpad 0 key
	Numpad1,      ///< The numpad 1 key
	Numpad2,      ///< The numpad 2 key
	Numpad3,      ///< The numpad 3 key
	Numpad4,      ///< The numpad 4 key
	Numpad5,      ///< The numpad 5 key
	Numpad6,      ///< The numpad 6 key
	Numpad7,      ///< The numpad 7 key
	Numpad8,      ///< The numpad 8 key
	Numpad9,      ///< The numpad 9 key
	F1,           ///< The F1 key
	F2,           ///< The F2 key
	F3,           ///< The F3 key
	F4,           ///< The F4 key
	F5,           ///< The F5 key
	F6,           ///< The F6 key
	F7,           ///< The F7 key
	F8,           ///< The F8 key
	F9,           ///< The F9 key
	F10,          ///< The F10 key
	F11,          ///< The F11 key
	F12,          ///< The F12 key
	F13,          ///< The F13 key
	F14,          ///< The F14 key
	F15,          ///< The F15 key
	Pause,        ///< The Pause key
	*/

	return map;
}