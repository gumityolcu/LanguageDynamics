#include "Model.h"


Model::Model(){}
Model::Model(int N, int M, int S, int m)
{
    std::random_device r;
    this->seed=r();
    this->rnd.seed(this->seed);

    this->N=N;
    this->M=M;
    this->S=S;
    this->m=m;
    for(int i=0;i<N;i++)
    {
        this->agents.emplace_back(Agent(M,S,m));
        std::cout<<this->agents[i]<<std::endl<<std::endl<<"======"<<std::endl<<std::endl;
        for(int j=0;j<N;j++)
        {
            if(i!=j)
            {
                this->combinations.emplace_back(std::pair<int,int>(i,j));
            }
        }
    }
}
Model::~Model(){}



// Empty update functions, these will be overridden by actual model classes
void Model::FSpSuc(Agent& speaker, int m, int s){return;}
void Model::FLisSuc(Agent& listener, int m, int s){return;}
void Model::FSpFail(Agent& speaker, int m_s, int s, int m_l){return;}
void Model::FLisFail(Agent& listener, int m_s, int s, int m_l){return;}





std::string Model::toStr()
{
    std::string ret="";
    ret+=this->name+"|"+std::to_string(this->N)+"|"+std::to_string(this->M)+"|"+std::to_string(this->S)+"|"+std::to_string(this->m);
    return ret;
}

int Model::getN()
{
    return this->N;
}

void Model::runOnce()
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

Agent& Model::getAgent(int index)
{
    return this->agents[index];
}



bool Model::interact(Agent& speaker, Agent& listener)
{
    std::pair<int,int> fromSpeaker;
    int m_s,sigma,m_l;
    fromSpeaker=speaker.speak();
    m_s=fromSpeaker.first;
    sigma=fromSpeaker.second;
    std::cout<<"Speaker selected "<<m_s<<" and "<<sigma<<std::endl;
    m_l=listener.listen(sigma);
    std::cout<<"Listener selected "<<m_l<<std::endl;
    if(m_s==m_l)
    {
        std::cout<<"Success!"<<std::endl;

        this->FSpSuc(speaker, m_s, sigma);
        this->FLisSuc(listener, m_l, sigma);
    }
    else
    {
        std::cout<<"Failure!"<<std::endl;

        this->FSpFail(speaker, m_s, sigma, m_l);
        this->FLisFail(listener,m_s,sigma,m_l);
    }
    return (m_s==m_l);
}

bool Model::interact(int speaker, int listener)
{
    std::cout<<"S: "<<speaker<<"\tL:"<<listener<<std::endl;
    return this->interact(this->agents[speaker],this->agents[listener]);
}