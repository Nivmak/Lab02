#include <algorithm>
#include "ROUTEKeeper.h"

ROUTEKeeper::ROUTEKeeper() {
    std::cout << "Object ROUTEKeeper. Call a simple constructor\n\n";
    this->routeKeeper = new ROUTE[10];
    this->arraySize = 10;
    this->tempKeep = 0;
}

ROUTEKeeper::~ROUTEKeeper() {
    std::cout << "Object ROUTEKeeper. Call destructor\n";
    delete[] this->routeKeeper;
}

int comparator(ROUTE a, ROUTE b) {
    return a.getDestination()[0] < b.getDestination()[0];
}

void ROUTEKeeper::dataProcessing(int value) {
    switch (value) {
    case 1: {
        ROUTE route;
        std::cin.ignore(32767, '\n');
        std::cout << "Print next data separated by commas: destination, plane number and plane type\n";

        std::cin >> route;
        addROUTE(route);
        std::sort(routeKeeper, routeKeeper + tempKeep, comparator);
        break;
    }
    case 2: {
        if (!tempKeep) {
            std::cout << "You have not aircraft\n";
            return;
        }
        std::cin.ignore(32676, '\n');
        std::cout << "Your aircraft types:\n";
        std::string aircrafts;
        for (int i = 0; i < tempKeep; i++) {
            if (aircrafts.find(routeKeeper[i].getAircraftType()) == std::string::npos) {
                std::cout << "\t" << routeKeeper[i].getAircraftType() << "\n";
                aircrafts.append(routeKeeper[i].getAircraftType());
            }
        }
        int number = 1;
        std::cout << "Enter an aircraft type:\n";
        std::string aircraft;
        std::getline(std::cin, aircraft);
        for (int i = 0; i < tempKeep; i++) {
            if (routeKeeper[i].getAircraftType() == aircraft) {
                std::cout << "This aircraft \"" << routeKeeper[i].getAircraftType() << "\" serves:\n";
                std::cout << "\t" << number << ": Flight number " << routeKeeper[i].getFlightNumber()
                    << ", destination " << routeKeeper[i].getDestination() << "\n";
                number++;
            }
        }
        if (number == 1) {
            std::cout << "The aircraft \"" << aircraft << "\" does not serve any flights\n";
        }
        break;
    }
    default:
        throw std::invalid_argument("Wrong number. Number should be from 1 to 3");
    }
}

void ROUTEKeeper::addROUTE(ROUTE route) {
    if (this->tempKeep == this->arraySize - 1) {
        this->routeKeeper[this->tempKeep] = route;
        ROUTE* newArray = new ROUTE[this->arraySize + 10];
        for (int i = 0; i < this->arraySize; i++)
            newArray[i] = this->routeKeeper[i];
        delete[] this->routeKeeper;
        this->routeKeeper = newArray;
        this->arraySize += 10;
        this->tempKeep++;
    }
    else {
        this->routeKeeper[this->tempKeep] = route;
        this->tempKeep++;
    }
}