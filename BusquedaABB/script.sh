#!/bin/bash

#Arreglo de las diferentes n pruebas
N=(100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000) 

#Arreglo de las diferentes numeros a buscar
M=(322486 14700764 3128036 6337399 61396 10393545 2147445644 1295390003 450057883 187645041 1980098116 152503 5000 1493283650 214826 1843349527 1360839354 2109248666 2147470852 0) 

#Compilacion de los programas a probar

gcc mainOrden.c tiempo.c arbolBB.c -o insercion
#Recopilacion del muestreo para sacar la funcion

echo -e "Tiempos del Insercion\n" > TiemposInsercion.txt


for ((var = 0; var < 20; var++)); do
	for ((v = 0; v < 20; v++)); do
		echo -e "TEl tiempo en" "${N[var]}" "datos buscando "${M[v]}" es:\n" >> TiemposInsercion.txt

			./insercion "${N[var]}" "${M[v]}" < numeros10millones.txt >> TiemposInsercion.txt
	
	done


done

