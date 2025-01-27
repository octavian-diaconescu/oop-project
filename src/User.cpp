#include "Watchlist.hpp"
#include "User.hpp"
#include "Movie.hpp"
#include "Storage.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <Exceptions.hpp>


using namespace std;

User::User(const int d) : data(d) {
}

User &User::instance() {
    return uniqueInstance;
}

void User::printWatchlistContents() const {
    int id;
    for (const auto &i: watchlist)
        cout << "ID: " << i.getID() << " | Name: " << i.getName() << endl;
    cout << "Enter ID: ";
    cin >> id;
    watchlist[id].printContents();
}

void User::registerUser(User &other) {
    const string filename = "input_files/users.txt";
    Storage<User> userStorage;
    if (userStorage.loadFromFile_User(filename, other)) {
        cout << "Please enter your full name: ";
        getline(cin, other.fullName);
        cout << "Please enter your birth date:(yyyy.mm.dd) ";
        cin >> other.birthDate;
        cout << "Please enter your preferred language:(EN, FR, RO, etc.) ";
        cin >> other.preferredLanguage;
        cout << "Please choose a username:(must not include spaces) ";
        cin >> other.username;
        try {
            userStorage.saveToFile_Users(filename, other);
        } catch (const FilePathError &e) {
            cerr << e.what() << endl;
        }
    } else {
        const string watchlist_filename = "input_files/watchlists.txt";
        Storage<Watchlist> watchStorage;
        cout << "Welcome, " << other.getUsername() << "!" << endl;
        try {
            watchStorage.loadFromFile(watchlist_filename);
        } catch (const FilePathError &e) {
            cerr << e.what() << endl;
        }
        other.watchlist = watchStorage.getItems();
    }
}

void User::reregisterUser(User &other) {
    const string filename = "input_files/users.txt";
    cout << "!WARNING! All users and associated watchlists will be lost. Do you want to proceed?(y/n): ";
    char choice = 'n';
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        Storage<User> userStorage;
        cin.ignore();
        cout << "Please enter your full name: ";
        getline(cin, other.fullName);
        cout << "Please enter your birth date:(yyyy.mm.dd) ";
        cin >> other.birthDate;
        cout << "Please enter your preferred language:(EN, FR, RO, etc.) ";
        cin >> other.preferredLanguage;
        cout << "Please choose a username:(must not include spaces) ";
        cin >> other.username;
        try {
            userStorage.saveToFile_Users(filename, other);
        } catch (const FilePathError &e) {
            cerr << e.what() << endl;
        }
    }
    ofstream emptyFile("input_files/watchlists.txt", ios::trunc);
    other.watchlist.clear();
}

void User::createWatchlist() {
    cout << "Do you want to name your watchlist? (y/n): ";
    char answer = 'n';
    string name;
    Watchlist obj1;
    cin >> answer;
    cin.ignore();
    switch (answer) {
        case 'y':
            cout << "Please enter your watchlist name: ";
            getline(cin, name);
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
}

const std::string &User::getUsername() const {
    return username;
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
            watchlist[id].addContent(make_shared<Movie>(i));
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
            cout << "Rate TVShow?: (y/n)";
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
                i.userRates();
            i.IsinWatchlist();
            watchlist[id].addContent(make_shared<TVShow>(i));
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
            cout << "Rate movie/tv show?: (y/n)";
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
    cout << "Movies in watchlist: " << endl;
    for (const auto &i: contents)
        if (const auto* movie = dynamic_cast<Movie*>(i.get()))
            movie->printInfo();
    cout << "TV Shows in watchlist: " << endl;
    for (const auto &content: contents)
        if (const auto *tvs = dynamic_cast<TVShow *>(content.get())) {
            tvs->printInfo();
        }
    cout << endl;
}

int User::checkWatchlist() const {
    if (watchlist.empty()) {
        cout << "No watchlist found!" << endl;
        return 1;
    }
    return 0;
}

void User::deleteContentFromWatchlist() {
    int id;
    cout << "Available watchlists:\n";
    for (const auto &wl: watchlist) {
        cout << "ID: " << wl.getID() << " | Name: " << wl.getName() << '\n';
    }
    cout << "Enter the ID of the watchlist to modify: ";
    cin >> id;
    if (id < 0 || id > Watchlist::getCnt()) {
        cout << "Invalid watchlist ID.\n";
        return;
    }
    cout << "Enter the title of the content to delete: ";
    string title;
    cin.ignore();
    getline(std::cin, title);
    watchlist[id].deleteContent(title);
}

void User::deleteWatchlist() {
    int id;
    cout << "Available watchlists:\n";
    for (const auto &wl: watchlist) {
        cout << "ID: " << wl.getID() << " | Name: " << wl.getName() << '\n';
    }
    cout << "Enter the ID of the watchlist to delete: ";
    cin >> id;

    if (id < 0 || id > Watchlist::getCnt()) {
        cout << "Invalid watchlist ID.\n";
        return;
    }

    watchlist[id].deleteWatchlist();
    watchlist.erase(watchlist.begin() + id);
}

void User::saveWatchlists() const {
    Storage<Watchlist> watchStorage;
    const string filename = "input_files/watchlists.txt";
    for (const auto& i: watchlist) {
        watchStorage.addItem(i);
    }
    watchStorage.saveToFile(filename);
}


istream &operator>>(istream &is, User &user) {
    getline(is, user.fullName);
    is >> user.birthDate >> user.preferredLanguage >> user.username;
    return is;
}

ostream &operator<<(ostream &os, const User &user) {
    os << user.fullName << endl;
    os << user.birthDate << " " << user.preferredLanguage << " " << user.username << endl;
    return os;
}

User User::uniqueInstance(0);


