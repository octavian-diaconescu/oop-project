#include <TVShow.hpp>
using namespace std;

TVShow::TVShow(string Title, float R, string ageR, std::vector<Episode>& ep) : Content(Title, R, ageR), episodes(ep){};

TVShow::TVShow(const TVShow& other) : Content(other), episodes(other.episodes){};

ifstream& operator>>(ifstream& fin, TVShow& obj){}
ostream& operator<<(ostream& out, const TVShow& obj)
{
    //out<<
}
TVShow::~TVShow()
{
    episodes.clear();
}


