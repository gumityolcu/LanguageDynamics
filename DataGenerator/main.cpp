#include <iostream>
#include <random>
#include <vector>
#include "LanguageDynamics.h"
using namespace std;
int main() {
    MemorySpeakerUpdateBoth model(5,5,5,5);
    Simulation s(&model);
    s.runForIterations(500);
    s.saveResults();

}