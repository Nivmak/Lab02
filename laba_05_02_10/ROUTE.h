//#pragma once
#ifndef LAB2_1_AEROFLOT_H
#define LAB2_1_AEROFLOT_H
#include <iostream>
#include <string>
class ROUTE
{
public:
    ROUTE();
    ROUTE(std::string _destination, int _flightNumber, std::string _planeType);
    ROUTE(const ROUTE& route);
    ~ROUTE();
    std::string getDestination();
    void setDestination(std::string value);
    int getFlightNumber();
    void setFlightNumber(int value);
    std::string getAircraftType();
    void setAircraftType(std::string value);
    friend std::ostream& operator<<(std::ostream& ostream, const ROUTE& route);
    friend std::istream& operator>>(std::istream& istream, ROUTE& route);
private:
    std::string destination;
    int flightNumber;
    std::string planeType;
};
#endif //LAB2_1_AEROFLOT_H