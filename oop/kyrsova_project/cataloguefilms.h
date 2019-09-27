#ifndef CATALOGUEFILMS_H
#define CATALOGUEFILMS_H
#include "film.h"
#include <vector>

class CatalogueFilms {
private:
    vector<Film> catalogue;
    vector<Film>::iterator iterCatalogue;
public:
    CatalogueFilms();
    void in_file();
    void out_file();
    void menu();
    bool check_id(const Film &film);
    void add_film();
    void search_film();
    void delete_film();
    void edit_film();
    void show_all();
    Film get_by_id(int id);
};

#endif // CATALOGUEFILMS_H
