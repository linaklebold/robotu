#include "cataloguepracivnukiv.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

CataloguePracivnukiv::CataloguePracivnukiv() {
    out_file();
}

void CataloguePracivnukiv::in_file() {
    ofstream pracivnuk_file("pracivnuki.txt", ios_base::trunc);
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
        pracivnuk_file << iterCatalogue->get_code() << " " <<
                     iterCatalogue->get_name() << " " <<
                     iterCatalogue->get_surname() << " " <<
                     iterCatalogue->get_posada() << " " <<
                     iterCatalogue->get_data_narodzhennya() << " " <<
                     iterCatalogue->get_vulutsya_prozhuvannya() << " " <<
                     iterCatalogue->get_zarplata() << " " <<
                     iterCatalogue->get_zmina() << " " << endl;
    }
    pracivnuk_file.close();
}

void CataloguePracivnukiv::out_file() {
    int code;
    string name;
    string surname;
    string posada;
    string data_narodzhennya;
    string vulutsya_prozhuvannya;
    float zarplata;
    int zmina;
    Pracivnuk pracivnuk(-1);
    ifstream pracivnuk_file("pracivnuki.txt");
    while(pracivnuk_file >> code >> name >> surname >> posada >> data_narodzhennya >> vulutsya_prozhuvannya >> zarplata >> zmina) {
        pracivnuk.set_code(code);
        pracivnuk.set_name(name);
        pracivnuk.set_surname(surname);
        pracivnuk.set_posada(posada);
        pracivnuk.set_data_narodzhennya(data_narodzhennya);
        pracivnuk.set_vulutsya_prozhuvannya(vulutsya_prozhuvannya);
        pracivnuk.set_zarplata(zarplata);
        pracivnuk.set_zmina(zmina);
        catalogue.push_back(pracivnuk);
    }
    pracivnuk_file.close();
}

void CataloguePracivnukiv::menu() {
    bool exit = false;
    int choise;

    while(!exit) {
        system("cls");
          cout << "  +--------------------------+"  <<
                "\n ||                          ||" <<
                "\n || "  << "1. " << "������ ����������     " << "||" <<
                "\n || "  << "2. " << "������ ����������     " << "||" <<
                "\n || "  << "3. " << "�������� ����������   " << "||" <<
                "\n || "  << "4. " << "���������� ���������� " << "||" <<
                "\n || "  << "5. " << "�� ����������        " << "||" <<
                "\n || "  << "6. " << "�����                 " << "||" <<
                "\n ||                          ||" <<
                "\n  +--------------------------+" <<
                "\n  " << "->  ";
        cin >> choise;
        switch(choise) {
            case 1:
                add_pracivnuk();
                break;
            case 2:
                search_pracivnuk();
                break;
            case 3:
                delete_pracivnuk();
                break;
            case 4:
                edit_pracivnuk();
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

bool CataloguePracivnukiv::check_id(const Pracivnuk &pracivnuk) {
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
        if(iterCatalogue->code == pracivnuk.code) {
            return false;
        }
    }
    return true;
}

void CataloguePracivnukiv::add_pracivnuk() {
    Pracivnuk pracivnuk;
    if(check_id(pracivnuk)) {
       catalogue.push_back(pracivnuk);
    }
    else {
        cout << "����� ��� ��� ���������������. ����� ��� �� �����" << endl;
    }
}

void CataloguePracivnukiv::search_pracivnuk() {
    bool exit = false;
    int choise;

    int code;
    string surname;
    string posada;
    int zmina;

    while(!exit) {
        system("cls");
        cout << "  +-----------------------+"  <<
                "\n ||                       ||" <<
                "\n || "  << "1. " << "����� �� �����     " << "||" <<
                "\n || "  << "2. " << "����� �� �������� " << "||" <<
                "\n || "  << "3. " << "����� �� �������   " << "||" <<
                "\n || "  << "4. " << "����� �� �����    " << "||" <<
                "\n || "  << "5. " << "�����              " << "||" <<
                "\n ||                       ||" <<
                "\n  +-----------------------+" <<
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
                cout << "�������: ";
                cin >> surname;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_surname() == surname) {
                        cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_name() << " " << iterCatalogue->get_surname() << " | " << iterCatalogue->get_posada() << " | " << iterCatalogue->get_data_narodzhennya() << " | " << iterCatalogue->get_vulutsya_prozhuvannya() << " | " << iterCatalogue->get_zarplata() << " | " << iterCatalogue->get_zmina() << endl;
                    }
                }
                break;
            case 3:
                cout << "������: ";
                cin >> posada;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_posada() == posada) {
                        cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_name() << " " << iterCatalogue->get_surname() << " | " << iterCatalogue->get_posada() << " | " << iterCatalogue->get_data_narodzhennya() << " | " << iterCatalogue->get_vulutsya_prozhuvannya() << " | " << iterCatalogue->get_zarplata() << " | " << iterCatalogue->get_zmina() << endl;
                    }
                }
                break;
            case 4:
                cout << "����: ";
                cin >> zmina;
                for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
                    if(iterCatalogue->get_zmina() == zmina) {
                       cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_name() << " " << iterCatalogue->get_surname() << " | " << iterCatalogue->get_posada() << " | " << iterCatalogue->get_data_narodzhennya() << " | " << iterCatalogue->get_vulutsya_prozhuvannya() << " | " << iterCatalogue->get_zarplata() << " | " << iterCatalogue->get_zmina() << endl;
                    }
                }
                break;
            case 5:
                exit = true;
        }
        system("pause");
    }
}

