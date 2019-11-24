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
        //std::cout<<"Running at time "<<T<<std::endl<<std::endl;
        this->m->runOnce();
        this->T++;
    }
}

void Simulation::saveResults(std::string path)
{
    std::string fname=path;
    if(fname=="")
    {
        fname=this->m->toStr()+"|T="+std::to_string(this->T)+".txt";
    }
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

std::vector<Eigen::MatrixXi> Simulation::getMatrices()
{
    std::vector<Eigen::MatrixXi> ret;
    for(int i=0; i<this->m->getN();i++)
    {
        ret.push_back(this->m->getAgent(i).A);
    }
    return ret;
}