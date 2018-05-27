#include <buffer.h>

bool Buffer::validateDataSet(int optionFile){
	return (optionFile != 1 && optionFile != 2 && optionFile != 3);
}

void Buffer::printDataSetError(){
	cout << "Error al escoger el archivo" << endl;
	cout << "1 -> Ozone" << endl;
	cout << "2 -> Parkinsons" << endl;
	cout << "3 -> Spectf-Heart" << endl;
}

bool Buffer::validateAlgorithm(int optionAlgorithm){
	return (optionAlgorithm != 1 && optionAlgorithm != 2 && optionAlgorithm != 3 && optionAlgorithm != 4 && optionAlgorithm != 5);
}

void Buffer::printAlgorithmError(){
	cout << "Error al escoger el algoritmo" << endl;
	cout << "1 -> 1-NN" << endl;
	cout << "2 -> Busqueda Local" << endl;
	cout << "3 -> Greedy Relief" << endl;
	cout << "4 -> Enfriamiento Simulado" << endl;
	cout << "5 -> ILS" << endl;
}

void Buffer::printDataSet(int optionFile){
	switch(optionFile){
		case 1:{
			cout << "----------------------------------------------" << endl;
			cout << "Archivo de Datos: Ozone" << endl;
			break;
		}
		case 2:{
			cout << "----------------------------------------------" << endl;
			cout << "Archivo de Datos: Parkisons" << endl;
			break;
		}
		case 3:{
			cout << "----------------------------------------------" << endl;
			cout << "Archivo de Datos: Spectf-Heart" << endl;
			break;
		}
	}
}

void Buffer::printAlgorithm(int optionAlgorithm){
	switch(optionAlgorithm){
		case 1:{
			cout << "----------------------------------------------" << endl;
			cout << "Algoritmo: 1-NN" << endl;
			break;
		}
		case 2:{
			cout << "----------------------------------------------" << endl;
			cout << "Algoritmo: Busqueda Local" << endl;
			break;
		}
		case 3:{
			cout << "----------------------------------------------" << endl;
			cout << "Algoritmo: Greedy Relief" << endl;
			break;
		}
		case 4:{
			cout << "----------------------------------------------" << endl;
			cout << "Algoritmo: Enfriamiento Simulado" << endl;
			break;
		}
		case 5:{
			cout << "----------------------------------------------" << endl;
			cout << "Algoritmo: ILS" << endl;
			break;
		}
	}
}

int Buffer::getFromFile(string path, int &optionFile, int &optionAlgorithm, unsigned long &chosenSeed){
	ifstream file(path);
	string row;
	getline(file, row, ' ');
	optionFile = stoi(row);
	if(validateDataSet(optionFile)){
		file.close();
		printDataSetError();
		return -1;
	}
	getline(file, row, ' ');
	optionAlgorithm = stoi(row);
	if(validateAlgorithm(optionAlgorithm)){
		file.close();
		printAlgorithmError();
		return -1;
	}
	getline(file, row);
	unsigned long auxSeed = stoul(row);
	if(auxSeed != 0){
		chosenSeed = auxSeed;
	}
	file.close();
	printDataSet(optionFile);
	printAlgorithm(optionAlgorithm);
	cout << "----------------------------------------------" << endl;
	cout << "Semilla Escogida: " << chosenSeed << endl;
	return 1;
}

int Buffer::getFromParameter(string pathOptionFile, string pathOptionAlgorithm, string pathChosenSeed, int &optionFile, int &optionAlgorithm, unsigned long &chosenSeed){
	string readOptionFile(pathOptionFile);
	string readOptionAlgorithm(pathOptionAlgorithm);
	string readChosenSeed(pathChosenSeed);
	optionFile = stoi(readOptionFile);
	if(validateDataSet(optionFile)){
		printDataSetError();
		return -1;
	}
	optionAlgorithm = stoi(readOptionAlgorithm);
	if(validateAlgorithm(optionAlgorithm)){
		printAlgorithmError();
		return -1;
	}
	unsigned long auxSeed = stoul(readChosenSeed);
	if(auxSeed != 0){
		chosenSeed = auxSeed;
	}
	printDataSet(optionFile);
	printAlgorithm(optionAlgorithm);
	cout << "----------------------------------------------" << endl;
	cout << "Semilla Escogida: " << chosenSeed << endl;
	return 1;
}

void Buffer::getFromTerminal(int &optionFile, int &optionAlgorithm, unsigned long &chosenSeed){
	while(validateDataSet(optionFile)){
		cout << "----------------------------------------------" << endl;
		cout << "Elija el Archivo de Datos:" << endl;
		cout << "\tOpcion 1 -> Ozone" << endl;
		cout << "\tOpcion 2 -> Parkinsons" << endl;
		cout << "\tOpcion 3 -> Spectf-Heart" << endl;
		cin >> optionFile;
	}
	while(validateAlgorithm(optionAlgorithm)){
		cout << "----------------------------------------------" << endl;
		cout << "Elija el Algoritmo:" << endl;
		cout << "\tOpcion 1 -> 1-NN" << endl;
		cout << "\tOpcion 2 -> Busqueda Local" << endl;
		cout << "\tOpcion 3 -> Greedy Relief" << endl;
		cout << "\tOpcion 4 -> Enfriamiento Simulado" << endl;
		cout << "\tOpcion 5 -> ILS" << endl;
		cin >> optionAlgorithm;
	}
	cout << "----------------------------------------------" << endl;
	cout << "Elija la Semilla:" << endl;
	cout << "\t0 -> Semilla por Defecto (20000913)" << endl;
	unsigned long auxSeed;
	cin >> auxSeed;
	if(auxSeed != 0){
		chosenSeed = auxSeed;
	}
}
