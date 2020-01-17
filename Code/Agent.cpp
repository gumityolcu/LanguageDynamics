#include "Agent.h"

#define MAXRND 10;

Agent::Agent() {}

Agent::Agent(int M, int S, int memory = 0, int init = 10) {

    std::random_device r;
    this->seed = r();
    this->rnd.seed(this->seed);

    this->memory_size = memory;

    std::uniform_int_distribution<int> unifS(0, S - 1);

    int incBase;

    if (memory > 0) {
        if (init > memory) {
            init = memory;
        }
        this->memoryUpdateHistory.resize(M);
    }

    incBase = init;

    this->A = Eigen::MatrixXi::Zero(M, S);
    this->rowsums = std::vector<int>(M, 0);
    this->colsums = std::vector<int>(S, 0);
    // For each meaning
    for (int r = 0; r < M; r++) {
        // For incBase many times
        for (int i = incBase; i > 0; i--) {
            // Select a random symbol and increment association
            int c = unifS(this->rnd);

            // Increment matrix and if needed, memory_size structure
            if (memory > 0) {
                this->updateMemory(r, c);
            } else {
                this->incA(r, c);
            }
        }
    }

    //INITIALIZE WITH IDENTITY MATRIX
    /*for(int a=0;a<M;a++)
    {
        this->rowsums[a]=incBase;
        this->colsums[a]=incBase;
        this->A=incBase*Eigen::MatrixXi::Identity(M,S);
        std::queue<int> x;
        for(int i=0;i<incBase;i++)
        {
            x.push(a);
        }
        this->memoryUpdateHistory[a]=x;
    }*/
}

Agent::~Agent() {}

std::pair<int, int> Agent::speak() {
    // Uniform distribution between 0 and M-1
    std::uniform_int_distribution<int> unifM(0, this->A.rows() - 1);

    // We will return ret
    // ret will be of form <meaning, symbol>
    std::pair<int, int> ret;

    // Select meaning
    ret.first = unifM(this->rnd);

    // If the model contains instructions to decrease associations, we may have all zeroes for a selected meaning
    // For now, we select a random symbol in this case and update A and memory_size accordingly.
    if (this->rowsums[ret.first] == 0) {
        std::uniform_int_distribution<int> unifS(0, this->A.cols() - 1);
        int symbol = unifS(rnd);

        if (this->memory_size > 0) {
            updateMemory(ret.first, symbol);
        } else {
            this->incA(ret.first, symbol);
        }
    }

    std::uniform_int_distribution<int> unifRow(1, this->rowsums[ret.first]);
    // Select a number from 1 to the rowsum
    int rn = unifRow(this->rnd);
    int sum = 0;
    int i;
    // Sum the numbers in the row until you pass the selected random number
    for (i = 0; (i < this->A.cols()) && (rn > sum); i++) {
        sum += this->A(ret.first, i);
    }
    // Choose the previous column's symbol
    ret.second = i - 1;

    return ret;
}

int Agent::listen(int sigma) {
    // We can have all zeroes for a symbol in any model. In this case, we select a random symbol
    // and update the internal state accordingly for now
    if (this->colsums[sigma] == 0) {
        std::uniform_int_distribution<int> unifM(0, this->A.rows() - 1);
        int mu = unifM(rnd);

        if (this->memory_size > 0) {
            this->updateMemory(mu, sigma);
        } else {
            this->incA(mu, sigma);
        }
    }
    // Select meaning according to column probability distribution. Consult speak() for details
    std::uniform_int_distribution<int> unifCol(1, this->colsums[sigma]);
    int rn = unifCol(this->rnd);
    int sum = 0;
    int i;
    for (i = 0; (i < this->A.rows()) && (rn > sum); i++) {
        sum += this->A(i, sigma);
    }
    return i - 1;
}

std::ostream &operator<<(std::ostream &out, const Agent &x) {
    //out << x.A;
    for (int r = 0; r < x.A.rows(); r++) {
        for (int c = 0; c < x.A.cols(); c++) {
            int val = x.A(r, c);
            out.write((char*)&val,sizeof(int));
        }
    }
    return out;
}

void Agent::setA(int row, int col, int val) {
    int old = this->A(row, col);
    this->rowsums[row] = this->rowsums[row] + val - old;
    this->colsums[col] = this->colsums[col] + val - old;
    this->A(row, col) = val;
}

int Agent::getA(int row, int col) {
    return this->A(row, col);
}

void Agent::incA(int row, int col) {
    this->A(row, col)++;
    this->rowsums[row]++;
    this->colsums[col]++;
}

void Agent::decA(int row, int col) {
    this->A(row, col)--;
    this->rowsums[row]--;
    this->colsums[col]--;
}

Eigen::MatrixXi Agent::getMatrix() {
    return this->A;
}

void Agent::updateMemory(int m, int s) {
    // If the memory_size isn't full, we are not overwriting anything
    if (this->memoryUpdateHistory[m].size() == this->memory_size) {
        this->decA(m, this->memoryUpdateHistory[m].front());
        this->memoryUpdateHistory[m].pop();
    }
    this->memoryUpdateHistory[m].push(s);
    this->incA(m, s);
}

bool Agent::hasMemory() {
    return (memory_size > 0);
}