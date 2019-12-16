#pragma once

#include "Object.h"
#include "ObjectList.h"

 class ObjectList;

 class ObjectListIterator {

 private:
	 ObjectListIterator(); // Must be g i v e n l i s t when c r e a t e d .
	 int m_index; // I n d ex i n t o l i s t .
	 const ObjectList* m_p_list; // L i s t i t e r a t i n g o ve r .

 public:
	 // C re a te i t e r a t o r , o ve r i n d i c a t e d l i s t .
	 ObjectListIterator(const ObjectList* p_l);

	 void first(); // S e t i t e r a t o r t o f i r s t i tem i n l i s t .

	 void next(); // S e t i t e r a t o r t o n e x t i tem i n l i s t .

	 bool isDone() const; // Re turn t r u e i f a t end o f l i s t .

	 // Re turn p o i n t e r t o c u r r e n t O b j ec t , NULL i f done / empty .
	 Object* currentObject() const;
 };