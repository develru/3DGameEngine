#ifndef TIME_H
#define TIME_H


class Time
{
public:
    Time();
    static long getTime();
    double getDelta(){ return m_delta;  }
    void setDelta(double delta);

private:
    double m_delta;
};

#endif // TIME_H
