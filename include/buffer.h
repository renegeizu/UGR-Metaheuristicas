#ifndef __BUFFER__H
#define __BUFFER__H

#include <fstream>
#include <iostream>

using namespace std;

class Buffer{
	private:
		bool validateDataSet(int optionFile);
		void printDataSetError();
		bool validateAlgorithm(int optionAlgorithm);
		void printAlgorithmError();
		void printDataSet(int optionFile);
		void printAlgorithm(int optionAlgorithm);
	public:
		int getFromFile(string path, int &optionFile, int &optionAlgorithm, unsigned long &chosenSeed);
		int getFromParameter(string pathOptionFile, string pathOptionAlgorithm, string pathChosenSeed, int &optionFile, int &optionAlgorithm, unsigned long &chosenSeed);
		void getFromTerminal(int &optionFile, int &optionAlgorithm, unsigned long &chosenSeed);
};

#endif
