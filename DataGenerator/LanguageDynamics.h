#ifndef LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H
#define LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H

#include "Simulation.h"


class SpeakerIncrementBoth: public Model
{
public:
    void FSpSuc(Agent& speaker, int m, int s);
    void FSpFail(Agent& speaker, int m_s, int s, int m_l);

    SpeakerIncrementBoth(int N, int M, int S);
    SpeakerIncrementBoth();
    ~SpeakerIncrementBoth();
};

class SpeakerIncrementFailure: public Model
{
public:
    void FSpFail(Agent& speaker, int m_s, int s, int m_l);

    SpeakerIncrementFailure(int N, int M, int S);
    SpeakerIncrementFailure();
    ~SpeakerIncrementFailure();
};

class BothIncrementBoth: public Model
{
public:
    void FSpSuc(Agent& speaker, int m, int s);
    void FLisSuc(Agent& listener, int m, int s);
    void FSpFail(Agent& speaker, int m_s, int s, int m_l);
    void FLisFail(Agent& listener, int m_s, int s, int m_l);

    BothIncrementBoth(int N, int M, int S);
    BothIncrementBoth();
    ~BothIncrementBoth();
};

class MemorySpeakerUpdateBoth: public Model
{
public:
    void FSpSuc(Agent& speaker, int m, int s);
    void FSpFail(Agent& speaker, int m_s, int s, int m_l);

    MemorySpeakerUpdateBoth(int N, int M, int S, int m);
    MemorySpeakerUpdateBoth();
    ~MemorySpeakerUpdateBoth();
};

#endif //LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H
