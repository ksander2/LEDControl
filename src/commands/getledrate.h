#ifndef GETLEDFREQUENCY_H
#define GETLEDFREQUENCY_H

#include "abstractcommand.h"
#include <map>

class GetLedRate: public AbstractCommand
{

public:
    GetLedRate();
     bool execute();
};

#endif // GETLEDFREQUENCY_H
