#include  <iostream>
using namespace std;
struct Node
{
	int data;
	Node* pLeft;
	Node* pRight;
};
typedef struct Node* Tree;
void KhoiTaoTree(Tree& t)
{
	t = NULL;
}
Node* KhoiTaoNode(int x)
{
	Node* p = new Node();
	if (p == NULL)
		return NULL;
	else
	{
		p->data = x;
		p->pLeft = p->pRight = NULL;
	}
	return p;
}
int ThemNodeVaoCay(Tree& t, int x)
{
	if (t == NULL)
	{
		Node* p = new Node;
		if (p == NULL)
			return -1;
		p->data = x;
		p->pLeft = p->pRight = NULL;
		t = p;
		return 1;
	}
	else
	{
		if (x < t->data)
			ThemNodeVaoCay(t->pLeft, x);
		if (x > t->data)
			ThemNodeVaoCay(t->pRight, x);
		if (t->data == x)
			return -1;
	}
}
void DuyetRNL(Tree t)
{
	if (t != NULL)
	{
		DuyetRNL(t->pRight);
		cout << t->data << " ";
		DuyetRNL(t->pLeft);
	}
}
int DoDai(Tree t, int x)
{
	if (t->data== x)
		return 0;
	else if (x < t->data)
	{
		return 1 + DoDai(t->pLeft, x);
	}
	else
	{
		return 1 + DoDai(t->pRight, x);
	}
}
void XuatLevelNodeTheoChieuNodeTangDan(Tree t,Tree ogr)
{
	if (t != NULL)
	{
		XuatLevelNodeTheoChieuNodeTangDan(t->pLeft,ogr);
		cout << DoDai(ogr,t->data) << " ";
		XuatLevelNodeTheoChieuNodeTangDan(t->pRight,ogr);
	}
}
int BacCuaNode(Tree t)
{
	if (t !=  NULL)
	{
		if (t->pLeft != NULL && t->pRight != NULL)
			return 2;
		if (t->pLeft != NULL || t->pRight != NULL)
			return 1;
		else
			return 0;
	}
}
void XuatBacCuaNodeCoLevelLTheoChieuGiaTriGiamDan(Tree t,int L)
{
	if (t == NULL || L < 0)
		return;
	else
	{
		XuatBacCuaNodeCoLevelLTheoChieuGiaTriGiamDan(t->pRight, L - 1);
		if (L == 0)
		{
			cout << BacCuaNode(t) << " ";
		}
		XuatBacCuaNodeCoLevelLTheoChieuGiaTriGiamDan(t->pLeft, L - 1);
	}

}
Node* searchforparentnode(Tree t, int value)
{
	if (t == NULL)
		return NULL;

	if (t->pLeft == NULL && t->pRight == NULL)
		return NULL;

	if ((t->pLeft != NULL && t->pLeft->data == value)
		|| (t->pRight != NULL && t->pRight->data == value))
		return t;

	if (t->data > value)
		return searchforparentnode(t->pLeft, value);

	if (t->data < value)
		return searchforparentnode(t->pRight, value);
}
int ChieuCaoCay(Tree t) 
{
	if (t == NULL|| (t->pLeft==NULL &&t->pRight==NULL))
		return 0;
	return 1 + max(ChieuCaoCay(t->pLeft), ChieuCaoCay(t->pRight));
}
bool SNT(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
void TimNodeTheMang(Tree& p, Tree& pTM)
{
	if (pTM->pLeft != NULL)
		TimNodeTheMang(p, pTM->pLeft);
	else
	{
		p->data = pTM->data;
		p = pTM;
		pTM = pTM->pRight;
	}
}
void XoaNode(Tree& t, int x)
{
	if (t == NULL)
		return;
	else
	{
		if (x < t->data)
			XoaNode(t->pLeft, x);
		else if (x > t->data)
			XoaNode(t->pRight, x);
		else
		{
			Node* p = t;
			if (t->pLeft == NULL)
				t = t->pRight;
			else if (t->pRight == NULL)
				t = t->pLeft;
			else
				TimNodeTheMang(p, t->pRight);
			delete p;
			//return true;
		}
	}
	//else return false;
}
void DeleteAllNodeIsPrime(Tree& t)
{
	if (t != NULL)
	{
		DeleteAllNodeIsPrime(t->pLeft);
		DeleteAllNodeIsPrime(t->pRight); 
		if (SNT(t->data))
		{
			XoaNode(t, t->data);
		}
	}
}
int DemSoNode(Tree t)
{
	if (t == NULL)
	{
		return 0;
	}
	return 1 + DemSoNode(t->pLeft) + DemSoNode(t->pRight);
}
bool SoConBenTraiBangSoConBenPhai(Tree t)
{
	if (t == NULL)
		return 0;
	else
	{
		if (DemSoNode(t->pLeft) == 0 && DemSoNode(t->pRight) == 0)
			return 0;
		else
		{
			if (DemSoNode(t->pLeft) == DemSoNode(t->pRight))
				return 1;
			else
				return 0;
		}
	}
}

void TimNodeCoSoConTraiBangConPhai(Tree t)
{
	if (t == NULL)
		return;
	else
	{
		TimNodeCoSoConTraiBangConPhai(t->pLeft);
		TimNodeCoSoConTraiBangConPhai(t->pRight);
		if (SoConBenTraiBangSoConBenPhai(t))
			cout << t->data << " ";

	}
}
int TinhTongGiaTri(Tree t)
{
	if (t == NULL)
		return 0;
	else
	{
		return t->data + TinhTongGiaTri(t->pLeft) + TinhTongGiaTri(t->pRight);
	}

}
bool TongGTConBenTraiBangTongGTConBenPhai(Tree t)
{
	if (t == NULL|| ((t->pLeft==NULL)&&(t->pRight==NULL)))
		return 0;
	else
	{
			if (TinhTongGiaTri(t->pLeft) == TinhTongGiaTri(t->pRight))
				return 1;
			else
				return 0;
	
	}
}
void TimNodeCoGTCayConTraiBangCayConPhai(Tree t)
{
	if (t != NULL)
	{
		TimNodeCoGTCayConTraiBangCayConPhai(t->pLeft);
		TimNodeCoGTCayConTraiBangCayConPhai(t->pRight);
		if (TongGTConBenTraiBangTongGTConBenPhai(t))
			cout << t->data << " ";
	}
}
void Menu(Tree& t)
{
	while (true)
	{
		cout << "\n\t\t===========MENU===========";
		cout << "\n\t1.Tao cay nhi phan va xuat theo chieu giam dan";
		cout << "\n\t2.Xuat level cua cac node theo chieu gia tri node tang dan";
		cout << "\n\t3.Xuat ra bac cua node o level L + 1 theo chieu gia tri node giam dan";
		cout << "\n\t4.Tim node cha cua node co khoa la x";
		cout << "\n\t5.Chieu cao cua cay";
		cout << "\n\t6.Xoa tat ca cac so nguyen to";
		cout << "\n\t7.Dem so node con";
		cout << "\n\t8.Cac node co so con trai bang so con phai";
		cout << "\n\t9.Tong gia tri cay";
		cout << "\n\t10.Cac node co tong gia tri cay con trai bang cay con phai";
		cout << "\n\t0.Thoat";
		cout << "\n\t\t===========END===========";
		int luachon;
		cout << "\nNhap lua chon : ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "Nhap gia tri node : ";
			cin >> x;
			while (x > 0)
			{
				ThemNodeVaoCay(t, x);
				cout << "Nhap gia tri node : ";
				cin >> x;
				
			}
			cout << "Ket qua cay theo thu tu giam dan : ";
			DuyetRNL(t);
			system("pause");
		}
		if (luachon == 2)
		{
			Tree ogr = t;
			cout << "Level cua cac node theo thu tu gia tri node tang dan : ";
			XuatLevelNodeTheoChieuNodeTangDan(t, ogr);
			system("pause");
		}
		if (luachon == 3)
		{
			int L;
			cout << "Nhap level L : ";
			cin >> L;
			XuatBacCuaNodeCoLevelLTheoChieuGiaTriGiamDan(t, L + 1);
		}
		if (luachon == 4)
		{
			Node* p = new Node;
			int x;
			cout << "Cha cua x = ";
			cin >> x;
			p = searchforparentnode(t, x);
			if (p != NULL)
			{
				if (x == t->data)
				{
					cout << "1";
				}
				else
					cout << p->data;
			}
			else
				cout << "0";

		}
		if (luachon == 5)
		{
			cout << "Chieu Cao cua cay : " << ChieuCaoCay(t);
		}
		if (luachon == 6)
		{
			DeleteAllNodeIsPrime(t);
			cout << "cay sau khi xoa (RNL) : ";
			DuyetRNL(t);
		}
		if (luachon == 7)
		{
			cout << "So con : " << DemSoNode(t);
		}
		if (luachon == 8)
		{
			TimNodeCoSoConTraiBangConPhai(t);
		}
		if (luachon == 9)
		{
			cout << "Tong Gia tri : " << TinhTongGiaTri(t);
		}
		if (luachon == 10)
		{
			TimNodeCoGTCayConTraiBangCayConPhai(t);
		}
	}
}

int main()
{
	Tree t;
	KhoiTaoTree(t);
	Menu(t); 
}