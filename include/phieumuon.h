#pragma once
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

struct PhieuMuon {
	string maPhieu;
	string cmnd;
	string ISBN;
	time_t ngayMuon;
	time_t ngayHenTra;
	time_t ngayTra;
	bool daTra;
	double tienPhat;
};
struct LinkNode;
typedef LinkNode* LinkNodeptr;

string taoMaPhieu(int &pso);
void Nhapphieumuon(PhieuMuon& pm,string ISBN,string cmnd,int& pso);
void themPhieuMuon(LinkNodeptr& root,PhieuMuon pm);
void xoaPhieumuon(LinkNodeptr& root,string pm);
LinkNodeptr timPhieuMuon(LinkNodeptr root,string mapm );
void xuatphieumuon(PhieuMuon pm);
void xuatdspm(LinkNodeptr root);
string ngay(time_t t);