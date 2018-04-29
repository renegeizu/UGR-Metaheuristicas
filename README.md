Clasificador KNN C++
==========

Clasificador KNN (1NN) con Busqueda Local y Greedy Relief


Directorios
--------------------

+ bin: Ejecutable
+ data: Conjuntos de Datos
+ include: Ficheros .h
+ obj: Ficheros .o
+ sol: Ficheros con los Resultados // Tablas .xls
+ src: Codigo fuente .cpp


Uso del Ejecutable
--------------------
+ Ejecucion con Entrada de Datos por Terminal: ./ClasificadorKNN
+ Ejecucion con Entrada de Datos como Parametro: ./ClasificadorKNN archivo algoritmo semilla
+ Ejecucion con Entrada de Datos por Archivo: ./ClasificadorKNN documento


Formato del Archivo de Parametros
--------------------
+ archivo algoritmo semilla


Uso del Archivo Makefile
--------------------
+ Compilar el codigo fuente: make
+ Limpiar archivos de compilacion: make clean


Uso del Archivo Practica01.sh
--------------------
+ ./Practica01.sh


Opciones
--------------------
+ archivo: 1 (Ozone)     2 (Parkinsons)     3 (Spectf-Heart)
+ algoritmo: 1 (KNN)     2 (Busqueda Local)     3 (Greedy Relief)
+ semilla: 0 (Semilla Predefinida)     Otro valor

	
Ejemplos
--------------------
+ Ejecucion con Entrada de Datos como Parametro para Ozone, BL y semilla: ./ClasificadorKNN 1 2 1012131415
+ Ejecucion con Entrada de Datos como Parametro para Ozone, BL y semilla predefinida: ./ClasificadorKNN 1 2 0
