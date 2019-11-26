//
// Created by rehrev on 24.11.2019.
//

#include "LanguageDynamics.h"

// The model where speaker increments according to listener in both success and failure

SpeakerIncrementBoth::SpeakerIncrementBoth(int N, int M, int S):Model(N,M,S)
{
    this->name="SpeakerIncrementBoth";
}


void SpeakerIncrementBoth::FSpSuc(Agent& speaker, int m, int s)
{
    speaker.incA(m,s);
}

void SpeakerIncrementBoth::FSpFail(Agent& speaker, int m_s, int s, int m_l)
{
    speaker.incA(m_l,s);
}

SpeakerIncrementBoth::~SpeakerIncrementBoth(){}


//===================================================================

// The model where speaker increments according to listener in failure

SpeakerIncrementFailure::SpeakerIncrementFailure(int N, int M, int S):Model(N,M,S)
{
    this->name="SpeakerIncrementFailure";
}

void SpeakerIncrementFailure::FSpFail(Agent& speaker, int m_s, int s, int m_l)
{
    speaker.incA(m_l,s);
}

SpeakerIncrementFailure::~SpeakerIncrementFailure(){}


//===================================================================

/* The model where:
 * speaker increments according to listener in both success and failure
 * listener increments according to speaker in both success and failure
 */
BothIncrementBoth::BothIncrementBoth(int N, int M, int S):Model(N,M,S)
{
    this->name="BothIncrementBoth";
}

void BothIncrementBoth::FSpSuc(Agent& speaker, int m, int s)
{
    speaker.incA(m,s);
}
void BothIncrementBoth::FLisSuc(Agent& listener, int m, int s)
{
    listener.incA(m,s);
}
void BothIncrementBoth::FSpFail(Agent& speaker, int m_s, int s, int m_l)
{
    speaker.incA(m_l,s);
}
void BothIncrementBoth::FLisFail(Agent& listener, int m_s, int s, int m_l)
{
    listener.incA(m_s,s);
}

BothIncrementBoth::~BothIncrementBoth(){}


//===================================================================

/* The model where:
 * The speaker updates memory according to the listener's action
 */
MemorySpeakerUpdateBoth::MemorySpeakerUpdateBoth(int N, int M, int S, int m):Model(N,M,S,m)
{
    this->name="MemorySpeakerUpdateBoth";
}

void MemorySpeakerUpdateBoth::FSpSuc(Agent& speaker, int m, int s)
{
    speaker.updateMemory(m, s);
}

void MemorySpeakerUpdateBoth::FSpFail(Agent& speaker, int m_s, int s, int m_l)
{
    if(m_l>-1)
    {
        speaker.updateMemory(m_l, s);
    }
}

MemorySpeakerUpdateBoth::~MemorySpeakerUpdateBoth(){}


//===================================================================

MemoryBothUpdateBoth::MemoryBothUpdateBoth(int N, int M, int S, int m):Model(N,M,S,m)
{
    this->name="MemorySpeakerUpdateBoth";
}

void MemoryBothUpdateBoth::FSpSuc(Agent& speaker, int m, int s)
{
    speaker.updateMemory(m, s);
}

void MemoryBothUpdateBoth::FSpFail(Agent& speaker, int m_s, int s, int m_l)
{
    speaker.updateMemory(m_l, s);
}


void MemoryBothUpdateBoth::FLisSuc(Agent& listener, int m, int s)
{
    listener.updateMemory(m, s);
}
void MemoryBothUpdateBoth::FLisFail(Agent& listener, int m_s, int s, int m_l)
{
    listener.updateMemory(m_s,s);
}

MemoryBothUpdateBoth::~MemoryBothUpdateBoth(){}


//===================================================================