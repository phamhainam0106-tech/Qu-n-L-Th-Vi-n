#pragma once
#include "../include/BSTNode.h"
#include"../include/AVLNode.h"
#include"../include/HashTable.h"
#include"../include/Linklist.h"
#include "../include/DynamicArray.h"



void hienMenuqlySach(AVLNodeptr& root);
void hienMenuqlyDocGia(HashNodeptr hashTable[SIZE]);
void quanLyPhieuMuon(LinkNodeptr& root, HashNodeptr hashTable[SIZE], AVLNodeptr avlroot,int& n, DynamicArray& dsGiaoDich);