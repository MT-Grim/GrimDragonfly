#include "ObjectListIterator.h"
#include "ObjectList.h"

	ObjectListIterator::ObjectListIterator() {
		
		int m_index; // I n d ex i n t o l i s t .
		const ObjectList* m_p_list; // L i s t i t e r a t i n g o ve r .

	}

	// C re a te i t e r a t o r , o ve r i n d i c a t e d l i s t .
	ObjectListIterator::ObjectListIterator(const ObjectList* p_l) {


	}

	// S e t i t e r a t o r t o f i r s t i tem i n l i s t .
	void ObjectListIterator::first() {


		m_index = 0;

	};

	// S e t i t e r a t o r t o n e x t i tem i n l i s t .
	void ObjectListIterator::next() {


		if (m_index > MAX_OBJECTS) {
			m_index = MAX_OBJECTS;
		}
		if (m_index < m_p_list->m_count) {
			m_index++;
		}

	}

	// Re turn t r u e i f a t end o f l i s t .
	bool ObjectListIterator::isDone() const {

		return (m_index == m_p_list->m_count);

	}

	// Re turn p o i n t e r t o c u r r e n t O b j ec t , NULL i f done / empty .
	Object* ObjectListIterator::currentObject() const {

		

	}

