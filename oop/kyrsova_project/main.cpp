#include <iostream>
#include "cataloguefilms.h"
#include "cataloguepracivnukiv.h"
#include "catalogueseans.h"

#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string setColor(int i) {
    SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | i));
    return "";
}

int main() {
	system("chcp 1251 > nul");
	system("color 70");
    CatalogueFilms catalogueFilms;
    CataloguePracivnukiv cataloguePracivnukiv;
    CatalogueSeans catalogueSeans;

    bool exit = false;
    int choise;


    while(!exit) {
        system("cls");
        cout << setColor(4) << "  +---------------+"  <<
                "\n ||               ||" <<
                "\n || "  << "1. " << "Фільми     " << "||" <<
                "\n || "  << "2. " << "Працівники " << "||" <<
                "\n || "  << "3. " << "Сеанси     " << "||" <<
                "\n || "  << "4. " << "Вихід      " << "||" <<
                "\n ||               ||" <<
                "\n  +---------------+" <<
                "\n  " << "->  ";
        COORD pos = {5, 8};
        SetConsoleCursorPosition ( hConsole, pos );
        cin >> choise;
        switch(choise) {
            case 1:
                catalogueFilms.menu();
                break;
            case 2:
                cataloguePracivnukiv.menu();
                break;
            case 3:
                catalogueSeans.menu();
                break;
            case 4:
                exit = true;
        }
    }
    return 0;
}
