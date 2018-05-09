#!/bin/bash

#Uso: ./Practica01.sh

#Guardamos los directorios necesarios
bin=$(pwd)/bin
obj=$(pwd)/obj
soluciones=$(pwd)/sol

#Colores para los mensajes por terminal
nocolor='\033[0m'
color='\033[0;34m'

#Se crean los directorios "vacios" si no existen
if [ -d $bin ];
then
	echo -e "${color}Directorio 'bin' listo${nocolor}"
else
	mkdir $bin
	echo -e "${color}Directorio 'bin' creado${nocolor}"
fi
if [ -d $obj ];
then
	echo -e "${color}Directorio 'obj' listo${nocolor}"
else
	mkdir $obj
	echo -e "${color}Directorio 'obj' creado${nocolor}"
fi
if [ -d $soluciones ];
then
	echo -e "${color}Directorio 'sol' listo${nocolor}"
else
	mkdir $soluciones
	echo -e "${color}Directorio 'sol' creado${nocolor}"
fi

#Usa make clean para limpiar
echo -e "\n${color}Limpiando los Directorios...\n${nocolor}"
make clean

#Compila el codigo
echo -e "\n${color}Compilando en Codigo...\n${nocolor}"
make

#Se lanzan las ejecuciones de la Practica 01
#Los resultados se almacenan en 'sol'
echo -e "\n${color}Ejecutando Ozone para 1NN...\n${nocolor}"
$bin/ClasificadorKNN 1 1 0 >> $soluciones/"Ozone 1NN.txt"
echo -e "${color}Ejecutando Ozone para BL...\n${nocolor}"
$bin/ClasificadorKNN 1 2 0 >> $soluciones/"Ozone BL.txt"
echo -e "${color}Ejecutando Ozone para RELIEF...\n${nocolor}"
$bin/ClasificadorKNN 1 3 0 >> $soluciones/"Ozone RELIEF.txt"
echo -e "${color}Ejecutando Parkinsons para 1NN...\n${nocolor}"
$bin/ClasificadorKNN 2 1 0 >> $soluciones/"Parkinsons 1NN.txt"
echo -e "${color}Ejecutando Parkinsons para BL...\n${nocolor}"
$bin/ClasificadorKNN 2 2 0 >> $soluciones/"Parkinsons BL.txt"
echo -e "${color}Ejecutando Parkinsons para RELIEF...\n${nocolor}"
$bin/ClasificadorKNN 2 3 0 >> $soluciones/"Parkinsons RELIEF.txt"
echo -e "${color}Ejecutando Spectf-Heart para 1NN...\n${nocolor}"
$bin/ClasificadorKNN 3 1 0 >> $soluciones/"Spectf-Heart 1NN.txt"
echo -e "${color}Ejecutando Spectf-Heart para BL...\n${nocolor}"
$bin/ClasificadorKNN 3 2 0 >> $soluciones/"Spectf-Heart BL.txt"
echo -e "${color}Ejecutando Spectf-Heart para RELIEF...\n${nocolor}"
$bin/ClasificadorKNN 3 3 0 >> $soluciones/"Spectf-Heart RELIEF.txt"

#Se lanzan las ejecuciones de XLSparser
#Los resultados se almacenan en 'sol', en un fichero .xls
echo -e "\n${color}Insertando datos en .xls para Ozone 1NN...\n${nocolor}"
$bin/XLSparser 0 4 1 $soluciones/"Ozone 1NN.txt"
echo -e "${color}Insertando datos en .xls para Ozone BL...\n${nocolor}"
$bin/XLSparser 0 14 1 $soluciones/"Ozone BL.txt"
echo -e "${color}Insertando datos en .xls para Ozone RELIEF...\n${nocolor}"
$bin/XLSparser 0 24 1 $soluciones/"Ozone RELIEF.txt"
echo -e "${color}Insertando datos en .xls para Parkinsons 1NN...\n${nocolor}"
$bin/XLSparser 0 4 5 $soluciones/"Parkinsons 1NN.txt"
echo -e "${color}Insertando datos en .xls para Parkinsons BL...\n${nocolor}"
$bin/XLSparser 0 14 5 $soluciones/"Parkinsons BL.txt"
echo -e "${color}Insertando datos en .xls para Parkinsons RELIEF...\n${nocolor}"
$bin/XLSparser 0 24 5 $soluciones/"Parkinsons RELIEF.txt"
echo -e "${color}Insertando datos en .xls para Spectf-Heart 1NN...\n${nocolor}"
$bin/XLSparser 0 4 9 $soluciones/"Spectf-Heart 1NN.txt"
echo -e "${color}Insertando datos en .xls para Spectf-Heart BL...\n${nocolor}"
$bin/XLSparser 0 14 9 $soluciones/"Spectf-Heart BL.txt"
echo -e "${color}Insertando datos en .xls para Spectf-Heart RELIEF...\n${nocolor}"
$bin/XLSparser 0 24 9 $soluciones/"Spectf-Heart RELIEF.txt"
