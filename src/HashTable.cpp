#include"../include/HashTable.h"

void init(HashNodeptr hashTable[SIZE])
{
	for (int i = 0;i < SIZE;i++)
	{
		hashTable[i]=NULL;
	}
}
int HamBam(string CMND)
{
	int soCuoi = stoi(CMND.substr(CMND.length() - 1));
	return soCuoi % SIZE;
}
HashNodeptr taoHNode(DocGia dg)
{
	HashNodeptr p = new HashNode;
	p->data = dg;
	p->next = NULL;
	return p;
}
bool themHNode(HashNodeptr hashTable[SIZE], DocGia dg)
{
	int n = HamBam(dg.CMND);
	if (hashTable[n] == NULL)
	{
		hashTable[n] = taoHNode(dg);
		return true;
	}
	else
	{
		HashNodeptr q = hashTable[n];
		while (q != NULL)
		{
			if (q->data.CMND == dg.CMND)
			{
				return false;
			}
			q = q->next;
		}
		HashNodeptr p = taoHNode(dg);
		p->next = hashTable[n];
		hashTable[n] = p;
		return true;
	}
}
bool xoaHNode(HashNodeptr hashTable[SIZE], string cmnd)
{
	int n = HamBam(cmnd);

	if (hashTable[n] == NULL)
	{
		return false;
	}
	else if (hashTable[n]->data.CMND == cmnd)
	{
		HashNodeptr p = hashTable[n];
		hashTable[n] = p->next;
		delete p;
		return true;
	}
	else {
		HashNodeptr q = hashTable[n];
		while (q->next != NULL)
		{
			
			if (cmnd == q->next->data.CMND)
			{
				HashNodeptr p = q->next;
				q->next = p->next;
				delete p;
				return true;
			}
			q = q->next;
		}
		return false;
	}
}
HashNodeptr timHNode(HashNodeptr hashTable[SIZE], string cmnd)
{
	int n = HamBam(cmnd);

	if (hashTable[n] == NULL)
	{
		return NULL;
	}
	else
	{
		HashNodeptr p = hashTable[n];
		while (p != NULL)
		{
			if (p->data.CMND == cmnd)
				return p;
			p = p->next;
		}
		return NULL;
	}
}

void duyetBangBam(HashNodeptr hashTable[SIZE])
{

	for (int i = 0;i < SIZE;i++)
	{
		if (hashTable[i] != NULL)
		{
			HashNodeptr p = hashTable[i];
			cout << "\nHashTable[" << i << "]";
			while (p != NULL)
			{
				cout << endl;
				xuatDocGia(p->data);
				p = p->next;
			}
		}
		else
			cout << "\nHashTable[" << i << "]=NULL";
	}
}