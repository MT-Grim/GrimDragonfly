#include "Manager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Event.h"
#include <vector>



namespace df {

	Manager::Manager() {
		printf("Manager successfully loadedd");

		setType("Manager");

		m_is_started = false;
	};

	Manager::~Manager() {
	
	}

	std::string Manager::getType() const{
		return Manager::m_type;
	};

	void Manager::setType(std::string type) {
		m_type = type;
	};

	int Manager::startUp() {
		m_is_started = true;
		return m_is_started;
	};

	void Manager::shutDown() {
		m_is_started = false;
	};

	bool Manager::isStarted() const{
		return Manager::m_is_started;
	};

	int Manager::onEvent(const Event *p_event) const {

		int count = 0;

		std::vector<Object*> all_objects = WM.getAllObjects();

		std::vector<Object*>::iterator li;

		while (li != all_objects.end()) {

			(*li)->eventHandler(p_event);

			li++;

			count++;

		}

		return count;
	}

	//once onEvent() is defined the GM code in lusting 4.51 needs to be remove and replaced with 
	//EventStep s;
	//onEvent(&s);

	void Manager::testManager() {

		Manager m;

		LM.writeLog("m.startUp %s", std::to_string(m.startUp()).c_str());

		m.shutDown();

		LM.writeLog("m.shutDown %s", std::to_string(m.isStarted()).c_str());

		m.setType("Test");

		LM.writeLog("m.getType %s", m.getType().c_str());
	}

}



