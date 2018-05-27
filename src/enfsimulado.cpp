#include <enfsimulado.h>

default_random_engine normalGen;
normal_distribution<double> normalDist(0.0, 0.3);

void EnfriamientoSimulado::neighboursGeneration(vector<float> &weights, const int &component){
	weights[component] += normalDist(normalGen);
	if(weights[component] > 1){
		weights[component] = 1;
	}else if(weights[component] < 0){
		weights[component] = 0;
	}
}

EnfriamientoSimulado::EnfriamientoSimulado(){
	this->matrixData.clear();
	this->vectorLabel.clear();
	this->limit = 0.0;
	this->alpha = 0.0;
	this->aleatorio.set(0L);
}

EnfriamientoSimulado::EnfriamientoSimulado(vector<vector<float>> matrixData, vector<int> vectorLabel){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = 0.0;
	this->alpha = 0.0;
	this->aleatorio.set(0L);
}

EnfriamientoSimulado::EnfriamientoSimulado(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = limit;
	this->alpha = 0.0;
	this->aleatorio.set(0L);
}

EnfriamientoSimulado::EnfriamientoSimulado(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit, float alpha){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = limit;
	this->alpha = alpha;
	this->aleatorio.set(0L);
}

EnfriamientoSimulado::EnfriamientoSimulado(vector<vector<float>> matrixData, vector<int> vectorLabel, float limit, float alpha, unsigned long Seed){
	this->matrixData = matrixData;
	this->vectorLabel = vectorLabel;
	this->limit = limit;
	this->alpha = alpha;
	this->aleatorio.set(Seed);
}

void EnfriamientoSimulado::run(const vector<int> &train, vector<float> &initSol, float mu, float phi){
	int numCharact = matrixData[0].size(), maxNeighbours = 10 * numCharact, maxSuccess = 0.1 * maxNeighbours;
	int maxCooling = MAX_EVALS/maxNeighbours, numCooling = 0, actualSuccess = 1, componentMutate, i;
	float tStart, tEnd = 0.001, actualSolCost, newSolCost,  bestSolCost, classificationRate, reductionRate, agregacion;
	float randomNum, difference, beta;
	vector<float> actualSol, newSol, bestSol;
	Clasificador KNN(matrixData, vectorLabel, limit, alpha);
	KNN.Train(train, train, initSol, classificationRate, reductionRate, agregacion);
	actualSol = initSol;
	bestSol = actualSol;
	actualSolCost = agregacion;
	bestSolCost = actualSolCost;
	tStart = (mu * agregacion) / -(log(phi));
	beta = (tStart - tEnd) / (maxCooling * tStart * tEnd);
	while((numCooling < maxCooling) && (actualSuccess > 0)){
		actualSuccess = 0;
		for(i = 0; (i < maxNeighbours) && (actualSuccess < maxSuccess); i++){
			newSol = actualSol;
			componentMutate = aleatorio.randInt(0, numCharact-1);
			neighboursGeneration(newSol, componentMutate);
			KNN.Train(train, train, initSol, classificationRate, reductionRate, agregacion);
			randomNum = aleatorio.rand();
			difference = newSolCost - actualSolCost;
			if(difference > 0 || randomNum <= exp((-difference)/(tStart*i))){
				actualSol = newSol;
				actualSolCost = newSolCost;
				actualSuccess++;
				if(actualSolCost > bestSolCost)
					bestSol = actualSol, bestSolCost = actualSolCost;
			}
		}
 		tStart = tStart / (1.0 + (beta*tStart));
		numCooling++;
	}
	initSol = bestSol;
}

void EnfriamientoSimulado::setMatrixData(vector<vector<float>> matrixData){
	this->matrixData = matrixData;
}

void EnfriamientoSimulado::setVectorLabel(vector<int> vectorLabel){
	this->vectorLabel = vectorLabel;
}

void EnfriamientoSimulado::setLimit(float limit){
	this->limit = limit;
}

void EnfriamientoSimulado::setAlpha(float alpha){
	this->alpha = alpha;
}

void EnfriamientoSimulado::setSeed(unsigned long Seed){
	this->aleatorio.set(Seed);
}

vector<vector<float>> EnfriamientoSimulado::getMatrixData(){
	return matrixData;
}

vector<int> EnfriamientoSimulado::getVectorLabel(){
	return vectorLabel;
}

float EnfriamientoSimulado::getLimit(){
	return limit;
}

float EnfriamientoSimulado::getAlpha(){
	return alpha;
}
