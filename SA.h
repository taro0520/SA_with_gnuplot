#ifndef __SA_H__
#define __SA_H__
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <fstream>
#include <math.h>
using namespace std;

class SA
{
    public:
        SA(int run,int iteration,int bit,double temperature,double alpha);
        void start();
    private:
        void Initial(vector<int>&solution);
        int Evaluate(vector<int>soution);
        vector<int>Transition(vector<int>solution);
        void Show(vector<int>solution);

        int run;
        int iteration;
        int bit;
        double temperature;
        double alpha;
};

#endif