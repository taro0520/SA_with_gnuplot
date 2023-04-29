#include "SA.h"
#include "gnuplot.h"

SA::SA(int run,int iteration,int bit,double temperature,double alpha)
{
    this->run=run;
    this->iteration=iteration;
    this->bit=bit;
    this->temperature=temperature;
    this->alpha=alpha;

    unsigned seed;
    seed=(unsigned)time(NULL);
    srand(seed);
}
void SA::Initial(vector<int>&solution)
{
    for(int i=0;i<bit;i++)
        solution[i]=rand()%2;
}
int SA::Evaluate(vector<int>solution)
{
    int c=0;
    for(int i=0;i<bit;i++)
        c+=solution[i];
    return c;
}
vector<int>SA::Transition(vector<int>solution)
{
    int rnd=rand()%bit;
    if(solution[rnd])
        solution[rnd]=0;
    else
        solution[rnd]=1;
    return solution;
}
void SA::start()
{
    int fitness1,fitness2,iter,run_;
    run_=run;
    vector<double>answer(iteration, 0.0);
    while(run--)
    {
        vector<int>S(bit);
        vector<int>V(bit);
        iter=iteration;
        Initial(S);
        fitness1=Evaluate(S);
        
        while(iter--)
        {
            V=Transition(S);
            fitness2=Evaluate(V);
            if(fitness2>=fitness1)
            {
                fitness1=fitness2;
                S=V;
            }
            else
            {
                double r= (double)rand()/(RAND_MAX+1.0);
                double prob=exp((double)(fitness2-fitness1)/temperature);
                if(r<prob)
                {
                    fitness1=fitness2;
                    S=V;
                }
            }
            temperature*=alpha;
            answer[iteration - iter - 1]+=fitness1;
        }
    }
    
    for(int i = 0; i < iteration; i++)
        answer[i]/=run_;
    writeEvolutionHead(iteration, bit+1);
    for(int i = 0; i < iteration; i++)
        writeEvolution(i, answer[i]);
    writeEvolutionEnd();
}