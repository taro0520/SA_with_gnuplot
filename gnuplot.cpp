#include "gnuplot.h"

void
writeEvolutionHead(int iteration, int fitness_max)
{
	cout << "set terminal postscript eps color solid 'Times,12'" << endl;
    cout << "set grid" << endl
     << "set term png" << endl
     << "set output 'SA.png'" << endl
     << "set xlabel 'Iteration'" << endl
     << "set ylabel 'Fitness'" << endl
     << "set title 'SA'" << endl
     << "set key right bottom" << endl
	 << "set xrange [0:" << iteration << "]" << endl
     << "set xtics 0," << iteration/10 << "," << iteration << endl
	 << "set yrange [0:" << fitness_max << "]" << endl
     << "set ytics 0," << fitness_max/10 << "," << fitness_max << endl
     << "plot '-' u 1:2 smooth bezier with lines linestyle 1 linewidth 3 title 'SA'" << endl;
}

void
writeEvolution(int current_iteration, double fitness)
{
    cout << current_iteration << " " << fitness << endl;
}

void
writeEvolutionEnd()
{
    cout << "e" << endl
     << "pause 0.000000" << endl;
}