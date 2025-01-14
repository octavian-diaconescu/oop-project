#pragma once
#include <Exceptions.hpp>

#include "User.hpp"
#include <sstream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <functional>

using namespace std;

template<class T>
class Storage {
    std::vector<T> items;

public:
    void addItem(const T &item) {
        items.push_back(item);
    }

    const vector<T> &getItems() {
        return items;
    }

    void saveToFile_Users(const string &filename, const User &user) const {
        ofstream outFile(filename, ios::binary | ios::out);
        if (!outFile) {
            throw FilePathError(filename);
        }
        ostringstream oss;
        oss << user;
        string serializedItem = oss.str();

        size_t itemSize = serializedItem.size();
        outFile.write(reinterpret_cast<const char *>(&itemSize), sizeof(itemSize));

        outFile.write(serializedItem.c_str(), itemSize);
        outFile.close();
    }


    void saveToFile(const string &filename) const {
        ofstream outFile(filename, ios::binary | ios::out);
        if (!outFile) {
            throw FilePathError(filename);
        }

        const size_t size = items.size();
        outFile.write(reinterpret_cast<const char *>(&size), sizeof(size));

        for (const auto &item: items) {
            ostringstream oss;
            item <<= oss;
            string serializedItem = oss.str();

            size_t itemSize = serializedItem.size();
            outFile.write(reinterpret_cast<const char *>(&itemSize), sizeof(itemSize));

            outFile.write(serializedItem.c_str(), itemSize);
        }

        outFile.close();
    }

    int loadFromFile_User(const string &filename, User &user) {
        ifstream inFile(filename, ios::binary | ios::in);
        if (!inFile) {
            throw FilePathError(filename);
        }
        if (inFile.peek() == ifstream::traits_type::eof()) {
            return 1;
        }
        size_t itemSize;
        inFile.read(reinterpret_cast<char *>(&itemSize), sizeof(itemSize));

        string serializedItem(itemSize, '\0');
        inFile.read(&serializedItem[0], itemSize);

        istringstream iss(serializedItem);
        iss >> user;

        return 0;
    }


    int loadFromFile(const string &filename) {
        ifstream inFile(filename, ios::binary | ios::in);
        if (!inFile) {
            throw FilePathError(filename);
        }
        if (inFile.peek() == ifstream::traits_type::eof()) {
            return 1;
        }
        size_t size;
        inFile.read(reinterpret_cast<char *>(&size), sizeof(size));
        items.clear();
        items.reserve(size);

        for (size_t i = 0; i < size; ++i) {
            size_t itemSize;
            inFile.read(reinterpret_cast<char *>(&itemSize), sizeof(itemSize));

            string serializedItem(itemSize, '\0');
            inFile.read(&serializedItem[0], itemSize);

            istringstream iss(serializedItem);
            T item;
            item >>= iss;
            items.push_back(item);
        }
        inFile.close();
        return 0;
    }
};





