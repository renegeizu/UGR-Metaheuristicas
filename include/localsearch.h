#ifndef __LOCALSEARCH__H
#define __LOCALSEARCH__H

#include <algorithm>
#include <clasificador.h>
#include <numeric>
#include <random>

using namespace std;

void calibrateWeights(vector<float> &weights);
void neighboursGeneration(vector<float> &weights, const int &component);
void LocalSearch(const vector<int> &train, const vector<vector<float>> matrixData, const vector<int> vectorLabel, const int &generatedNeighbours, vector<float> &weights);

#endif
