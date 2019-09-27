#ifndef CATALOGUESEANS_H
#define CATALOGUESEANS_H
#include "seans.h"
#include <vector>

class CatalogueSeans {
private:
    vector<Seans> catalogue;
    vector<Seans>::iterator iterCatalogue;
public:
    CatalogueSeans();
    void in_file();
    void out_file();
    void menu();
    bool check_id(const Seans &seans);
    void add_seans();
    void search_seans();
    void delete_seans();
    void edit_seans();
    void show_all();
    void show_miscya();
    void buy_misce();
    void show_zmina();
    void profit();
};

#endif // CATALOGUESEANS_H
