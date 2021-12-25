#include "ROUTE.h"

ROUTE::ROUTE() {
    this->flightNumber = 0;
    std::cout << "Object ROUTE. Call simple constructor\n";
}

ROUTE::ROUTE(std::string _destination, int _flightNumber, std::string _planeType) : destination(_destination),
flightNumber(_flightNumber),
planeType(_planeType) {
    std::cout << "Object ROUTE. Call constructor with parameters\n";
}

ROUTE::ROUTE(const ROUTE& aeroflot) : destination(aeroflot.destination), flightNumber(aeroflot.flightNumber),
planeType(aeroflot.planeType) {
    std::cout << "Object ROUTE. Call copy constructor\n";
}

ROUTE::~ROUTE() {
    std::cout << "Object ROUTE. Call destructor\n";
}

std::string ROUTE::getDestination() {
    return this->destination;
}

void ROUTE::setDestination(std::string value) {
    this->destination = value;
}

int ROUTE::getFlightNumber() {
    return this->flightNumber;
}

void ROUTE::setFlightNumber(int value) {
    this->flightNumber = value;
}

std::string ROUTE::getAircraftType() {
    return this->planeType;
}

void ROUTE::setAircraftType(std::string value) {
    this->planeType = value;
}

std::ostream& operator<<(std::ostream& ostream, const ROUTE& route) {
    ostream << "Destination: " << route.destination << "\nPlane number: " << route.flightNumber
        << "\nPlane type: " << route.planeType << "\n";

    return ostream;
}

std::istream& operator>>(std::istream& istream, ROUTE& route) {
    std::string input;
    std::getline(istream, input);

    int wordCount = 0;
    std::string tempValue;

    for (char i : input) {
        if (i == ' ') {
            continue;
        }
        if (i == ',') {
            if (wordCount == 0) {
                route.destination = tempValue;
                wordCount++;
                tempValue.clear();
            }
            else if (wordCount == 1) {
                route.flightNumber = std::stoi(tempValue);
                wordCount++;
                tempValue.clear();
            }
        }
        else {
            tempValue.push_back(i);
        }
    }
    if (wordCount == 2)
        route.planeType = tempValue;
    else
        throw std::invalid_argument("Wrong plane data. Data should have the following form: \"destination, aircraft number, aircraft type\"\n");

    return istream;
}