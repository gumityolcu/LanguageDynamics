#ifndef LANGUAGEDYNAMICS_SIMULATION_H
#define LANGUAGEDYNAMICS_SIMULATION_H

#include "Model.h"

class Simulation {
private:
    // A simulations consists of the state of a model m after T iterations
    // This class is really a wrapper for easy IO
    int T;
    Model *m= nullptr;

public:
    Simulation();

    Simulation(Model *m);

    ~Simulation();

    void runForIterations(int IT);

    void saveState(std::string path="");

    std::vector<Eigen::MatrixXi> getMatrices(); // For score calculation
    void loadState(std::string path);

};


#endif
