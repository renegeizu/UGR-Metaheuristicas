#ifndef __CLASIFICADOR__H
#define __CLASIFICADOR__H

#include <cmath>
#include <vector>

using namespace std;

float euclideanDistance(const vector<float> &train, const vector<float> &test, const vector<float> &weights, float &distance, float limit);
float KNN_Train(const vector<int> &train, const vector<int> &test, vector<vector<float>> matrixData, vector<int> vectorLabel, const vector<float> &weights, float limit = 0.0);
float KNN_Test(const vector<int> &train, const vector<int> &test, vector<vector<float>> matrixData, vector<int> vectorLabel, const vector<float> &weights, float limit = 0.0);

#endif
