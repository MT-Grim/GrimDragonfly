#include "Event.h"
#include "Logmanager.h"
#include <cstdio>
#include <string>

Event::Event() {

	m_event_type;

};

Event::~Event() {
	


};

void Event::setType(std::string new_type) {

	m_event_type = new_type;

};

std::string Event::getType() const {

	return m_event_type;

};

void testEvent() {

	Event eVENT;

	eVENT.setType("Event");

	LM.writeLog("eVENT.setType: %s ", eVENT.getType().c_str() );

	eVENT.setType("");

	LM.writeLog("eVENT.setType: %s ", eVENT.getType().c_str());

	eVENT.setType("null");

	LM.writeLog("eVENT.setType: %s ", eVENT.getType().c_str());

}

