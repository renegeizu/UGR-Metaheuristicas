#ifndef __DATOS_H
#define __DATOS_H

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Datos{
	private:
		void clearData();
		void normalizeData();
		void partitionData();
		void readData(string path);
		vector<vector<float>> matrixData;
		vector<int> vectorLabel;
		vector<int> train1, test1, train2, test2, train3, test3, train4, test4, train5, test5;
	public:
		Datos();
		vector<int> getParticionTest(int index);
		vector<int> getParticionTrain(int index);
		vector<vector<float>> getDatos();
		vector<int> getEtiquetas();
		int getTamAtributos();
		int getTamDatos();
		void leerDatos(string path);
};

#endif
