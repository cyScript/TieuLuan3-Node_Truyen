#include <stdio.h>
typedef struct QLSach
{
	char MaSach[21];
	char TenSach[51];
	char TacGia[21];
	char TheLoai[16];
	int NamXuatBan;
	int GiaBan;
}Sach;


void Nhap(Sach &s)
{
	printf("\nNhap ma sach: ");
	gets(s.MaSach);
	gets(s.MaSach);
	printf("\nNhap ten sach: ");
	gets(s.TenSach);
	printf("\nNhap ten tac gia: ");
	gets(s.TacGia);
	printf("\nNhap the loai sach: ");
	gets(s.TheLoai);
	printf("\nNhap nam xuat ban: ");
	scanf("%d",&s.NamXuatBan);
	printf("\nNhap gia ban: ");
	scanf("%d",&s.GiaBan);
}
void Xuat(Sach &s)
{
	printf("\nMa sach: %s",s.MaSach);
	printf("\nTen sach: %s",s.TenSach);
	printf("\nTen tac gia: %s",s.TacGia);
	printf("\nThe loai sach: %s",s.TheLoai);
	printf("\nNam xuat ban: %d",s.NamXuatBan);
	printf("\nGia ban: %d",s.GiaBan);
}
struct Node
{
	Sach info;
	Node *pNext;
};
typedef Node *PtrNode;
void Init(PtrNode &pHead)
{
	pHead = NULL;
}
bool IsEmpty(PtrNode pHead)
{
	return pHead == NULL;
}
PtrNode CreateNode(Sach s)
{
	PtrNode p;
	p = new Node;

	p->info = s;
	p->pNext = NULL;
	return p;
}

void InsertLast(PtrNode &pHead, PtrNode pNew)
{
	if (IsEmpty(pHead))
		pHead = pNew;
	else
	{
		PtrNode p = pHead;
		while (p->pNext != NULL)
			p = p->pNext;
		p->pNext = pNew;
	}
}
void Input(PtrNode &pHead)
{
	Sach x; //int -> S 
	Init(pHead);
	int n;
	printf("Moi nhap so luong sach: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nMoi nhap thong tin sach thu thu %d: ", i + 1);
		Nhap(x);
		PtrNode pNew = CreateNode(x);
		InsertLast(pHead, pNew);
	}
}
void ShowList(PtrNode pHead)
{
	Node *p = pHead;
	int i = 0;
	while (p != NULL)
	{
		printf("\n Thong tin sinh vien thu %d: ", i + 1);
		Xuat(p->info);
		p = p->pNext;
		i++;
	}
}