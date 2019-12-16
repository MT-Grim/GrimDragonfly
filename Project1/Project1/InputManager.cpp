#include "InputManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"


namespace df {

	InputManager::InputManager() {

		setType("INPUT_MANAGER");

	}

	int InputManager::startUp() {

		if (DM.startUp() == -1) {

			return -1;

		}

		sf::RenderWindow* window = DM.getWindow();

		//disable key repeat. 
		window->setKeyRepeatEnabled(false);

		Manager::startUp();

		return 1;
	}

	void InputManager::shutDown() {

		DM.getWindow()->setKeyRepeatEnabled(true);

		Manager::shutDown();

	}

	void InputManager::getInput() {

		sf::RenderWindow* window = DM.getWindow();

		sf::Event e;

		while (window->pollEvent(e)) {

			if (e.type == sf::Event::KeyPressed) {

				EventKeyboard k = EventKeyboard();
				WM.onEvent(&k);

			}

			if (e.type == sf::Event::KeyReleased) {

				EventKeyboard k = EventKeyboard();
				WM.onEvent(&k);

			}
			if (e.type == sf::Event::MouseMoved) {

				df::EventMouse m = df::EventMouse();

				WM.onEvent(&m);

			}

			if (e.type == sf::Event::MouseLeft) {

				df::EventMouse m = df::EventMouse();

				WM.onEvent(&m);

			}

		}

		EventMouse m;

		switch (e.mouseButton.button) {
		case(sf::Mouse::Left):
			m.setMouseButton(Mouse::LEFT);
			WM.onEvent(&m);
			break;
		case(sf::Mouse::Right):
			m.setMouseButton(Mouse::RIGHT);
			WM.onEvent(&m);
			break;
		case(sf::Mouse::Middle):
			m.setMouseButton(Mouse::MIDDLE);
			WM.onEvent(&m);
			break;
		}

		EventKeyboard k;

		switch (e.key.code) {
		case(sf::Keyboard::A):
			k.setKey(Keyboard::A);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::B):
			k.setKey(Keyboard::B);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::C):
			k.setKey(Keyboard::C);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::D):
			k.setKey(Keyboard::D);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::E):
			k.setKey(Keyboard::E);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F):
			k.setKey(Keyboard::F);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::G):
			k.setKey(Keyboard::G);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::H):
			k.setKey(Keyboard::H);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::I):
			k.setKey(Keyboard::I);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::J):
			k.setKey(Keyboard::J);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::K):
			k.setKey(Keyboard::K);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::L):
			k.setKey(Keyboard::L);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::M):
			k.setKey(Keyboard::M);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::N):
			k.setKey(Keyboard::N);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::O):
			k.setKey(Keyboard::O);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::P):
			k.setKey(Keyboard::P);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Q):
			k.setKey(Keyboard::Q);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::R):
			k.setKey(Keyboard::R);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::S):
			k.setKey(Keyboard::S);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::T):
			k.setKey(Keyboard::T);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::U):
			k.setKey(Keyboard::U);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::V):
			k.setKey(Keyboard::V);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::W):
			k.setKey(Keyboard::W);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::X):
			k.setKey(Keyboard::X);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Y):
			k.setKey(Keyboard::Y);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Z):
			k.setKey(Keyboard::Z);
			WM.onEvent(&k);
			break;
			//SPACE, RETURN, ESCAPE, TAB, LEFTARROW, RIGHTARROW, UPARROW, DOWNARROW,
		case(sf::Keyboard::Space):
			k.setKey(Keyboard::SPACE);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Return):
			k.setKey(Keyboard::RETURN);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Escape):
			k.setKey(Keyboard::ESCAPE);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Tab):
			k.setKey(Keyboard::TAB);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Left):
			k.setKey(Keyboard::LEFTARROW);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Right):
			k.setKey(Keyboard::RIGHTARROW);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Down):
			k.setKey(Keyboard::DOWNARROW);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Up):
			k.setKey(Keyboard::UPARROW);
			WM.onEvent(&k);
			break;
			//PAUSE, MINUS, PLUS, TILDE, PERIOD, COMMA, SLASH, LEFTCONTROL,
		case(sf::Keyboard::Pause):
			k.setKey(Keyboard::PAUSE);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Dash):
			k.setKey(Keyboard::MINUS);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Equal):
			k.setKey(Keyboard::PLUS);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Tilde):
			k.setKey(Keyboard::TILDE);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Period):
			k.setKey(Keyboard::PERIOD);
			WM.onEvent(&k);
			break;
			//COMMA, SLASH, LEFTCONTROL,
		case(sf::Keyboard::Comma):
			k.setKey(Keyboard::COMMA);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Slash):
			k.setKey(Keyboard::SLASH);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::LControl):
			k.setKey(Keyboard::LEFTCONTROL);
			WM.onEvent(&k);
			break;
			//RIGHTCONTROL, LEFTSHIFT, RIGHTSHIFT, F1, F2, F3, F4, F5, F6, F7, F8,
			//F9, F10, F11, F12,
		case(sf::Keyboard::RControl):
			k.setKey(Keyboard::RIGHTCONTROL);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::LShift):
			k.setKey(Keyboard::LEFTSHIFT);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::RShift):
			k.setKey(Keyboard::RIGHTSHIFT);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F1):
			k.setKey(Keyboard::F1);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F2):
			k.setKey(Keyboard::F2);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F3):
			k.setKey(Keyboard::F3);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F4):
			k.setKey(Keyboard::F4);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F5):
			k.setKey(Keyboard::F5);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F6):
			k.setKey(Keyboard::F6);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F7):
			k.setKey(Keyboard::F7);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F8):
			k.setKey(Keyboard::F8);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F9):
			k.setKey(Keyboard::F9);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F10):
			k.setKey(Keyboard::F10);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F11):
			k.setKey(Keyboard::F11);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::F12):
			k.setKey(Keyboard::F12);
			WM.onEvent(&k);
			break;
			//NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7,
			//NUM8, NUM9, NUM0,
		case(sf::Keyboard::Num0):
			k.setKey(Keyboard::NUM0);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Num1):
			k.setKey(Keyboard::NUM1);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Num2):
			k.setKey(Keyboard::NUM2);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Num3):
			k.setKey(Keyboard::NUM3);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Num4):
			k.setKey(Keyboard::NUM4);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Num5):
			k.setKey(Keyboard::NUM5);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Num6):
			k.setKey(Keyboard::NUM6);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Num7):
			k.setKey(Keyboard::NUM7);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Num8):
			k.setKey(Keyboard::NUM8);
			WM.onEvent(&k);
			break;
		case(sf::Keyboard::Num9):
			k.setKey(Keyboard::NUM9);
			WM.onEvent(&k);
			break;


		};

	}
}