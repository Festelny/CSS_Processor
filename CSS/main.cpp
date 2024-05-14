#include "String.cpp"
#include "ListD.cpp"
#include <iostream>

using namespace std;

void instructionreader(String* a1, String* a2, String* a3, char* tab, int charpos) {
    int i = 0, j = 0;
    if (tab[i] == '?')
    {
        String bu(tab, 1);
        a1->copy(bu);
        a2->copy(bu);
        a3->copy(bu);
        tab[0] = '/';
        return;
    }
    while (i < charpos && j < 3) {
        char buff[200] = {};
        int k = 0;
        while (tab[i] != ',' && tab[i] != '\n' && i < charpos && k < 100) {
            buff[k] = tab[i];
            i++;
            k++;
        }
        i++;
        buff[k] = '\0';
        if (j == 0) {
            String b(buff);
            a1->copy(b);
        }
        else if (j == 1) {
            String b(buff);
            a2->copy(b);
        }
        else if (j == 2) {
            String b(buff);
            a3->copy(b);
            tab[0] = '/';
            return;
        }
        j++;
    }
    tab[0] = '/';
    String bu(tab, 1);
    a1->copy(bu);
    a2->copy(bu);
    a3->copy(bu);
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ListD* list = new ListD;

    int whereami = 0; 
    int numberofsections = 0;
    char cinn = 'x';
    char tab[250] = {};
    int charpos = 0;
    int valuestart = 0;
    while (cinn != EOF )
    {
        cinn = getchar();
        if (whereami == 0)
        {
            if (cinn < 32) {
                continue;
            }
            else if (cinn == '?') {
                cin >> tab[0];
                cin >> tab[0];
                cin >> tab[0];
                tab[0] = 'x';
                charpos = 0;
                whereami = 2;
            }
            else if (cinn != ',' && cinn != '{') {
                tab[charpos] = cinn;
                charpos++;
            }
            else if (cinn == ',') {
                if (tab[charpos] == 32) {
                    charpos--;
                }
                String name(tab, charpos);
                list->addSelectors(&list, &name);
                charpos = 0;
                if ((cinn = getchar()) == 32) {
                    continue;
                }
                else if (cinn == '\n') {
                    continue;
                }
                else {
                    tab[charpos] = cinn;
                    charpos++;
                }

            }
            else if (cinn == '{')
            {
                if (tab[charpos - 1] == 32) {
                    charpos--;
                }
                String name(tab, charpos);
                list->addSelectors(&list, &name);
                charpos = 0;
                whereami = 1;
            }
        }
        else if (whereami == 1)
        {
            if (cinn < 32) {
                continue;
            }
            if (cinn == ' ' && charpos == 0) {
                continue;
            }
            else if (cinn != ';' && cinn != '}') {
                if (cinn == ':') {
                    valuestart = charpos;
                }
                tab[charpos] = cinn;
                charpos++;
            }
            else if (cinn == ';') {
                String name(tab, valuestart);
                String value(tab, valuestart + 1, charpos);
                list->addAtrybutes(&list, &name, &value);
                charpos = 0;
                valuestart = 0;
            }
            else if (cinn == '}') {
                //list->printsele(&list);
                //list->printatryb(&list);
                numberofsections++;
                list = list->addNode(&list);
                charpos = 0;
                whereami = 0;

            }
        }
        else if (whereami == 2)
        {
            if (cinn == EOF) {
                return 0;
            }
            if (cinn == '\n')
            {
                String a1;
                String a2;
                String a3;
                instructionreader(&a1, &a2, &a3, tab, charpos);
                if (a1 == "/") {
                    continue;
                }
                else if (a1 == a2) {
                    printf("? == %d", numberofsections);
                    printf("\n");
                }
                else if (a2 == "S") {
                    if (a3 == "?")
                    {
                        if (a1.czytoint() != 0) {
                            list->liczbaSznakz(a1.czytoint());
                        }
                        else {
                            list->znakSznakz(&a1, numberofsections);
                        }
                    }
                    else {
                        list->liczbaSliczba(a1.czytoint(), a3.czytoint(), numberofsections);
                    }
                }
                else if (a2 == "A") {
                    if (a3 == "?")
                    {
                        if (a1.czytoint() != 0) {
                            list->liczbaAznakz(a1.czytoint());
                        }
                        else {
                            list->znakAznakz(&a1, numberofsections);
                        }
                    }
                    else {
                        list->liczbaAznak(a1.czytoint(), &a3);
                    }

                }
                else if (a2 == "D") {
                    if (a3 == "*") {
                        list->liczbaDgwiazdka(a1.czytoint(),&numberofsections);
                        numberofsections--;
                        a1.print();
                        cout << ",";
                        a2.print();
                        cout << ",";
                        a3.print();
                        cout << " == ";
                        cout << "deleted";
                        printf("\n");
                    }
                    else {
                        list->liczbaDgwiazdka(a1.czytoint(), &numberofsections);
                        numberofsections--;
                        a1.print();
                        cout << ",";
                        a2.print();
                        cout << ",";
                        a3.print();
                        cout << " == ";
                        cout << "deleted";
                        printf("\n");
                    }
                }
                else if (a2 == "E") {
                    list->znakEznak(&a1, &a3, numberofsections);
                }
                charpos = 0;
            }
            else if (tab[charpos - 1] == '*' && cinn == '*') {
                cin >> tab[0];
                cin >> tab[0];
                cin >> tab[0];
                tab[0] = 'x';
                whereami = 0;
                charpos = 0;
            }
            else if (cinn < 32) {
                continue;
            }
            else {
                tab[charpos] = cinn;
                charpos++;
            }

        }
    }
    delete list;
    return 0;
};