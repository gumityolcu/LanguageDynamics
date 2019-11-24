#include "Model.h"


Model::Model(){}
Model::Model(int N, int M, int S, std::string name)
{
    std::random_device r;
    this->seed=r();
    this->rnd.seed(this->seed);

    this->N=N;
    for(int i=0;i<N;i++)
    {
        this->agents.emplace_back(Agent(M,S,0));
        for(int j=0;j<N;j++)
        {
            if(i!=j)
            {
                this->combinations.emplace_back(std::pair<int,int>(i,j));
            }
        }
    }
    this->M=M;
    this->S=S;
    this->name=name;
}
Model::~Model(){}

void Model::runOnce(int IT)
{
    for(int boundary=this->combinations.size(); boundary>0; boundary--)
    {
        std::uniform_int_distribution<int> unif(0,boundary-1);
        int r=unif(this->rnd);
        std::pair<int,int> sel=this->combinations[r];
        this->combinations[r]=this->combinations[boundary-1];
        this->combinations[boundary-1]=sel;
        this->interact(sel.first,sel.second);
    }
}


bool Model::interact(Agent& speaker, Agent& listener)
{
    std::pair<int,int> fromSpeaker;
    int m_s,sigma,m_l;
    fromSpeaker=speaker.speak();
    m_s=fromSpeaker.first;
    sigma=fromSpeaker.second;
    m_l=listener.listen(sigma);
    if(m_s==m_l)
    {
        this->FSpSuc(speaker, m_s, sigma);
        this->FLisSuc(listener, m_l, sigma);
    }
    else
    {
        this->FSpFail(speaker, m_s, sigma, m_l);
        this->FLisFail(listener,m_s,sigma,m_l);
    }
    return (m_s==m_l);
}

bool Model::interact(int speaker, int listener)
{
    return this->interact(this->agents[speaker],this->agents[listener]);
}