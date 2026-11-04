#pragma once
#include"Sach.h"
using namespace std;

struct AVLNode {
	Sach data;
	AVLNode* left;
	AVLNode* right;
	int height;
};

typedef AVLNode* AVLNodeptr;
void initAVL(AVLNodeptr& root);
bool isEmpty(AVLNodeptr root);
AVLNodeptr taoAVLNode(Sach s);
int height(AVLNodeptr root);
int getBalance(AVLNodeptr root);
AVLNodeptr themAVLNode(AVLNodeptr root,Sach s);
AVLNodeptr xoaAVLNode(AVLNodeptr root, string mas);
AVLNodeptr timAVLNode(AVLNodeptr root, string mas);
AVLNodeptr xoayPhai(AVLNodeptr y);
AVLNodeptr xoayTrai(AVLNodeptr x);
int maxHeight(int x, int y);
AVLNodeptr canBang(AVLNodeptr root);
void LNR(AVLNodeptr root);
AVLNodeptr timMax(AVLNodeptr root);
void Nhap(AVLNodeptr root,Sach& s);