#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include "domain/led.h"

#include <iostream>
#include "abstractcommand.h"

using namespace std;
class AbstractCommand
{
public:
    void setLedControl(led *ledControl);
    virtual bool execute() =0;
    virtual ~AbstractCommand();

    string argStr() const;
    void setArgStr(const string &argStr);

    string result_command_message() const;

protected:
    led *_ledControl;
    string _argStr = "";
    string _result_command_message ="";
};

#endif // ABSTRACTCOMMAND_H
