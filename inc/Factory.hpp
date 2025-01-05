#pragma once
#include "Movie.hpp"
#include "TVShow.hpp"
#include "Episode.hpp"
#include <memory>

class ContentFactory {
public:
    virtual ~ContentFactory() = default;
    [[nodiscard]] virtual std::shared_ptr<Content> createShortContent() const = 0;
    [[nodiscard]] virtual std::shared_ptr<Content> createLongContent() const = 0;
};

class ShortContent : public ContentFactory {
public:
    [[nodiscard]] std::shared_ptr<Content> createShortContent() const override {
        return std::make_shared<Episode>();
    }
    [[nodiscard]] std::shared_ptr<Content> createLongContent() const override {
         return std::make_shared<Movie>();
    }
};

class LongContent : public ContentFactory {
public:
    [[nodiscard]] std::shared_ptr<Content> createShortContent() const override {
        return std::make_shared<Episode>();
    }
    [[nodiscard]] std::shared_ptr<Content> createLongContent() const override {
      return std::make_shared<TVShow>();
    }
};
