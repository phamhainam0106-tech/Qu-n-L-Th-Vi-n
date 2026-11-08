#pragma once
#include"DocGia.h"

struct HashNode
{
    DocGia data;
    HashNode* next;
};
typedef HashNode* HashNodeptr;

void init(HashNodeptr hashTable[SIZE]);
int HamBam(string CMND);
HashNodeptr taoHNode(DocGia dg);
bool themHNode(HashNodeptr hashTable[SIZE], DocGia dg);
bool xoaHNode(HashNodeptr hashTable[SIZE], string cmnd);
HashNodeptr timHNode(HashNodeptr hashTable[SIZE], string cmnd);
void duyetBangBam(HashNodeptr hashTable[SIZE]);