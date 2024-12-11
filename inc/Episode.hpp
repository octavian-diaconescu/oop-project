#pragma once
#include <string>
class Episode
{
    std::string runtime;
    std::string name;
    float rating; //out of 10
public:
    Episode(std::string, std::string, float);
    Episode(const Episode &);
    Episode &operator=(const Episode &);
    friend std::ifstream& operator>>(std::ifstream&, const Episode &);
    friend std::ostream& operator<<(std::ostream&, const Episode &);
    ~Episode();
};