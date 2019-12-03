#ifndef LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H
#define LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H

#include "Simulation.h"

/*
 * This file contains definitions of various models.
 *
 * The naming convention is as follows:
 *
 * The first word denotes who acts: this can be "Speaker", "Listener" or "Both"
 * The second word denotes when the acter(s) acts(act): This can be "Failure", "Success" or "Both"
 * The third word denotes the action: "Increment", "Decrement", "IncrementDecrement" etc.
 *
 * If the model includes memory, these three words are preceded by the word "Memory" and
 * the last word is "Updates" because memory can only be updated.
 *
 * Notice that this is not strict as there can be names like "SpeakerSuccessIncrementFailureDecrement" or "MemorySpeakerSuccessUpdateListenerSuccessUpdate"
 */

// THIS FILE IS FOR ACCUMULATING DIFFERENT CLASSES(MODELS)

class SpeakerBothIncrement : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    SpeakerBothIncrement(int N, int M, int S);

    SpeakerBothIncrement();

    ~SpeakerBothIncrement();
};

class SpeakerFailureIncrement : public Model {
public:
    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    SpeakerFailureIncrement(int N, int M, int S);

    SpeakerFailureIncrement();

    ~SpeakerFailureIncrement();
};

class BothBothIncrement : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    void ListenerSuccess(Agent &listener, int m, int s);

    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    void ListenerFailure(Agent &listener, int m_s, int s, int m_l);

    BothBothIncrement(int N, int M, int S);

    BothBothIncrement();

    ~BothBothIncrement();
};

class MemorySpeakerBothUpdate : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    MemorySpeakerBothUpdate(int N, int M, int S, int m);

    MemorySpeakerBothUpdate();

    ~MemorySpeakerBothUpdate();
};

class MemoryBothBothUpdate : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    void ListenerSuccess(Agent &listener, int m, int s);

    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    void ListenerFailure(Agent &listener, int m_s, int s, int m_l);

    MemoryBothBothUpdate(int N, int M, int S, int m);

    MemoryBothBothUpdate();

    ~MemoryBothBothUpdate();
};


class SpeakerSuccessIncrementFailureDecrement : public Model {
public:
    int increment;
    int decrement;

    void SpeakerSuccess(Agent &speaker, int m, int s);

    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    SpeakerSuccessIncrementFailureDecrement(int N, int M, int S, int inc, int dec);

    SpeakerSuccessIncrementFailureDecrement();

    ~SpeakerSuccessIncrementFailureDecrement();
};


#endif //LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H
