#ifndef LANGUAGEDYNAMICS_SIMULATION_H
#define LANGUAGEDYNAMICS_SIMULATION_H

#include "Model.h"

class Simulation
{
private:
    int T;
    Model* m;

public:
    Simulation();
    Simulation(Model* m);
    ~Simulation();
    void runForIterations(int IT);
    void saveResults(std::string path);
    void loadSimulation();

};


#endif
