#include "Agent.h"
#include <random>
#define MAXRND 10;

Agent::Agent()
{

}

Agent::Agent(int M, int W, int memory)
{
    std::random_device r;
    std::default_random_engine rnd(r());
    int incBase;
    if(memory==0)
    {
        incBase=10;
    }
    else
    {
        this->updateHistory.resize(M);
        incBase=memory;
    }


    std::uniform_int_distribution<int> distW(0,W-1);
    this->A=Eigen::MatrixXi::Zero(M,W);
    this->rowsums=Eigen::VectorXi::Zero(M);
    this->colsums=Eigen::VectorXi::Zero(W);
    for(int r=0;r<M;r++)
    {
        for(int i=incBase;i>0;i--)
        {
            int c=distW(rnd);
            this->A(r,c)++;
            this->rowsums(r)++;
            this->colsums(c)++;
            if(memory>0)
            {
                this->updateHistory[r].push(c);
            }
        }
    }
}

Agent::~Agent()
{

}

bool Agent::speak()
{


}

int Agent::listen(int sigma)
{

}
