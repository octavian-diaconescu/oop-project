#pragma once
#include <memory>
#include "Movie.hpp"
#include "TVShow.hpp"

class ContentFactory {
public:
    virtual ~ContentFactory() = default;
    [[nodiscard]] virtual std::shared_ptr<Content> createContent() const = 0;
};

class MovieFactory : public ContentFactory {
public:
    [[nodiscard]] std::shared_ptr<Content> createContent() const override {
        return std::make_shared<Movie>();
    }
};

class TVShowFactory : public ContentFactory {
public:
    [[nodiscard]] std::shared_ptr<Content> createContent() const override {
        return std::make_shared<TVShow>();
    }
};
