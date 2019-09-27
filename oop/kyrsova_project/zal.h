#ifndef ZAL_H
#define ZAL_H


class Zal {
private:
    unsigned int kilkist_ryadiv;
    unsigned int miscya_in_ryad;
    bool **miscya;
public:
    Zal();
protected:
    void show_miscya();
    void buy_misce(int i, int j);
    int kilkist_prodanuh_kvutkiv();
    void set_misce(int i, int j, bool isBuy);
    bool get_misce(int i, int j);
    int get_kilkist_ryadiv();
    int get_miscya_in_ryad();
};

#endif // ZAL_H
