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
        std::cout<<std::endl<<std::endl<<std::endl;
        std::cout<<"Agent 0:"<<std::endl;
        for(int r=0;r<this->m->getAgent(0).A.rows();r++)
        {
            std::cout<<r<<": ";
            std::queue<int> q=this->m->getAgent(0).updateHistory[r];
            while(!q.empty())
            {
                std::cout<<q.front()<<" ";
                q.pop();
            }
                std::cout<<std::endl;
        }

        std::cout<<"Agent 1:"<<std::endl;
        for(int r=0;r<this->m->getAgent(1).A.rows();r++)
        {
            std::cout<<r<<": ";
            std::queue<int> q=this->m->getAgent(1).updateHistory[r];
            while(!q.empty())
            {
                std::cout<<q.front()<<" ";
                q.pop();
            }
            std::cout<<std::endl;
        }


        std::cout<<std::endl<<std::endl;


        std::cout<<"Running at time "<<T<<std::endl<<std::endl;
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