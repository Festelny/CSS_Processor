#pragma once
#include <iostream>

using namespace std;

class String {
public:
    // Konstruktory
    String() : str(nullptr), len(0) {}

    String(const char* s) {
        len = strlen(s);
        str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            str[i] = s[i];
        }
        str[len] = '\0';
    }

    String(const char* s, int iterator) {
        str = new char[iterator + 1];
        len = iterator + 1;
        for (int i = 0; i < iterator; i++) {
            str[i] = s[i];
        }
        str[iterator] = '\0';
    }

    String(const char* s, int start, int koniec) {
        int k = start;
        len = koniec - start + 1;
        str = new char[len];
        for (int i = 0; i < len - 1; i++) {
            str[i] = s[k];
            k++;
        }
        str[len - 1] = '\0';
    }

    ~String() {
        delete[] str;
    }

    String& copy(const String& other) {
        if (this == &other) {
            return *this;
        }
        delete[] str;
        len = other.len;
        str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            str[i] = other.str[i];
        }
        str[len] = '\0';
        return *this;
    }

    void print() const {
        std::cout << str;
    }

    int czytoint() {
        return atoi(str);
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

private:
    char* str;
    int len;
};