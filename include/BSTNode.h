#pragma once
#include <iostream>
#include "AVLNode.h"
#include <string>
using namespace std;

struct BSTNode
{
    Sach data;
    BSTNode* left;
    BSTNode* right;
};

typedef BSTNode* BSTNodeptr;

void initBST(BSTNodeptr& root);
BSTNodeptr taoBSTNode(Sach s);
bool themBSTNode(BSTNodeptr& root, Sach s);
void taoDanhMucBST(AVLNodeptr rootAVL, BSTNodeptr& rootBST);
void duyetBST(BSTNodeptr root);
void xoaCayBST(BSTNodeptr& root);
void inDanhMuc(AVLNodeptr rootAVL);