#include <Eigen/Dense>
#include <queue>
#include <vector>
class Agent
{
    public:
        // Integer association matrix
        Eigen::MatrixXi A;

        // Integer vectors for keeping track of sums of columns and rows
        Eigen::VectorXi rowsums;
        //Eigen::VectorXd rowsumd;
        Eigen::VectorXi colsums;
        //Eigen::VectorXd colsumd;

        std::vector<std::queue<int>> updateHistory;

        // Vanilla constuctor, should not be used
        Agent();

        // Constructor with M = # of meanings, W= # of symbols and integer = whether the matrix values are constrained to be integers
        //Agent(int M, int W, bool integer);

        // Constructor with M = # of meanings, W= # of symbols and memory = memory size. Use memory=-1 for infinite memory
        Agent(int M, int W, int memory=-1);
        ~Agent();
        bool speak();
        int listen(int sigma);

};