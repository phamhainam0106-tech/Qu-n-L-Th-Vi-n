#pragma once
#include<iostream>
#include<string>

using namespace std;
struct HashNode;
typedef HashNode* HashNodeptr;
const int SIZE = 9;
struct DocGia {
    string CMND;          
    string hoTen;
    string email;
    string soDienThoai;      
    int    dangMuon;      
    int    tongLuotMuon; 
};

void NhapCCCD(string &cccd);
void NhapDocGia(DocGia& dg);
bool ktDangMuon(DocGia dg);
bool themDocGia(HashNodeptr hastTable[SIZE],DocGia dg);
bool xoaDocGia(HashNodeptr hastTable[SIZE],string cmnd);
bool suaDocGia(HashNodeptr hashTable[SIZE],string cmnd);
HashNodeptr timDocGia(HashNodeptr hastTable[SIZE]);
void xuatDocGia(DocGia dg);

