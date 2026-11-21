#include"../include/Linklist.h"


void initLink(LinkNodeptr& root)
{
	root = NULL;
}
LinkNodeptr taoLinkNode(PhieuMuon pm)
{
	LinkNodeptr p = new LinkNode;
	p->data = pm;
	p->next = NULL;
	return p;
}
bool themLinkNode(LinkNodeptr& root, PhieuMuon pm)
{
	if (root == NULL)
	{
		root = taoLinkNode(pm);
		return true;
	}
	else
	{
		LinkNodeptr p = root;
		while (p != NULL)
		{
			if (p->data.maPhieu == pm.maPhieu)
			{
				return false;
			}
			p = p->next;
		}
		p = taoLinkNode(pm);
		p->next = root;
		root = p;
		return true;
	}
}
bool xoaLinkNode(LinkNodeptr& root, string mapm)
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		LinkNodeptr p = root;
		if (p->data.maPhieu == mapm)
		{
			root = p->next;
			delete p;
			return true;
		}
		while (p->next != NULL)
		{
			if (p->next->data.maPhieu == mapm)
			{
				LinkNodeptr q = p->next;
				p->next = q->next;
				delete q;
				return true;
			}
			p = p->next;
		}
		return false;
	}
}
LinkNodeptr timLinkNode(LinkNodeptr root, string mapm)
{
	LinkNodeptr p = root;
	while (p != NULL)
	{
		if (p->data.maPhieu == mapm)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
