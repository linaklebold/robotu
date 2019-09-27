#include "seans.h"
#include <iostream>
using namespace std;

ostream& operator<<(std::ostream &out, Seans seans) {
    out << "���: " << seans.get_code() <<
           "\nԳ���: " << seans.get_nazva() <<
           "\n����: " << seans.get_date() << " " << seans.get_chas() <<
           "\nֳ�� ������: " << seans.get_cina_kvutka() <<
           "\n����: " << seans.get_zmina() << endl;
    return out;
}

Seans::Seans(Film film) : Film(film) {
    set_data();
}

Seans::Seans(int code) {
    this->code = code;
}

Seans::Seans(Film film, int id) : Film(film) {
    this->code = id;
}

void Seans::set_data() {
    cout << "���� (dd.mm.yyyy): ";
    cin >> date;
    cout << "��� (hh:mm): ";
    cin >> chas;
    cout << "ֳ�� ������: ";
    cin >> cina_kvutka;
    cout << "����: ";
    cin >> zmina;
    cout << "���: ";
    cin >> code;

}
void Seans::set_code(int code) {
    this->code = code;
}
void Seans::set_date(string date) {
    this->date = date;
}
void Seans::set_chas(string chas) {
    this->chas = chas;
}
void Seans::set_cina_kvutka(int cina_kvutka) {
    this->cina_kvutka = cina_kvutka;
}
void Seans::set_zmina(int zmina) {
    this->zmina = zmina;
}
int Seans::get_code() {
    return code;
}
string Seans::get_date() {
    return date;
}
string Seans::get_chas() {
    return chas;
}
int Seans::get_cina_kvutka() {
    return cina_kvutka;
}
int Seans::get_zmina() {
    return zmina;
}
void Seans::edit_film(Film film) {
    Film::set_code(film.get_code());
    Film::set_nazva(film.get_nazva());
    Film::set_zhanr(film.get_zhanr());
    Film::set_data_vuhoda(film.get_data_vuhoda());
    Film::set_truvalist(film.get_truvalist());
    Film::set_format(film.get_format());
}
