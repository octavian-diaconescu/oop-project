#include "../inc/Builder.hpp"
#include "../inc/Movie.hpp"
#include "../inc/TVShow.hpp"

const Movie& MovieBuilder::build() {
    return movie;
}

// MovieBuilder &MovieBuilder::setTitle(const string &t) {
//         movie.title = t;
//         return *this;
// }

const TVShow& TVShowBuilder::build() {
    return tvshow;
}
