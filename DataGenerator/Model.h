#ifndef LANGUAGEDYNAMICS_MODEL_H
#define LANGUAGEDYNAMICS_MODEL_H

#include "Agent.h"
#include <string>
class Model
{
protected:
    int N; // # of agents
    int M; // # of meanings
    int S; // # of symbols
    int m; // memory size
    std::vector<Agent> agents;
    std::string name="plain";
    std::vector<std::pair<int,int>> combinations;
    std::default_random_engine rnd;
    unsigned int seed;

    bool interact(Agent& speaker, Agent& listener);
    virtual void FSpSuc(Agent& speaker, int m, int s);
    virtual void FLisSuc(Agent& listener, int m, int s);
    virtual void FSpFail(Agent& speaker, int m_s, int s, int m_l);
    virtual void FLisFail(Agent& listener, int m_s, int s, int m_l);
public:
    int getN();
    Agent& getAgent(int index);
    void runOnce();
    bool interact(int speaker, int listener);
    std::string toStr();
    Model();
    Model(int N, int M, int S, int m);
    ~Model();

};

#endif