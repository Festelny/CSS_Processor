#pragma once
#define T 17
#include"String.cpp"
#include"ListS.cpp"
#include <iostream>

using namespace std;


struct node {
    ListS* selektory = nullptr;
    ListA* atrybuty = nullptr;
    int selektoryc = 0;
    int atrybutyc = 0;
    bool czycostujest = false;
};

class ListD {
private:
    struct node Sekcje[T];
    int index = 0;
public:
    ListD* next;
    ListD* prev;

    ListD() {
        next = nullptr;
        prev = nullptr;
    }

    ListD* addNode(ListD** node) {
        index++;
        if (index == T) {
            ListD* newNode = new ListD;
            ListD* curr = (*node);
            curr->next = newNode;
            newNode->prev = curr;
            index = 0;
            return newNode;
        }
        return (*node);
    }

    void addSelectors(ListD** sectionnode, String* name) {
        ListS* newNode = new ListS;
        String* copy = new String;
        copy->copy(*name);
        if ((*sectionnode)->Sekcje[index].selektory == nullptr) {
            (*sectionnode)->Sekcje[index].selektory = newNode;
        }
        else {
            ListS* next = (*sectionnode)->Sekcje[index].selektory;
            while (next->headS != nullptr) {
                if (*(next->nazwa) == *copy) {
                    next = nullptr;
                    return;
                }
                next = next->headS;
            }
            next->headS = newNode;
        }
        newNode->nazwa = copy;
        (*sectionnode)->Sekcje[index].czycostujest = true;
        (*sectionnode)->Sekcje[index].selektoryc++;
    }


    void addAtrybutes(ListD** sectionnode, String* name, String* value) {
        ListA* newNode = new ListA;
        String* copy = new String;
        String* copyvalue = new String;
        copy->copy(*name);
        copyvalue->copy(*value);
        if ((*sectionnode)->Sekcje[index].atrybuty == nullptr) {
            (*sectionnode)->Sekcje[index].atrybuty = newNode;
        }
        else {
            ListA* next = (*sectionnode)->Sekcje[index].atrybuty;
            while (next->headA != nullptr) {
                if (*(next->nazwa) == *name) {
                    next->wartosc = copyvalue;
                    return;
                }
                next = next->headA;
            }
            if (*(next->nazwa) == *name) {
                next->wartosc = copyvalue;
                return;
            }
            next->headA = newNode;
        }
        newNode->nazwa = copy;
        newNode->wartosc = copyvalue;
        (*sectionnode)->Sekcje[index].czycostujest = true;
        (*sectionnode)->Sekcje[index].atrybutyc++;

    }

    void printsele(ListD** sectionnode) {
        ListS* current = (*sectionnode)->Sekcje[index].selektory;
        while (current != nullptr) {
            current->nazwa->print();
            cout << " ";
            current = current->headS;
        }
        std::cout << std::endl;
    }

    void printatryb(ListD** sectionnode) {
        ListA* current = (*sectionnode)->Sekcje[index].atrybuty;
        while (current != nullptr) {
            current->nazwa->print();
            cout << " ";
            current->wartosc->print();
            cout << " ";
            current = current->headA;
        }
        std::cout << std::endl;
    }

    void liczbaSznakz(int i) {
        i = i - 1;
        int position = i % T;
        ListD* curr = this;
        while (curr->prev != nullptr) {
            curr = curr->prev;
        }
        for (int w = 0; w < i / T; w++) {
            curr = curr->next;
        }
        if (curr->Sekcje[position].atrybutyc == 0) {
            return;
        }
        printf("%d,S,? == %d", i + 1, curr->Sekcje[position].selektoryc);
        printf("\n");

    }

    void liczbaSliczba(int i, int j, int numberofsections) {
        j = j - 1;
        i = i - 1;
        int position = i % T;
        ListD* curr = this;
        while (curr->prev != nullptr) {
            curr = curr->prev;
        }
        for (int w = 0; w < i / T; w++) {
            curr = curr->next;
        }
        ListS* item = curr->Sekcje[i].selektory;
        for (int w = 0; w < j; w++) {
            item = curr->Sekcje[i].selektory->headS;
        }
        if (item != nullptr) {
            if (item->nazwa != nullptr) {
                printf("%d,S,%d == ", i + 1, j + 1);
                item->nazwa->print();
                printf("\n");
                return;
            }
        }

    }

