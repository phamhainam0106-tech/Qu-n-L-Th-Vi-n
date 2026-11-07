#include "../include/BSTNode.h"
#include "../include/AVLNode.h"
#include <iomanip>

void initBST(BSTNodeptr& root)
{
    root = NULL;
}
BSTNodeptr taoBSTNode(Sach s)
{
    BSTNodeptr p = new BSTNode;

    p->data = s;
    p->left = NULL;
    p->right = NULL;

    return p;
}
bool themBSTNode(BSTNodeptr& root, Sach s)
{
    if (root == NULL)
    {
        root = taoBSTNode(s);
        return true;
    }

    if (s.tenSach < root->data.tenSach ||
        (s.tenSach == root->data.tenSach && s.ISBN < root->data.ISBN))
        return themBSTNode(root->left, s);

    if (s.tenSach > root->data.tenSach ||
        (s.tenSach == root->data.tenSach && s.ISBN > root->data.ISBN))
        return themBSTNode(root->right, s);

    return false;
}
void taoDanhMucBST(AVLNodeptr rootAVL, BSTNodeptr& rootBST)
{
    if (rootAVL == NULL)
        return;

    taoDanhMucBST(rootAVL->left, rootBST);
    cout << "Ten sach trong AVL: [" << rootAVL->data.tenSach << "]\n";
    themBSTNode(rootBST, rootAVL->data);

    taoDanhMucBST(rootAVL->right, rootBST);
}

void duyetBST(BSTNodeptr root)
{
    if (root == NULL)
        return;

    duyetBST(root->left);

    cout << left
        << setw(12) << root->data.ISBN
        << setw(25) << root->data.tenSach
        << setw(20) << root->data.tacGia
        << setw(20) << root->data.theLoai << endl;

    duyetBST(root->right);
}
void xoaCayBST(BSTNodeptr& root)
{
    if (root == NULL)
        return;

    xoaCayBST(root->left);
    xoaCayBST(root->right);

    delete root;
    root = NULL;
}
void inDanhMuc(AVLNodeptr rootAVL)
{
    if (rootAVL == NULL)
    {
        cout << "\nThu vien chua co sach!\n";
        return;
    }

    BSTNodeptr bst;
    initBST(bst);

    taoDanhMucBST(rootAVL, bst);

    cout << "\n========== DANH MUC SACH ==========\n";
    cout << left
        << setw(12) << "ISBN"
        << setw(25) << "TEN SACH"
        << setw(20) << "TAC GIA"
        << setw(20) << "THE LOAI" << endl;

    duyetBST(bst);
    xoaCayBST(bst);
}