#include "cataloguefilms.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;



CatalogueFilms::CatalogueFilms() {
    out_file();
}

void CatalogueFilms::in_file() {
    ofstream film_file("films.txt", ios_base::trunc);
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
        film_file << iterCatalogue->get_code() << " " <<
                     iterCatalogue->get_nazva() << " " <<
                     iterCatalogue->get_zhanr() << " " <<
                     iterCatalogue->get_data_vuhoda() << " " <<
                     iterCatalogue->get_truvalist() << " " <<
                     iterCatalogue->get_format() << " " << endl;
    }
    film_file.close();
}

void CatalogueFilms::out_file() {
    int code;
    string nazva;
    string zhanr;
    string data_vuhoda;
    int truvalist;
    char format[3];
    Film film(-1);
    ifstream film_file("films.txt");
    while(film_file >> code >> nazva >> zhanr >> data_vuhoda >> truvalist >> format) {
        film.set_code(code);
        film.set_nazva(nazva);
        film.set_zhanr(zhanr);
        film.set_data_vuhoda(data_vuhoda);
        film.set_truvalist(truvalist);
        film.set_format(format);
        catalogue.push_back(film);
    }
    film_file.close();
}

void CatalogueFilms::menu() {
    bool exit = false;
    int choise;

    while(!exit) {
        system("cls");
         cout << "  +---------------------+"  <<
                "\n ||                     ||" <<
                "\n || "  << "1. " << "������ �����     " << "||" <<
                "\n || "  << "2. " << "������ �����     " << "||" <<
                "\n || "  << "3. " << "�������� �����   " << "||" <<
                "\n || "  << "4. " << "���������� ����� " << "||" <<
                "\n || "  << "5. " << "�� ������       " << "||" <<
                "\n || "  << "6. " << "�����            " << "||" <<
                "\n ||                     ||" <<
                "\n  +---------------------+" <<
                "\n  " << "->  ";
        cin >> choise;
        switch(choise) {
            case 1:
                add_film();
                break;
            case 2:
                search_film();
                break;
            case 3:
                delete_film();
                break;
            case 4:
                edit_film();
                break;
            case 5:
                show_all();
                break;
            case 6:
                exit = true;
        }
        in_file();
    }
}

bool CatalogueFilms::check_id(const Film &film) {
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
        if(iterCatalogue->code == film.code) {
            return false;
        }
    }
    return true;
}

void CatalogueFilms::add_film() {
    Film film;
    if(check_id(film)) {
       catalogue.push_back(film);
    }
    else {
        cout << "����� ��� ��� ���������������. ����� �� �����" << endl;
    }
    system("pause");
}

void CatalogueFilms::search_film() {
    bool exit = false;
    int choise;

    int code;
    string nazva;
    string zhanr;
    string data_vuhoda;
    int truvalist_from;
    int truvalist_to;
    char format[3];

    while(!exit) {
        system("cls");
          cout << "  +--------------------------+"  <<
                "\n ||                          ||" <<
                "\n || "  << "1. " << "����� �� �����        " << "||" <<
                "\n || "  << "2. " << "����� �� ������       " << "||" <<
                "\n || "  << "3. " << "����� �� ������       " << "||" <<
                "\n || "  << "4. " << "����� �� ����� ������ " << "||" <<
                "\n || "  << "5. " << "����� �� ���������   " << "||" <<
                "\n || "  << "6. " << "����� �� ��������     " << "||" <<
                "\n || "  << "7. " << "�����                 " << "||" <<
                "\n ||                          ||" <<
                "\n  +--------------------------+" <<
                "\n  " << "->  ";
        cin >> choise;
        switch(choise) {
            case 1:
                cout << "���: ";
                cin >> code;
                cout << endl;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_code() == code) {
                        cout << *iterCatalogue;
                    }
                }
                break;
            case 2:
                cout << "�����: ";
                cin >> nazva;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_nazva() == nazva) {
                        cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_nazva() << " | " << iterCatalogue->get_zhanr() << " | " << iterCatalogue->get_format() << " | " << iterCatalogue->get_truvalist() << " | " << iterCatalogue->get_data_vuhoda() << endl;
                    }
                }
                break;
            case 3:
                cout << "����: ";
                cin >> zhanr;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_zhanr() == zhanr) {
                        cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_nazva() << " | " << iterCatalogue->get_zhanr() << " | " << iterCatalogue->get_format() << " | " << iterCatalogue->get_truvalist() << " | " << iterCatalogue->get_data_vuhoda() << endl;
                    }
                }
                break;
            case 4:
                cout << "���� ������ (dd.mm.yyyy): ";
                cin >> data_vuhoda;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_data_vuhoda() == data_vuhoda) {
                        cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_nazva() << " | " << iterCatalogue->get_zhanr() << " | " << iterCatalogue->get_format() << " | " << iterCatalogue->get_truvalist() << " | " << iterCatalogue->get_data_vuhoda() << endl;
                    }
                }
                break;
            case 5:
                cout << "��������� (hv)\n ��: ";
                cin >> truvalist_from;
                cout << " ��: ";
                cin >> truvalist_to;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_truvalist() >= truvalist_from && iterCatalogue->get_truvalist() <= truvalist_to) {
                        cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_nazva() << " | " << iterCatalogue->get_zhanr() << " | " << iterCatalogue->get_format() << " | " << iterCatalogue->get_truvalist() << " | " << iterCatalogue->get_data_vuhoda() << endl;
                    }
                }
                break;
            case 6:
                cout << "������: ";
                cin >> format;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(!strcmp(iterCatalogue->get_format(), format)) {
                        cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_nazva() << " | " << iterCatalogue->get_zhanr() << " | " << iterCatalogue->get_format() << " | " << iterCatalogue->get_truvalist() << " | " << iterCatalogue->get_data_vuhoda() << endl;
                    }
                }
                break;
            case 7:
                exit = true;
        }
        system("pause");
    }
}

