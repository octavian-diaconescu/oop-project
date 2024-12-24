#include <fstream>
#include <Menu.hpp>
#include <User.hpp>
#include <iostream>
#include <TVShow.hpp>

#include "Actor.hpp"
#include "Movie.hpp"
Menu Menu::uniqueInstance(0);
using namespace std;

Menu &Menu::instance() { return uniqueInstance; }

void Menu::populateDB(vector<Movie> &movies, vector<TVShow> &tv_shows) {
    ifstream mfin("movies.in");
    ifstream sfin("tvshows.in");
    Movie::readFile(mfin, movies);
    // for (const auto & movie : movies)
    //     cout << movie << endl;
    TVShow::readFile(sfin, tv_shows);
    // for (auto& tvshow : tv_shows)
    //     cout << tvshow << endl;
    TVShow::populateEpisodes(tv_shows);
    mfin.close();
}

void Menu::run() {
    cout << "Populating database, please wait..." << endl << endl;
    vector<Movie> movies;
    vector<TVShow> tvShow;
    populateDB(movies, tvShow);
    User &user = User::instance();
    string title;
    char ch;
    //User::registerUser(user);
    while (true) {
        int choice;
        bool chk = false;
        cout << "Enter 1 to create a watchlist, 2 to add a movie to a watchlist, 3 to add a TV Show to a watchlist,\n"
                "4 to print the contents of a watchlist, 5 to show the episodes from a TV Show,\n"
                "6 to update the status of a movie/tv show, 7 to delete a watchlist\n"
                "0 to end the program" << endl;
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Exiting..." << endl;
                movies.clear();
                tvShow.clear();
                exit(0);
            case 1:
                user.createWatchlist();
                break;
            case 2:
                if (user.checkWatchlist())
                    break;
                user.addMovie(movies);
                break;
            case 3:
                if (user.checkWatchlist())
                    break;
                user.addTVShow(tvShow);
                break;
            case 4:
                if (user.checkWatchlist())
                    break;
                user.printWatchlistContents();
                break;
            case 5:
                cout << "Title: ";
                cin >> title;
                cout << endl;
                for (const auto &i: tvShow) {
                    if (i.getTitle() == title)
                        i.printEpisodes(), chk = true;
                }
                if (!chk)
                    cout << "Show not found or there is a typo in your title." << endl;
                break;
            case 6:
                if (user.checkWatchlist())
                    break;
                user.markAsWatched();
                break;
            case 7:
                if (user.checkWatchlist())
                    break;
                user.deleteWatchlist();
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}
