#include"../include/AVLNode.h"


void initAVL(AVLNodeptr& root)
{
	root = NULL;
}
bool isEmpty(AVLNodeptr root)
{
	return root == NULL ? true : false;
}
AVLNodeptr taoAVLNode(Sach s)
{
	AVLNodeptr p = new AVLNode;
	
	p->data = s;
	p->left = NULL;
	p->right = NULL;
	p->height = 1;

	return p;
}
int height(AVLNodeptr root)
{
	if (root == NULL)
		return 0;
	return root->height;
}
int getBalance(AVLNodeptr root)
{
	if (root == NULL)
		return 0;
	return  height(root->left) - height(root->right);
}
AVLNodeptr xoayPhai(AVLNodeptr y)
{
	AVLNodeptr x = y->left;
	AVLNodeptr p = x->right;

	x->right = y;
	y->left = p;

	y->height = 1 + maxHeight(height(y->left), height(y->right));
	x->height = 1 + maxHeight(height(x->left), height(x->right));

	return x;
}
AVLNodeptr xoayTrai(AVLNodeptr x)
{
	AVLNodeptr y = x->right;
	AVLNodeptr t = y->left;

	y->left = x;
	x->right = t;

	x->height = 1 + maxHeight(height(x->left), height(x->right));
	y->height = 1 + maxHeight(height(y->left), height(y->right));

	return y;

}
AVLNodeptr themAVLNode(AVLNodeptr root, Sach s)
{
	if (root == nullptr)
	{
		return taoAVLNode(s);
	}

	if (s.ISBN < root->data.ISBN)
	{
		root->left=themAVLNode(root->left, s);
	}
	else if (s.ISBN > root->data.ISBN)
	{
		root->right=themAVLNode(root->right, s);
	}
	else 
	{
		return root;
	}

	return canBang(root);



}
AVLNodeptr xoaAVLNode(AVLNodeptr root, string mas)
{
	if (root == NULL)
		return NULL;
	if (mas < root->data.ISBN)
	{
		root->left=xoaAVLNode(root->left, mas);
	}
	else if(mas > root->data.ISBN)
	{
		root->right=xoaAVLNode(root->right, mas);
	}
	else
	{
		if (root->left != NULL && root->right != NULL)
		{
			AVLNodeptr temp = timMax(root->left);
			root->data = temp->data;
			root->left = xoaAVLNode(root->left, root->data.ISBN);
		}
		else if (root->left != NULL)
		{
			AVLNodeptr temp = root->left;
			delete root;
			return temp;
		}
		else if (root->right != NULL)
		{
			AVLNodeptr temp = root->right;
			delete root;
			return temp;
		}
		else
		{
			delete root;
			return NULL;
		}

	}

	return canBang(root);
}
AVLNodeptr timAVLNode(AVLNodeptr root, string mas)
{
	if (root == NULL)
		return NULL;
	if (mas < root->data.ISBN)
	{
		return timAVLNode(root->left, mas);
	}
	else if (mas > root->data.ISBN)
	{
		return timAVLNode(root->right, mas);
	}
	else
		return root;
}
int maxHeight(int x, int y)
{
	return (x > y) ? x : y;
}

AVLNodeptr canBang(AVLNodeptr root)
{
	if (root == nullptr)
		return root;

	root->height= 1+ maxHeight(height(root->left), height(root->right));

	if (getBalance(root) > 1 && getBalance(root->left)>=0) //lech ll
	{
		return xoayPhai(root);

	}
	else if (getBalance(root) > 1 && getBalance(root->left) < 0)// lech LR
	{
		root->left = xoayTrai(root->left);
		return xoayPhai(root);
	}
	else if (getBalance(root) < -1 && getBalance(root->right) <= 0) //lech RR
	{
		return xoayTrai(root);
	}
	else if (getBalance(root) < -1 && getBalance(root->right) > 0) //lệch RL
	{
		root->right = xoayPhai(root->right);
		return xoayTrai(root);
	}

	return root;
}

void LNR(AVLNodeptr root)
{
	if (root == nullptr)
		return;

		LNR(root->left);
		xuatSach(root->data);
		cout << "\n\n";
		LNR(root->right);

}
AVLNodeptr timMax(AVLNodeptr root)
{
	if (root == NULL)
		return NULL;

	AVLNodeptr p = root;
	while (p->right != NULL)
	{
		p = p->right;
	}
	return p;
}
void Nhap(Sach &s)
{
	
	cout << "Nhap ma isbn " << endl;
	cin >> s.ISBN;
	s.namxuatBan = 1;
	s.soLuong = 1;
	s.soLuongCon = 1;
	s.tacGia = "a";
	s.tenSach = "b";
	s.theLoai = "c";
}