void CatalogueFilms::delete_film() {
    int code;
    cout << "���: ";
    cin >> code;
    for(unsigned int i = 0; i < catalogue.size(); i++) {
        if(catalogue[i].get_code() == code) {
            catalogue.erase(catalogue.begin() + i);
            return;
        }
    }
    cout << "��� �� ��������" << endl;
    system("pause");
}

void CatalogueFilms::edit_film() {
    bool exit = false;
    int choise;
    bool isPresent = false;

    int code;
    string nazva;
    string zhanr;
    string data_vuhoda;
    int truvalist;
    char format[3];

    cout << "��� ������ ���� ������ ����������: ";
    cin >> code;

    unsigned int i;
    for(i = 0; i < catalogue.size(); i++) {
        if(catalogue[i].get_code() == code) {
            isPresent = true;
            break;
        }
    }

    if(!isPresent) {
        cout << "��� �� ��������" << endl;
        return;
    }

    else {
        while(!exit) {
            system("cls");
          cout << "  +---------------------------+"  <<
                "\n ||                           ||" <<
                "\n || "  << "1. " << "���������� �����       " << "||" <<
                "\n || "  << "2. " << "���������� ����        " << "||" <<
                "\n || "  << "3. " << "���������� ���� ������ " << "||" <<
                "\n || "  << "4. " << "���������� ���������  " << "||" <<
                "\n || "  << "5. " << "���������� ������      " << "||" <<
                "\n || "  << "6. " << "�����                  " << "||" <<
                "\n ||                           ||" <<
                "\n  +---------------------------+" <<
                "\n  " << "->  ";
                    
            cin >> choise;
            switch(choise) {
                case 1:
                    cout << "���� �����: ";
                    cin >> nazva;
                    catalogue[i].set_nazva(nazva);
                    break;
                case 2:
                    cout << "����� ����: ";
                    cin >> zhanr;
                    catalogue[i].set_zhanr(zhanr);
                    break;
                case 3:
                    cout << "���� ���� ������ (dd.mm.yyyy): ";
                    cin >> data_vuhoda;
                    catalogue[i].set_data_vuhoda(data_vuhoda);
                    break;
                case 4:
                    cout << "���� ���������: ";
                    cin >> truvalist;
                    catalogue[i].set_truvalist(truvalist);
                    break;
                case 5:
                    cout << "����� ������: ";
                    cin >> format;
                    catalogue[i].set_format(format);
                    break;
                case 6:
                    exit = true;
            }
            system("pause");
        }
    }
}

void CatalogueFilms::show_all() {
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
            cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_nazva() << " | " << iterCatalogue->get_zhanr() << " | " << iterCatalogue->get_format() << " | " << iterCatalogue->get_truvalist() << " | " << iterCatalogue->get_data_vuhoda() << endl;
    }
    system("pause");
}

Film CatalogueFilms::get_by_id(int id) {
    try {
        for(unsigned int i = 0; i < catalogue.size(); i++) {
            if(catalogue[i].get_code() == id)  {
                return catalogue[i];
            }
        }
        throw "��� ������ �� ��������";
    } catch(const char*) {
        throw;
    };
}
