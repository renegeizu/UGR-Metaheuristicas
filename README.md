Clasificador KNN C++
==========

Clasificador KNN (1NN) con Busqueda Local y Greedy Relief


Directorios
--------------------

+ bin: Ejecutable
+ data: Conjuntos de Datos
+ include: Ficheros .h
+ lib: librerias
+ obj: Ficheros .o
+ sol: Ficheros con los Resultados // Tablas .xls
+ src: Codigo fuente .cpp


Uso del Ejecutable - ClasificadorKNN
---------------------------------------

+ Ejecucion con Entrada de Datos por Terminal: ./bin/ClasificadorKNN
+ Ejecucion con Entrada de Datos como Parametro: ./bin/ClasificadorKNN archivo algoritmo semilla
+ Ejecucion con Entrada de Datos por Archivo: ./bin/ClasificadorKNN documento


Uso del Ejecutable - XLSparser
---------------------------------

+ Ejecucion: ./bin/XLSparser hoja fila columna archivo


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


Opciones - ClasificadorKNN
-----------------------------

+ archivo: 1 (Ozone)     2 (Parkinsons)     3 (Spectf-Heart)
+ algoritmo: 1 (KNN)     2 (Busqueda Local)     3 (Greedy Relief)
+ semilla: 0 (Semilla Predefinida)     Otro valor


Opciones - XLSparser
-----------------------

+ hoja: numero de hoja del archivo .xls (0... n)
+ fila: fila en la que empieza (0... n)
+ columna: columna en la que empieza (0... n)
+ archivo: archivo de texto con los resultados del Clasificador

	
Ejemplos
--------------------

+ Ejecucion con Entrada de Datos como Parametro para Ozone, BL y semilla: ./bin/ClasificadorKNN 1 2 1012131415
+ Ejecucion con Entrada de Datos como Parametro para Ozone, BL y semilla predefinida: ./bin/ClasificadorKNN 1 2 0
