#ifndef LANGUAGEDYNAMICS_AGENT_H
#define LANGUAGEDYNAMICS_AGENT_H

#include <Eigen/Dense>
#include <queue>
#include <utility>
#include <vector>
#include <random>
#include <iostream>

class Agent {
private:
    // Integer association matrix
    Eigen::MatrixXi A;
    // The value used to randomize the random engine upon construcion of the object
    // Kept for debugging purposes
    unsigned int seed;
    // Integer vectors for keeping track of sums of columns and rows
    std::vector<int> rowsums;
    std::vector<int> colsums;
    // A vector of queues. In models that use memory structure, each queue represents the memory for a meaning, the firs element in the queue being the oldest entry
    std::vector<std::queue<int>> memoryUpdateHistory;
    // The memory size. 0 if the model doesn't include memory
    int memory_size;
public:
    //Random engine
    std::default_random_engine rnd;

    // Vanilla constuctor, should not be used
    Agent();

    // Constructor with M = # of meanings, S = # of symbols and integer = whether the matrix values are constrained to be integers
    //Agent(int M, int S, bool integer);

    // Constructor with M = # of meanings, S = # of symbols and memory_size = memory size. Use memory_size=0 for infinite memory size(i.e. no memory).
    // init controls the rowsum of the initial state. If memory_size != 0 and init>memory_size, the initial rowsum is equal to memory_size.
    Agent(int M, int S, int memory_size, int init);

    ~Agent();

    // Choose a meaning and a symbol, return them as a 2-tuple
    std::pair<int, int> speak();

    // Choose a meaning for a given symbol
    int listen(int sigma);

    // Straight read access to association matrix cell
    int getA(int row, int col);

    // Straight write access to association matrix cell. It handles correcting rowsums and colsums vector values
    void setA(int row, int col, int val);

    // Returns true iff the agent has memory structure
    bool hasMemory();

    //Easy access to association matrix A. These increment and decrement values for given row and columns and also handle rowsums and colsums values.
    void incA(int row, int col);

    void decA(int row, int col);

    // Get the association matrix as a whole. Used for fitness calculation.
    Eigen::MatrixXi getMatrix();

    // Update memory structure, i.e. decrement/increment appropriate cells in the association matrix
    // and edit the memoryUpdateHistory queue to hold the correct symbols
    void updateMemory(int m, int s);

    // For outputting association matrices to file easily
    friend std::ostream &operator<<(std::ostream &out, const Agent &x);
};

#endif