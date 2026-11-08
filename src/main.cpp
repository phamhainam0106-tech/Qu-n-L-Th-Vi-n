#include "../include/BSTNode.h"
#include"../include/AVLNode.h"
#include"../include/HashTable.h"
#include"../include/Menu.h"
void main()
{
	AVLNodeptr AVLroot = NULL;
	BSTNodeptr BSTroot = NULL;

	HashNodeptr hashTable[SIZE] = { NULL };
    int chon;
    do
    {
        system("cls");

        cout << "========== QUAN LY THU VIEN ==========\n";
        cout << "1. Quan ly sach\n";
        cout << "2. Quan ly doc gia\n";
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
        case 0:
            cout << "Cam mon!\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai.\n";
            cout << "\nNhan Enter de tiep tuc...";
            cin.get();
            break;
        }

    } while (chon != 0);
	

}