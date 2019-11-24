#ifndef LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H
#define LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H

#include "Simulation.h"


class SpeakerIncrementBoth: Model
{
    void FSpSuc(Agent& speaker, int m, int s);
    void FSpFail(Agent& speaker, int m_s, int s, int m_l);

    SpeakerIncrementBoth();
    ~SpeakerIncrementBoth();
};

class BothIncrementBoth: Model
{
    void FSpSuc(Agent& speaker, int m, int s);
    void FLisSuc(Agent& listener, int m, int s);
    void FSpFail(Agent& speaker, int m_s, int s, int m_l);
    void FLisFail(Agent& listener, int m_s, int s, int m_l);

    BothIncrementBoth();
    ~BothIncrementBoth();
};

#endif //LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H
