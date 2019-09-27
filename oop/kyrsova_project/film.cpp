#include "film.h"
#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(std::ostream &out, Film film) {
    out << "���: " << film.code <<
           "\n�����: " << film.nazva <<
           "\n����: " << film.zhanr <<
           "\n���� ������: " << film.data_vuhoda <<
           "\n��������� (��): " << film.truvalist <<
           "\n������: " << film.format << endl;
    return out;
}

Film::Film() {
    set_data();
}

Film::Film(int code) {
    this->code = code;
}

void Film::set_data() {
    cout << "�����: ";
    cin >> nazva;
    cout << "����: ";
    cin >> zhanr;
    cout << "���� ������ (dd.mm.yyyy): ";
    cin >> data_vuhoda;
    cout << "��������� (��): ";
    cin >> truvalist;
    cout << "������: ";
    cin >> format;
    cout << "���: ";
    cin >> code;
}
void Film::set_code(int code) {
    this->code = code;
}
void Film::set_nazva(string nazva) {
    this->nazva = nazva;
}
void Film::set_zhanr(string zhanr) {
    this->zhanr = zhanr;
}
void Film::set_data_vuhoda(string data_vuhoda) {
    this->data_vuhoda = data_vuhoda;
}
void Film::set_truvalist(int truvalist) {
    this->truvalist = truvalist;
}
void Film::set_format(char format[3]) {
    for(int i = 0; i < 3; i++) {
        this->format[i] = format[i];
    }
}
int Film::get_code() {
    return code;
}
string Film::get_nazva() {
    return nazva;
}
string Film::get_zhanr() {
    return zhanr;
}
string Film::get_data_vuhoda() {
    return  data_vuhoda;
}
int Film::get_truvalist() {
    return truvalist;
}
char* Film::get_format() {
    return format;
}
