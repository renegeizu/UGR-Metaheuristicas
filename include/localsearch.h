#ifndef __LOCALSEARCH__H
#define __LOCALSEARCH__H

#include <algorithm>
#include <clasificador.h>
#include <numeric>
#include <random>

using namespace std;

class LocalSearch{
	private:
		vector<vector<float>> matrixData;
		vector<int> vectorLabel;
		float limit;
		void neighboursGeneration(vector<float> &weights, const int &component);
		float reduction(const vector<float> &weights);
	public:
		LocalSearch();
		LocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel);
		LocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit);
		void run(const vector<int> &train, const int &generatedNeighbours, vector<float> &weights);
		void runnable(const vector<int> &train, const int &generatedNeighbours, vector<float> &weights);
		void setMatrixData(vector<vector<float>> matrixData);
		void setVectorLabel(vector<int> vectorLabel);
		void setLimit(float limit);
		vector<vector<float>> getMatrixData();
		vector<int> getVectorLabel();
		float getLimit();
};

#endif
