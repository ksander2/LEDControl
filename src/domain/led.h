#ifndef LED_H
#define LED_H

class led
{
public:
    led();

    enum Color
    {
        Red,
        Green,
        Blue
    };

    enum State
    {
        on,
        off
    };


    Color color() const;
    void setColor(const Color &color);

    State state() const;
    void setState(const State &state);

    int rate() const;
    void setRate(int rate);

private:

    State _state = off;

    int _rate = 0;

    Color _color = Red;
};

#endif // LED_H
