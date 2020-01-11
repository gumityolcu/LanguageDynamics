#include <iostream>
#include <random>
#include <vector>
#include "LanguageDynamics.h"

#define REALISATIONS 5

using namespace std;
using namespace Eigen;

double fitnessBetweenAgents(pair<MatrixXd, MatrixXd> m1, pair<MatrixXd, MatrixXd> m2);

double populationFitness(vector<pair<MatrixXd, MatrixXd>>

                         pop);

MatrixXd normalize(MatrixXi M);

vector<pair<MatrixXd, MatrixXd>>
generateMatrices(vector<MatrixXi>
                 M);

// DATA ANALYSER WILL BE A SEPERATE PROJECT!! ALL THIS IS FOR FAST DEBUGGING AND VERIFICATION
int main() {
    //for (int i = 1; i < 35; i += 1) {
        double score = 0;
        vector<MatrixXi> pop;
        for (int rea = 0; rea < REALISATIONS; rea++) {
            BaseModel model(10, 10, 10, 15,1,1,0,0,0);
            Simulation s(&model);
            cout << "Realisation " << rea << endl;
            s.runForIterations(1500);
            //s.saveState();
            pop = s.getMatrices();

            score += populationFitness(generateMatrices(pop));
        }
        //cout << "Memory " << i << " :   ";
        for (int i = 0; i < pop.size(); i++) {
            cout << pop[i] << endl << endl << "=====" << endl << endl;
        }
        score = score / REALISATIONS;
        //cout << "Population score with memory " << i << " : " << score << endl << flush;
        cout << "Population score : " << score << endl << flush;
    //}

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

