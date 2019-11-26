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
    std::vector<int> rowsums;
    std::vector<int> colsums;
    std::vector<std::queue<int>> updateHistory;
    int memory;
public:
    std::default_random_engine rnd;
    // Vanilla constuctor, should not be used
    Agent();

    // Constructor with M = # of meanings, S = # of symbols and integer = whether the matrix values are constrained to be integers
    //Agent(int M, int S, bool integer);

    // Constructor with M = # of meanings, S = # of symbols and memory = memory size. Use memory=0 for infinite memory.
    Agent(int M, int S, int memory, int init);
    ~Agent();

    std::pair<int,int> speak();
    int listen(int sigma);
    int getA(int row, int col);
    void setA(int row, int col, int val);
    bool hasMemory();
    void incA(int row, int col);
    void decA(int row, int col);
    Eigen::MatrixXi getMatrix();
    void updateMemory(int m, int s);
    friend std::ostream & operator << (std::ostream &out, const Agent &x);
};

#endif