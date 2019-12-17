#include "LogManager.h"
#include "Clock.h"
#include "Windows.h"
#include "EventStep.h"
#include "Event.h"
#include "Manager.h"
#include "Object.h"
#include "WorldManager.h"
#include "Vector.h"
#include "EventCollision.h"
#include "DisplayManager.h"

#include <cstdio>
#include <string>


void testClock();
void eventStepTest();
void testEvent();
void testObject();
void testVector();
void testEventCollision();
//no test for EventOut

//need tests for 



int main(int argc, char* argv[]) {
	// Start up LogManager. 
	LM.startUp();

	LM.setFlush();

	DM.startUp();

	LM.writeLog("TestClock start");
	testClock();
	LM.writeLog("TestClock end");
	LM.writeLog("eventStepTest start");
	eventStepTest();
	LM.writeLog("eventStepTest end");
	LM.writeLog("testEvent start");
	testEvent();
	LM.writeLog("testEvent end");
	LM.writeLog("testObject start");
	testObject();
	LM.writeLog("testObject end");
	LM.writeLog("testVector start");
	testVector();
	LM.writeLog("testVector end");
	LM.writeLog("testEventCollision start");
	testEventCollision();
	LM.writeLog("testEventCollision end");
	LM.writeLog("testWorldManager start");
	WM.testWorldManager();
	LM.writeLog("testWorldManager end");
	LM.writeLog("testDisplayManager start");
	DM.testDisplayManager();
	LM.writeLog("testDisplayManager end");


//LM.writeLog("This tests the 'to string' for other tests: %s", test.c_str());
/*
//create our clock and variables for the game loop
Clock clock;
long int loop_time = 0;
long int TARGET_TIME = 30;


//lets test if clock is working by running through a pseudo game loop. 
if (true) {
	
	clock.delta();
	LM.writeLog("clock test delta: %s", std::to_string(clock.delta()).c_str());
	Sleep(.1);
	LM.writeLog("loop_time test before split: %s", std::to_string(loop_time).c_str());
	loop_time = clock.split();
	loop_time = loop_time / 100;
	LM.writeLog("loop_time test after split: %s", std::to_string(loop_time).c_str());
	LM.writeLog("TARGET_TIME - loop_time test after split, before sleep: %s", std::to_string(TARGET_TIME-loop_time).c_str());

	//if target time - loop time is 0, then sleep for 0, else sleep normally. Only for testing. Remove in final build.
	if ((TARGET_TIME - loop_time) < 0) {
		LM.writeLog("Sleep for 0");
		Sleep(0);
	}
	else {
		LM.writeLog("Sleep for target");
		Sleep(TARGET_TIME - loop_time);
	}

}
*/

// Shutdown LogManager. 
LM.shutDown();
}

//if you get a string with writeLog you need to have .c_str after it. 