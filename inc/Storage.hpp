#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Storage {
    vector<T> items;

public:
    void addItem(const T &item) {
        items.push_back(item);
    }

    void printItems(ostream& os) const {
        for (const auto &item: items) {
            os << item << " " << std::endl;
        }
        os << std::endl;
    }
};




