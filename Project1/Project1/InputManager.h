#pragma once

#include "Manager.h"

#define IM df::InputManager::getInstance()
namespace df {

	class InputManager : public Manager {

	private:
		InputManager(); // P r i v a t e ( a s i n g l e t o n ) .
		InputManager(InputManager const&); // Don ’ t a l l o w copy .
		void operator =(InputManager const&);

	public:

		static InputManager& getInstance();

		int startUp();

		void shutDown();

		void getInput();

	};

}