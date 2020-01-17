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

void Simulation::runForRealisations(int IT, int RE, bool save, int initRE) {
    this->REALISATION = initRE;
    for (int i = 0; i < RE; i++) {
        this->T = 0;
        this->REALISATION++;
        this->runForIterations(IT);

        if (save) {
            this->saveState();
        }
    }
}

void Simulation::setSavePath(std::string path) {
    this->savePath = path;
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

    fname += this->m->toStr() + "T=" + std::to_string(this->T) + "|REALISATION=" +
             std::to_string(this->REALISATION);
    std::ofstream file;
    file.open(fname, std::ios::out | std::ios::binary);
    file.write((char *) &(this->T), sizeof(int));
    file.write((char *) &(this->REALISATION), sizeof(int));
    int wrN = this->m->getN();
    int wrM = this->m->getM();
    int wrS = this->m->getS();
    file.write((char *) &(wrN), sizeof(int));
    file.write((char *) &(wrM), sizeof(int));
    file.write((char *) &(wrS), sizeof(int));
    for (int i = 0; i < this->m->getN(); i++) {
        file << this->m->getAgent(i);
    }
    int END=-1;
    file.write((char*)&END,sizeof(int));
    file.close();
}

void Simulation::loadState(std::string path) {
    if (this->m == nullptr) {
        throw std::runtime_error("Simulation object should have a model before loading");
    } else {
        int N, M, S;
        std::ifstream file(this->savePath + path, std::ios::in | std::ios::binary);
        if (!file) {
            throw std::runtime_error("No such file : " + path);
        } else {
            file.read((char *) &this->T, sizeof(int));
            file.read((char *) &this->REALISATION, sizeof(int));
            file.read((char *) &N, sizeof(int));
            file.read((char *) &M, sizeof(int));
            file.read((char *) &S, sizeof(int));

            for (int a = 0; a < N; a++) {
                for (int r = 0; r < M; r++) {
                    for (int c = 0; c < S; c++) {
                        int val;
                        file.read((char *) &val, sizeof(int));
                        this->m->getAgent(a).setA(r, c, val);
                    }
                }
            }
            file.close();
        }

    }
}