#include <datos.h>

void Datos::clearData(){
	matrixData.clear();
	vectorLabel.clear();
	train1.clear();
	test1.clear();
	train2.clear();
	test2.clear();
	train3.clear();
	test3.clear();
	train4.clear();
	test4.clear();
	train5.clear();
	test5.clear();
}

void Datos::normalizeData(){
	vector<vector<float>> trasposeMatrix;
	vector<float> characteristics;
	int rows = matrixData[0].size(), cols = matrixData.size();
	for(int i = 0; i < rows; ++i){
		characteristics.clear();
		for(int j = 0; j < cols; ++j){
			characteristics.push_back(matrixData[j][i]);
		}
		trasposeMatrix.push_back(characteristics);
	}
	vector<vector<float>> minMaxMatrix;
	for(int i = 0; i < rows; ++i){
		vector<float> minMax;
		minMax.push_back(*min_element(trasposeMatrix[i].begin(), trasposeMatrix[i].end()));
		minMax.push_back(*max_element(trasposeMatrix[i].begin(), trasposeMatrix[i].end()));
		minMaxMatrix.push_back(minMax);
	}
	for(int i = 0; i < cols; ++i){
		for(int j = 0; j < rows; ++j){
			matrixData[i][j] = (matrixData[i][j] - minMaxMatrix[j][0]) / (minMaxMatrix[j][1]- minMaxMatrix[j][0]);
		}
	}
}

void Datos::partitionData(){
	vector<int> indexLabel1, indexLabel2;
	int matrixDataSize = matrixData.size();
	for(int i = 0; i < matrixDataSize; ++i){
		if(vectorLabel[i] == 1){
			indexLabel1.push_back(i);
		}else{
			indexLabel2.push_back(i);
		}
	}
	int indexLabel1Size = indexLabel1.size(), indexLabel2Size = indexLabel2.size();
	for(int i = 0; i < indexLabel1Size; ++i){
		int index = i%5;
		switch(index){
			case 0:{
				train1.push_back(indexLabel1[i]);
				train2.push_back(indexLabel1[i]);
				train3.push_back(indexLabel1[i]);
				train4.push_back(indexLabel1[i]);
				test5.push_back(indexLabel1[i]);				
				break;
			}
			case 1:{
				train1.push_back(indexLabel1[i]);
				train2.push_back(indexLabel1[i]);
				train3.push_back(indexLabel1[i]);
				train5.push_back(indexLabel1[i]);
				test4.push_back(indexLabel1[i]);
				break;
			}
			case 2:{
				train1.push_back(indexLabel1[i]);
				train2.push_back(indexLabel1[i]);
				train5.push_back(indexLabel1[i]);
				train4.push_back(indexLabel1[i]);
				test3.push_back(indexLabel1[i]);
				break;
			}
			case 3:{
				train1.push_back(indexLabel1[i]);
				train5.push_back(indexLabel1[i]);
				train3.push_back(indexLabel1[i]);
				train4.push_back(indexLabel1[i]);
				test2.push_back(indexLabel1[i]);
				break;
			}
			case 4:{
				train5.push_back(indexLabel1[i]);
				train2.push_back(indexLabel1[i]);
				train3.push_back(indexLabel1[i]);
				train4.push_back(indexLabel1[i]);
				test1.push_back(indexLabel1[i]);
				break;
			}
		}
	}
	for(int i = 0; i < indexLabel2Size; ++i){
		int index = i%5;
		switch(index){
			case 0:{
				train1.push_back(indexLabel2[i]);
				train2.push_back(indexLabel2[i]);
				train3.push_back(indexLabel2[i]);
				train4.push_back(indexLabel2[i]);
				test5.push_back(indexLabel2[i]);				
				break;
			}
			case 1:{
				train1.push_back(indexLabel2[i]);
				train2.push_back(indexLabel2[i]);
				train3.push_back(indexLabel2[i]);
				train5.push_back(indexLabel2[i]);
				test4.push_back(indexLabel2[i]);
				break;
			}
			case 2:{
				train1.push_back(indexLabel2[i]);
				train2.push_back(indexLabel2[i]);
				train5.push_back(indexLabel2[i]);
				train4.push_back(indexLabel2[i]);
				test3.push_back(indexLabel2[i]);
				break;
			}
			case 3:{
				train1.push_back(indexLabel2[i]);
				train5.push_back(indexLabel2[i]);
				train3.push_back(indexLabel2[i]);
				train4.push_back(indexLabel2[i]);
				test2.push_back(indexLabel2[i]);
				break;
			}
			case 4:{
				train5.push_back(indexLabel2[i]);
				train2.push_back(indexLabel2[i]);
				train3.push_back(indexLabel2[i]);
				train4.push_back(indexLabel2[i]);
				test1.push_back(indexLabel2[i]);
				break;
			}
		}
	}
}

void Datos::readData(string path){
	ifstream file(path);
	string row;
	getline(file, row);
	getline(file, row);
	getline(file, row);
	int numCharact = 0;
	while(row[0] == '@'){
		getline(file, row);
		numCharact++;
	}
	getline(file, row);
	getline(file, row, ',');
	while(!file.eof()){
		vector<float> characteristics;
		characteristics.push_back(stof(row));
		for(int i = 1; i < numCharact-1; ++i){
			getline(file, row, ',');
			characteristics.push_back(stof(row));
		}
		matrixData.push_back(characteristics);
		getline(file, row);
		vectorLabel.push_back(stoi(row));
		getline(file, row, ',');
	}
	file.close();
}

Datos::Datos(){
	clearData();
}

Datos::Datos(string path){
	clearData();
	setData(path);
}

vector<int> Datos::getPartitionTest(int index){
	switch(index){
		case 0:
			return test1;
			break;
		case 1:
			return test2;
			break;
		case 2:
			return test3;
			break;
		case 3:
			return test4;
			break;
		case 4:
			return test5;
			break;
		default:
			return test1;
			break;
	}
}

vector<int> Datos::getPartitionTrain(int index){
	switch(index){
		case 0:
			return train1;
			break;
		case 1:
			return train2;
			break;
		case 2:
			return train3;
			break;
		case 3:
			return train4;
			break;
		case 4:
			return train5;
			break;
		default:
			return train1;
			break;
	}
}

vector<vector<float>> Datos::getData(){
	return matrixData;
}
vector<int> Datos::getLabels(){
	return vectorLabel;
}

int Datos::getAttributeSize(){
	return matrixData[0].size();
}

int Datos::getDataSize(){
	return matrixData.size();
}

void Datos::setData(string path){
	clearData();
	readData(path);
	normalizeData();
	partitionData();
}
