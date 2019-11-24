#ifndef LANGUAGEDYNAMICS_AGENT_H
#define LANGUAGEDYNAMICS_AGENT_H

#include <Eigen/Dense>
#include <queue>
#include <utility>
#include <vector>
#include <random>
#include <iostream>

class Agent
{
private:
    // Integer association matrix
    Eigen::MatrixXi A;
    unsigned int seed;
    // Integer vectors for keeping track of sums of columns and rows
    Eigen::VectorXi rowsums;
    //Eigen::VectorXd rowsumd;
    Eigen::VectorXi colsums;
    //Eigen::VectorXd colsumd;

    std::vector<std::queue<int>> updateHistory;
    std::default_random_engine rnd;

public:
    // Vanilla constuctor, should not be used
    Agent();

    // Constructor with M = # of meanings, S = # of symbols and integer = whether the matrix values are constrained to be integers
    //Agent(int M, int S, bool integer);

    // Constructor with M = # of meanings, S = # of symbols and memory = memory size. Use memory=-1 for infinite memory
    Agent(int M, int S, int memory=-1);
    ~Agent();

    std::pair<int,int> speak();
    int listen(int sigma);
    friend std::ostream & operator << (std::ostream &out, const Agent &x);
};

#endif