#pragma once

class Vector {


private:
	float m_x; // H o r i z o n t a l component .
	float m_y; // V e r t i c a l component .
public:

	// C re a te Vec tor w i t h ( x , y ) .
	Vector(float init_x, float init_y);

	// D e f a u l t 2 d ( x , y ) i s ( 0 , 0 ) .
	Vector();

	// Get / s e t h o r i z o n t a l component .
	void setX(float new_x);
	float getX() const;

	// Get / s e t v e r t i c a l component .
	void setY(float new_y);
	float getY() const;

	// S e t h o r i z o n t a l & v e r t i c a l componen ts .
	void setXY(float new_x, float new_y);

	// Re turn m agn i tu de o f v e c t o r .
	float getMagnitude() const;

	// N orm al i ze v e c t o r .
	void normalize();

	// S c a l e v e c t o r .
	void scale(float s);

	 // Add two Vec tors , r e t u r n new Vec tor .
	Vector operator +(const Vector & other) const;

	void testVector();
};