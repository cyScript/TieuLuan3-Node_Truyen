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

typedef Node *PtrNode;
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
	scanf("%d",&GiaBan);
}
void Xuat(Sach &s)
{
	printf("\nMa sach: ",s.MaSach);
	printf("\nTen sach: ",s.TenSach);
	printf("\nTen tac gia: ",s.TacGia);
	printf("\nThe loai sach: ",s.TheLoai);
	printf("\nNam xuat ban: ",s.NamXuatBan);
	printf("\nGia ban: ",s.GiaBan);
}
struct Node
{
	Sach info;
	Node *pNext;
};
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
