#include <Episode.hpp>
#include <iostream>
#include <utility>
using namespace std;

Episode::Episode(const Episode &other) : Content(other), epS(other.epS), runtime(other.runtime) {
}

Episode &Episode::operator=(const Episode &other) {
    if (this != &other) {
        epS = other.epS;
        runtime = other.runtime;
    }
    return *this;
}

void Episode::printInfo() const {
    cout << epS <<  " " << title << " " << rating << " " << runtime << endl;
}

std::istream & operator>>(std::istream &in, Episode &ep) {
    in >> ep.epS >> ep.title >> ep.rating >> ep.runtime;
    return in;
}

std::ostream & operator<<(std::ostream &out, const Episode & other) {
    out << other.epS << " " << other.title << " " << other.rating << " " << other.runtime << endl;
    return out;
}
