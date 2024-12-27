#include "Menu.hpp"
#include "User.hpp"
#include "TVShow.hpp"
#include "Movie.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Menu Menu::uniqueInstance(0);

Menu::Menu(const Menu &other) {
    data = other.data;
}

Menu &Menu::instance() { return uniqueInstance; }

// void Menu::populateDB(vector<Movie> &movies, vector<TVShow> &tv_shows) {
//     string fileName1 = "../input_files/movies.txt";
//     string fileName2 = "../input_files/tvshows.txt";
//     ifstream movies_in(fileName1, ios::in);
//     ifstream shows_in(fileName2, ios::in);
//     if (!movies_in || !shows_in) {
//         std::cerr << "Error opening files (in function populateDB)" << std::endl;
//         return;
//     }
//     const vector<string> names = {
//         "Black_Mirror", "Breaking_Bad", "Friends", "Game_of_Thrones", "Sherlock", "Stranger_Things", "The_Crown",
//         "The_Office", "The_Sopranos", "The_Wire"
//     };
//
//     Movie::readFile(movies_in, movies);
//     TVShow::readFile(shows_in, tv_shows);
//
//     size_t j = 0;
//     for (auto &i: tv_shows) {
//         if (j >= names.size()) break;
//         if (i.getTitle() == names[j]) {
//             ifstream in("../input_files/" + names[j] + ".txt");
//             if (!in) {
//                 cerr << "Error opening file " << names[j] + ".txt" << endl;
//                 continue;
//             }
//             i.populateEpisodes(in);
//             ++j;
//         }
//     }
// }

void Menu::run() {
    cout << "Populating database, please wait..." << endl << endl;
    vector<Movie> movies;
    vector<TVShow> tvShow;
    //populateDB(movies, tvShow);
    User &user = User::instance();
    //User::registerUser(user);
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
