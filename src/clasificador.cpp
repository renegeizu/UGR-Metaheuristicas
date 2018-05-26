#include <clasificador.h>

float Clasificador::euclideanDistance(const vector<float> &train, const vector<float> &test, const vector<float> &weights){
	int trainSize = train.size();
	float distance = 0.0;
	for(int i = 0; i < trainSize; ++i){
		if(weights[i] >= limit){
			distance += (weights[i]*((test[i]-train[i])*(test[i]-train[i])));
		}
	}
	return sqrt(distance);
}

Clasificador::Clasificador(){
	this->matrixData.clear();
	this->vectorLabel.clear();
	this->limit = 0.0;
}

Clasificador::Clasificador(vector<vector<float>> matrixData, vector<int> vectorLabel){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = 0.0;
}

Clasificador::Clasificador(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = limit;
}

float Clasificador::Train(const vector<int> &train, const vector<int> &test, const vector<float> &weights){
	int success = 0, label = vectorLabel[0], trainSize = train.size(), testSize = test.size();
	float distance = 0.0, minDistance;
	for(int i = 0; i < trainSize; ++i){
		minDistance = 999999;
		for(int j = 0; j < testSize; ++j){
			if(train[i] != test[j]){
				distance = euclideanDistance(matrixData[train[i]], matrixData[test[j]], weights);
				if(distance < minDistance){
					minDistance = distance;
					label = vectorLabel[test[j]];
				}
			}
		}
		if(label == vectorLabel[train[i]]){
			success++;
		}
	}
	return (100.0 * (success * (1.0/trainSize)));
}

float Clasificador::Test(const vector<int> &train, const vector<int> &test, const vector<float> &weights){
	int success = 0, label = vectorLabel[0], trainSize = train.size(), testSize = test.size();
	float distance = 0.0, minDistance;
	for(int i = 0; i < trainSize; ++i){
		minDistance = 999999;
		for(int j = 0; j < testSize; ++j){
			distance = euclideanDistance(matrixData[train[i]], matrixData[test[j]], weights);
			if(distance < minDistance){
				minDistance = distance;
				label = vectorLabel[test[j]];
			}
		}
		if(label == vectorLabel[train[i]]){
			success++;
		}
	}
	return (100.0 * (success * (1.0/trainSize)));
}

void Clasificador::setMatrixData(vector<vector<float>> matrixData){
	this->matrixData = matrixData;
}

void Clasificador::setVectorLabel(vector<int> vectorLabel){
	this->vectorLabel = vectorLabel;
}

void Clasificador::setLimit(float limit){
	this->limit = limit;
}

vector<vector<float>> Clasificador::getMatrixData(){
	return matrixData;
}

vector<int> Clasificador::getVectorLabel(){
	return vectorLabel;
}

float Clasificador::getLimit(){
	return limit;
}
