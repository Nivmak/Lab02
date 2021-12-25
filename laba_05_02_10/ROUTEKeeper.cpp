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
    return a.getPunct1()[0] < b.getPunct1()[0];
}

void ROUTEKeeper::dataProcessing(int value) {
    switch (value) {
    case 1: {
        ROUTE route;
        std::cin.ignore(32767, '\n');
        std::cout << "Print next data separated by commas: Punct1, Punct2, Route number\n";

        std::cin >> route;
        addROUTE(route);
        std::sort(routeKeeper, routeKeeper + tempKeep, comparator);
        break;
    }
    case 2: {
        if (!tempKeep) {
            std::cout << "You have not route\n";
            return;
        }
        std::cin.ignore(32676, '\n');
        std::cout << "Your routecraft types:\n";
        std::string routecrafts;
        for (int i = 0; i < tempKeep; i++) {
            if (routecrafts.find(routeKeeper[i].getPunct1()) == std::string::npos) {
                std::cout << "\t" << routeKeeper[i].getROUTENumber() << "\n";
                routecrafts.append(routeKeeper[i].getPunct1());
            }
        }
        int number = 1;
        std::cout << "Enter an Route number:\n";
        int routecraft;
        std::cin >> routecraft;

        for (int i = 0; i < tempKeep; i++) {
            if (routeKeeper[i].getROUTENumber() == routecraft) {
                std::cout << "This routecraft \"" << routeKeeper[i].getROUTENumber() << "\" serves:\n";
                std::cout << "\t" << number << ": Punct1 " << routeKeeper[i].getPunct1()
                    << ", Punct2 " << routeKeeper[i].getPunct2() << "\n";
                number++;
            }
        }
        if (number == 1) {
            std::cout << "The routecraft \"" << routecraft << "\" does not serve any flights\n";
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