    void znakSznakz(String* name, int numberofsections) {
        int index = 0;
        int skip = (numberofsections / T) + 1;
        ListD* curr = this;
        for (int i = 0; i < skip; i++) {
            for (int w = 0; w < T; w++) {
                ListS* item = curr->Sekcje[w].selektory;
                if (item != NULL) {
                    while (item != nullptr) {
                        if (*(item->nazwa) == *name) {
                            index++;
                        }
                        item = item->headS;
                    }
                }
            }
            curr = curr->prev;
        }

        name->print();
        printf(",S,? == %d\n", index);
    }

    void liczbaAznakz(int i) {
        i = i - 1;
        int position = i % T;
        ListD* curr = this;
        while (curr->prev != nullptr) {
            curr = curr->prev;
        }
        for (int w = 0; w < i / T; w++) {
            curr = curr->next;
        }
        if (curr->Sekcje[position].atrybutyc == 0) {
            return;
        }
        printf("%d,A,? == %d", i + 1, curr->Sekcje[position].atrybutyc);
        printf("\n");

    }

    void liczbaAznak(int i, String* a3) {
        i = i - 1;
        int position = i % T;
        ListD* curr = this;
        while (curr->prev != nullptr) {
            curr = curr->prev;
        }
        for (int w = 0; w < i / T; w++) {
            curr = curr->next;
        }
        ListA* item = curr->Sekcje[position].atrybuty;
        while (item != nullptr) {
            if (*(item->nazwa) == *a3) {
                printf("%d,A,", i + 1);
                item->nazwa->print();
                printf(" == ");
                item->wartosc->print();
                printf("\n");
                return;
            }
            item = item->headA;
        }
    }

    void znakAznakz(String* name, int numberofsections) {
        int index = 0;
        int skip = (numberofsections / T) + 1;
        ListD* curr = this;
        for (int i = 0; i < skip; i++) {
            for (int w = 0; w < T; w++) {
                ListA* item = curr->Sekcje[w].atrybuty;
                if (item != NULL) {
                    while (item != nullptr) {
                        if (*(item->nazwa) == *name) {
                            index++;
                        }
                        item = item->headA;
                    }
                }
            }
            curr = curr->prev;
        }
        name->print();
        printf(",A,? == %d", index);
        printf("\n");
    }

    void znakEznak(String* a1, String* a2, int numberofsections) {
        int skip = (numberofsections / T) + 1;
        ListD* curr = this;
        for (int k = 0; k < skip; k++) {
            for (int i = T - 1; i >= 0; i--) {
                ListS* item = curr->Sekcje[i].selektory;
                if (item != NULL) {
                    while (item != nullptr) {
                        if (*(item->nazwa) == *a1) {
                            ListA* itemm = curr->Sekcje[i].atrybuty;
                            if (itemm != NULL) {
                                while (itemm != nullptr) {
                                    if (*(itemm->nazwa) == *a2) {
                                        a1->print();
                                        printf(",E,");
                                        a2->print();
                                        printf(" == ");
                                        itemm->wartosc->print();
                                        printf("\n");
                                        return;
                                    }
                                    itemm = itemm->headA;
                                }
                            }
                        }
                        item = item->headS;
                    }
                }
            }
            curr = curr->prev;
        }
    }

    void liczbaDgwiazdka(int i, int* numberofsections) {
        i = i - 1 ;
        int position = i % T;
        ListD* curr = this;
        while (curr->prev != nullptr) {
            curr = curr->prev;
        }
        ListS* todel = curr->Sekcje[position].selektory;
        ListS* next = nullptr;
        while (todel != nullptr) {
            next = todel->headS;
            delete todel->nazwa;
            delete todel;
            todel = next;
        }

        ListA* todell = curr->Sekcje[position].atrybuty;
        ListA* nextl = nullptr;
        while (todell != nullptr) {
            nextl = todell->headA;
            delete todell->nazwa;
            delete todell->wartosc;
            delete todell;
            todell = nextl;
        }
        curr->Sekcje[position].atrybuty = nullptr;
        curr->Sekcje[position].selektory = nullptr;
        curr->Sekcje[position].selektoryc = 0;
        curr->Sekcje[position].atrybutyc = 0;
        curr->Sekcje[position].czycostujest = false;

    }

};







