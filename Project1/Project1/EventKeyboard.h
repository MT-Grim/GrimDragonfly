#pragma once

#pragma once

#include "Event.h"

const std::string KEYBOARD_EVENT = "df::keyboard";

enum EventKeyboardAction {

	UNDEFINED_KEYBOARD_ACTION = -1, // Un de f ined .
	KEY_PRESSED, // Was down .
	KEY_RELEASED, // Was r e l e a s e d .
	KEY_DOWN, // I s down .

};

namespace Keyboard {
	enum Key {
		UNDEFINED_KEY = -1,
		SPACE, RETURN, ESCAPE, TAB, LEFTARROW, RIGHTARROW, UPARROW, DOWNARROW,
		PAUSE, MINUS, PLUS, TILDE, PERIOD, COMMA, SLASH, LEFTCONTROL,
		RIGHTCONTROL, LEFTSHIFT, RIGHTSHIFT, F1, F2, F3, F4, F5, F6, F7, F8,
		F9, F10, F11, F12, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q,
		R, S, T, U, V, W, X, Y, Z, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7,
		NUM8, NUM9, NUM0,

	};
} // end o f namespace Keyboard

class EventKeyboard : public Event {

private:
	Keyboard::Key m_key_val; // Key v a l u e .
	EventKeyboardAction m_keyboard_action; // Key a c t i o n .

public:
	EventKeyboard();

	// S e t key i n e v e n t .
	void setKey(Keyboard::Key new_key);

	// Get key from e v e n t .
	Keyboard::Key getKey() const;

	// S e t keyb o a r d e v e n t a c t i o n .
	void setKeyboardAction(EventKeyboardAction new_action);

	// Get keyb o a r d e v e n t a c t i o n .
	EventKeyboardAction getKeyboardAction() const;

};