#include "SA.h"

int main(int argc,char** argv)
{
    int run=stoi(argv[1]);
    int iteration=stoi(argv[2]);
    int bit=stoi(argv[3]);
    double temperature=stod(argv[4]);
    double alpha=stod(argv[5]);

    SA runmachine(run,iteration,bit,temperature,alpha);
    runmachine.start();
}