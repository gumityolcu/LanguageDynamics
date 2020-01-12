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

class BaseModel: public Model{
    int speakerSuccessInc;
    int listenerSuccessInc;
    int speakerFailureInc;
    int speakerFailureDec;
    int listenerFailureInc;
    int listenerFailureDec;
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);
    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    void ListenerSuccess(Agent &listener, int m, int s);
    void ListenerFailure(Agent &listener, int m_s, int s, int m_l);


    BaseModel(int N, int M, int S, int speakerSucInc, int speakerFailInc, int speakerFailDec, int listenerSucInc, int listenerFailInc, int listenerFailDec);

    BaseModel();

    ~BaseModel();
};

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

class SpeakerSuccessIncrement : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    SpeakerSuccessIncrement(int N, int M, int S);

    SpeakerSuccessIncrement();

    ~SpeakerSuccessIncrement();
};

class BothSuccessIncrement : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    void ListenerSuccess(Agent &listener, int m, int s);

    BothSuccessIncrement(int N, int M, int S);

    BothSuccessIncrement();

    ~BothSuccessIncrement();
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

class SpeakerSuccessIncrementFailureIncrementDecrement : public Model {
public:
    int successIncrement;
    int failureDecrement;
    int failureIncrement;

    void SpeakerSuccess(Agent &speaker, int m, int s);

    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    SpeakerSuccessIncrementFailureIncrementDecrement(int N, int M, int S, int sucInc, int failDec, int failInc);

    SpeakerSuccessIncrementFailureIncrementDecrement();

    ~SpeakerSuccessIncrementFailureIncrementDecrement();
};

class ListenerSuccessIncrementFailureIncrementDecrement : public Model {
public:
    int increment;
    int decrement;

    void ListenerSuccess(Agent &listener, int m, int s);

    void ListenerFailure(Agent &listener, int m_s, int s, int m_l);

    ListenerSuccessIncrementFailureIncrementDecrement(int N, int M, int S, int inc, int dec);

    ListenerSuccessIncrementFailureIncrementDecrement();

    ~ListenerSuccessIncrementFailureIncrementDecrement();
};

//Models including memory

class MemorySpeakerBothUpdate : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    MemorySpeakerBothUpdate(int N, int M, int S, int m);

    MemorySpeakerBothUpdate();

    ~MemorySpeakerBothUpdate();
};

class MemorySpeakerSuccessUpdate : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    MemorySpeakerSuccessUpdate(int N, int M, int S, int m);

    ~MemorySpeakerSuccessUpdate();
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

class MemorySpeakerSuccessListenerBothUpdate : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    void ListenerSuccess(Agent &listener, int m, int s);

    void ListenerFailure(Agent &listener, int m_s, int s, int m_l);

    MemorySpeakerSuccessListenerBothUpdate(int N, int M, int S, int m);

    ~MemorySpeakerSuccessListenerBothUpdate();
};

class MemorySpeakerBothListenerSuccessUpdate : public Model {
public:
    void SpeakerSuccess(Agent &speaker, int m, int s);

    void SpeakerFailure(Agent &speaker, int m_s, int s, int m_l);

    void ListenerSuccess(Agent &listener, int m, int s);

    MemorySpeakerBothListenerSuccessUpdate(int N, int M, int S, int m);

    MemorySpeakerBothListenerSuccessUpdate();

    ~MemorySpeakerBothListenerSuccessUpdate();
};


#endif //LANGUAGEDYNAMICS_LANGUAGEDYNAMICS_H
