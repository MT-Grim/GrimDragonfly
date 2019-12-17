#include "EventCollision.h"
#include "LogManager.h"

EventCollision::EventCollision() {

	Vector m_pos; 
	Object* m_p_obj1; 
	Object* m_p_obj2; 

}

EventCollision::EventCollision(Object* p_o1, Object* p_o2, Vector p) {

	m_pos = p;
	m_p_obj1 = p_o1;
	m_p_obj2 = p_o2;

}

void EventCollision::setObject1(Object* p_new_o1) {

	m_p_obj1 = p_new_o1;

}

Object* EventCollision::getObject1() const {

	return m_p_obj1;

}

void EventCollision::setObject2(Object* p_new_o2) {

	m_p_obj2 = p_new_o2;

}

Object* EventCollision::getObject2() const {

	return m_p_obj2;

}

void EventCollision::setPosition(Vector new_pos) {

	m_pos = new_pos;

}

Vector EventCollision::getPosition() const {

	return m_pos;

}

void testEventCollision() {

	Object a;

	Object* a_ptr = &a;

	Object b;

	Object* b_ptr = &b;

	Vector v(1.0, 1.0);

	EventCollision ec(a_ptr, b_ptr, v);

	if (ec.getObject1() == a_ptr) {

		LM.writeLog("Getobj1() test passed");
	}

	if (ec.getObject2() == b_ptr) {

		LM.writeLog("Getobj2() test passed");
	}

	if (ec.getPosition().getX() == 1.0 && ec.getPosition().getY() == 1.0) {
		
		LM.writeLog("EC getPosition() test passed");

	}

	ec.setObject1(b_ptr);

	ec.setObject2(a_ptr);

	if (ec.getObject1() == b_ptr && ec.getObject2() == a_ptr) {

		LM.writeLog("setObject() test passed");

	}


}