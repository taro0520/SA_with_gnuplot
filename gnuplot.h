#ifndef __GNUPLOT_H_INCLUDED__
#define __GNUPLOT_H_INCLUDED__

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

extern void writeEvolutionHead(int, int);
extern void writeEvolution(int, double);
extern void writeEvolutionEnd();

#endif
