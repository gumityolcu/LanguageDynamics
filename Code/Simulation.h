#ifndef LANGUAGEDYNAMICS_SIMULATION_H
#define LANGUAGEDYNAMICS_SIMULATION_H

#include "Model.h"

class Simulation {
private:
    // A simulations consists of the state of a model m after T iterations at the REALISATION th realisation
    // This class is really a wrapper for easy IO
    int T;
    int REALISATION;
    std::string savePath="";
    Model *m = nullptr;

public:
    Simulation();

    Simulation(Model *m);

    ~Simulation();

    void runForIterations(int IT);
    void runForRealisations(int IT, int RE, bool save=true);
    void setRealisation(int val);
    void setSavePath(std::string path);

    void saveState();

    std::vector<Eigen::MatrixXi> getMatrices(); // For score calculation
    void loadState(std::string path);

};


#endif
