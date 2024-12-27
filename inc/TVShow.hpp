#pragma once
#include <string>
#include <vector>
#include "Category.hpp"
#include "Content.hpp"
#include "Episode.hpp"

class TVShow : public Content {
    std::vector<Episode> episodes;
public:
    friend class TVShowBuilder;

    TVShow() = default;

    TVShow(const TVShow &) = default;

    TVShow &operator=(const TVShow &) = default;

    friend std::istream &operator>>(std::istream &, TVShow &);

    friend std::ostream &operator<<(std::ostream &, const TVShow &);

    void printInfo() const override;

   // std::vector<Episode> *getEpisodes();

    [[nodiscard]] std::string getTitle() const override;

    void populateEpisodes(std::istream &);

    void printEpisodes(const std::string&) const ;

    ~TVShow() override = default;

    static void readFile(std::istream &sfin, std::vector<TVShow> &vector);
};
