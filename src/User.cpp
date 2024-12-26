#include <iostream>
#include <fstream>
#include <algorithm>
#include "Watchlist.hpp"
#include "User.hpp"
#include "Movie.hpp"
#include "Storage.hpp"


using namespace std;

User::User(const int d) : data(d) {
}


// User::User(const User &other) {
//     fullName = other.fullName;
//     birthDate = other.birthDate;
//     preferredLanguage = other.preferredLanguage;
//     watchlist = other.watchlist;
//     data = other.data;
// }

User &User::instance() {
    return uniqueInstance;
}

// User &User::operator=(const User &other) {
//     if (this != &other) {
//         fullName = other.fullName;
//         birthDate = other.birthDate;
//         preferredLanguage = other.preferredLanguage;
//         watchlist = other.watchlist;
//         data = other.data;
//     }
//     return *this;
// }

void User::printWatchlistContents() const {
    int id;
    for (const auto &i: watchlist)
        cout << "ID: " << i.getID() << " | Name: " << i.getName() << endl;
    cout << "Enter ID: ";
    cin >> id;
    watchlist[id].printContents();
}

// void User::registerUser(User &other) {
//     cout << "Please enter your full name: ";
//     getline(cin, other.fullName);
//     cout << "Please enter your birth date:(yyyy.mm.dd) ";
//     cin >> other.birthDate;
//     cout << "Please enter your preferred language:(EN, FR, RO, etc.) ";
//     cin >> other.preferredLanguage;
//     cout << "Please choose a username:(must not include spaces) ";
//     cin >> other.username;
//     ofstream userFile("users.out");
//     Storage<User> storeUsers;
//     storeUsers.addItem(other);
//     storeUsers.printItems(userFile);
//     userFile.close();
// }

void User::createWatchlist() {
    cout << "Do you want to name your watchlist? (y/n): ";
    char answer;
    string name;
    Watchlist obj1;
    cin >> answer;
    cin.ignore();
    switch (answer) {
        case 'y':
            cout << "Please enter your watchlist name: ";
            getline(cin, name);
            //obj1.setName(name);
            obj1 + name;
            watchlist.push_back(obj1);
            break;
        case 'Y':
            cout << "Please enter your watchlist name: ";
            getline(cin, name);
            obj1 + name;
            watchlist.push_back(obj1);
            break;
        case 'n':
            watchlist.push_back(obj1);
            break;
        case 'N':
            watchlist.push_back(obj1);
            break;
        default:
            cout << "Please enter a valid option!" << endl;
            break;
    }
    Storage<Watchlist> storeWatchlists;
    ofstream watchlistFile("watchlists.out");
    for (const auto &i: watchlist)
        storeWatchlists.addItem(i);
    storeWatchlists.printItems(watchlistFile);
    watchlistFile.close();
}


void User::addMovie(vector<Movie> &mvs) {
    cout << "Available watchlists: " << endl;
    for (const auto &i: watchlist)
        cout << "ID: " << i.getID() << " | Name: " << i.getName() << endl;
    cout << endl;
    cout << "Enter the ID of the watchlist where you want to add a movie: ";
    int id;
    cin >> id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter an integer!\n";
        cout << "ID: ";
        cin.ignore();
        cin >> id;
    }
    if (id < 0 || id > Watchlist::getCnt()) {
        cout << "Please enter a valid ID!\nID: ";
        cin >> id;
    }
    cout << endl;
    cout << "What movie would you like to add?(enter its name): ";
    string name;
    cin >> name;
    int ok = 0;
    for (auto &i: mvs)
        if (i.getTitle() == name && !i.getWatchlistStatus()) {
            cout << "Mark movie as watched?: (y/n)";
            char answer;
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
                i.updateProgress();
            cout << "Rate movie?: (y/n)";
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
                i.userRates();
            i.IsinWatchlist();
            watchlist[id].addContent(shared_ptr<Content>(&i));
            ok = 1;
        }
    if (!ok)
        cout <<
                "Movie wasn't found in the database or it may already be in the watchlist. Check your spelling or add it manually!"
                << endl;
    if (ok) {
        cout << "Added successfully." << endl;
    }
}

