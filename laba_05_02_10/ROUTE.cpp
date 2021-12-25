#include "ROUTE.h"

ROUTE::ROUTE() {
    this->routeNumber = 0;
    std::cout << "Object ROUTE. Call simple constructor\n";
}

ROUTE::ROUTE(std::string _punct1, std::string _punct2, int _routeNumber) : punct1(_punct1),
punct2(_punct2), routeNumber(_routeNumber) {
    std::cout << "Object ROUTE. Call constructor with parameters\n";
}

ROUTE::ROUTE(const ROUTE& route) : punct1(route.punct1), punct2(route.punct2), routeNumber(route.routeNumber) {
    std::cout << "Object ROUTE. Call copy constructor\n";
}

ROUTE::~ROUTE() {
    std::cout << "Object ROUTE. Call destructor\n";
}

std::string ROUTE::getPunct1() {
    return this->punct1;
}

void ROUTE::setPunct1(std::string value) {
    this->punct1 = value;
}

std::string ROUTE::getPunct2() {
    return this->punct2;
}

void ROUTE::setPunct2(std::string value) {
    this->punct2 = value;
}

int ROUTE::getROUTENumber() {
    return this->routeNumber;
}

void ROUTE::setROUTENumber(int value) {
    this->routeNumber = value;
}

std::ostream& operator<<(std::ostream& ostream, const ROUTE& route) {
    ostream << "Punct1: " << route.punct1 << "\nPunct2: " << route.punct2
        << "\nRoute number: " << route.routeNumber << "\n";

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
                route.punct1 = tempValue;
                wordCount++;
                tempValue.clear();
            }
            else if (wordCount == 1) {
                route.punct2 = tempValue;
                wordCount++;
                tempValue.clear();
            }
        }
        else {
            tempValue.push_back(i);
        }
    }
    if (wordCount == 2)
        route.routeNumber = std::stoi(tempValue);
    else
        throw std::invalid_argument("Wrong route data. Data should have the following form: \"Punct1, Punct2, Route Number\"\n");

    return istream;
}