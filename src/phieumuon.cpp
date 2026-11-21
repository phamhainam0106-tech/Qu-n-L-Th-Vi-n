#pragma once
#include"../include/DocGia.h"
#include"../include/Sach.h"
#include"../include/Linklist.h"

string taoMaPhieu(int& pso)
{
	pso++;
	string  so = to_string(pso);
	while (so.size() < 5)
		so = "0" + so;
	return "MP" + so;
}
void Nhapphieumuon(PhieuMuon& pm, string ISBN, string cmnd,int& pso)
{
	pm.maPhieu = taoMaPhieu(pso);
	pm.cmnd = cmnd;
	pm.ISBN = ISBN;
	pm.ngayMuon = time(nullptr);
	pm.ngayHenTra = pm.ngayMuon + 14 * 24 * 60 * 60;
	pm.ngayTra = 0;
	pm.daTra = false;
	pm.tienPhat = 0;
}
void themPhieuMuon(LinkNodeptr& root, PhieuMuon pm)
{

	if (themLinkNode(root, pm) == true)
	{
		cout << "them thanh cong ";
		return ;
	}
	else
		cout << "them khong thanh cong ";
	return ;
}
void xoaPhieumuon(LinkNodeptr& root, string pm)
{
	if (xoaLinkNode(root, pm))
	{
		cout << "xoa thanh cong";
		return;
	}
	else
		cout << "xoa khong thanh cong ";
	return ;

}
LinkNodeptr timPhieuMuon(LinkNodeptr root, string mapm)
{
	LinkNodeptr p = timLinkNode(root, mapm);
	if(p!=NULL)
	{
		return p;
	}
	return NULL;
}
void xuatphieumuon(PhieuMuon pm)
{
	cout <<"Ma phieu:     " << pm.maPhieu << endl;
	cout <<"CMND:         " << pm.cmnd << endl;
	cout <<"ISBN:         " << pm.ISBN << endl;
	cout <<"Ngay muon:    " << ngay(pm.ngayMuon) << endl;
	cout <<"Ngay hen tra: " << ngay(pm.ngayHenTra) << endl;
	cout <<"Ngay tra:     " << ngay(pm.ngayTra) << endl;
	cout <<"Tien phat:    " << pm.tienPhat << endl;
}
void xuatdspm(LinkNodeptr root)
{
	LinkNodeptr p = root;
	while (p != NULL)
	{
		xuatphieumuon(p->data);
		p = p->next;
	}
}

string ngay(time_t t)
{
	tm ngay;
	localtime_s(&ngay, &t);
	char buf[20];
	strftime(buf, sizeof(buf), "%d/%m/%Y", &ngay);
	return string(buf);
}