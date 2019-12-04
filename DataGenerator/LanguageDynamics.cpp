//
// Created by rehrev on 24.11.2019.
//

#include "LanguageDynamics.h"

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

SpeakerSuccessIncrementFailureDecrement::SpeakerSuccessIncrementFailureDecrement(int N, int M, int S, int inc, int dec)
        : Model(N, M, S) {
    this->increment = inc;
    this->decrement = dec;
    this->name = "SpeakerSuccessIncrementFailureDecrement";
}

void SpeakerSuccessIncrementFailureDecrement::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.setA(m, s, speaker.getA(m, s) + this->increment);
}

void SpeakerSuccessIncrementFailureDecrement::SpeakerFailure(Agent &speaker, int m_s, int s, int m_l) {
    speaker.setA(m_l, s, std::max(0, speaker.getA(m_l, s) - this->decrement));
}

SpeakerSuccessIncrementFailureDecrement::~SpeakerSuccessIncrementFailureDecrement() {}

//==============================================

/* The model where:
 * The speaker updates memory_size according to the listener's action
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


void MemorySpeakerSuccessUpdate::SpeakerSuccess(Agent &speaker, int m, int s) {
    speaker.updateMemory(m, s);
}

MemorySpeakerSuccessUpdate::~MemorySpeakerSuccessUpdate() {};

MemorySpeakerSuccessUpdate::MemorySpeakerSuccessUpdate(int N, int M, int S, int m) : Model(N, M, S, m) {
    this->name = "MemorySpeakerSuccessUpdate";
}

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
