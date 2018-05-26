#include <relief.h>

using namespace std;

void Relief::closeEnemies(const vector<int> &train, vector<float> &distEnemy, const int &index){
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

void Relief::closeFriends(const vector<int> &train, vector<float> &distEnemy, const int &index){
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

float Relief::euclideanDistanceRelief(const vector<float> &train, const vector<float> &test, vector<float> &distances, const vector<float> &weights){
	float distance = 0.0;
	int trainSize = train.size();
	for(int i = 0; i < trainSize; ++i){
			distances.push_back(test[i]-train[i]);
			distance += (weights[i] * ((test[i]-train[i]) * (test[i]-train[i])));
	}
	return sqrt(distance);
}

Relief::Relief(){
	this->matrixData.clear();
	this->vectorLabel.clear();
}

Relief::Relief(vector<vector<float>> matrixData, vector<int> vectorLabel){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
}

void Relief::run(const vector<int> &train, vector<float> &weights){
	int trainSize = train.size(), weightsSize = weights.size();
	vector<float> distFriends, distEnemies;
	for(int i = 0; i < trainSize; ++i){
		distFriends.clear();
		distEnemies.clear();
		closeEnemies(train, distEnemies, train[i]);
		closeFriends(train, distFriends, train[i]);
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


void Relief::setMatrixData(vector<vector<float>> matrixData){
	this->matrixData = matrixData;
}

void Relief::setVectorLabel(vector<int> vectorLabel){
	this->vectorLabel = vectorLabel;
}

vector<vector<float>> Relief::getMatrixData(){
	return matrixData;
}

vector<int> Relief::getVectorLabel(){
	return vectorLabel;
}
