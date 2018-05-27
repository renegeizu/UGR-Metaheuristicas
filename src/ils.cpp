#include <ils.h>

default_random_engine normGen;
normal_distribution<double> normDist(0.0, 0.4);

void IteratedLocalSearch::neighboursGeneration(vector<float> &weights, const int &component){
	weights[component] += normDist(normGen);
	if(weights[component] > 1){
		weights[component] = 1;
	}else if(weights[component] < 0){
		weights[component] = 0;
	}
}

void IteratedLocalSearch::randomSolution(vector<float> &weights){
	weights.clear();
	for(int i = 0; i < matrixData[0].size(); i++){
		weights.push_back(aleatorio.randFloat(0.0, 1.0));
	}
}

void IteratedLocalSearch::mutateILS(vector<float> &weights, int &componentesAMutar){
	vector<int> indices(weights.size(),0);
	iota(indices.begin(), indices.end(),0);
	vector<int>::iterator it = indices.begin();
	int randomNum, i;
	for(i = 0; i < componentesAMutar; i++){
		randomNum = aleatorio.randInt(0, indices.size()-1);
		neighboursGeneration(weights, randomNum);
		it = it + randomNum;
		indices.erase(it);
		it = indices.begin();
	}
}

IteratedLocalSearch::IteratedLocalSearch(){
	this->matrixData.clear();
	this->vectorLabel.clear();
	this->limit = 0.0;
	this->alpha = 0.0;
}

IteratedLocalSearch::IteratedLocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = 0.0;
	this->alpha = 0.0;
}

IteratedLocalSearch::IteratedLocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = limit;
	this->alpha = 0.0;
}

IteratedLocalSearch::IteratedLocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit, float alpha){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = limit;
	this->alpha = alpha;
}

IteratedLocalSearch::IteratedLocalSearch(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit, float alpha, unsigned long Seed){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = limit;
	this->alpha = alpha;
	this->aleatorio.set(Seed);
}

void IteratedLocalSearch::run(const vector<int> &train, vector<float> &sol, const int &generatedNeighbours){
	int numCharact = matrixData[0].size();
	float actualRate, newRate, bestRate, reductionRate, classificationRate;
	vector<float> actualSol, newSol, bestSol;
	randomSolution(actualSol);
	LocalSearch LS(matrixData, vectorLabel, limit, alpha);
	LS.run(train, generatedNeighbours, actualSol, actualRate);
	newSol = actualSol;
	bestSol = actualSol;
	bestRate = 0;
	int t = 0.1 * numCharact, i;
	for(i = 1; i < 15; i++){
		mutateILS(newSol, t);
		LS.run(train, generatedNeighbours, newSol, newRate);
		if(newRate < actualRate){
			newSol = actualSol;
			newRate = actualRate;
		}else{
			actualSol = newSol;
			actualRate = newRate;
		}
		if(newRate > bestRate){
			bestSol = newSol;
			bestRate = newRate;
		}
	}
	sol = bestSol;
}

void IteratedLocalSearch::setMatrixData(vector<vector<float>> matrixData){
	this->matrixData = matrixData;
}

void IteratedLocalSearch::setVectorLabel(vector<int> vectorLabel){
	this->vectorLabel = vectorLabel;
}

void IteratedLocalSearch::setLimit(float limit){
	this->limit = limit;
}

void IteratedLocalSearch::setAlpha(float alpha){
	this->alpha = alpha;
}

vector<vector<float>> IteratedLocalSearch::getMatrixData(){
	return matrixData;
}

vector<int> IteratedLocalSearch::getVectorLabel(){
	return vectorLabel;
}

float IteratedLocalSearch::getLimit(){
	return limit;
}

float IteratedLocalSearch::getAlpha(){
	return alpha;
}
