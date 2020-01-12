#ifndef LANGUAGEDYNAMICS_MODEL_H
#define LANGUAGEDYNAMICS_MODEL_H

#include "Agent.h"
#include <string>

class Model {
protected:
    int N; // # of agents
    int M; // # of meanings
    int S; // # of symbols
    int memory_size; // memory size
    std::vector<Agent> agents;
    std::string paramsString = ""; // Used for output file name, should be updated by child class if additional parameters are used
    std::string name = "plain"; // Used for output file name
    std::vector<std::pair<int, int>> combinations; // Holds N*(N-1) combinations of agents. Randomly sampled to select interacting pairs
    std::default_random_engine rnd; // Random engine
    unsigned int seed; // Kept for debugging purposes

    // Given two agent objects (that will be from the agents vector), makes them interact and updates their state
    bool interact(Agent &speaker, Agent &listener);

    // These functions will be overridden by specific models inheriting from this class
    virtual void SpeakerSuccess(Agent &speaker, int m, int s);

    virtual void ListenerSuccess(Agent &listener, int m, int s);

    virtual void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    virtual void ListenerFailure(Agent &listener, int m_s, int s, int m_l);


public:
    int getN(); // Returns the # of agents
    int getM(); // Returns the # of meanings
    int getS(); // Returns the # of symbols

    Agent &getAgent(int index); // Returns reference of an Agent object with a given index

    void runOnce(); //Make everyone speak to everyone once in a random order
    bool interact(int speaker,
                  int listener);// Takes agent indices and calls     bool interact(Agent& speaker, Agent& listener);
    std::string toStr(); // For outputting purposes. Returns string representation of the model parameters and name
    Model();

    Model(int N, int M, int S, int memory = 0, int init = 10);

    ~Model();

};

#endif