#ifndef __ENFSIMULADO__H
#define __ENFSIMULADO__H

#include <clasificador.h>
#include <generador.h>
#include <random>
#include <vector>

#define MAX_EVALS 15000

using namespace std;

class EnfriamientoSimulado{
	private:
		vector<vector<float>> matrixData;
		vector<int> vectorLabel;
		float limit, alpha;
		Generador aleatorio;
		void neighboursGeneration(vector<float> &weights, const int &component);
	public:
		EnfriamientoSimulado();
		EnfriamientoSimulado(vector<vector<float>> matrixData, vector<int> vectorLabel);
		EnfriamientoSimulado(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit);
		EnfriamientoSimulado(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit, float alpha);
		EnfriamientoSimulado(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit, float alpha, unsigned long Seed);
		void run(const vector<int> &train, vector<float> &initSol, float mu, float phi);
		void setMatrixData(vector<vector<float>> matrixData);
		void setVectorLabel(vector<int> vectorLabel);
		void setLimit(float limit);
		void setAlpha(float alpha);
		void setSeed(unsigned long Seed);
		vector<vector<float>> getMatrixData();
		vector<int> getVectorLabel();
		float getLimit();
		float getAlpha();
};

#endif
