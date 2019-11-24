#include "Simulation.h"
#include <fstream>

Simulation::Simulation(){}

Simulation::Simulation(Model* m)
{
    this->m=m;
    this->T=0;
}

Simulation::~Simulation(){}

void Simulation::runForIterations(int IT)
{
    for(int i=0;i<IT;i++)
    {
        this->m->runOnce();
        this->T++;
        std::cout<<"Running at time "<<T<<std::endl<<std::endl;
    }
}

void Simulation::saveResults(std::string path)
{
    std::string fname=this->m->toStr()+"|T="+std::to_string(this->T)+".txt";
    std::ofstream file;
    file.open(fname);
    file<<this->T<<"|";
    for(int i=0;i<this->m->getN();i++)
    {
        file<<this->m->getAgent(i)<<"|";
    }
    file<<"END";
    file.close();
}