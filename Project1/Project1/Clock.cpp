#include "Clock.h"
#include "Windows.h"
#include "LogManager.h"
#include <Windows.h>

	Clock::Clock() {
		SYSTEMTIME current;
		GetSystemTime(&current);
		m_previous_time = (current.wMinute * 60 * 1000000)
			+ (current.wSecond * 1000000)
			+ (current.wMilliseconds * 1000);
		LM.writeLog("m_previous_time initialization test: %s", std::to_string(m_previous_time).c_str());

	};

	long int Clock::delta() {
		SYSTEMTIME before_st, after_st, new_current;
		GetSystemTime(&before_st);
		GetSystemTime(&after_st);

		long int before_msec = (before_st.wMinute * 60 * 1000000)
			+ (before_st.wSecond * 1000000)
			+ (before_st.wMilliseconds * 1000);
		long int after_msec = (after_st.wMinute * 60 * 1000000)
			+ (after_st.wSecond * 1000000)
			+ (after_st.wMilliseconds * 1000);
		long int elapsed_time = after_msec - m_previous_time;
 
		GetSystemTime(&new_current);
		m_previous_time = (new_current.wMinute * 60 * 1000000)
			+ (new_current.wSecond * 1000000)
			+ (new_current.wMilliseconds * 1000);

		if (elapsed_time < 0) {
			elapsed_time = 0;
			//LM sometimes gets an error. Ignore those. It runs fine. 
			LM.writeLog("delta elapsed_time returned 0");
		}

		return elapsed_time;
	};

	long int Clock::split() const {

		SYSTEMTIME before_st, after_st;
		GetSystemTime(&before_st);
		GetSystemTime(&after_st);

		long int before_msec = (before_st.wMinute * 60 * 1000000)
			+ (before_st.wSecond * 1000000)
			+ (before_st.wMilliseconds * 1000);
		long int after_msec = (after_st.wMinute * 60 * 1000000)
			+ (after_st.wSecond * 1000000)
			+ (after_st.wMilliseconds * 1000);
		long int elapsed_time = after_msec - m_previous_time;

		if (elapsed_time < 0) {
			elapsed_time = 0;
			LM.writeLog("split elapsed_time returned 0");
		}

		return elapsed_time;

	}

	void testClock() {

		Clock c;
		c.delta();

		Sleep(1000);

		int coutdelta = c.delta();

		LM.writeLog("coutdelta %d", coutdelta);

		Sleep(1000);

		int coutsplit = c.split();

		LM.writeLog("coutsplit %d", coutsplit);

	}



