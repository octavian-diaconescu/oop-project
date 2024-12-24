#include <iostream>
#include <fstream>
#include "Watchlist.hpp"
#include "User.hpp"
#include "Movie.hpp"
using namespace std;


User::User(const User &other) {
    fullName = other.fullName;
    birthDate = other.birthDate;
    preferredLanguage = other.preferredLanguage;
    watchlist = other.watchlist;
    data = other.data;
}

User &User::instance() {
    return uniqueInstance;
}

User &User::operator=(const User &other) {
    if (this != &other) {
        fullName = other.fullName;
        birthDate = other.birthDate;
        preferredLanguage = other.preferredLanguage;
        watchlist = other.watchlist;
    }
    return *this;
}

void User::printWatchlistContents() const {
    int id;
    for (const auto &i: watchlist)
        cout << "ID: " << i.getID() << " | Name: " << i.getName() << endl;
    cout << "Enter ID: ";
    cin >> id;
    watchlist[id].printContents();
}

// void User::registerUser(User &other) {
//     ofstream usersOutFile("user.out");
//     cout << "Please enter your full name: ";
//     getline(cin, other.fullName);
//     cout << "Please enter your birth date:(yyyy.mm.dd) ";
//     cin >> other.birthDate;
//     cout << "Please enter your preferred language:(EN, FR, RO, etc.) ";
//     cin >> other.preferredLanguage;
//     cout << "Please choose a username:(must not include spaces) ";
//     cin >> other.username;
//     usersOutFile << other.fullName << " " << other.birthDate << " " << other.preferredLanguage << " " << other.username;
//     usersOutFile.close();
// }

void User::createWatchlist() {
    cout << "Do you want to name your watchlist? (y/n): ";
    int i = 0;
    char answer;
    string name;
    Watchlist obj1;
    while (i < 1) {
        cin >> answer;
        cin.ignore();
        switch (answer) {
            case 'y':
                cout << "Please enter your watchlist name: ";
                getline(cin, name);
                obj1.setName(name);
                watchlist.push_back(obj1);
                ++i;
                break;
            case 'Y':
                cout << "Please enter your watchlist name: ";
                getline(cin, name);
                obj1.setName(name);
                watchlist.push_back(obj1);
                i++;
                break;
            case 'n':
                ++i;
                watchlist.push_back(obj1);
                break;
            case 'N':
                i++;
                watchlist.push_back(obj1);
                break;
            default:
                cout << "Please enter a valid option!" << endl;
                cout << ": ";
                break;
        }
    }
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
    if (id < 0 || static_cast<size_t>(id) > watchlist.size()) {
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

        if (id < 0 || static_cast<size_t>(id) > watchlist.size()) {
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
        // cout << "TV Shows in '" << watchlist[id].getName() << "': " << endl;
        // watchlist[id].printContents();
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
    if (id < 0 || static_cast<size_t>(id) > watchlist.size()) {
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

void User::deleteWatchlist() {
    cout << "Enter ID: ";
    int id;
    cin >> id;
   if (id < 0 || static_cast<size_t>(id) > watchlist.size()) {
        cout << "Please enter a valid ID!\nID: ";
        cin >> id;
    }
    for (auto it = watchlist.begin(); it != watchlist.end(); ++it) {
        if (it->getID() == id) {
            watchlist.erase(it);
            break;
        }
    }
}

// void User::removeFromWatchlist() const {
//     cout << "Available watchlists: " << endl;
//     for (const auto &i: watchlist)
//         cout << "ID: " << i.getID() << " | Name: " << i.getName() << endl;
//     cout << endl;
//     cout << "Enter the ID of the watchlist from which you want to remove: ";
//     int id;
//     cin >> id;
//     if (cin.fail()) {
//         cin.clear();
//         cin.ignore();
//         cout << "Invalid input. Please enter an integer!\n";
//         cout << "ID: ";
//         cin.ignore();
//         cin >> id;
//     }
//     if (id < 0 || id > watchlist.size()) {
//         cout << "Please enter a valid ID!\nID: ";
//         cin >> id;
//     }
//     cout << endl;
//     cout << "What would you like to remove?(enter its name): ";
//     string name;
//     cin >> name;
//     int ok = 0;
//     auto cp = watchlist[id].contentsReference();
//     for (auto it = cp.begin(); it != cp.end(); ++it) {
//         if (dynamic_cast<Movie *>(it->get()) || dynamic_cast<TVShow *>(it->get())) {
//             if ((*it)->getTitle() == name) {
//                 cp.erase(it);
//                 ok = 1;
//                 break;
//             }
//         }
//     }
//
//     if (!ok)
//         cout <<
//                 "Movie/TV Show wasn't found in the watchlist. Check your spelling."
//                 << endl;
//     if (ok) {
//         //watchlist[id].insertIntoContents(cp);
//         cout << "Removed from watchlist." << endl;
//     }
// }

// void User::printWatchlist() const {
//     for (const auto &i: watchlist)
//         i.printContents();
// }

int User::checkWatchlist() const {
    if (watchlist.empty()) {
        cout << "No watchlist found!" << endl;
        return 1;
    }
    return 0;
}

// void User::readFile(ifstream&fin, vector<User>& us)
// {
//     User user;
//     while (fin >> user)
//     {
//         user.id = cnt++;
//         us.push_back(user);
//     }
// }

// ifstream& operator>>(ifstream& fin, User& users)
// {
//     fin >> users.fullName >> users.birthDate >> users.preferedLanguage;
//     return fin;
// }
//
istream &operator>>(istream &is, User &user) {
    is >> user.fullName >> user.birthDate >> user.preferredLanguage;
    return is;
}

ostream &operator<<(ostream &os, const User &user) {
    os << user.fullName << " " << user.birthDate << " " << user.preferredLanguage << " " << user.username << endl;
    return os;
}

User User::uniqueInstance(0);

User::~User() {
    fullName.clear();
    birthDate.clear();
    preferredLanguage.clear();
    watchlist.clear();
}
