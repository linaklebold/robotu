#include "zal.h"
#include <iostream>
using namespace std;

Zal::Zal() {
    kilkist_ryadiv = 8;
    miscya_in_ryad = 6;

    miscya = new bool*[kilkist_ryadiv];
    for(unsigned int i = 0; i < kilkist_ryadiv; i++)
        miscya[i] = new bool[miscya_in_ryad];

    for(unsigned int i = 0; i < kilkist_ryadiv; i++) {
        for(unsigned int j = 0; j < miscya_in_ryad; j++) {
            miscya[i][j] = true;
        }
    }
}

void Zal::show_miscya() {
    int misce;
    for(unsigned int i = 0; i < kilkist_ryadiv; i++) {
        cout << "Ðÿä " << i+1 << ":\t";
        misce = 0;
        for(unsigned int j = 0; j < miscya_in_ryad; j++) {
            misce++;
            if(!miscya[i][j]) {
                cout << "[" << misce << "]" << "\t";
            }
            else cout << " " << misce << "\t";
        }
        cout << endl;
    }
    system("pause");
}

void Zal::buy_misce(int i, int j) {
    miscya[i-1][j-1] = false;
}

int Zal::kilkist_prodanuh_kvutkiv() {
    int count = 0;
    for(unsigned int i = 0; i < kilkist_ryadiv; i++) {
        for(unsigned int j = 0; j < miscya_in_ryad; j++) {
            if(!miscya[i][j]) {
                count++;
            }
        }
    }
    return count;
}

void Zal::set_misce(int i, int j, bool isBuy) {
    miscya[i][j] = isBuy;
}

bool Zal::get_misce(int i, int j) {
    return miscya[i][j];
}

int Zal::get_kilkist_ryadiv() {
    return  kilkist_ryadiv;
}
int Zal::get_miscya_in_ryad() {
    return miscya_in_ryad;
}
