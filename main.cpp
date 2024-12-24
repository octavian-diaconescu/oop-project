#include <iostream>
#include <fstream>
#include <Actor.hpp>
//#include <Category.hpp>
#include <Movie.hpp>
#include "Menu.hpp"
#include <User.hpp>
//#include <Watchlist.hpp>
//#include <TVShow.hpp>
using namespace std;

void populate()
{
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
    mfin.close();
    afin.close();
}

int main()
{
    Menu::run();

    return 0;
}