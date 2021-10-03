//gcc -Wall orden.cpp -lm -o grafica

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	 int NUM_COMANDOS=10;

    char * configGnuplot[] = {"set title \"Comparacion: NroDatos VS Tiempo\"", 
                                "set ylabel \"Tiempo\"",
                                "set xlabel \"NroDatos\"",
                                "plot \"BubbleSort.txt\" using 1:2 with lines",
										  "replot \"InsertionSort.txt\" using 1:2 with lines",
										  "replot \"MergeSort.txt\" using 1:2 with lines",
										  "replot \"QuickSort.txt\" using 1:2 with lines",
										  "replot \"CountingSort.txt\" using 1:2 with lines",
										  "replot \"HeapSort.txt\" using 1:2 with lines",
										  "replot \"SelectionSort.txt\" using 1:2 with lines"
                               };

    FILE * ventanaGnuplot = popen ("gnuplot -persist", "w");

    // Ejecuta los comandos del GNU Plot uno por uno
    for (int i=0;i<NUM_COMANDOS;i++){
		 fprintf(ventanaGnuplot, "%s \n", configGnuplot[i]);
	 }

    return 0;

}