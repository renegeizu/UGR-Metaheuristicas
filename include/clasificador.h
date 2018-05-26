#ifndef __CLASIFICADOR__H
#define __CLASIFICADOR__H

#include <cmath>
#include <vector>

using namespace std;

class Clasificador{
	private:
		vector<vector<float>> matrixData;
		vector<int> vectorLabel;
		float limit;
		float euclideanDistance(const vector<float> &train, const vector<float> &test, const vector<float> &weights);
	public:
		Clasificador();
		Clasificador(vector<vector<float>> matrixData, vector<int> vectorLabel);
		Clasificador(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit);
		float Train(const vector<int> &train, const vector<int> &test, const vector<float> &weights);
		float Test(const vector<int> &train, const vector<int> &test, const vector<float> &weights);
		void setMatrixData(vector<vector<float>> matrixData);
		void setVectorLabel(vector<int> vectorLabel);
		void setLimit(float limit);
		vector<vector<float>> getMatrixData();
		vector<int> getVectorLabel();
		float getLimit();
};

#endif
