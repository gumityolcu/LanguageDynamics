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
    int memory; // memory size
    std::vector<Agent> agents;
    std::string name="plain"; // Used for output file name
    std::vector<std::pair<int,int>> combinations; // Holds N choose 2 combinations of agents. Randomly sampled to select interacting pairs
    std::default_random_engine rnd;
    unsigned int seed;

    // Where the party happens
    bool interact(Agent& speaker, Agent& listener);

    // These functions will be overridden by specific models inheriting from this class
    virtual void FSpSuc(Agent& speaker, int m, int s);
    virtual void FLisSuc(Agent& listener, int m, int s);
    virtual void FSpFail(Agent& speaker, int m_s, int s, int m_l);
    virtual void FLisFail(Agent& listener, int m_s, int s, int m_l);

public:
    int getN();
    Agent& getAgent(int index);
    void runOnce(); //Make everyone speak to everyone once in a random order
    bool interact(int speaker, int listener);// Takes agent indices and calls     bool interact(Agent& speaker, Agent& listener);
    std::string toStr(); // For outputting purposes
    Model();
    Model(int N, int M, int S, int memory=0, int init=10);
    ~Model();

};

#endif