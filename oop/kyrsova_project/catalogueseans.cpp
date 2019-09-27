#include "catalogueseans.h"
#include "cataloguefilms.h"
#include "cataloguepracivnukiv.h"

#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

CatalogueSeans::CatalogueSeans() {
    out_file();
}

void CatalogueSeans::in_file() {
    ofstream seans_file("seans.txt", ios_base::trunc);
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
        seans_file << iterCatalogue->get_code() << " " <<
                     iterCatalogue->Film::get_code() << " " <<
                     iterCatalogue->get_date() << " " <<
                     iterCatalogue->get_chas() << " " <<
                     iterCatalogue->get_cina_kvutka() << " " <<
                     iterCatalogue->get_zmina() << " " << endl;
        for(int i = 0; i < iterCatalogue->get_kilkist_ryadiv(); i++) {
            for(int j = 0; j < iterCatalogue->get_miscya_in_ryad(); j++) {
                seans_file << iterCatalogue->get_misce(i, j) << " ";
            }
        }
    }
    seans_file.close();
}

void CatalogueSeans::out_file() {
    CatalogueFilms f_catalog;
    int code;
    int f_code;
    string date;
    string chas;
    int cina_kvutka;
    int zmina;

    bool isBuy;

    ifstream seans_file("seans.txt");
    while(seans_file >> code >> f_code >> date >> chas >> cina_kvutka >> zmina) {
        try {
            Seans seans(f_catalog.get_by_id(f_code), -1);
            seans.set_code(code);
            seans.set_date(date);
            seans.set_chas(chas);
            seans.set_cina_kvutka(cina_kvutka);
            seans.set_zmina(zmina);

            for(int i = 0; i < seans.get_kilkist_ryadiv(); i++) {
                for(int j = 0; j < seans.get_miscya_in_ryad(); j++) {
                    seans_file >> isBuy;
                    seans.set_misce(i, j, isBuy);
                }
            }

            catalogue.push_back(seans);
        } catch (const char*) {
            continue;
        }
    }
    seans_file.close();
}

void CatalogueSeans::menu() {
    bool exit = false;
    int choise;

    while(!exit) {
        system("cls");
          cout << "  +----------------------------+"  <<
                "\n ||                            ||" <<
                "\n || "  << "1. " << "Додати сеанс            " << "||" <<
                "\n || "  << "2. " << "Знайти сеанс            " << "||" <<
                "\n || "  << "3. " << "Видалити сеанс          " << "||" <<
                "\n || "  << "4. " << "Редагувати сеанс        " << "||" <<
                "\n || "  << "5. " << "Всі сеанси              " << "||" <<
                "\n || "  << "6. " << "Місця                   " << "||" <<
                "\n || "  << "7. " << "Продати місце           " << "||" <<
                "\n || "  << "8. " << "Подивитись зміну сеансу " << "||" <<
                "\n || "  << "9. " << "Заробіток від сеансу    " << "||" <<
                "\n || "  << "10. " << "Назад                  " << "||" <<
                "\n ||                            ||" <<
                "\n  +----------------------------+" <<
                "\n  " << "->  ";
        cin >> choise;
        switch(choise) {
            case 1:
                add_seans();
                break;
            case 2:
                search_seans();
                break;
            case 3:
                delete_seans();
                break;
            case 4:
                edit_seans();
                break;
            case 5:
                show_all();
                break;
            case 6:
                show_miscya();
                break;
            case 7:
                buy_misce();
                break;
            case 8:
                show_zmina();
                break;
            case 9:
                profit();
                break;
            case 10:
                exit = true;
        }
        in_file();
    }
}

bool CatalogueSeans::check_id(const Seans &seans) {
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
        if(iterCatalogue->code == seans.code) {
            return false;
        }
    }
    return true;
}

void CatalogueSeans::add_seans() {
    CatalogueFilms f_catalog;
    int f_code;
    cout << "Код фільму: ";
    cin >> f_code;

    try {
        Seans seans(f_catalog.get_by_id(f_code));
        if(check_id(seans)) {
           catalogue.push_back(seans);
        }
        else {
            cout << "Такий код вже використовується. Змініть код на інший" << endl;
        system("pause");
		}
    } catch (const char *msg) {
        cout << msg << endl;
        system("pause");
    }
}

void CatalogueSeans::search_seans() {
    bool exit = false;
    int choise;

    int code;
    string date;
    string f_name;

    while(!exit) {
        system("cls");
          cout << "  +---------------------+"  <<
                "\n ||                     ||" <<
                "\n || "  << "1. " << "Пошук за кодом   " << "||" <<
                "\n || "  << "2. " << "Пошук за фільмом " << "||" <<
                "\n || "  << "3. " << "Пошук за датою   " << "||" <<
                "\n || "  << "4. " << "Назад            " << "||" <<
                "\n ||                     ||" <<
                "\n  +---------------------+" <<
                "\n  " << "->  ";
        cin >> choise;
        switch(choise) {
            case 1:
                cout << "Код: ";
                cin >> code;
                cout << endl;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_code() == code) {
                        cout << *iterCatalogue;
                    }
                }
                break;
            case 2:
                cout << "Назва фільму: ";
                cin >> f_name;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->Film::get_nazva() == f_name) {
                        cout << iterCatalogue->get_code() << " | " << iterCatalogue->Film::get_nazva() << "(код" << iterCatalogue->Film::get_code() << ") | " << iterCatalogue->get_date() << " " << iterCatalogue->get_chas() << " | " << iterCatalogue->get_cina_kvutka() << " grn | " << iterCatalogue->get_zmina() << " zmina"  <<endl;
                    }
                }
                break;
            case 3:
                cout << "Дата сеансів (dd.mm.yyyy): ";
                cin >> date;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_date() == date) {
                        cout << iterCatalogue->get_code() << " | " << iterCatalogue->Film::get_nazva() << "(код " << iterCatalogue->Film::get_code() << ") | " << iterCatalogue->get_date() << " " << iterCatalogue->get_chas() << " | " << iterCatalogue->get_cina_kvutka() << " grn | " << iterCatalogue->get_zmina() << " zmina"  <<endl;
                    }
                }
                break;
            case 4:
                exit = true;
        }
        system("pause");
    }
}

