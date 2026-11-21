#pragma once
#include"phieumuon.h"

struct LinkNode
{
	PhieuMuon data;
	LinkNode* next;
};
typedef LinkNode* LinkNodeptr;

void initLink(LinkNodeptr& root);
LinkNodeptr taoLinkNode(PhieuMuon pm);
bool themLinkNode(LinkNodeptr& root, PhieuMuon pm);
bool xoaLinkNode(LinkNodeptr& root, string mapm);
LinkNodeptr timLinkNode(LinkNodeptr root, string mapm);

