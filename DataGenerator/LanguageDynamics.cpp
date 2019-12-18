//
// Created by rehrev on 24.11.2019.
//

#include "LanguageDynamics.h"


BaseModel::BaseModel(int N, int M, int S, int speakerSucInc, int speakerFailInc, int speakerFailDec, int listenerSucInc, int listenerFailInc, int listenerFailDec) : Model(N, M, S) {
    this->name = "BaseModel";
    this->speakerSuccessInc=speakerSucInc;
    this->speakerFailureInc=speakerFailInc;
    this->speakerFailureDec=speakerFailDec;

    this->listenerSuccessInc=listenerSucInc;
    this->listenerFailureInc=listenerFailInc;
    this->listenerFailureDec=listenerFailDec;
}



void BaseModel::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.setA(m, s, speaker.getA(m, s) + this->speakerSuccessInc);
}

void BaseModel::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) {
    speaker.setA(m_s, s, std::max(0, speaker.getA(m_s, s) - this->speakerFailureDec));
    speaker.setA(m_l, s, speaker.getA(m_l, s) + this->speakerFailureInc);
}

void BaseModel::ListenerSuccess(Agent &listener, int m, int s) {
    listener.setA(m, s, listener.getA(m, s) + this->listenerSuccessInc);
}

void BaseModel::ListenerFailure(Agent &listener, int m_s, int s, int m_l){
    listener.setA(m_l, s, std::max(0, listener.getA(m_l, s) - this->listenerFailureDec));
    listener.setA(m_s, s, listener.getA(m_s, s) + this->listenerFailureInc);
}



//=============================



// The model where speaker increments according to listener in both success and failure

SpeakerBothIncrement::SpeakerBothIncrement(int N, int M, int S) : Model(N, M, S) {
    this->name = "SpeakerBothIncrement";
}


void SpeakerBothIncrement::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.incA(m, s);
}

void SpeakerBothIncrement::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) {
    speaker.incA(m_l, s);
}

SpeakerBothIncrement::~SpeakerBothIncrement() {}


//===================================================================

// The model where speaker increments according to listener in failure

SpeakerFailureIncrement::SpeakerFailureIncrement(int N, int M, int S) : Model(N, M, S) {
    this->name = "SpeakerFailureIncrement";
}

void SpeakerFailureIncrement::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) {
    speaker.incA(m_l, s);
}

SpeakerFailureIncrement::~SpeakerFailureIncrement() {}


//===================================================================


// The model where speaker increments according to listener in failure

SpeakerSuccessIncrement::SpeakerSuccessIncrement(int N, int M, int S) : Model(N, M, S) {
    this->name = "SpeakerSuccessIncrement";
}

void SpeakerSuccessIncrement::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.incA(m, s);
}

SpeakerSuccessIncrement::~SpeakerSuccessIncrement() {}

//========================================

// The model where speaker increments according to listener in failure

BothSuccessIncrement::BothSuccessIncrement(int N, int M, int S) : Model(N, M, S) {
    this->name = "BothSuccessIncrement";
}

void BothSuccessIncrement::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.incA(m, s);
}

void BothSuccessIncrement::ListenerSuccess(Agent &listener, int m, int s) {
    listener.incA(m, s);
}

BothSuccessIncrement::~BothSuccessIncrement() {}

//========================================


/* The model where:
 * speaker increments according to listener in both success and failure
 * listener increments according to speaker in both success and failure
 */
BothBothIncrement::BothBothIncrement(int N, int M, int S) : Model(N, M, S) {
    this->name = "BothBothIncrement";
}

void BothBothIncrement::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.incA(m, s);
}

void BothBothIncrement::ListenerSuccess(Agent &listener, int m, int s) {
    listener.incA(m, s);
}

void BothBothIncrement::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) {
    speaker.incA(m_l, s);
}

void BothBothIncrement::ListenerFailure(Agent &listener, int m_s, int s, int m_l) {
    listener.incA(m_s, s);
}

BothBothIncrement::~BothBothIncrement() {}


//===================================================================


