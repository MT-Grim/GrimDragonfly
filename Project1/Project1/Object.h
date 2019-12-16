#pragma once

#include <string>
#include "Vector.h"
#include "Event.h"

enum Solidness {
	HARD,
	SOFT,
	SPECTRAL,
};

class Object {


	private:
	
		int m_id; // Un ique game e n g i n e d e f i n e d i d e n t i f i e r .
		std::string m_type; // Game programmer d e f i n e d t y p e .
		Vector m_position; // P o s i t i o n i n game w o rl d .
		int m_altitude;
		Vector m_direction;
		Vector m_velocity;
		float m_speed;
		Solidness m_solidness;

	public:
		 // C o n s t r u c t O b j e c t . S e t d e f a u l t p a r am e te r s and
		 // add t o game w o rl d (WorldManager ) .
		 Object();
	
		 // D e s t r oy O b j e c t .
		 // Remove from game w o rl d (WorldManager ) .
		 virtual ~Object();

		 //solidness stuff
		 bool isSolid() const;

		 int setSolidness(Solidness new_solidness);

		 Solidness getSolidness() const;

		 //various kinematics code
		 void setSpeed(float speed);

		 float getSpeed() const;

		 void setDirection(Vector new_direction);

		 Vector getDirection() const;

		 void setVelocity(Vector new_velocity);

		 Vector getVelocity() const;

		 Vector predictPosition();

		 virtual int draw();

		 int setAltitude(int newAltitude);

		 int getAltitude() const;
	
		 // S e t O b j e c t i d .
		 void setId(int new_id);
	
		 // Get O b j e c t i d .
		 int getId() const;
	
		 // S e t t y p e i d e n t i f i e r o f O b j e c t .
		 void setType(std::string new_type);
	
		 // Get t y p e i d e n t i f i e r o f O b j e c t .
		 std::string getType() const;
	
		 // S e t p o s i t i o n o f O b j e c t .
		 void setPosition(Vector new_pos);
	
		 // Get p o s i t i o n o f O b j e c t .
		 Vector getPosition() const;

		 virtual int eventHandler(const Event* p_e);

		 void testObject();
	 
};