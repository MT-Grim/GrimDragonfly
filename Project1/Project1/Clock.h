#include "Windows.h"


class Clock {
	
	private:
		 long int m_previous_time; 

	public:
		Clock();

		long int delta();
		long int split() const;
		void testClock();

};


//sleep(TARGET_TIME-elapse_time)