#ifndef CATALOGUEPRACIVNUKIV_H
#define CATALOGUEPRACIVNUKIV_H
#include "pracivnuk.h"
#include <vector>

class CataloguePracivnukiv {
private:
    vector<Pracivnuk> catalogue;
    vector<Pracivnuk>::iterator iterCatalogue;
public:
    CataloguePracivnukiv();
    void in_file();
    void out_file();
    void menu();
    bool check_id(const Pracivnuk &pracivnuk);
    void add_pracivnuk();
    void search_pracivnuk();
    void delete_pracivnuk();
    void edit_pracivnuk();
    void show_all();
    void search_by_zmina(int zmina);
};

#endif // CATALOGUEPRACIVNUKIV_H
