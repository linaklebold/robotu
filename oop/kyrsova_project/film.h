#ifndef FILM_H
#define FILM_H

#include <string>
using namespace std;

class CatalogueFilms;

class Film {
private:
    int code;
    string nazva;
    string zhanr;
    string data_vuhoda;
    int truvalist;
    char format[3];
public:
    friend class CatalogueFilms;

    Film();
    Film(int code);
    void set_data();
    void set_code(int code);
    void set_nazva(string nazva);
    void set_zhanr(string zhanr);
    void set_data_vuhoda(string data_vuhoda);
    void set_truvalist(int truvalist);
    void set_format(char format[3]);
    int get_code();
    string get_nazva();
    string get_zhanr();
    string get_data_vuhoda();
    int get_truvalist();
    char* get_format();

    friend ostream& operator<<(std::ostream &out, Film film);
};

#endif // FILM_H
