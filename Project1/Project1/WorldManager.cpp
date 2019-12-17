#include "WorldManager.h"
#include "LogManager.h"
#include "EventOut.h"


namespace df {

	WorldManager::WorldManager() {

		m_updates;
		m_deletions;

	};

	WorldManager& WorldManager::getInstance() {

		static WorldManager instance;
		return instance;
	}

	/*
	void WorldManager::draw() {

		std::vector<Object*>::iterator li = m_updates.begin();

		for (i = 0; i < 5; i++) {

			while (li != m_updates.end()) {
				
				if (*li->getAltitude() == i) {//I assume this goes here. Also ask how to get obj

					Object* p_temp_o = *li;//ask about this part

					p_temp_o->draw();

					li++;
				}

			}



		}

	}
	*/
	int WorldManager::startUp() {

		m_updates.clear();
		m_deletions.clear();
		Manager::startUp();
		return 0;

	};

	void WorldManager::shutDown() {

		std::vector<Object*> ol = m_updates;

		std::vector<Object*>::iterator li;

		for (std::vector<Object*>::iterator li = ol.begin(); li != ol.end(); ++li) {

			m_updates.erase(li);

		}

		Manager::shutDown();

	}

	int WorldManager::insertObject(Object* p_o) {

		m_updates.insert(m_updates.end(), p_o);
		
		//LM.writeLog("insertObject new size %s", std::to_string(m_updates.size()).c_str());

		return 0;

	};

	int WorldManager::removeObject(Object* p_o) {

		for (std::vector<Object*>::iterator li = m_updates.begin(); li != m_updates.end(); ++li) {

			if (*li == p_o) {

				m_updates.erase(li);

				return 0;
			}

		}

		return -1;

	}

	std::vector<Object*> WorldManager::getAllObjects() const {

		return m_updates;

	};

	std::vector<Object*> WorldManager::objectsOfType(std::string type) const {

		std::vector<Object*> objectList;

		for (std::vector<Object*>::iterator li = objectList.begin(); li != objectList.end(); ++li) {

			if ((*li)->getType() == type) {

				objectList.insert(objectList.end(), *li);

			}

		}

		return objectList;

	}

	void WorldManager::update() {

		std::vector<Object*> ov = m_updates;
		std::vector<Object*>::iterator ll = ov.begin();

		while (ll != ov.end()) {
			
			Object* p_o = *ll;

			Vector new_pos = p_o->getPosition();

			if (new_pos.getX() != p_o->predictPosition().getX() && new_pos.getY() != p_o->predictPosition().getY()) {

				p_o->setPosition(new_pos);

			}

			ll++;
		}


		std::vector<Object*> ol = m_deletions;
		std::vector<Object*>::iterator li = ol.begin();

		while (li != ol.end()) {

			LM.writeLog("WM.m_deletions size before delete %s", std::to_string(m_deletions.size()).c_str());

			delete *li; //<-

			LM.writeLog("Deleted");

			li++;

			LM.writeLog("WM.m_deletions size after delete %s", std::to_string(m_deletions.size()).c_str());

		}

		m_deletions.clear();
		LM.writeLog("WM.m_deletions size %s", std::to_string(m_deletions.size()).c_str());
	}

	int WorldManager::markForDelete(Object* p_o) {

		std::vector<Object*>::iterator li;
		//LM.writeLog("MFD iterator created");

		//iterate over m_deletions list
		for (li = m_deletions.begin(); li != m_deletions.end(); ++li) {
			//LM.writeLog("Iterate");
			
			//if object is found in list, return 0
			if (p_o == *li) {

				//LM.writeLog("p_o == *li passed");
				return 0;

			}

		}

		//if not, add it and return 1. 
		//LM.writeLog("before m_deletions.push_back()");
		m_deletions.push_back(p_o);
		//LM.writeLog("m_deletions new size %s", std::to_string(m_deletions.size()).c_str());
		return 1;

	}

	void WorldManager::draw() {



	}

	bool WorldManager::positionsIntersect(Vector p1, Vector p2) const{

		if (abs(p1.getX() - p2.getX()) <= 1 && abs(p1.getY() - p2.getY()) <= 1){

			return true;

		}
		else {
			return false;
		}
	}

	std::vector<Object*> WorldManager::getCollisions(Object* p_o, Vector where) const {

		std::vector<Object*> collision_list;

		std::vector<Object*> ol = m_updates;
		std::vector<Object*>::iterator li = ol.begin();

		while (li != ol.end()) {

			Object* p_temp_o = *li;

			if (p_temp_o != p_o) {

				if (positionsIntersect(p_temp_o->getPosition(), where) && p_temp_o->isSolid() ) {

					collision_list.insert(ol.end(), p_temp_o);
						
				}

			}

			li++;

		}

		return collision_list;

	}

	int WorldManager::moveObject(Object* p_o, Vector where) {

		if (p_o->isSolid()) {

			std::vector<Object*> list = getCollisions(p_o, where);

			if (list.size() != 0) {

				bool do_move = true;

				std::vector<Object*> ol = m_updates;
				std::vector<Object*>::iterator li = ol.begin();

				while (li != ol.end()) {

					Object* p_temp_o = *li;

					EventCollision c(p_o, p_temp_o, where);

					p_o->eventHandler(&c);

					p_temp_o->eventHandler(&c);

					if (p_o->getSolidness() == HARD && p_temp_o->getSolidness() == HARD) {

						do_move = false;

					}


				}

				if (do_move == false) {

					return -1;

				}
			}
		}
		p_o->setPosition(where);

		EventOut ov;

		p_o->eventHandler(&ov);

		return 0;
	}

	void WorldManager::testWorldManager() {

		//create some objects to add to WM
		Object* a = new Object;
		Object* b = new Object;
		Object* c = new Object;

		//set types for objOfType test
		a->setType("Test");
		b->setType("Test");
		c->setType("Test");

		
		//test by adding obj again.
		if (WM.insertObject(a) == 0 && WM.insertObject(b) == 0 && WM.insertObject(c) == 0) {

			LM.writeLog("WM.insertObject Passed");

		}

		//remove dup objects
		if (WM.removeObject(a) == 0) {

			LM.writeLog("WM.removeObj a Passed");
		}

		if (WM.removeObject(b) == 0) {

			LM.writeLog("WM.removeObj b Passed");
		}

		if (WM.removeObject(c) == 0) {

			LM.writeLog("WM.removeObj c Passed");
		}

		//remove original c obj
		if (WM.removeObject(c) == 0) {

			LM.writeLog("WM.removeObj dup obj test passed");

		}

		//test remove obj that isnt there.
		if (WM.removeObject(c) == -1) {

			LM.writeLog("WM.removeObj obj dont exist test passed");

		}


		//LM.writeLog("WM.m_deletions size %s", std::to_string(m_deletions.size()).c_str());

		//test MFD
		if (WM.markForDelete(a) == 1) {

			LM.writeLog("markForDelete test 1 passed");

		}

		//test MFD with a alread in list
		if (WM.markForDelete(a) == 0) {

			LM.writeLog("markForDelete test 2 passed");

		}
		

		m_deletions.insert(m_deletions.end(), a);
		m_deletions.insert(m_deletions.end(), b);
		LM.writeLog("WM.m_deletions size before updates %s", std::to_string(m_deletions.size()).c_str());
		//LM.writeLog("&a.getType() %s", a.getType().c_str());
		



	}
}
