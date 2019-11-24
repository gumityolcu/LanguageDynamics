//
// Created by rehrev on 24.11.2019.
//

#include "LanguageDynamics.h"

// The model where speaker increments according to listener in both success and failure

SpeakerIncrementBoth::SpeakerIncrementBoth(int N, int M, int S, int m):Model(N,M,S,m)
{
    this->name="SpeakerIncrementBoth";
}


void SpeakerIncrementBoth::FSpSuc(Agent& speaker, int m, int s)
{
    speaker.A(m,s)++;
}

void SpeakerIncrementBoth::FSpFail(Agent& speaker, int m_s, int s, int m_l)
{
    speaker.A(m_l,s)++;
}

SpeakerIncrementBoth::~SpeakerIncrementBoth(){}


//===================================================================
// The model where speaker increments according to listener in both success and failure

BothIncrementBoth::BothIncrementBoth(int N, int M, int S, int m):Model(N,M,S,m)
{
    this->name="BothIncrementBoth";
}

void BothIncrementBoth::FSpSuc(Agent& speaker, int m, int s)
{
    speaker.A(m,s)++;
}
void FLisSuc(Agent& listener, int m, int s)
{
    listener.A(m,s)++;
}
void BothIncrementBoth::FSpFail(Agent& speaker, int m_s, int s, int m_l)
{
    speaker.A(m_l,s)++;
}
void FLisFail(Agent& listener, int m_s, int s, int m_l)
{
    listener.A(m_s,s)++;
}

BothIncrementBoth::~BothIncrementBoth(){}


//===================================================================