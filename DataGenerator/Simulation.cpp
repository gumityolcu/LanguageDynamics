#include "Simulation.h"

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
    }
}

void Simulation::saveResults(std::string path)
{
    std::string fname=this->m->toStr()+"|"+std::to_string(this->T);
}