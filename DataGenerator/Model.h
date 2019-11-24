#include "Agent.h"
#include <string>
class Model
{
    private:
        int N; // # of agents
        int M; // # of meanings
        int S; // # of symbols
        std::string name;
        std::vector<Agent> agents;
        std::vector<std::pair<int,int>> combinations;
        std::default_random_engine rnd;
        unsigned int seed;

        virtual void FSpSuc(Agent& speaker, int m, int s)=0;
        virtual void FLisSuc(Agent& listener, int m, int s)=0;
        virtual void FSpFail(Agent& speaker, int m_s, int s, int m_l)=0;
        virtual void FLisFail(Agent& listener, int m_s, int s, int m_l)=0;

    void runOnce(int IT);
    void printResults(std::string path);
    bool interact(Agent& speaker, Agent& listener);
    bool interact(int speaker, int listener);


    Model();
    Model(int N, int M, int S, std::string name);
    ~Model();

};