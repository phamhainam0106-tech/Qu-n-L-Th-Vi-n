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
	cin.ignore();
	s.soLuongCon = s.soLuong;
}

void nhapISBN(AVLNodeptr root, Sach& s)
{
	string isbn;
	while (true)
	{
		cout << "\nNhap ma ISBN: ";
		getline(cin, isbn);

		// kiểm tra có ký tự nào khác dấu cách không
		bool hopLe = false;
		for (int i = 0; i < isbn.length(); i++)
		{
			if (isbn[i] != ' ')
			{
				hopLe = true;
				break;
			}
		}

		if (hopLe == false)
		{
			cout << "ISBN khong duoc de trong hoac chi chua dau cach, hay nhap lai!";
		}
		else if (timAVLNode(root, isbn) != NULL)
		{
			cout << "ISBN da ton tai, hay nhap lai!";
		}
		else
		{
			s.ISBN = isbn;
			break;
		}
	}
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
	cin.ignore();
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
	cin.ignore();
	AVLNodeptr p = timAVLNode(root, s.ISBN);
	if (p != NULL)
	{
		
		nhapSach(p->data);
		return true;
	}
	return false;
}

AVLNodeptr timSach(AVLNodeptr root, string mas)
{

	cout << "\nNhap ma sach muon tim: ";
	cin >> mas;
	cin.ignore();
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


