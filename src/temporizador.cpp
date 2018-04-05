#include <temporizador.h>

using namespace std;
using namespace std::chrono;

Temporizador::Temporizador(){
	reset();
}

float Temporizador::getTime(){
	tTotal = duration_cast<duration<double>>(tEnd - tStart);
	return tTotal.count();
}

void Temporizador::reset(){
	tStart = tEnd = {};
}

void Temporizador::start(){
	tStart = high_resolution_clock::now();
}

void Temporizador::stop(){
	tEnd = high_resolution_clock::now();
}
