#ifndef __ITERATEDLOCALSEARCH__H
#define __ITERATEDLOCALSEARCH__H

#include <clasificador.h>
#include <generador.h>
#include <localsearch.h>
#include <vector>

#define MAX_EVALS 15000

using namespace std;

class IteratedLocalSearch{
	private:
		vector<vector<float>> matrixData;
		vector<int> vectorLabel;
		float limit, alpha;
		Generador aleatorio;
		void neighboursGeneration(vector<float> &weights, const int &component);
		void randomSolution(vector<float> &weights);
		void mutateILS(vector<float> &weights, int &componentesAMutar);
	public:
		IteratedLocalSearch();
		IteratedLocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel);
		IteratedLocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit);
		IteratedLocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit, float alpha);
		IteratedLocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit, float alpha, unsigned long Seed);
		void run(const vector<int> &train, vector<float> &sol, const int &generatedNeighbours);
		void setMatrixData(vector<vector<float>> matrixData);
		void setVectorLabel(vector<int> vectorLabel);
		void setLimit(float limit);
		void setAlpha(float alpha);
		vector<vector<float>> getMatrixData();
		vector<int> getVectorLabel();
		float getLimit();
		float getAlpha();
};

#endif
