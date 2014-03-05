#pragma once

class ISynchornized
{
public:
    virtual ~ISynchornized() {};
    virtual void clock(int time) = 0;
};