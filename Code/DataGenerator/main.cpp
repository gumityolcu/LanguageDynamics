#include <iostream>
#include <random>
#include <vector>
#include "../LanguageDynamics.h"

#define REALISATIONS 2
#define COLS 30
#define ROWS 30
#define COLSTEP 1
#define ROWSTEP 100
#define COLINIT 1
#define ROWINIT 100
using namespace std;
using namespace Eigen;

double fitnessBetweenAgents(pair<MatrixXd, MatrixXd> m1, pair<MatrixXd, MatrixXd> m2);

double populationFitness(vector<pair<MatrixXd, MatrixXd>>

                         pop);

MatrixXd normalize(MatrixXi M);

vector<pair<MatrixXd, MatrixXd>>
generateMatrices(vector<MatrixXi>
                 M);

int main() {
    for (int r = 1; r < REALISATIONS+1; r++) {
        for (int i = COLINIT; i < COLS * COLSTEP + COLINIT; i = i + COLSTEP) {
            MemorySpeakerSuccessUpdate model(10, 10, 10, i);
            Simulation s(&model);
            s.setRealisation(r);
            s.setSavePath("/home/rehrev/Documents/Okul/LanguageDynamics/Code/Data/");
            for (int j = ROWINIT; j < ROWS * ROWSTEP + ROWINIT; j = j + ROWSTEP) {
                s.runForIterations(100);
                s.saveState();
            }
        }
    }
    return 5;
}

MatrixXd normalize(MatrixXi M) {
    int sum;
    MatrixXd x(M.rows(), M.cols());
    for (int r = 0; r < M.rows(); r++) {
        sum = 0;
        for (int c = 0; c < M.cols(); c++) {
            sum = sum + M(r, c);
        }
        for (int c = 0; c < M.cols(); c++) {
            if (sum != 0) {
                x(r, c) = (double) M(r, c) / (double) sum;
            } else {
                x(r, c) = 0;
            }
        }
    }
    return x;
}

double fitnessBetweenAgents(pair<MatrixXd, MatrixXd> m1, pair<MatrixXd, MatrixXd> m2) {
    MatrixXd p1 = m1.first;
    MatrixXd c1 = m1.second;
    MatrixXd p2 = m2.first;
    MatrixXd c2 = m2.second;
    MatrixXd a1 = p1 * c2;
    MatrixXd a2 = p2 * c1;
    double fit = (a1.trace() + a2.trace()) / (2 * a1.rows());
    return fit;
}

double populationFitness(vector<pair<MatrixXd, MatrixXd >> pop) {
    double fitness = 0;
    int N = pop.size();
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double temfit = 0;

            temfit += fitnessBetweenAgents(pop[i], pop[j]);
            fitness += temfit;
        }
    }
    fitness = 2 * (fitness / (N * (N - 1)));
    return fitness;
}

vector<pair<MatrixXd, MatrixXd>>
generateMatrices(vector<MatrixXi>
                 M) {
    vector<pair<MatrixXd, MatrixXd>>
            ret;
    for (
            int i = 0;
            i < M.

                    size();

            i++) {
        pair<MatrixXd, MatrixXd> x;
        x.
                first = normalize(M[i]);
        x.
                second = normalize(M[i].transpose());
        ret.
                emplace_back(x);
    }
    return
            ret;
}

