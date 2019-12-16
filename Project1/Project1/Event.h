#pragma once

# include < string >

 const std::string UNDEFINED_EVENT = "df::undefined";

 class Event {

	 private:
		std::string m_event_type; // H ol d s e v e n t t y p e .

	 public:
		 // C re a te b a se e v e n t .
		 Event();

		 // D e s t r u c t o r .
		 virtual ~Event();

		 // S e t e v e n t t y p e .
		 void setType(std::string new_type);

		 // Get e v e n t t y p e .
		 std::string getType() const;

		 void testEvent();

};

