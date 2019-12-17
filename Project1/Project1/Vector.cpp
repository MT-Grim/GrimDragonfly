#pragma once

#include "Vector.h"
#include "LogManager.h"
#include <math.h>

Vector::Vector() {

	m_x = 0;
	m_y = 0;

};

Vector::Vector(float init_x, float init_y) {

	m_x = init_x;	
	m_y = init_y;

	LM.writeLog("x and y set to %f , %f", m_x, m_y);

};

void Vector::setX(float new_x) {

	m_x = new_x;

};


float Vector::getX() const {

	return m_x;

};

void Vector::setY(float new_y) {

	m_y = new_y;

}

float Vector::getY() const {

	return m_y;

}

void Vector::setXY(float new_x, float new_y) {

	m_x = new_x;
	m_y = new_y;

}

float Vector::getMagnitude() const {

	float mag = sqrt(m_x * m_x + m_y * m_y);
	return mag;

	LM.writeLog("mag set to , %f", m_x);

}

void Vector::normalize() {

	float length = getMagnitude();
	if (length > 0) {
		m_x = m_x / length;
		m_y = m_y;
	}
}

void Vector::scale(float s) {

	m_x = m_x * s;
	m_y = m_y * s;

}

Vector Vector::operator +(const Vector& other) const {

	Vector v;
	v.m_x = m_x + other.m_x;
	v.m_y = m_y + other.m_y;
	return v;
};

void testVector() {

	Vector v;

	Vector c(1.0, 1.0);

	Vector d(2.0, 2.0);

	if (v.getX() == 0) {

		LM.writeLog("Vector() test passed");

	}

	if (c.getX() == 1.0) {

		LM.writeLog("Vector(float float) test passed");

	}

	if (d.getMagnitude() == 2) {

		LM.writeLog("getMagnitude() test passed");

	}

	c.scale(2);

	if (c.getX() == 2 && c.getY() == 2) {

		LM.writeLog("scale() test passed");

	}

	c.operator+(d);

	if (c.getX() == 4 && c.getY() == 4) {

		LM.writeLog("+() test passed");

	}

	v.setXY(1, 1);

	if (v.getX() == 1 && v.getY() == 1) {

		LM.writeLog("setXY() test passed");

	}

}
