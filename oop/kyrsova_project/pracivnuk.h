#ifndef PRACIVNUK_H
#define PRACIVNUK_H
#include <string>
using namespace std;

class CataloguePracivnukiv;

class Pracivnuk {
private:
    int code;
    string name;
    string surname;
    string posada;
    string data_narodzhennya;
    string vulutsya_prozhuvannya;
    float zarplata;
    int zmina;
public:
    friend class CataloguePracivnukiv;

    Pracivnuk();
    Pracivnuk(int code);
    void set_data();
    void set_code(int code);
    void set_name(string name);
    void set_surname(string surname);
    void set_posada(string posada);
    void set_data_narodzhennya(string data_narodzhennya);
    void set_vulutsya_prozhuvannya(string vulutsya_prozhuvannya);
    void set_zarplata(float zarplata);
    void set_zmina(int zmina);
    int get_code();
    string get_name();
    string get_surname();
    string get_posada();
    string get_data_narodzhennya();
    string get_vulutsya_prozhuvannya();
    float get_zarplata();
    int get_zmina();

    friend ostream& operator<<(std::ostream &out, Pracivnuk pracivnuk);
};


#endif // PRACIVNUK_H
