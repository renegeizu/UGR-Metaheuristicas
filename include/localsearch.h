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
		float limit, alpha;
		void neighboursGeneration(vector<float> &weights, const int &component);
		float reduction(const vector<float> &weights);
	public:
		LocalSearch();
		LocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel);
		LocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit);
		LocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit, float alpha);
		void run(const vector<int> &train, const int &generatedNeighbours, vector<float> &weights);
		void run(const vector<int> &train, const int &generatedNeighbours, vector<float> &weights, float rate);
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
