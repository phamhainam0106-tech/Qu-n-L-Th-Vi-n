#include"../include/AVLNode.h"

void main()
{
	Sach s ;
	AVLNodeptr root;
	initAVL(root);
	/*do
	{
		Nhap(s);
		if (s.ISBN == "9999")
			break;
		root=themAVLNode(root, s);
	} while (s.ISBN != "9999");
	LNR(root);
	cout << "\nnhap isbn de xoa ";
	cin >> s.ISBN;
	xoaAVLNode(root,s.ISBN);
	LNR(root);
	cout << "\nnhap isbn tim ";
	cin >> s.ISBN;
	cout << timAVLNode(root, s.ISBN)->data.ISBN;*/

   
    
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
        cout << "0. Quay lai menu chinh\n";
        cout << "==================================\n";
        cout << "Vui long chon chuc nang: ";
        cin >> chon;

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
            else cout << "\nSach khong ton tai:\n";
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