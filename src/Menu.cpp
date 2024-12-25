#include <fstream>
#include <Menu.hpp>
#include <User.hpp>
#include <iostream>
#include <TVShow.hpp>
#include "Movie.hpp"
Menu Menu::uniqueInstance(0);
using namespace std;

Menu::Menu(const Menu &other) {
    data = other.data;
}

Menu &Menu::instance() { return uniqueInstance; }

void Menu::populateDB(vector<Movie> &movies, vector<TVShow> &tv_shows) {
    ifstream mfin("../input_files/movies.in");
    ifstream sfin("../input_files/tvshows.in");
    if (!mfin.is_open() || !sfin.is_open()) {
        std::cerr << "Error opening files (in function populateDB)" << std::endl;
        return;
    }
    Movie::readFile(mfin, movies);
    // for (const auto & movie : movies)
    //     cout << movie << endl;
    TVShow::readFile(sfin, tv_shows);
    // for (auto& tvshow : tv_shows)
    //     cout << tvshow << endl;
    TVShow::populateEpisodes(tv_shows);
    mfin.close();
    sfin.close();
}

void Menu::run() {
    cout << "Populating database, please wait..." << endl << endl;
    vector<Movie> movies;
    vector<TVShow> tvShow;
    populateDB(movies, tvShow);
    User &user = User::instance();
    string title;
    int choice = 1;
    int x = 0;
    while (choice && x <= 100) {
        bool chk = false;
        cout << "Enter 1 to create a watchlist, 2 to add a movie to a watchlist, 3 to add a TV Show to a watchlist,\n"
                "4 to print the contents of a watchlist, 5 to show the episodes from a TV Show,\n"
                "6 to update the status of a movie/tv show,\n"
                "7 to list movies and shows from a watchlist sorted by category\n"
                "0 to end the program" << endl;
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Exiting..." << endl;
                choice = 0;
                break;
            case 1:
                user.createWatchlist();
                ++x;
                break;
            case 2:
                if (user.checkWatchlist())
                    break;
                user.addMovie(movies);
                ++x;
                break;
            case 3:
                if (user.checkWatchlist())
                    break;
                user.addTVShow(tvShow);
                ++x;
                break;
            case 4:
                if (user.checkWatchlist())
                    break;
                user.printWatchlistContents();
                ++x;
                break;
            case 5:
                cout << "Title: ";
                cin >> title;
                cout << endl;
                for (const auto &i: tvShow) {
                    if (i.getTitle() == title)
                        i.printEpisodes(title), chk = true;
                }
                if (!chk)
                    cout << "Show not found or there is a typo in your title." << endl;
                ++x;
                break;
            case 6:
                if (user.checkWatchlist())
                    break;
                user.markAsWatched();
                ++x;
                break;
            case 7:
                if (user.checkWatchlist())
                    break;
                user.listSorted();
                ++x;
                break;
            default:
                ++x;
                cout << "Invalid choice." << endl;
                break;
        }
    }
    if (x > 100)
        cout << "Too many invalid choices. Program will now shutdown." << endl;
}
