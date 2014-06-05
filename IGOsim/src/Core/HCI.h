#pragma once

#include <string>

#include "Timer.h"

class HCI
{
public:
    enum logLevel {
        NOTHING = -1,
        ERROR = 0,
        WARNING = 1,
        CRITINFO = 2,
        INFO = 3

    };
protected:
    logLevel logLev;

public:
    HCI(logLevel = INFO);
    virtual ~HCI();

    void setLogLevel(logLevel);

    void log(logLevel, std::string, bool withTime = true) const;

    virtual void logv(std::string, bool withTime) const = 0;
};

