
#include "../include/FileIO.h"
#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;

void ghiChuoi(ofstream& file, string s)
{
    uint32_t n = (uint32_t)s.size();
    file.write((char*)&n, sizeof(n));

    if (n > 0)
        file.write(s.data(), n);
}

bool docChuoi(ifstream& file, string& s)
{
    uint32_t n;

    if (!file.read((char*)&n, sizeof(n)))
        return false;

    if (n > 1000000)
        return false;

    s.resize(n);

    if (n > 0 && !file.read(&s[0], n))
        return false;

    return true;
}

template <typename dulieu>
void ghiSo(ofstream& file, dulieu x)
{
    file.write((char*)&x, sizeof(dulieu));
}

template <typename dulieu>
bool docSo(ifstream& file, dulieu& x)
{
    return (bool)file.read((char*)&x, sizeof(dulieu));
}

void ghiMotSach(ofstream& file, Sach s)
{
    ghiChuoi(file, s.ISBN);
    ghiChuoi(file, s.tenSach);
    ghiChuoi(file, s.tacGia);
    ghiChuoi(file, s.theLoai);

    ghiSo(file, s.namxuatBan);
    ghiSo(file, s.soLuongCon);
    ghiSo(file, s.soLuong);
}

bool docMotSach(ifstream& file, Sach& s)
{
    if (!docChuoi(file, s.ISBN)) return false;
    if (!docChuoi(file, s.tenSach)) return false;
    if (!docChuoi(file, s.tacGia)) return false;
    if (!docChuoi(file, s.theLoai)) return false;

    if (!docSo(file, s.namxuatBan)) return false;
    if (!docSo(file, s.soLuongCon)) return false;
    if (!docSo(file, s.soLuong)) return false;

    return true;
}

int demSach(AVLNodeptr root)
{
    if (root == NULL)
        return 0;

    return 1 + demSach(root->left) + demSach(root->right);
}

void ghiDsSach(ofstream& file, AVLNodeptr root)
{
    if (root == NULL)
        return;

    ghiDsSach(file, root->left);
    ghiMotSach(file, root->data);
    ghiDsSach(file, root->right);
}

bool ghiFileSach(string tenFile, AVLNodeptr root)
{
    ofstream file(tenFile, ios::binary);

    if (!file.is_open())
        return false;

    int n = demSach(root);
    ghiSo(file, n);

    ghiDsSach(file, root);

    file.close();
    return file.good();
}

bool docFileSach(string tenFile, AVLNodeptr& root)
{
    ifstream file(tenFile, ios::binary);
    int n;

    if (!docSo(file, n) || n < 0 || n > 100000)
    {
        file.close();
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        Sach s;

        if (!docMotSach(file, s))
        {
            file.close();
            return false;
        }

        root = themAVLNode(root, s);
    }

    file.close();
    return true;
}

void ghiMotDocGia(ofstream& file, DocGia dg)
{
    ghiChuoi(file, dg.CMND);
    ghiChuoi(file, dg.hoTen);
    ghiChuoi(file, dg.email);
    ghiChuoi(file, dg.soDienThoai);

    ghiSo(file, dg.dangMuon);
    ghiSo(file, dg.tongLuotMuon);
}

bool docMotDocGia(ifstream& file, DocGia& dg)
{
    if (!docChuoi(file, dg.CMND)) return false;
    if (!docChuoi(file, dg.hoTen)) return false;
    if (!docChuoi(file, dg.email)) return false;
    if (!docChuoi(file, dg.soDienThoai)) return false;

    if (!docSo(file, dg.dangMuon)) return false;
    if (!docSo(file, dg.tongLuotMuon)) return false;

    return true;
}

int demDocGia(HashNodeptr hashTable[SIZE])
{
    int dem = 0;

    for (int i = 0; i < SIZE; i++)
    {
        HashNodeptr p = hashTable[i];

        while (p != NULL)
        {
            dem++;
            p = p->next;
        }
    }

    return dem;
}

bool ghiFileDocGia(string tenFile, HashNodeptr hashTable[SIZE])
{
    ofstream file(tenFile, ios::binary);

    if (!file.is_open())
        return false;

    int n = demDocGia(hashTable);
    ghiSo(file, n);

    for (int i = 0; i < SIZE; i++)
    {
        HashNodeptr p = hashTable[i];

        while (p != NULL)
        {
            ghiMotDocGia(file, p->data);
            p = p->next;
        }
    }

    file.close();
    return file.good();
}

bool docFileDocGia(string tenFile, HashNodeptr hashTable[SIZE])
{
    ifstream file(tenFile, ios::binary);

    if (!file.is_open())
        return false;

    int n;

    if (!docSo(file, n) || n < 0 || n > 100000)
    {
        file.close();
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        DocGia dg;

        if (!docMotDocGia(file, dg))
        {
            file.close();
            return false;
        }

        themHNode(hashTable, dg);
    }

    file.close();
    return true;
}
