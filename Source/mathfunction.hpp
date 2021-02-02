#ifndef mathfunction_hpp
#define mathfunction_hpp

#include <stdio.h>
#include <cmath>

class myMath {
protected:
    
public:
    static int absInt(int number);
    static float absFloat(float number);
    static short CountIntNumberRadix(int number);
    static short squareOf(float number);
    static short squarerootOf(float number);
};

#endif /* mathfunction_hpp */
