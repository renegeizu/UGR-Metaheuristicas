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
		vector<vector<float>> matrixData;
		vector<int> vectorLabel;
		vector<int> train1, test1, train2, test2, train3, test3, train4, test4, train5, test5;
		void clearData();
		void normalizeData();
		void partitionData();
		void readData(string path);
	public:
		Datos();
		Datos(string path);
		vector<int> getPartitionTest(int index);
		vector<int> getPartitionTrain(int index);
		vector<vector<float>> getData();
		vector<int> getLabels();
		int getAttributeSize();
		int getDataSize();
		void setData(string path);
};

#endif
