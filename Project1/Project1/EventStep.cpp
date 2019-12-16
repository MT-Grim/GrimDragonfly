#include "EventStep.h"
#include "LogManager.h"

EventStep::EventStep() {

	setType("STEP_EVENT");
	m_step_count;

};

EventStep::EventStep(int init_step_count) {

	setType("STEP_EVENT");
	m_step_count = init_step_count;

};

void EventStep::setStepCount(int new_step_count) {

	m_step_count = new_step_count;

};

int EventStep::getStepCount() const {

	return m_step_count;

};

void eventStepTest() {

	EventStep e;

	EventStep ee(1);

	e.setStepCount(1);

	LM.writeLog("e.setStepCount %d : ", e.getStepCount());

	ee.setStepCount(1);

	LM.writeLog("ee.setStepCount %d : ", ee.getStepCount());

	e.setStepCount(0);

	LM.writeLog("e.setStepCount %d : ", e.getStepCount());

	ee.setStepCount(0);

	LM.writeLog("ee.setStepCount %d : ", ee.getStepCount());

	e.setStepCount(10);

	LM.writeLog("e.setStepCount %d : ", e.getStepCount());

	ee.setStepCount(10);

	LM.writeLog("ee.setStepCount %d : ", ee.getStepCount());

	e.setStepCount(-1);

	LM.writeLog("e.setStepCount %d : ", e.getStepCount());

	ee.setStepCount(-1);

	LM.writeLog("ee.setStepCount %d : ", ee.getStepCount());

}