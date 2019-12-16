#include "GameManager.h"
#include "LogManager.h"
#include "Clock.h"
#include "Object.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include <Windows.h>
#include <vector>

namespace df {

	GameManager::GameManager() {
		setType("GameManager");

		game_over = false;
		frame_time = FRAME_TIME_DEFAULT;

	}

	int GameManager::startUp() {

		if (LM.startUp()) {
			printf("Error starting log manager!\n");
			return 1;
		}
		// Successfully started, so write some stuff. 

		//add lots of logs messages
		//writing things
		//LM.writeLog("This is a test.");
		//LM.writeLog("This is test %d.", 2);
		//LM.writeLog("This is %s %0.1f.", "test", 2.5);
		//LM.writeLog("Test", "test", 2.5);

		//display manager
		DM.startUp();
		//input manager
		IM.startUp();

		//add error check
		timeBeginPeriod(1);
		//WorldManager::startUp();
		
		WM.startUp();

		//start up manager being last
		Manager::startUp();

		return 0;
	};

	void GameManager::shutDown() {
		LM.shutDown();
		
		//error check this as well
		timeEndPeriod(1);
		Manager::shutDown();
		//setGameOver();
	};

	void GameManager::run() {
		startUp();

		Clock clock;
		long int loop_time = 0;
		//add counter and if onenside loop initialize var outside of loop for tesing
		while (getGameOver() == false) {

			clock.delta();

			//listing 4.5.2. Iterates over all the objects event handlers
			/*
			//Goes under worldmanager for get type
			// Copy so we can iterate....
			std::vector<Object*> ol = m_updates;
			// Iterate...
			for (std::vector<Object*>::iterator li = ol.begin(); li != ol.end(); ++li) {
				// Check if right type...
				if ((*li)->getType() == type)

			}
			//*/

			//ADD TESTS TO EVERYTHING. WRITE TEST METHODS
			//resubmit after tests and code is remade. 

			//Ask about the order of these

			IM.getInput();

			WM.update();

			WM.draw();

			DM.swapBuffers();

			//clock stuff
			LM.writeLog("clock test delta: %s", std::to_string(clock.delta()).c_str());
			LM.writeLog("loop_time test before split: %s", std::to_string(loop_time).c_str());
			loop_time = clock.split();

			LM.writeLog("loop_time test after split: %s", std::to_string(loop_time).c_str());
			LM.writeLog("frame_time - loop_time test after split, before sleep: %s", std::to_string(frame_time - loop_time).c_str());

			//if target time - loop time is 0, then sleep for 0, else sleep normally. Only for testing. Remove in final build.
			if ((frame_time - loop_time) < 0) {
				LM.writeLog("Sleep for 0");
				Sleep(0);
			}
			else {
				LM.writeLog("Sleep for target");
				Sleep(frame_time - loop_time);
			}
		}
		LM.writeLog("Shutting Down");
		shutDown();
		LM.writeLog("Shut Down");
	};

	void GameManager::setGameOver(bool new_game_over) {

		game_over = new_game_over;
	}

	bool GameManager::getGameOver() const {

		return game_over;
	};

	int GameManager::getFrameTime() const {

		return frame_time;

	}

	void GameManager::testGameManager() {



	}

}