void CataloguePracivnukiv::delete_pracivnuk() {
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

void CataloguePracivnukiv::edit_pracivnuk() {
    bool exit = false;
    int choise;
    bool isPresent = false;

    int code;
    string name;
    string surname;
    string posada;
    string data_narodzhennya;
    string vulutsya_prozhuvannya;
    float zarplata;
    int zmina;

    cout << "��� ���������� ��� ����� ������ ����������: ";
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
          cout << "  +--------------------------------+"  <<
                "\n ||                                ||" <<
                "\n || "  << "1. " << "���������� ��'�             " << "||" <<
                "\n || "  << "2. " << "���������� �������         " << "||" <<
                "\n || "  << "3. " << "���������� ������           " << "||" <<
                "\n || "  << "4. " << "���������� ���� ����������  " << "||" <<
                "\n || "  << "5. " << "���������� ������ ����������" << "||" <<
                "\n || "  << "6. " << "���������� ��������         " << "||" <<
                "\n || "  << "7. " << "���������� ����            " << "||" <<
                "\n || "  << "8. " << "�����                       " << "||" <<
                "\n ||                                ||" <<
                "\n  +--------------------------------+" <<
                "\n  " << "->  ";
            cin >> choise;
            switch(choise) {
                case 1:
                    cout << "���� ��'�: ";
                    cin >> name;
                    catalogue[i].set_name(name);
                    break;
                case 2:
                    cout << "���� �������: ";
                    cin >> surname;
                    catalogue[i].set_surname(surname);
                    break;
                case 3:
                    cout << "���� ������: ";
                    cin >> posada;
                    catalogue[i].set_posada(posada);
                    break;
                case 4:
                    cout << "���� ���� ���������� (dd.mm.yyyy): ";
                    cin >> data_narodzhennya;
                    catalogue[i].set_data_narodzhennya(data_narodzhennya);
                    break;
                case 5:
                    cout << "���� ������ ����������: ";
                    cin >> vulutsya_prozhuvannya;
                    catalogue[i].set_vulutsya_prozhuvannya(vulutsya_prozhuvannya);
                    break;
                case 6:
                    cout << "���� ��������: ";
                    cin >> zarplata;
                    catalogue[i].set_zarplata(zarplata);
                    break;
                case 7:
                    cout << "���� ����: ";
                    cin >> zmina;
                    catalogue[i].set_zmina(zmina);
                    break;
                case 8:
                    exit = true;
            }
            system("pause");
        }
    }
}

void CataloguePracivnukiv::show_all() {
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
        cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_name() << " " << iterCatalogue->get_surname() << " | " << iterCatalogue->get_posada() << " | " << iterCatalogue->get_data_narodzhennya() << " | " << iterCatalogue->get_vulutsya_prozhuvannya() << " | " << iterCatalogue->get_zarplata() << " | " << iterCatalogue->get_zmina() << endl;
    }
    system("pause");
}


void CataloguePracivnukiv::search_by_zmina(int zmina) {
    for(iterCatalogue = catalogue.begin(); iterCatalogue != catalogue.end(); *iterCatalogue++) {
        if(iterCatalogue->get_zmina() == zmina) {
           cout << iterCatalogue->get_code() << " | " << iterCatalogue->get_name() << " " << iterCatalogue->get_surname() << " | " << iterCatalogue->get_posada() << endl;
        }
    }
    system("pause");
}
