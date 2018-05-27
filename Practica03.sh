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
echo -e "\n${color}Ejecutando Ozone para Enfriamiento Simulado...\n${nocolor}"
$bin/ClasificadorKNN 1 4 0 >> $soluciones/"Ozone EnfSimulado.txt"
echo -e "${color}Ejecutando Ozone para ILS...\n${nocolor}"
$bin/ClasificadorKNN 1 5 0 >> $soluciones/"Ozone ILS.txt"
echo -e "${color}Ejecutando Parkinsons para Enfriamiento Simulado...\n${nocolor}"
$bin/ClasificadorKNN 2 4 0 >> $soluciones/"Parkinsons EnfSimulado.txt"
echo -e "${color}Ejecutando Parkinsons para ILS...\n${nocolor}"
$bin/ClasificadorKNN 2 5 0 >> $soluciones/"Parkinsons ILS.txt"
echo -e "${color}Ejecutando Spectf-Heart para Enfriamiento Simulado...\n${nocolor}"
$bin/ClasificadorKNN 3 4 0 >> $soluciones/"Spectf-Heart EnfSimulado.txt"
echo -e "${color}Ejecutando Spectf-Heart para ILS...\n${nocolor}"
$bin/ClasificadorKNN 3 5 0 >> $soluciones/"Spectf-Heart ILS.txt"

#Se lanzan las ejecuciones de XLSparser
#Los resultados se almacenan en 'sol', en un fichero .xls
echo -e "\n${color}Insertando datos en .xls para Ozone Enfriamiento Simulado...\n${nocolor}"
$bin/XLSparser 2 4 1 $soluciones/"Ozone EnfSimulado.txt"
echo -e "${color}Insertando datos en .xls para Ozone ILS...\n${nocolor}"
$bin/XLSparser 2 14 1 $soluciones/"Ozone ILS.txt"
echo -e "${color}Insertando datos en .xls para Parkinsons Enfriamiento Simulado...\n${nocolor}"
$bin/XLSparser 2 4 5 $soluciones/"Parkinsons EnfSimulado.txt"
echo -e "${color}Insertando datos en .xls para Parkinsons ILS...\n${nocolor}"
$bin/XLSparser 2 14 5 $soluciones/"Parkinsons ILS.txt"
echo -e "${color}Insertando datos en .xls para Spectf-Heart Enfriamiento Simulado...\n${nocolor}"
$bin/XLSparser 2 4 9 $soluciones/"Spectf-Heart EnfSimulado.txt"
echo -e "${color}Insertando datos en .xls para Spectf-Heart ILS...\n${nocolor}"
$bin/XLSparser 2 14 9 $soluciones/"Spectf-Heart ILS.txt"
