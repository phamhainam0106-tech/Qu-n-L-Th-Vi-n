#pragma once
#include "phieumuon.h"

class DynamicArray {
    private:
    PhieuMuon* data;
    int size;
    int capacity;

    public:
    DynamicArray ();
    void moRong();
    void themGiaoDich(PhieuMuon pm);
    void hienThiGiaoDich();
    int getSize();
    ~DynamicArray();
};