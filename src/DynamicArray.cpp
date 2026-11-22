#include "../include/DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray ::DynamicArray ()
{
    size = 0;
    capacity = 2;
    data = new PhieuMuon[capacity];
}

void DynamicArray::moRong() 
{
    capacity *= 2;

    PhieuMuon* temp = new PhieuMuon[capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    delete[] data;
    data = temp;
}

void DynamicArray::themGiaoDich(PhieuMuon pm) 
{
    if (size == capacity) {
        moRong();
    }

    data[size] = pm;
    size++;
}

void DynamicArray::hienThiGiaoDich()
{
    if (size == 0) 
    {
        cout << "Chua co giao dich nao!\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "\nMa phieu: " << data[i].maPhieu;
        cout << "\nCMND: " << data[i].cmnd;
        cout << "\nISBN: " << data[i].ISBN;
        cout << "\nTrang thai: "
            << (data[i].daTra ? "Da Tra Sach" : "Chua Tra Sach");
        cout << "\nTien Phat: " << data[i].tienPhat;
        cout << "\n----------------------\n";
    }
}
int DynamicArray::getSize() 
{
    return size;
}
DynamicArray::~DynamicArray() 
{
    delete[] data;
}