void User::addTVShow(vector<TVShow> &tvs) {
    cout << "Available watchlists: " << endl;
    for (const auto &i: watchlist)
        cout << "ID: " << i.getID() << " | Name: " << i.getName() << endl;
    cout << endl;
    cout << "Enter the ID of the watchlist where you want to add a TV Show: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter an integer!\n";
        cout << "ID: ";
        cin.ignore();
        cin >> id;
        cout.flush();

        if (id < 0 || id > Watchlist::getCnt()) {
            cout << "Please enter a valid ID!\nID: ";
            cin >> id;
        }
    }

    cout << endl;
    cout << "What TV Show would you like to add?(enter its name): ";
    string name;
    cin >> name;
    int ok = 0;
    for (auto &i: tvs) {
        if (i.getTitle() == name && !i.getWatchlistStatus()) {
            cout << "Mark TV Show as watched?: (y/n)";
            char answer;
            cin >> answer;
            if (answer == 'y')
                i.updateProgress();
            i.IsinWatchlist();
            watchlist[id].addContent(shared_ptr<Content>(&i));
            ok = 1;
        }
    }
    if (!ok)
        cout <<
                "TV Show wasn't found in the database or it may already be in the watchlist. Check your spelling or add it manually!"
                << endl;
    if (ok) {
        cout << "Added successfully." << endl;
    }
}

void User::markAsWatched() const {
    cout << "Available watchlists: " << endl;
    for (const auto &i: watchlist)
        cout << "ID: " << i.getID() << " | Name: " << i.getName() << endl;
    cout << endl;
    cout << "Enter the ID of the watchlist where you want to add a movie: ";
    int id;
    cin >> id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter an integer!\n";
        cout << "ID: ";
        cin.ignore();
        cin >> id;
    }
    if (id < 0 || id > Watchlist::getCnt()) {
        cout << "Please enter a valid ID!\nID: ";
        cin >> id;
    }
    watchlist[id].printContents();
    cout << endl;
    cout << "What would you like to mark as watched?(enter its name): ";
    string name;
    cin >> name;
    int ok = 0;
    for (const auto &i: watchlist[id].getContents()) {
        if (i->getTitle() == name) {
            cout << "Mark as watched?: (y/n)";
            char answer;
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
                i->updateProgress();
            cout << "Rate movie?: (y/n)";
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
                i->userRates();
            ok = 1;
        }
    }
    if (!ok)
        cout <<
                "Movie/TV Show wasn't found in the watchlist. Check your spelling."
                << endl;
    if (ok) {
        cout << "Marked as watched." << endl;
    }
}

void User::listSorted() const {
    cout << "Available watchlists: " << endl;
    for (const auto &i: watchlist)
        cout << "ID: " << i.getID() << " | Name: " << i.getName() << endl;
    cout << endl;
    cout << "Enter the ID of the watchlist that you want to list(sorted): ";
    int id;
    cin >> id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter an integer!\n";
        cout << "ID: ";
        cin.ignore();
        cin >> id;
    }
    if (id < 0 || id > Watchlist::getCnt()) {
        cout << "Please enter a valid ID!\nID: ";
        cin >> id;
    }
    auto contents = watchlist[id].getContents();
    sort(contents.begin(), contents.end(), [](const shared_ptr<Content> &i, const shared_ptr<Content> &j) {
        return i->getCategory() < j->getCategory();
    });
    Storage<Movie> storeMovie;
    Storage<TVShow> storeTVShow;
    cout << "Movies in watchlist: " << endl;
    for (const auto &content: contents)
        if (const auto *movie = dynamic_cast<Movie *>(content.get())) {
            movie->printInfo();
            storeMovie.addItem(*movie);
        }
    cout << "TV Shows in watchlist: " << endl;
    for (const auto &content: contents)
        if (const auto *tvs = dynamic_cast<TVShow *>(content.get())) {
            tvs->printInfo();
            storeTVShow.addItem(*tvs);
        }
    cout << endl;
    ofstream watchlistFile("watchlists.out", ios::app);
    storeMovie.printItems(watchlistFile);
    storeTVShow.printItems(watchlistFile);
    watchlistFile.close();
}

int User::checkWatchlist() const {
    if (watchlist.empty()) {
        cout << "No watchlist found!" << endl;
        return 1;
    }
    return 0;
}

istream &operator>>(istream &is, User &user) {
    is >> user.fullName >> user.birthDate >> user.preferredLanguage;
    return is;
}

ostream &operator<<(ostream &os, const User &user) {
    os << user.fullName << " " << user.birthDate << " " << user.preferredLanguage << " " << user.username << endl;
    return os;
}

User User::uniqueInstance(0);


