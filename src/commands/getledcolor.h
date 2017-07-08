#ifndef GETLEDCOLOR_H
#define GETLEDCOLOR_H

#include "abstractcommand.h"
#include <map>
class GetLedColor : public AbstractCommand
{
private:
    map<led::Color, string> _colorMap =
    {
        {led::Color::Red, "red"},
        {led::Color::Green, "green"},
        {led::Color::Blue, "blue"}
    };
public:
    GetLedColor();
    bool execute();
};

#endif // GETLEDCOLOR_H
