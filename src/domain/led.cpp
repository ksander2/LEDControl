#include "domain/led.h"

led::led()
{
}

led::Color led::color() const
{
    return _color;
}

void led::setColor(const Color &color)
{
    _color = color;
}
led::State led::state() const
{
    return _state;
}

void led::setState(const State &state)
{
    _state = state;
}
int led::rate() const
{
    return _rate;
}

void led::setRate(int rate)
{
    _rate = rate;
}





