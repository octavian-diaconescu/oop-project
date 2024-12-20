#pragma once
#include <string>

class Content
{
protected:
    std::string title;
    float rating;//out of 10
    std::string ageRating;//rated R, PG, etc.;
    std::string progress;
public:
    Content();
    Content(std::string, float, std::string);
    Content(const Content&);
    virtual std::string getTitle() const = 0;
    virtual ~Content() = 0;
};

