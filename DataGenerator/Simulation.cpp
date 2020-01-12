#include "Simulation.h"
#include <fstream>

Simulation::Simulation() {}

Simulation::Simulation(Model *m) {
    this->m = m;
    this->T = 0;
    this->REALISATION = 0;
}

Simulation::~Simulation() {}

void Simulation::runForIterations(int IT) {
    for (int i = 0; i < IT; i++) {
        //std::cout<<"Running at time "<<T<<std::endl<<std::endl;
        this->m->runOnce();
        this->T++;
    }
}

void Simulation::runForRealisations(int IT, int RE, bool save) {
    for(int i =0;i<RE;i++)
    {
        this->T=0;
        this->REALISATION++;
        this->runForIterations(IT);
        this->saveState();
    }
}

void Simulation::setSavePath(std::string path) {
    this->savePath=path;
}

std::vector<Eigen::MatrixXi> Simulation::getMatrices() {
    std::vector<Eigen::MatrixXi> ret;
    for (int i = 0; i < this->m->getN(); i++) {
        ret.push_back(this->m->getAgent(i).getMatrix());
    }
    return ret;
}

void Simulation::saveState() {
    std::string fname = this->savePath;
    if (fname == "") {
        fname = this->m->toStr() + "T=" + std::to_string(this->T) + "|REALISATION="+std::to_string(this->REALISATION)+".txt";
    }
    std::ofstream file;
    file.open(fname);
    file << this->T << " " << this->m->getN() << " " << this->m->getM() << " " << this->m->getS() << " ";
    for (int i = 0; i < this->m->getN(); i++) {
        file << this->m->getAgent(i);
        if (i < this->m->getN() - 1) {
            file << " ";
        }
    }
    file << " END";
    file.close();
}

void Simulation::loadState(std::string path) {
    if (this->m == nullptr) {
        throw std::runtime_error("Simulation object should have a model before loading");
    } else {
        int N, M, S;
        std::ifstream file(path);
        file >> this->T >> this->REALISATION >> N >> M >> S;
        for (int a = 0; a < N; a++) {
            for (int r = 0; r < M; r++) {
                for (int c = 0; c < S; c++) {
                    int val;
                    file >> val;
                    this->m->getAgent(a).setA(r, c, val);
                }
            }
        }
        file.close();
    }
}