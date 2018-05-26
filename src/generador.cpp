#include <generador.h>

Generador::Generador(){
	this->Seed = 0L;
}

Generador::Generador(unsigned long Seed){
	this->Seed = Seed;
}

unsigned long Generador::get(){
	return this->Seed;
}

void Generador::set(unsigned long x){
	this->Seed = (unsigned long) x;
}

float Generador::rand(){
    return ((this->Seed = ((this->Seed * PRIME) & MASK)) * SCALE);
}

float Generador::randFloat(float low, float high){
	return (low + (high - (low)) * rand());
}

int Generador::randInt(int low, int high){
    return (int) (low + (high - (low) + 1) * rand());
}
