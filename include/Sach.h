#pragma once
#include<iostream>
#include<string>
using namespace std;

struct AVLNode;
typedef AVLNode* AVLNodeptr;

struct Sach {
	string ISBN;
	string tenSach;
	string tacGia;
	string theLoai;
	int namxuatBan;
	int soLuongCon;
	int soLuong;

};

void nhapSach(Sach& s);
bool themSach(AVLNodeptr& root,Sach s);
bool xoaSach(AVLNodeptr& root, Sach s);
bool suaSach(AVLNodeptr& root, Sach s);
AVLNodeptr timSach(AVLNodeptr root, string mas);
void xuatSach(Sach s);
void nhapISBN(Sach& s);
