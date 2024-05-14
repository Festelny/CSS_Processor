#pragma once
#include"String.cpp"
#include <iostream>

using namespace std;

class ListS {
private:
    String* nazwa;
    friend class ListD;
public:

    ListS* headS;

    ListS() {
        headS = nullptr;
        nazwa = 0;
    }

};

class ListA {
private:
    String* nazwa;
    String* wartosc;
    friend class ListD;
public:

    ListA* headA;

    ListA() {
        headA = nullptr;
        nazwa = 0;
        wartosc = 0;
    }
};