SpeakerSuccessIncrementFailureIncrementDecrement::SpeakerSuccessIncrementFailureIncrementDecrement(int N, int M, int S, int sucInc, int failDec, int failInc)
        : Model(N, M, S) {
    this->successIncrement = sucInc;
    this->failureDecrement = failDec;
    this->failureIncrement = failInc;
    this->name = "SpeakerSuccessIncrementFailureIncrementDecrement";
}

void SpeakerSuccessIncrementFailureIncrementDecrement::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.setA(m, s, speaker.getA(m, s) + this->successIncrement);
}

void SpeakerSuccessIncrementFailureIncrementDecrement::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) {
    speaker.setA(m_s, s, std::max(0, speaker.getA(m_s, s) - this->failureDecrement));
    speaker.setA(m_l, s, speaker.getA(m_l, s) + this->failureIncrement);
}

SpeakerSuccessIncrementFailureIncrementDecrement::~SpeakerSuccessIncrementFailureIncrementDecrement() {}

//===================================================================

/* The model where:
 * The speaker updates memory according to the listener's action
 */
MemorySpeakerBothUpdate::MemorySpeakerBothUpdate(int N, int M, int S, int m) : Model(N, M, S, m) {
    this->name = "MemorySpeakerBothUpdate";
}

void MemorySpeakerBothUpdate::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.updateMemory(m, s);
}

void MemorySpeakerBothUpdate::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) {
    if (m_l > -1) {
        speaker.updateMemory(m_l, s);
    }
}

MemorySpeakerBothUpdate::~MemorySpeakerBothUpdate() {}


//===================================================================


void MemorySpeakerSuccessUpdate::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.updateMemory(m, s);
}

MemorySpeakerSuccessUpdate::~MemorySpeakerSuccessUpdate() {};

MemorySpeakerSuccessUpdate::MemorySpeakerSuccessUpdate(int N, int M, int S, int m) : Model(N, M, S, m) {
    this->name = "MemorySpeakerSuccessUpdate";
}


//===================================================================

MemoryBothBothUpdate::MemoryBothBothUpdate(int N, int M, int S, int m) : Model(N, M, S, m) {
    this->name = "MemorySpeakerBothUpdate";
}

void MemoryBothBothUpdate::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.updateMemory(m, s);
}

void MemoryBothBothUpdate::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) {
    speaker.updateMemory(m_l, s);
}

void MemoryBothBothUpdate::ListenerSuccess(Agent &listener, int m, int s) {
    listener.updateMemory(m, s);
}

void MemoryBothBothUpdate::ListenerFailure(Agent &listener, int m_s, int s, int m_l) {
    listener.updateMemory(m_s, s);
}

MemoryBothBothUpdate::~MemoryBothBothUpdate() {}



//===================================================================

void MemorySpeakerSuccessListenerBothUpdate::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.updateMemory(m, s);
}

void MemorySpeakerSuccessListenerBothUpdate::ListenerSuccess(Agent &listener, int m, int s) {
    listener.updateMemory(m, s);
}

void MemorySpeakerSuccessListenerBothUpdate::ListenerFailure(Agent &listener, int m_s, int s, int m_l) {
    listener.updateMemory(m_s, s);
}

MemorySpeakerSuccessListenerBothUpdate::~MemorySpeakerSuccessListenerBothUpdate() {};

MemorySpeakerSuccessListenerBothUpdate::MemorySpeakerSuccessListenerBothUpdate(int N, int M, int S, int m) : Model(N, M, S, m)
{
    this->name = "MemorySpeakerSuccessListenerBothUpdate";
}

//===================================================================

void MemorySpeakerBothListenerSuccessUpdate::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.updateMemory(m, s);
}

void MemorySpeakerBothListenerSuccessUpdate::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) {
    speaker.updateMemory(m_l, s);
}

void MemorySpeakerBothListenerSuccessUpdate::ListenerSuccess(Agent &listener, int m, int s){
    listener.updateMemory(m, s);
}

MemorySpeakerBothListenerSuccessUpdate::~MemorySpeakerBothListenerSuccessUpdate() {};

MemorySpeakerBothListenerSuccessUpdate::MemorySpeakerBothListenerSuccessUpdate(int N, int M, int S, int m) : Model(N, M, S, m)
{
    this->name = "MemorySpeakerBothListenerSuccessUpdate";
}
