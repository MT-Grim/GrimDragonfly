#pragma once

const int MAX_OBJECTS = 5000;

#include "Object.h"

class ObjectListIterator;

class ObjectList {

 private:
 int m_count; 
 Object * m_p_obj[MAX_OBJECTS]; 

 public:

 ObjectList();

 int insert(Object * p_o);

 int remove(Object * p_o);

 void clear();

 int getCount() const;

 bool isEmpty() const;

 bool isFull() const;
};
