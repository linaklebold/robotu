#include "film.h"
#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(std::ostream &out, Film film) {
    out << "Код: " << film.code <<
           "\nНазва: " << film.nazva <<
           "\nЖанр: " << film.zhanr <<
           "\nДата виходу: " << film.data_vuhoda <<
           "\nТривалість (хв): " << film.truvalist <<
           "\nФормат: " << film.format << endl;
    return out;
}

Film::Film() {
    set_data();
}

Film::Film(int code) {
    this->code = code;
}

void Film::set_data() {
    cout << "Назва: ";
    cin >> nazva;
    cout << "Жанр: ";
    cin >> zhanr;
    cout << "Дата виходу (dd.mm.yyyy): ";
    cin >> data_vuhoda;
    cout << "Тривалість (хв): ";
    cin >> truvalist;
    cout << "Формат: ";
    cin >> format;
    cout << "Код: ";
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
