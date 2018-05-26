#include <localsearch.h>

using namespace std;

default_random_engine normalGenerator;
normal_distribution<double> normalDistribution(0.0, 0.3);

void LocalSearch::neighboursGeneration(vector<float> &weights, const int &component){
	weights[component] += normalDistribution(normalGenerator);
	if(weights[component] > 1){
		weights[component] = 1;
	}else if(weights[component] < 0){
		weights[component] = 0;
	}
}

float LocalSearch::reduction(const vector<float> &weights){
	int pesosDescartados = 0;
	for(int i = 0; i < weights.size(); ++i){
		if(weights[i] < limit){
			pesosDescartados++;
		}
	}
	return ((float)100.0 * ((float)pesosDescartados/(float)weights.size()));
}

LocalSearch::LocalSearch(){
	this->matrixData.clear();
	this->vectorLabel.clear();
	this->limit = 0.0;
}

LocalSearch::LocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = 0.0;
}

LocalSearch::LocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = limit;
}

void LocalSearch::run(const vector<int> &train, const int &generatedNeighbours, vector<float> &weights){
	Clasificador KNN(matrixData, vectorLabel, limit);
	int neighbours = 0, evaluations = 0, weightsSize = weights.size();
	bool improvement = false;
	vector<int> index(weightsSize, 0);
	iota(index.begin(), index.end(), 0);
	vector<float> actualSolW(weights.begin(), weights.end()), newSolW(weights.begin(), weights.end());
	float actualSol = -999999, newSol = -999999;
	actualSol = KNN.Train(train, train, actualSolW);
	while(evaluations < 15000 && neighbours < generatedNeighbours){
		random_shuffle(index.begin(), index.end());
		improvement = false;
		for(int i = 0; i < weightsSize && !improvement; ++i){
			neighboursGeneration(newSolW, index[i]);
			neighbours++;
			newSol =  KNN.Train(train, train, newSolW);
			evaluations++;
			if(newSol > actualSol){
				actualSol = newSol;
				actualSolW = newSolW;
				improvement = true;
				neighbours = 0;
			}
		}
	}
	weights = actualSolW;
}

void LocalSearch::runnable(const vector<int> &train, const int &generatedNeighbours, vector<float> &weights){
	Clasificador KNN(matrixData, vectorLabel, limit);
	int neighbours = 0, evaluations = 0, weightsSize = weights.size();
	bool improvement = false;
	vector<int> index(weightsSize, 0);
	iota(index.begin(), index.end(), 0);
	vector<float> actualSolW(weights.begin(), weights.end()), newSolW(weights.begin(), weights.end());
	float actualSol = -999999, newSol = -999999, actualReduction = -999999, newReduction = -999999;
	actualSol = KNN.Train(train, train, actualSolW);
	actualReduction = reduction(actualSolW);
	while(evaluations < 15000 && neighbours < generatedNeighbours){
		random_shuffle(index.begin(), index.end());
		improvement = false;
		for(int i = 0; i < weightsSize && !improvement; ++i){
			neighboursGeneration(newSolW, index[i]);
			neighbours++;
			newSol =  KNN.Train(train, train, newSolW);
			evaluations++;
			newReduction = reduction(newSolW);
			if(newSol > actualSol && newReduction > actualReduction){
				actualSol = newSol;
				actualSolW = newSolW;
				improvement = true;
				neighbours = 0;
				actualReduction = newReduction;
			}
		}
	}
	weights = actualSolW;
}

void LocalSearch::setMatrixData(vector<vector<float>> matrixData){
	this->matrixData = matrixData;
}

void LocalSearch::setVectorLabel(vector<int> vectorLabel){
	this->vectorLabel = vectorLabel;
}

void LocalSearch::setLimit(float limit){
	this->limit = limit;
}

vector<vector<float>> LocalSearch::getMatrixData(){
	return matrixData;
}

vector<int> LocalSearch::getVectorLabel(){
	return vectorLabel;
}

float LocalSearch::getLimit(){
	return limit;
}
