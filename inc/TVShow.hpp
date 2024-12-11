#pragma once
#include <string>
#include <vector>
#include "Content.hpp"
#include "Episode.hpp"

class TVShow : public Content{
    std::vector<Episode> episodes;
public:
    TVShow(std::string, float, std::string, std::vector<Episode>&);
    TVShow(const TVShow&);
    friend std::ifstream& operator>>(std::ifstream&, const TVShow&);
    friend std::ostream& operator<<(std::ostream&, const TVShow&);
    ~TVShow();
};