void CatalogueSeans::delete_seans() {
    int code;
    cout << "Код: ";
    cin >> code;
    for(unsigned int i = 0; i < catalogue.size(); i++) {
        if(catalogue[i].get_code() == code) {
            catalogue.erase(catalogue.begin() + i);
            return;
        }
    }
    cout << "Код не знайдено" << endl;
    system("pause");
}

void CatalogueSeans::edit_seans() {
    bool exit = false;
    int choise;
    bool isPresent = false;

    int code;
    int f_code;
    string date;
    string chas;
    int cina_kvutka;
    int zmina;
    CatalogueFilms f_catalog;

    cout << "Код сеансу дані якого будемо редагувати: ";
    cin >> code;

    unsigned int i;
    for(i = 0; i < catalogue.size(); i++) {
        if(catalogue[i].get_code() == code) {
            isPresent = true;
            break;
        }
    }

    if(!isPresent) {
        cout << "Код не знайдено" << endl;
        return;
    }
    else {
        while(!exit) {
            system("cls");
          cout << "  +----------------------------+"  <<
                "\n ||                            ||" <<
                "\n || "  << "1. " << "Редагувати дату         " << "||" <<
                "\n || "  << "2. " << "Редагувати час          " << "||" <<
                "\n || "  << "3. " << "Редагувати фільм        " << "||" <<
                "\n || "  << "4. " << "Редагувати ціну квитка  " << "||" <<
                "\n || "  << "5. " << "Редагувати зміну        " << "||" <<
                "\n || "  << "6. " << "Назад                   " << "||" <<
                "\n ||                            ||" <<
                "\n  +----------------------------+" <<
                "\n  " << "->  ";
            cin >> choise;
            switch(choise) {
                case 1:
                    cout << "Нова дата (dd.mm.yyyy): ";
                    cin >> date;
                    catalogue[i].set_date(date);
                    break;
                case 2:
                    cout << "Новий час: ";
                    cin >> chas;
                    catalogue[i].set_chas(chas);
                    break;
                case 3:
                    cout << "Новий код фільму: ";
                    cin >> f_code;
                    try {
                        catalogue[i].edit_film(f_catalog.get_by_id(f_code));
                    } catch (const char *msg) {
                        cout << msg << endl;
                    }
                    break;
                case 4:
                    cout << "Нова ціна квитка: ";
                    cin >> cina_kvutka;
                    catalogue[i].set_cina_kvutka(cina_kvutka);
                    break;
                case 5:
                    cout << "Нова зміна: ";
                    cin >> zmina;
                    catalogue[i].set_zmina(zmina);
                    break;
                case 6:
                    exit = true;
            }
            system("pause");
        }
    }
}

void CatalogueSeans::show_all() {
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
        cout << iterCatalogue->get_code() << " | " << iterCatalogue->Film::get_nazva() << "(код " << iterCatalogue->Film::get_code() << ") | " << iterCatalogue->get_date() << " " << iterCatalogue->get_chas() << " | " << iterCatalogue->get_cina_kvutka() << " grn | " << iterCatalogue->get_zmina() << " zmina"  <<endl;
    }
    system("pause");
}

void CatalogueSeans::show_miscya() {
    int code;
    cout << "Код сеансу: ";
    cin >> code;
    for(unsigned int i = 0; i < catalogue.size(); i++) {
        if(catalogue[i].get_code() == code) {
            catalogue[i].show_miscya();
            return;
        }
    }
    cout << "Код не знайдено" << endl;
    system("pause");
}

void CatalogueSeans::buy_misce() {
    int code;
    int ryad, misce;
    cout << "Код сеансу: ";
    cin >> code;
    for(unsigned int i = 0; i < catalogue.size(); i++) {
        if(catalogue[i].get_code() == code) {
            cout << "Ряд: ";
            cin >> ryad;
            cout << "Місце: ";
            cin >> misce;
            catalogue[i].buy_misce(ryad, misce);
            return;
        }
    }
    cout << "Код не знайдено" << endl;
    system("pause");
}

void CatalogueSeans::show_zmina() {
    CataloguePracivnukiv p_catalog;
    int code;
    cout << "Код сеанс: ";
    cin >> code;
    for(unsigned int i = 0; i < catalogue.size(); i++) {
        if(catalogue[i].get_code() == code) {
            p_catalog.search_by_zmina(catalogue[i].get_zmina());
            return;
        }
    }
    cout << "Код не знайдено" << endl;
    system("pause");
}

void CatalogueSeans::profit() {
    int suma = 0;
    int code;
    cout << "Код сеансу: ";
    cin >> code;
    for(unsigned int i = 0; i < catalogue.size(); i++) {
        if(catalogue[i].get_code() == code) {
            suma = catalogue[i].get_cina_kvutka() * catalogue[i].kilkist_prodanuh_kvutkiv();
            cout << "Прибуток = " << suma << endl;
            system("pause");
            return;
        }
    }
    cout << "Код не знайдено" << endl;
    system("pause");
}
