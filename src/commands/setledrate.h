#ifndef SETLEDFREQUENCY_H
#define SETLEDFREQUENCY_H

#include "abstractcommand.h"

class SetLedRate : public AbstractCommand
{
public:
    SetLedRate(string arg);
    bool execute();
};

#endif // SETLEDFREQUENCY_H
