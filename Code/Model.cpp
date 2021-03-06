#include "Model.h"


Model::Model() {}

Model::Model(int N, int M, int S, int memory, int init) {
    // RANDOMIIIISE!
    std::random_device r;
    this->seed = r();
    this->rnd.seed(this->seed);

    this->N = N;
    this->M = M;
    this->S = S;
    this->memory_size = memory;

    for (int i = 0; i < N; i++) {
        // Generate agents
        this->agents.emplace_back(Agent(M, S, memory, init));
        for (int j = 0; j < N; j++) {
            if (i != j) {
                //Generate combinations of agents
                this->combinations.emplace_back(std::pair<int, int>(i, j));
            }
        }
    }
}

Model::~Model() {}

// Empty update functions, these will be overridden by actual model classes inheriting from this class
void Model::SpeakerSuccess(Agent &speaker, int m, int s) { return; }

void Model::ListenerSuccess(Agent &listener, int m, int s) { return; }

void Model::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) { return; }

void Model::ListenerFailure(Agent &listener, int m_s, int s, int m_l) { return; }

std::string Model::toStr() {
    std::string ret = "";
    ret += this->name + "|N=" + std::to_string(this->N) + "|M=" + std::to_string(this->M) + "|S=" + std::to_string(this->S) +
           "|m=" + std::to_string(this->memory_size)+"|"+this->paramsString;
    return ret;
}

int Model::getN() {
    return this->N;
}

int Model::getM() {
    return this->M;
}

int Model::getS() {
    return this->S;
}

void Model::runOnce() {
    // Exhaust list by randomly selecting. At the end, the list will be shuffled and ready for reuse
    for (int boundary = this->combinations.size(); boundary > 0; boundary--) {
        std::uniform_int_distribution<int> unif(0, boundary - 1);
        int r = unif(this->rnd);
        std::pair<int, int> sel = this->combinations[r];
        this->combinations[r] = this->combinations[boundary - 1];
        this->combinations[boundary - 1] = sel;
        this->interact(sel.first, sel.second);
    }
}

Agent &Model::getAgent(int index) {
    return this->agents[index];
}

bool Model::interact(Agent &speaker, Agent &listener) {
    std::pair<int, int> fromSpeaker;
    int m_s, sigma, m_l;
    // Let the speaker speak
    fromSpeaker = speaker.speak();

    m_s = fromSpeaker.first;
    sigma = fromSpeaker.second;

    // Let the listener listen
    m_l = listener.listen(sigma);

    // Do what the model says
    if (m_s == m_l) {
        this->SpeakerSuccess(speaker, m_s, sigma);
        this->ListenerSuccess(listener, m_l, sigma);
    } else {
        this->SpeakerFailure(speaker, m_s, sigma, m_l);
        this->ListenerFailure(listener, m_s, sigma, m_l);
    }

    return (m_s == m_l);
}

bool Model::interact(int speaker, int listener) {
    return this->interact(this->agents[speaker], this->agents[listener]);
}


