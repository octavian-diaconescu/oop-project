#include "../inc/Builder.hpp"
#include "../inc/Movie.hpp"
#include "../inc/TVShow.hpp"

Movie MovieBuilder::build() {
    return movie;
}

// MovieBuilder &MovieBuilder::setTitle(const string &t) {
//         movie.title = t;
//         return *this;
// }

TVShow TVShowBuilder::build() {
    return tvshow;
}
