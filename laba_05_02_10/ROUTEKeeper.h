//#pragma once
#ifndef LAB2_1_AEROFLOTKEEPER_H
#define LAB2_1_AEROFLOTKEEPER_H
#include "ROUTE.h"
class ROUTEKeeper{
public:
    ROUTEKeeper();
    ~ROUTEKeeper();
    void addROUTE(ROUTE route);
    void dataProcessing(int value);
private:
    ROUTE* routeKeeper;
    int tempKeep;
    int arraySize;
};
#endif //LAB2_1_AEROFLOTKEEPER_H