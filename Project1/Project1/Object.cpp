#include "Object.h"
#include "LogManager.h"
#include "WorldManager.h"
#include <cstdio>
#include <string>

	Object::Object() {

		int m_id; // Un ique game e n g i n e d e f i n e d i d e n t i f i e r .
		std::string m_type; // Game programmer d e f i n e d t y p e .
		Vector m_position; // P o s i t i o n i n game w o rl d .

		setType("Object");

		WM.insertObject(this);

		LM.writeLog("Object Created");

		m_speed = 0;

		m_direction.setXY(0, 0);

		m_velocity.setXY(0, 0);

		m_solidness = HARD;
	}

	Object::~Object() {

		WM.removeObject(this);

	}

	void Object::setId(int new_id) {

		m_id = new_id;

	};

	int Object::getId() const{

		return m_id;

	}

	void Object::setType(std::string new_type) {

		m_type = new_type;

	}

	std::string Object::getType() const {

		return m_type;

	}

	void Object::setPosition(Vector new_pos) {

		m_position = new_pos;

	}

	Vector Object::getPosition() const {

		return m_position;

	}

	int Object::eventHandler(const Event* p_e) {

		return 0;

	}

	int Object::draw() {

		return 0;

	}

	void testObject() {

		Object o;

		o.setType("Blarg");

		LM.writeLog("o.setType: %s", o.getType().c_str());

		o.setId(1);

		LM.writeLog("o.setID: %s", std::to_string(o.getId()).c_str());

		o.setId(0);

		LM.writeLog("o.setID: %s", std::to_string(o.getId()).c_str());

		Vector v;

		v.setXY(1, 1);

		o.setPosition(v);

		LM.writeLog("o.setPosition x: %s y: %s", std::to_string(v.getX()).c_str(), std::to_string(v.getY()).c_str());

	}

	void Object::setSpeed(float speed) {

		m_speed = speed;

	}

	float Object::getSpeed() const {

		return m_speed;

	}

	void Object::setDirection(Vector new_direction) {

		m_direction = new_direction;

	}

	Vector Object::getDirection() const {

		return m_direction;

	}

	void Object::setVelocity(Vector new_velocity) {

		m_velocity = new_velocity;

	}

	Vector Object::getVelocity() const {

		return m_velocity;

	}

	Vector Object::predictPosition() {

		Vector new_pos = m_position + getVelocity();

		return new_pos;

	}

	bool Object::isSolid() const {

		if (m_solidness == HARD || m_solidness == SOFT) {
			return true;
		}
		else {
			return false;
		}

	}

	int Object::setSolidness(Solidness new_solidness) {

		if (new_solidness == HARD || new_solidness == SOFT) {
			m_solidness = new_solidness;
			return 0;
		}

		return -1;

	}

	Solidness Object::getSolidness() const {

		return m_solidness;
	}


