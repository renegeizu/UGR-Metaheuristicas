#include <clasificador.h>
#include <cstdlib>
#include <datos.h>
#include <generador.h>
#include <iostream>
#include <localsearch.h>
#include <buffer.h>
#include <relief.h>
#include <temporizador.h>

using namespace std;

int main(int argc, char* argv[]){
	unsigned long semilla = 20000913;
	int opcionArchivo = 0, opcionAlgoritmo = 0;
	float tMedio = 0.0, tasaMedia = 0.0;
	Buffer inputData;
	if(argc == 2){
		int valor = inputData.getFromFile(argv[1], opcionArchivo, opcionAlgoritmo, semilla);
		if(valor == -1){
			return -1;
		}
	}else if(argc == 4){
		int valor = inputData.getFromParameter(argv[1], argv[2], argv[3], opcionArchivo, opcionAlgoritmo, semilla);
		if(valor == -1){
			return -1;
		}
	}else{
		inputData.getFromTerminal(opcionArchivo, opcionAlgoritmo, semilla);
	}
	Generador aleatorio(semilla);
	srand(semilla);
	Datos conjuntoDatos;
	switch(opcionArchivo){
		case 1:{
			cout << "----------------------------------------------" << endl;
			cout << "Leyendo, normalizando y particionando datos Ozone..." << endl;
			conjuntoDatos.setData("data/ozone-320.arff");
			break;
		}
		case 2:{
			cout << "----------------------------------------------" << endl;
			cout << "Leyendo, normalizando y particionando datos Parkinsons..." << endl;
			conjuntoDatos.setData("data/parkinsons.arff");
			break;
		}
		case 3:{
			cout << "----------------------------------------------" << endl;
			cout << "Leyendo, normalizando y particionando datos Spectf-Heart..." << endl;
			conjuntoDatos.setData("data/spectf-heart.arff");
			break;
		}
	}
	Clasificador KNN(conjuntoDatos.getData(), conjuntoDatos.getLabels(), 0.2);
	switch(opcionAlgoritmo){
		case 1:{
			vector<float> pesos(conjuntoDatos.getAttributeSize(), 1.0);
			float tasa;
			for(int i = 0; i < 5; ++i){
				Temporizador temp;
				cout << "----------------------------------------------" << endl;
				cout << "Comienzo del procesamiento de la" << endl << "particion " << i+1 << ":" << endl;
				temp.start();
				tasa = KNN.Test(conjuntoDatos.getPartitionTrain(i), conjuntoDatos.getPartitionTest(i), pesos);
				temp.stop();
				tMedio += temp.getTime();
				tasaMedia += tasa;
				cout << "\tPorcentaje Acierto: " << tasa << "%" << endl;
				cout << "\tTiempo Ejecucion: " << temp.getTime() << " seg." << endl;
				cout << "\tTasa Reduccion: 0%" << endl;
				cout << "\tAgregacion: " << (float)0.5 * (float)tasa << "%" << endl;
			}
			break;
		}
		case 2:{
			LocalSearch LS(conjuntoDatos.getData(), conjuntoDatos.getLabels(), 0.2);
			vector<float> pesos, pesosAux;
			float tasa;
			for(int i = 0; i < conjuntoDatos.getAttributeSize(); ++i){
				pesos.push_back(aleatorio.randFloat(0.0, 1.0));
			}
			for(int i = 0; i < 5; ++i){
				Temporizador temp;
				pesosAux = pesos;
				int vecinosGenerados = 20 * (conjuntoDatos.getAttributeSize());
				cout << "----------------------------------------------" << endl;
				cout << "Comienzo del procesamiento de la" << endl << "particion " << i+1 << ":" << endl;
				temp.start();
				LS.runnable(conjuntoDatos.getPartitionTrain(i), vecinosGenerados, pesosAux);
				temp.stop();
				tasa = KNN.Test(conjuntoDatos.getPartitionTrain(i), conjuntoDatos.getPartitionTest(i), pesosAux);
				tMedio += temp.getTime();
				tasaMedia += tasa;
				int pesosDescartados = 0;
				for(int j = 0; j < pesosAux.size(); ++j){
					if(pesosAux[j] < 0.2){
						pesosDescartados++;
					}
				}
				double tasaReduccion = (float)100.0 * ((float)pesosDescartados/(float)pesosAux.size());
				cout << "\tPorcentaje Acierto: " << tasa << "%" << endl;
				cout << "\tTiempo Ejecucion: " << temp.getTime() << " seg." << endl;
				cout << "\tTasa Reduccion: " << tasaReduccion << "%" << endl;
				cout << "\tAgregacion: " << (float)0.5 * (float)tasa + (float)0.5 * (float)tasaReduccion << "%" << endl;
			}
			break;
		}
		case 3:{
			Relief greedy(conjuntoDatos.getData(), conjuntoDatos.getLabels());
			vector<float> pesos(conjuntoDatos.getAttributeSize(), 0.0), pesosAux;
			float tasa;
			for(int i = 0; i < 5; ++i){
				Temporizador temp;
				pesosAux = pesos;
				cout << "----------------------------------------------" << endl;
				cout << "Comienzo del procesamiento de la" << endl << "particion " << i+1 << ":" << endl;
				temp.start();
				greedy.run(conjuntoDatos.getPartitionTrain(i), pesosAux);
				temp.stop();
				tasa = KNN.Test(conjuntoDatos.getPartitionTrain(i), conjuntoDatos.getPartitionTest(i), pesosAux);
				tMedio += temp.getTime();
				tasaMedia += tasa;
				cout << "\tPorcentaje Acierto: " << tasa << "%" << endl;
				cout << "\tTiempo Ejecucion: " << temp.getTime() << " seg." << endl;
				cout << "\tTasa Reduccion: 0%" << endl;
				cout << "\tAgregacion: " << (float)0.5 * (float)tasa << "%" << endl;
			}
			break;
		}
	}
	cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
	cout<<"Porcentaje Medio de Acierto: " << tasaMedia/5 << endl;
	cout<<"Tiempo Medio de Ejecucion: " << tMedio/5 << endl;
	return 0;
}
