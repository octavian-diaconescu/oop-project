#include <Episode.hpp>
#include <iostream>
using namespace std;
Episode::Episode() : Content(){}

Episode::Episode(const std::string& name, const string& rating, const std::string& eps, const string& rt,  const float R) : Content(name, R, " "), epS(eps), runtime(rt) {}

Episode & Episode::operator+(const Episode & other) {
    epS = other.epS;
    title = other.title;
    rating = other.rating;
    runtime = other.runtime;
    return *this;
}

void Episode::printInfo() const {
    cout << epS <<  " " << title << " " << rating << " " << runtime << endl;
}

string Episode::getTitle() const {
    return title;
}

std::istream & operator>>(std::istream &in, Episode &ep) {
    in >> ep.epS >> ep.title >> ep.rating >> ep.runtime;
    return in;
}

std::ostream & operator<<(std::ostream &out, const Episode & other) {
    out << other.epS << " " << other.title << " " << other.rating << " " << other.runtime << endl;
    return out;
}
