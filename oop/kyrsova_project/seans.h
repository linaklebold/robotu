#ifndef SEANS_H
#define SEANS_H
#include "film.h"
#include "zal.h"

#include <string>
using namespace std;

class CatalogueSeans;

class Seans : public Zal, public Film {
private:
    int code;
    string date;
    string chas;
    int cina_kvutka;
    int zmina;
public:
    friend class CatalogueSeans;

    Seans(Film film);
    Seans(int code);
    Seans(Film film, int id);
    void set_data();
    void set_code(int code);
    void set_date(string date);
    void set_chas(string chas);
    void set_cina_kvutka(int cina_kvutka);
    void set_zmina(int zmina);
    int get_code();
    string get_date();
    string get_chas();
    int get_cina_kvutka();
    int get_zmina();
    void edit_film(Film film);

    friend ostream& operator<<(std::ostream &out, Seans seans);
};

#endif // SEANS_H
