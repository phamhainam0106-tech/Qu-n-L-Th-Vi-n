#include"../include/AVLNode.h"


void nhapSach(Sach& s)
{
	
	cout << "\nNhap ten Sach: ";
	getline(cin, s.tenSach);
	cout << "\nNhap tac gia: ";
	getline(cin, s.tacGia);
	cout << "\nNhap the loai: ";
	getline(cin, s.theLoai);
	cout << "\nNhap nam xuat ban: ";
	cin >> s.namxuatBan;
	cout << "\nNhap so luong: ";
	cin >> s.soLuong;
	s.soLuongCon = s.soLuong;
}

void nhapISBN(AVLNodeptr root, Sach& s)
{/*
	do
	{*/

	
	cin.ignore();
	cout << "\nNhap ma ISBN: ";
	getline(cin, s.ISBN);// getline để nhận luôn khoảng trắng
	/*if (timAVLNode(root, s.ISBN) == NULL && !s.ISBN.empty())
	{
		break;
	}
	else
	{
		cout << "\nISBN trung hoặc bi bo trong, hay nhap lai";
	}
	} while (true);*/
}
bool themSach(AVLNodeptr& root, Sach s)
{
	nhapISBN(root,s);
	nhapSach(s);
	if (timAVLNode(root, s.ISBN) == NULL)
	{
		root=themAVLNode(root, s);
		return true;
	}
	return false;
}
bool xoaSach(AVLNodeptr& root, Sach s)
{
	cout << "\nNhap ma sach muon xoa: ";
	cin >> s.ISBN;
	if (timAVLNode(root, s.ISBN) != NULL)
	{
		root = xoaAVLNode(root, s.ISBN);
		return true;
	}
	return false;
}
bool suaSach(AVLNodeptr& root, Sach s)
{
	cout << "\nNhap ma sach muon sua: ";
	cin >> s.ISBN;
	if (timAVLNode(root, s.ISBN) != NULL)
	{
		AVLNodeptr p = timAVLNode(root, s.ISBN);
		nhapSach(p->data);
		return true;
	}
	return false;
}

AVLNodeptr timSach(AVLNodeptr root, string mas)
{

	cout << "\nNhap ma sach muon tim: ";
	cin >> mas;
	if (timAVLNode(root, mas) != NULL)
	{
		xuatSach(timAVLNode(root, mas)->data);
		return timAVLNode(root, mas);
	}
	return NULL;
}
void xuatSach(Sach s)
{
	cout << "\nMa ISBN: " << s.ISBN;
	cout << "\nTen sach: " << s.tenSach;
	cout << "\nTac gia: " << s.tacGia;
	cout << "\nThe loai: " << s.theLoai;
	cout << "\nNam Xuat ban: " << s.namxuatBan;
	cout << "\nso luong: "<<s.soLuong;
	cout << "\nSo luong con lai: " << s.soLuongCon;
}


