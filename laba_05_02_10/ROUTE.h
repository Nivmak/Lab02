#pragma once
//#ifndef LAB2_1_ROUTE_H
//#define LAB2_1_ROUTE_H
#include <iostream>
#include <string>
class ROUTE
{
public:
    ROUTE();
    ROUTE(std::string _punct1, std::string _punct2, int _routeNumber);
    ROUTE(const ROUTE& route);
    ~ROUTE();
    std::string getPunct1();
    void setPunct1(std::string value);
    std::string getPunct2();
    void setPunct2(std::string value);
    int getROUTENumber();
    void setROUTENumber(int value);
    friend std::ostream& operator<<(std::ostream& ostream, const ROUTE& route);
    friend std::istream& operator>>(std::istream& istream, ROUTE& route);
private:
    std::string punct1;
    std::string punct2;
    int routeNumber;
};
//#endif //LAB2_1_ROUTE_H