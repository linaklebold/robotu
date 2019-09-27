#include "pracivnuk.h"
#include <iostream>
using namespace std;

ostream& operator<<(std::ostream &out, Pracivnuk pracivnuk) {
    out << "���: " << pracivnuk.code <<
           "\n��'�: " << pracivnuk.name <<
           "\n�������: " << pracivnuk.surname <<
           "\n������: " << pracivnuk.posada <<
           "\n���� ����������: " << pracivnuk.data_narodzhennya <<
           "\n������ ����������: " << pracivnuk.vulutsya_prozhuvannya <<
           "\n��������: " << pracivnuk.zarplata <<
           "\n����: " << pracivnuk.zmina << endl;
    return out;
}

Pracivnuk::Pracivnuk() {
    set_data();
}

Pracivnuk::Pracivnuk(int code) {
    this->code = code;
}

void Pracivnuk::set_data() {
    cout << "��'�: ";
    cin >> name;
    cout << "�������: ";
    cin >> surname;
    cout << "������: ";
    cin >> posada;
    cout << "���� ���������� (dd.mm.yyyy): ";
    cin >> data_narodzhennya;
    cout << "������ ����������: ";
    cin >> vulutsya_prozhuvannya;
    cout << "��������: ";
    cin >> zarplata;
    cout << "����: ";
    cin >> zmina;
    cout << "���: ";
    cin >> code;
}

void Pracivnuk::set_code(int code) {
    this->code = code;
}
void Pracivnuk::set_name(string name) {
    this->name = name;
}
void Pracivnuk::set_surname(string surname) {
    this->surname = surname;
}
void Pracivnuk::set_posada(string posada) {
    this->posada = posada;
}
void Pracivnuk::set_data_narodzhennya(string data_narodzhennya) {
    this->data_narodzhennya = data_narodzhennya;
}
void Pracivnuk::set_vulutsya_prozhuvannya(string vulutsya_prozhuvannya) {
    this->vulutsya_prozhuvannya = vulutsya_prozhuvannya;
}
void Pracivnuk::set_zarplata(float zarplata) {
    this->zarplata = zarplata;
}
void Pracivnuk::set_zmina(int zmina) {
    this->zmina = zmina;
}
int Pracivnuk::get_code() {
    return code;
}
string Pracivnuk::get_name() {
    return name;
}
string Pracivnuk::get_surname() {
    return surname;
}
string Pracivnuk::get_posada() {
    return posada;
}
string Pracivnuk::get_data_narodzhennya() {
    return data_narodzhennya;
}
string Pracivnuk::get_vulutsya_prozhuvannya() {
    return vulutsya_prozhuvannya;
}
float Pracivnuk::get_zarplata() {
    return zarplata;
}
int Pracivnuk::get_zmina() {
    return zmina;
}
