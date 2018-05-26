#ifndef __RELIEF__H
#define __RELIEF__H

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Relief{
	private:
		vector<vector<float>> matrixData;
		vector<int> vectorLabel;
		void closeEnemies(const vector<int> &train, vector<float> &distEnemy, const int &index);
		void closeFriends(const vector<int> &train, vector<float> &distEnemy, const int &index);
		float euclideanDistanceRelief(const vector<float> &train, const vector<float> &test, vector<float> &distances, const vector<float> &weights);
	public:
		Relief();
		Relief(vector<vector<float>> matrixData, vector<int> vectorLabel);
		void run(const vector<int> &train, vector<float> &weights);
		void setMatrixData(vector<vector<float>> matrixData);
		void setVectorLabel(vector<int> vectorLabel);
		vector<vector<float>> getMatrixData();
		vector<int> getVectorLabel();
};

#endif
