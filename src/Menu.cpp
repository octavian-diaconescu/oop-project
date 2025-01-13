#include "Menu.hpp"
#include "User.hpp"
#include "TVShow.hpp"
#include "Movie.hpp"
#include "Storage.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Menu Menu::uniqueInstance(0);

Menu::Menu(const Menu &other) {
    data = other.data;
}

Menu &Menu::instance() { return uniqueInstance; }

void Menu::populateDB(vector<Movie> &movies, vector<TVShow> &tv_shows) {
    ifstream movies_in("input_files/movies.txt");
    ifstream shows_in("input_files/tvshows.txt");
    if (!movies_in || !shows_in) {
        throw FilePathError("input_files/movies.txt or input_files/tvshows.txt");
    }

    Movie::readFile(movies_in, movies);
    TVShow::readFile(shows_in, tv_shows);
    const vector<string> names = {
        "Black_Mirror", "Breaking_Bad", "Friends", "Game_of_Thrones", "Sherlock", "Stranger_Things", "The_Crown",
        "The_Office", "The_Sopranos", "The_Wire"
    };

    size_t j = 0;
    for (auto &i: tv_shows) {
        if (j >= names.size()) break;
        if (i.getTitle() == names[j]) {
            ifstream in("input_files/" + names[j] + ".txt");
            if (!in) {
                cerr << "Error opening file " << names[j] + ".txt" << endl;
                continue;
            }
            i.populateEpisodes(in);
            ++j;
        }
    }
}

void Menu::run() {
    cout << "Populating database, please wait..." << endl << endl;
    vector<Movie> movies;
    vector<TVShow> tvShow;
    try {
        populateDB(movies, tvShow);
    } catch (const FilePathError &e) {
        cerr << e.what() << endl;
    }
    User &user = User::instance();
    User::registerUser(user);
    string title;
    int choice = 1;
    int innerChoice = 0;
    int x = 0;
    while (choice && x <= 100) {
        bool chk = false;
        cout << "1. Create a watchlist" << endl;
        cout << "2. Add a movie to a watchlist" << endl;
        cout << "3. Add a tv show to a watchlist" << endl;
        cout << "4. Print contents of a watchlist" << endl;
        cout << "5. Print the episodes from a TV Show" << endl;
        cout << "6. Update the status of a movie/tv show" << endl;
        cout << "7. Delete something from a watchlist / Delete a watchlist" << endl;
        cout << "8. List movies and shows from a watchlist sorted by category" << endl;
        cout << "9. Register a new user" << endl;
        cout << "0. Exit" << endl << endl;
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Saving watchlists..." << endl;
                user.saveWatchlists();
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
                cout <<
                        "Do you want to delete content(1) from a watchlist or an entire watchlist(2)?. Enter the corresponding number: ";
                cin >> innerChoice;
                if (innerChoice == 1)
                    user.deleteContentFromWatchlist();
                else if (innerChoice == 2)
                    user.deleteWatchlist();
                else cout << "Misinput. Try again!" << endl;
                break;
            case 8:
                if (user.checkWatchlist())
                    break;
                user.listSorted();
                ++x;
                break;
            case 9:
                User::reregisterUser(user);
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
