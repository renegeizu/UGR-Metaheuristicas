#include <relief.h>

using namespace std;

void closeEnemies(const vector<int> &train, const vector<vector<float>> matrixData, const vector<int> vectorLabel, vector<float> &distEnemy, const int &index){
	int trainSize = train.size(), label = vectorLabel[index];
	float minDistance = 9999999.0, actualDistance = 0.0;
	vector<float> weights(trainSize, 1.0), distances;
	distances.reserve(trainSize);
	for(int i = 0; i < trainSize; ++i){
		distances.clear();
		if(train[i] != index){
			actualDistance = euclideanDistanceRelief(matrixData[index], matrixData[train[i]], distances, weights);
			if(actualDistance < minDistance){
				if(label != vectorLabel[train[i]]){
					minDistance = actualDistance;
					distEnemy = distances;
				}
			}
		}
	}
}

void closeFriends(const vector<int> &train, const vector<vector<float>> matrixData, const vector<int> vectorLabel, vector<float> &distEnemy, const int &index){
	int trainSize = train.size(), label = vectorLabel[index];
	float minDistance = 9999999.0, actualDistance = 0.0;
	vector<float> weights(trainSize, 1.0), distances;
	distances.reserve(trainSize);
	for(int i = 0; i < trainSize; ++i){
		distances.clear();
		if(train[i] != index){
			actualDistance = euclideanDistanceRelief(matrixData[index], matrixData[train[i]], distances, weights);
			if(actualDistance < minDistance){
				if(label == vectorLabel[train[i]]){
					minDistance = actualDistance;
					distEnemy = distances;
				}
			}
		}
	}
}

float euclideanDistanceRelief(const vector<float> &train, const vector<float> &test, vector<float> &distances, const vector<float> &weights){
	float distance = 0.0;
	int trainSize = train.size();
	for(int i = 0; i < trainSize; ++i){
			distances.push_back(test[i]-train[i]);
			distance += (weights[i] * ((test[i]-train[i]) * (test[i]-train[i])));
	}
	return sqrt(distance);
}

void Relief(const vector<int> &train, const vector<vector<float>> matrixData, const vector<int> vectorLabel, vector<float> &weights){
	int trainSize = train.size(), weightsSize = weights.size();
	vector<float> distFriends, distEnemies;
	for(int i = 0; i < trainSize; ++i){
		distFriends.clear();
		distEnemies.clear();
		closeEnemies(train, matrixData, vectorLabel, distEnemies, train[i]);
		closeFriends(train, matrixData, vectorLabel, distFriends, train[i]);
		for(int j = 0; j < weightsSize; ++j){
			weights[j] += (abs(distEnemies[j]) - abs(distFriends[j]));
		}
	}
	float maxWeight = *max_element(weights.begin(), weights.end());
	for(int i = 0; i < weightsSize; ++i){
		if(weights[i] < 0){
			weights[i] = 0;
		}else{
			weights[i] = weights[i]/maxWeight;
		}
	}
}