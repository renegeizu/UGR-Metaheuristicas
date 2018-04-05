#ifndef __RELIEF__H
#define __RELIEF__H

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void closeEnemies(const vector<int> &train, const vector<vector<float>> matrixData, const vector<int> vectorLabel, vector<float> &distEnemy, const int &index);
void closeFriends(const vector<int> &train, const vector<vector<float>> matrixData, const vector<int> vectorLabel, vector<float> &distEnemy, const int &index);
float euclideanDistanceRelief(const vector<float> &train, const vector<float> &test, vector<float> &distances, const vector<float> &weights);
void Relief(const vector<int> &train, const vector<vector<float>> matrixData, const vector<int> vectorLabel, vector<float> &weights);

#endif
