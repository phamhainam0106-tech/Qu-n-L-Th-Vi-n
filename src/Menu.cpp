
#include"../include/Menu.h"
#include "../include/BSTNode.h"
#include"../include/AVLNode.h"
#include"../include/HashTable.h"
#include"../include/Linklist.h"
void hienMenuqlySach(AVLNodeptr& root)
{
    
    Sach s;
    int chon;
    do
    {
        system("cls");

        cout << "========== QUAN LY SACH ==========\n";
        cout << "1. Them sach\n";
        cout << "2. Xoa sach\n";
        cout << "3. Sua sach\n";
        cout << "4. Tim kiem sach\n";
        cout << "5. Duyet thu vien\n";
        cout << "6. In danh muc sach\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "==================================\n";
        cout << "Vui long chon chuc nang: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            if (themSach(root, s) == true)
            {
                cout << "\nthem sach thanh cong\n";
            }
            else cout << "\nma sach da ton tai:\n";
            break;

        case 2:
            if (xoaSach(root, s) == true)
            {
                cout << "\nXoa sach thanh cong:\n";
            }
            else cout << "\nSach khong ton tai:\n";
            break;

        case 3:
            if (suaSach(root, s) == true)
            {
                cout << "\nSua sach thanh cong:\n";
            }
            else cout << "\nSach khong ton tai:";
            break;

        case 4:
            if (timSach(root, s.ISBN) == NULL)
            {
                cout << "\nMa ISBN ko ton tai\n";
            }

            break;

        case 5:
            LNR(root);
            break;
        case 6:
            inDanhMuc(root);
            break;
        case 0:
            cout << "Dang quay lai menu chinh...\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
            break;
        }

        if (chon != 0)
        {
            system("pause");
        }

    } while (chon != 0);
}

void hienMenuqlyDocGia(HashNodeptr hashTable[SIZE])
{
    int chon;
    do
    {
        system("cls");

        cout << "========== QUAN LY DOC GIA ==========\n";
        cout << "1. Them doc gia\n";
        cout << "2. Xoa doc gia\n";
        cout << "3. Sua doc gia\n";
        cout << "4. Tim kiem doc gia\n";
        cout << "5. Duyet toan bo doc gia\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "=====================================\n";
        cout << "Vui long chon chuc nang: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
        {
            DocGia dg;
            if (themDocGia(hashTable, dg))
                cout << "Them doc gia thanh cong!\n";
            system("pause");
            break;
        }
        case 2:
        {
            string cmnd;
            if (xoaDocGia(hashTable, cmnd))
                cout << "Xoa doc gia thanh cong!\n";
            break;
        }
        case 3:
        {
            string cmnd;
            if (suaDocGia(hashTable, cmnd))
                cout << "Sua thong tin doc gia thanh cong!\n";
            break;
        }
        case 4:
        {
            HashNodeptr p = timDocGia(hashTable);
            if (p != NULL)
            {
                cout << "Da tim thay doc gia:\n";
                xuatDocGia(p->data);
            }
            else
                cout << "Khong tim thay doc gia!\n";
            break;
        }
        case 5:
        {
            duyetBangBam(hashTable);
            break;
        }
        case 0:
            cout << "Quay lai menu chinh...\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai.\n";
            break;
        }

        if (chon != 0)
        {
            cout << "\nNhan Enter de tiep tuc...";
            cin.get();
        }

    } while (chon != 0);
}


void quanLyPhieuMuon(LinkNodeptr& root, HashNodeptr hashTable[SIZE],AVLNodeptr avlroot, int& n )
{
    int chon;
    PhieuMuon pm;
    string isbn;
    string cmnd;
    do
    {
        system("cls");

        cout << "========== QUAN LY PHIEU MUON ==========\n";
        cout << "1. Them phieu muon\n";
        cout << "2. Xoa phieu muon\n";
        cout << "3. Tim kiem phieu muon\n";
        cout << "4. Xuat danh sach phieu muon\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "========================================\n";
        cout << "Vui long chon chuc nang: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            
            do
            {
                NhapCCCD(cmnd);
                HashNodeptr p = timHNode(hashTable, cmnd);
                if (p == NULL)
                {
                    cout << "\nDoc gia chua dang ki";
                    continue;
                }
                else
                    break;
            } while (true);

            
            do
            {
                cout << "\nNhap isbn :";
                cin >> isbn;
                cin.ignore();
                AVLNodeptr avl = timAVLNode(avlroot, isbn);
                if (avl == NULL)
                {
                    cout << "\nsach khong ton tai ";
                    continue;
                }
                else
                {

                    break;
                }
            } while (true);

            Nhapphieumuon(pm, isbn, cmnd, n);
            themPhieuMuon(root, pm);
            system("pause");


            break;
        case 2:
            cout << "\nNhap ma phieu muon ";
            cin >> pm.maPhieu;

            xoaPhieumuon(root, pm.maPhieu);
            system("pause");
        
            break;
        case 3:
            cout << "\nNhap ma phieu muon muon tim ";
            cin >> pm.maPhieu;
            
            if (timPhieuMuon(root, pm.maPhieu) != NULL)
            {
                cout << "\ntim thay phieu muon ";
                xuatphieumuon(timPhieuMuon(root, pm.maPhieu)->data);
                system("pause");
            }
            else
            {
                cout << "\nKhong tim thay phieu muon ";
            }
            break;
        case 4:
        {
            xuatdspm(root);
            system("pause");
        }
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le!\n";
            system("pause");
        }
    } while (chon != 0);
}