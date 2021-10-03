//gcc -Wall orden.cpp -lm -o grafica

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	 int NUM_COMANDOS=6;

    char * configGnuplot[] = {"set title \"Comparacion: NroDatos VS Tiempo\"", 
                                "set ylabel \"Tiempo Mili-Segundos (10e-6)\"",
                                "set xlabel \"NroDatos\"",
										  "plot \"CountingSortPython.txt\" using 1:2 with lines",

										  "replot \"CountingSortC++.txt\" using 1:2 with lines",

										  "replot \"CountingSortJava.txt\" using 1:2 with lines"

                               };

    FILE * ventanaGnuplot = popen ("gnuplot -persist", "w");

    // Ejecuta los comandos del GNU Plot uno por uno
    for (int i=0;i<NUM_COMANDOS;i++){
		 fprintf(ventanaGnuplot, "%s \n", configGnuplot[i]);
	 }

    return 0;

}
