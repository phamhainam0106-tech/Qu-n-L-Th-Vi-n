#pragma once
#include <iostream>
#include "../include/AVLNode.h"
#include <string>
using namespace std;

struct BSTNode
{
    string data;
    BSTNode* left;
    BSTNode* right;
};

typedef BSTNode* BSTNodeptr;

// Khoi tao cay
void initBST(BSTNodeptr& root);

// Tao node
BSTNodeptr taoBSTNode(string theLoai);

// Them the loai vao BST
bool themBSTNode(BSTNodeptr& root, string theLoai);

// Duyet cay AVL de lay the loai dua vao BST
void taoDanhMucBST(AVLNodeptr rootAVL, BSTNodeptr& rootBST);

// Duyet cay BST va in danh muc
void duyetBST(BSTNodeptr root);

// Giai phong bo nho BST
void xoaCayBST(BSTNodeptr& root);