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
	echo "${color}Directorio 'bin' listo${nocolor}"
else
	mkdir $bin
	echo "${color}Directorio 'bin' creado${nocolor}"
fi
if [ -d $obj ];
then
	echo "${color}Directorio 'obj' listo${nocolor}"
else
	mkdir $obj
	echo "${color}Directorio 'obj' creado${nocolor}"
fi
if [ -d $soluciones ];
then
	echo "${color}Directorio 'sol' listo${nocolor}"
else
	mkdir $soluciones
	echo "${color}Directorio 'sol' creado${nocolor}"
fi

#Usa make clean para limpiar
echo -e "${color}Limpiando los Directorios...\n${nocolor}"
make clean

#Compila el codigo
echo -e "\n${color}Compilando en Codigo...\n${nocolor}"
make

#Se mueve a la carpeta bin
cd $bin

#Se lanzan las ejecuciones de la Practica 01
#Los resultados se almacenan en 'sol'
echo "\n${color}Ejecutando Ozone para 1NN...\n${nocolor}"
$bin/ClasificadorKNN 1 1 0 >> $soluciones/"Ozone 1NN"
echo "\n${color}Ejecutando Ozone para BL...\n${nocolor}"
$bin/ClasificadorKNN 1 2 0 >> $soluciones/"Ozone BL"
echo "\n${color}Ejecutando Ozone para RELIEF...\n${nocolor}"
$bin/ClasificadorKNN 1 3 0 >> $soluciones/"Ozone RELIEF"
echo "\n${color}Ejecutando Parkinsons para 1NN...\n${nocolor}"
$bin/ClasificadorKNN 2 1 0 >> $soluciones/"Parkinsons 1NN"
echo "\n${color}Ejecutando Parkinsons para BL...\n${nocolor}"
$bin/ClasificadorKNN 2 2 0 >> $soluciones/"Parkinsons BL"
echo "\n${color}Ejecutando Parkinsons para RELIEF...\n${nocolor}"
$bin/ClasificadorKNN 2 3 0 >> $soluciones/"Parkinsons RELIEF"
echo "\n${color}Ejecutando Spectf-Heart para 1NN...\n${nocolor}"
$bin/ClasificadorKNN 3 1 0 >> $soluciones/"Spectf-Heart 1NN"
echo "\n${color}Ejecutando Spectf-Heart para BL...\n${nocolor}"
$bin/ClasificadorKNN 3 2 0 >> $soluciones/"Spectf-Heart BL"
echo "\n${color}Ejecutando Spectf-Heart para RELIEF...\n${nocolor}"
$bin/ClasificadorKNN 3 3 0 >> $soluciones/"Spectf-Heart RELIEF"
