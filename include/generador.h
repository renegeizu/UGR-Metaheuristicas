#ifndef __GENERADOR__H
#define __GENERADOR__H

#include <cmath>

#define MASK 2147483647
#define PRIME 65539
#define SCALE 0.4656612875e-9

class Generador{
	private:
		unsigned long Seed;
	public:
		Generador();
		Generador(unsigned long Seed);
		unsigned long get();
		void set(unsigned long x);
		float rand();
		float randFloat(float low, float high);
		int randInt(int low, int high);
};

#endif
