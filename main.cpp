#include <iostream>
#include <fstream>
#include <Actor.hpp>
//#include <Category.hpp>
#include <Movie.hpp>
#include <User.hpp>
//#include <Watchlist.hpp>
//#include <TVShow.hpp>
using namespace std;

void populate()
{
    ifstream fin("users.in");
    ifstream mfin("movies.in");
    ifstream afin("actors.in");
    //fread actors
    vector<Actor> actors;
    Actor::readFile(afin, actors);
     for (auto& actor : actors)
         cout << actor << endl;
    //fread movies
    vector<Movie> movies;
    Movie::readFile(mfin, movies);
    for (auto & movie : movies)
        cout << movie << endl;
    //fread users
    vector<User> users;
    User::readFile(fin, users);
    for (auto & user1 : users)
        cout << user1 << endl;
    fin.close();
    mfin.close();
    afin.close();
}
//main
int main()
{
    populate();
    return 0;
}