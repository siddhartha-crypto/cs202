/*
 * CityPath.cpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Definition file for CityPath content
 */

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>
#include <iterator>
#include <cmath>

#include "CityList.hpp"
#include "CityNode.hpp"
#include "CityPath.hpp"
#include "Takotna.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::pair;
using std::make_pair;
using std::setw;
using std::right;
using std::left;
using std::advance;

namespace fs = std::filesystem; 

void CityPath::addCity(const unsigned int& nextCity) {
    connections_.push_back(nextCity);
}

void CityPath::removeCity(const unsigned int& nextCity) {
    if (connections_.size() == 0) {
        cout << "Error calling .removeCity()" << endl;
        exit(0);
    }
    vector<unsigned int>::iterator it = connections_.begin();

    while (*it != nextCity && it != connections_.end()) advance(it, 1);

    if (it == connections_.end()) {
        cout << "Error searching for city to remove" << endl;
        exit(0);
    }

    connections_.erase(it);
}

size_t CityPath::getCount() {
    return connections_.size();
}
