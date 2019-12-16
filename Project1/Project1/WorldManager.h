#pragma once

 #include "Manager.h"
 #include "Object.h"
#include "EventCollision.h"
 #include <vector>

#define WM df::WorldManager::getInstance()

namespace df {

	class WorldManager : public Manager {


	private:
		WorldManager();
		WorldManager(WorldManager const&);
		void operator =(WorldManager const&);

		std::vector<Object*> m_updates;
		std::vector<Object*> m_deletions;

		//arent needed
		std::vector<Object*> ol = m_updates;
		std::vector<Object*> om = m_deletions;

	public:
		void draw();
		 
		static WorldManager& getInstance();

		//mk\ake sure the lists are clear
		int startUp();

		//through all the objects in the updates list and deletes them
		//need to make a list iterator. 
		void shutDown();

		//
		int insertObject(Object* p_o);

		int removeObject(Object* p_o);

		std::vector<Object*> getAllObjects() const;

		//return list of objects of type
		std::vector<Object*> objectsOfType(std::string type) const;

		void update();


		int markForDelete(Object* p_o);

		void testWorldManager();

		std::vector<Object*> getCollisions(Object* p_o, Vector where) const;

		int moveObject(Object* p_o, Vector where);

		//a utility method
		bool positionsIntersect(Vector p1, Vector p2) const;

	};

}