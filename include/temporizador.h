#ifndef __TEMPORIZADOR_H
#define __TEMPORIZADOR_H

#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

class Temporizador{
	private:
		high_resolution_clock::time_point tStart, tEnd;
		duration<double> tTotal;
	public:
		Temporizador();
		float getTime();
		void reset();
		void start();
		void stop();
};

#endif
