#include <Episode.hpp>
#include <iostream>

Episode::Episode(std::string rt, std::string Name, float R) : runtime(rt), name(Name), rating(R) {};
Episode::Episode(const Episode& other): runtime(other.runtime), name(other.name), rating(other.rating) {};
Episode& Episode::operator=(const Episode& other)
{
    if (this != &other)
    {
        runtime = other.runtime;
        name = other.name;
        rating = other.rating;
    }
    return *this;
}

std::ifstream& operator>>(std::ifstream& fin, Episode& episode)
{};
std::ostream& operator<<(std::ostream& os, const Episode& episode){}

Episode::~Episode(){runtime.clear(), name.clear(), rating = 0.0;}

