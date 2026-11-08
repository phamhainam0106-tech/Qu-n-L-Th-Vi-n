#include"../include/HashTable.h"

void NhapCCCD(string & cccd)
{
    do
    {
        cout << "Nhap CCCD: ";
        getline(cin, cccd);

        if (cccd.empty())
        {
            cout << "CCCD khong duoc de trong!\n";
            continue;
        }

        if (cccd.length() != 12)
        {
            cout << "CCCD phai co dung 12 chu so!\n";
            continue;
        }

        bool hopLe = true;

        for (int i = 0; i < cccd.length(); i++)
        {
            if (cccd[i] < '0' || cccd[i] > '9')
            {
                hopLe = false;
                break;
            }
        }

        if (hopLe)
            return;

        cout << "CCCD chi duoc chua chu so!\n";

    } while (true);
}
void NhapDocGia(DocGia& dg)
{
    cout << "Nhap ho ten: ";
    getline(cin, dg.hoTen);

    cout << "Nhap email: ";
    getline(cin, dg.email);

    cout << "Nhap so dien thoai: ";
    getline(cin, dg.soDienThoai);

    cout << "Nhap so sach dang muon: ";
    cin >> dg.dangMuon;

    cout << "Nhap tong luot muon: ";
    cin >> dg.tongLuotMuon;
    cin.ignore();
}
bool ktDangMuon(DocGia dg)
{
    if (dg.dangMuon == 0)
        return false;
    else return true;
}
bool themDocGia(HashNodeptr hastTable[SIZE], DocGia dg)
{
    NhapCCCD(dg.CMND);
    if (timHNode(hastTable, dg.CMND) != NULL)
    {
        cout << "Doc gia da ton tai ";
        return false;
    }
    else
    {
        NhapDocGia(dg);
        themHNode(hastTable, dg);
        return true;
    }
}
bool xoaDocGia(HashNodeptr hastTable[SIZE], string cmnd)
{
    NhapCCCD(cmnd);
    if (timHNode(hastTable, cmnd) != NULL)
    {
        if (!ktDangMuon(timHNode(hastTable, cmnd)->data))
        {
            cout << "Doc gia con sach dang muon chua tra nen ko the xoa";
            return false;
        }
        else {
            xoaHNode(hastTable, cmnd);
            return true;
        }
    }
    else
    {
        cout << "Khong tim thay doc gia can xoa!\n";
        return false;
    }
}
bool suaDocGia(HashNodeptr hashTable[SIZE], string cmnd)
{
    NhapCCCD(cmnd);
    HashNodeptr p = timHNode(hashTable, cmnd);
    if (p == NULL)
    {
        cout << "Doc gia chua ton tai ";
        return false;
    }
    else
    {
        NhapDocGia(p->data);
        return true;
    }
}
HashNodeptr timDocGia(HashNodeptr hastTable[SIZE])
{
    string cmnd;
    NhapCCCD(cmnd);
    HashNodeptr p=timHNode(hastTable, cmnd);
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        return p;
    }
}
void xuatDocGia(DocGia dg)
{
    cout << "\nCMND:          " << dg.CMND;
    cout << "\nHo Ten:        " << dg.hoTen;
    cout << "\nEmail:         " << dg.email;
    cout << "\nSDT:           " << dg.soDienThoai;
    cout << "\nDangMuon:      " << dg.dangMuon;
    cout << "\nTong luot muon:" << dg.tongLuotMuon;
    cin.ignore();
}