#include "EventKeyboard.h"
#include <SFML\Window\Event.hpp>


	EventKeyboard::EventKeyboard() {

		m_key_val = Keyboard::Key::UNDEFINED_KEY;

		m_keyboard_action = EventKeyboardAction::UNDEFINED_KEYBOARD_ACTION;

		setType("KEYBOARD_EVENT");

	}

	void EventKeyboard::setKey(Keyboard::Key new_key) {

		m_key_val = new_key;

	}

	Keyboard::Key EventKeyboard::getKey() const{

		return m_key_val;

	}

