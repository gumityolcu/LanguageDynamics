#include "Agent.h"
#define MAXRND 10;

Agent::Agent()
{

}

Agent::Agent(int M, int S, int memory)
{
    std::random_device r;
    this->rnd.seed(r());
    std::uniform_int_distribution<int> unifS(0,S-1);

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

    this->A=Eigen::MatrixXi::Zero(M,S);
    this->rowsums=Eigen::VectorXi::Zero(M);
    this->colsums=Eigen::VectorXi::Zero(S);

    // For each meaning
    for(int r=0;r<M;r++)
    {
        // For incBase many times
        for(int i=incBase;i>0;i--)
        {
            // Select a random symbol and increment association
            int c=unifS(this->rnd);
            this->A(r,c)++;
            this->rowsums(r)++;
            this->colsums(c)++;
            if(memory>0)
            {
                // Update the memory history if necessary
                this->updateHistory[r].push(c);
            }
        }
    }
}

Agent::~Agent()
{

}

std::pair<int,int> Agent::speak()
{
    std::uniform_int_distribution<int> unifM(0,this->A.rows()-1);

    std::pair<int,int> ret;

    ret.first=unifM(this->rnd);
    std::uniform_int_distribution<int> unifRow(1,this->rowsums(ret.first));
    int rn=unifRow(this->rnd);
    int sum=0;
    int i;
    for(i=0;(i<this->A.cols())&&(rn>sum);i++)
    {
        sum += this->A(ret.first,i);
    }
    ret.second = i-1;

    return ret;
}

int Agent::listen(int sigma)
{
    std::uniform_int_distribution<int> unifCol(1,this->colsums(sigma));

    int rn=unifCol(this->rnd);
    int sum=0;
    int i;
    for(i=0;(i<this->A.rows())&&(rn>sum);i++)
    {
        sum += this->A(i,sigma);
    }
    return i-1;
}
