#include "Random.h"
#define MAX 32767
float Random::randReal(void)
{
    int c;
    static bool first = 1;

    if (first)
    {
        seed1 *= 2;
        seed2 *= 2;
        if (seed1 > MAX)seed1 -= MAX;
        if (seed2 > MAX)seed2 -= MAX;
        first = 0;

        for (int index = 0; index <= 30; index++)
        {
            randReal();
        }
    }c = seed1 + seed2;
    if (c > MAX) c -= MAX;
    c *= 2;
    if (c > MAX) c -= MAX;
    seed1 = seed2;
    seed2 = c;
    return (float)c/32767.0;
}

unsigned Random::nextintBetween(int low, int high)
{
    float r, t;
    int c;

    r = (float)high - (float)low + 1.0;
    t = r * randReal();
    c = (int)t;
    return (low + c);
}
