#include "../include/BSTNode.h"
#include"../include/AVLNode.h"
#include"../include/HashTable.h"
#include"../include/Menu.h"
#include "../include/FileIO.h"
void main()
{
	AVLNodeptr AVLroot = NULL;
	BSTNodeptr BSTroot = NULL;
    LinkNodeptr LinkNoderoot = NULL;
	HashNodeptr hashTable[SIZE] = { NULL };
    docFileSach("data/Sach.txt", AVLroot);
    docFileDocGia("data/DocGia.txt", hashTable);

    if (docFileSach("data/Sach.txt", AVLroot))
        cout << "Doc file sach thanh cong!\n";
    else
        cout << "Doc file sach that bai!\n";

    if (docFileDocGia("data/DocGia.txt", hashTable))
        cout << "Doc file doc gia thanh cong!\n";
    else
        cout << "Doc file doc gia that bai!\n";
    system("pause");

    DynamicArray dsGiaoDich;

    int pso = 0;;
    int chon;
    do
    {
        system("cls");

        cout << "========== QUAN LY THU VIEN ==========\n";
        cout << "1. Quan ly sach\n";
        cout << "2. Quan ly doc gia\n";
        cout << "3. Quan ly phieu muon\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "======================================\n";
        cout << "Vui long chon chuc nang: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            hienMenuqlySach(AVLroot);
            break;
        case 2:
            hienMenuqlyDocGia(hashTable);
            break;
        case 3:
            quanLyPhieuMuon(LinkNoderoot, hashTable, AVLroot, pso, dsGiaoDich);
            break;
        case 0:
            ghiFileSach("data/Sach.txt", AVLroot);
            ghiFileDocGia("data/DocGia.txt", hashTable);
            cout << "Cam On!\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai.\n";
            cout << "\nNhan Enter de tiep tuc...";
            cin.get();
            break;
        }

    } while (chon != 0);
	

}