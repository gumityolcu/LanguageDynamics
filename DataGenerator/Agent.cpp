#include "Agent.h"
#define MAXRND 10;

Agent::Agent()
{

}

Agent::Agent(int M, int S, int memory=0, int init=10)
{
    std::random_device r;
    this->seed=r();
    this->memory=memory;
    this->rnd.seed(this->seed);
    std::uniform_int_distribution<int> unifS(0,S-1);

    int incBase;

    if(memory>0)
    {
        if(init>memory)
        {
            init=memory;
        }
        this->updateHistory.resize(M);
    }
    incBase=init;

    this->A=Eigen::MatrixXi::Zero(M,S);
    this->rowsums=std::vector<int>(M,0);
    this->colsums=std::vector<int>(S,0);
    // For each meaning
    for(int r=0;r<M;r++)
    {
        // For incBase many times
        for(int i=incBase;i>0;i--)
        {
            // Select a random symbol and increment association
            int c=unifS(this->rnd);
            this->incA(r,c);
            if(memory>0)
            {
                // Update the memory history if necessary
                this->updateHistory[r].push(c);
            }
        }
    }

    //INITIALIZE WITH IDENTITY MATRIX
    /*for(int a=0;a<M;a++)
    {
        this->rowsums[a]=incBase;
        this->colsums[a]=incBase;
        this->A=incBase*Eigen::MatrixXi::Identity(M,S);
        std::queue<int> x;
        for(int i=0;i<incBase;i++)
        {
            x.push(a);
        }
        this->updateHistory[a]=x;
    }*/
}

Agent::~Agent(){}

std::pair<int,int> Agent::speak()
{
    std::uniform_int_distribution<int> unifM(0,this->A.rows()-1);

    std::pair<int,int> ret;

    ret.first=unifM(this->rnd);

    /*if(this->rowsums[ret.first]==0)
    {
        std::uniform_int_distribution<int> unifS(0,this->A.cols()-1);
        int symbol=unifS(rnd);
        if(symbol<0)
        {
            int a;
        }

        if(this->memory)
        {
            //If model contains memory
            //NOTE
            if(this->updateHistory[ret.first].size()>0)
            {
                this->decA(ret.first,this->updateHistory[ret.first].front());
                this->updateHistory[ret.first].pop();
            }
            this->updateHistory[ret.first].push(symbol);
        }
        this->incA(ret.first, symbol);
    }*/
    std::uniform_int_distribution<int> unifRow(1,this->rowsums[ret.first]);
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
    // NOTE DELETE THIS PART!!!!!!!!!!!!!!!!!!!!! THIS IS A HACK!!!
    if(this->colsums[sigma]==0)
    {
        //If can't find meaning for the symbol, randomly select one meaning and change internal state accordingly
        std::uniform_int_distribution<int> unifM(0,this->A.rows()-1);
        int mu=unifM(rnd);

        if(this->memory>0)
        {
            this->updateMemory(mu,sigma);
        }
        else
        {
            this->incA(mu,sigma);
        }
    }

    std::uniform_int_distribution<int> unifCol(1,this->colsums[sigma]);
    int rn=unifCol(this->rnd);
    int sum=0;
    int i;
    for(i=0;(i<this->A.rows())&&(rn>sum);i++)
    {
        sum += this->A(i,sigma);
    }
    return i-1;
}

std::ostream & operator << (std::ostream &out, const Agent &x)
{
    //out << x.A;
    for(int r=0;r<x.A.rows();r++)
    {
        for(int c=0;c<x.A.cols();c++)
        {
            out<<x.A(r,c);
            if((r<x.A.rows()-1)||(c<x.A.cols()-1))
            {
                out<<" ";
            }
        }
    }
    return out;
}

void Agent::setA(int row, int col, int val)
{
    int old = this->A(row, col);
    this->rowsums[row]=this->rowsums[row]+val-old;
    this->colsums[col]=this->colsums[col]+val-old;
    this->A(row, col)=val;
}

int Agent::getA(int row, int col)
{
    return this->A(row, col);
}

void Agent::incA(int row, int col)
{
    this->A(row, col)++;
    this->rowsums[row]++;
    this->colsums[col]++;
}

void Agent::decA(int row, int col)
{
    this->A(row, col)--;
    this->rowsums[row]--;
    this->colsums[col]--;
}

Eigen::MatrixXi Agent::getMatrix()
{
    return this->A;
}

void Agent::updateMemory(int m, int s)
{
    if(this->updateHistory[m].size()==this->memory)
    {
        this->decA(m,this->updateHistory[m].front());
        this->updateHistory[m].pop();
    }
    this->updateHistory[m].push(s);
    this->incA(m,s);
}

bool Agent::hasMemory()
{
    return (memory>0);
}