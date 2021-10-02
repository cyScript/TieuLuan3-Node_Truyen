#include <stdio.h>
#define TL3 "D:\\QuanLySach.txt"
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
typedef struct Stack{
	Sach info;
	struct Stack* next;
}Stack;
 
//Khoi tao ngan xep
void Init (Stack &S){
   S = NULL;
}
//Kiem tra ngan xep rong
int Isempty(Stack S){
    return S==NULL;
}

Stack CreateNode(int x){
	Stack p=new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
void InsertFirst(Stack &S, Stack pNew)
{
	if(Isempty(S))
		S = pNew;
	else
	{
		pNew->next = S;
		S = pNew;
	}
}

// Them du lieu ngan xep
bool Push(Stack &S, int newItem)
{
	Stack pNew = CreateNode(newItem);
	InsertFirst(S,pNew);
}

// Lay du lieu ra khoi ngan xep
bool Pop(Stack &S, int &outItem)
{
	if(s==NULL) return false;
	Stack pTop = S;
	S = S->next;
	outItem = pTop->info;
	delete pTop;
	return true;
}



void DocFile(Sach s[]){
	FILE *f = fopen(TL3, "r");
	for(int i = 0; i<n; i++)
	{
		fscanf(f,"%s\t%s\t%s\t\t%s\t%d\t%d",&s[i].MaSach,&s[i].TenSach,&s[i].TacGia,&s[i].TheLoai,&s[i].NamXuatBan,&s[i].GiaBan);
	}
	fclose(f);
}
void Ghifile(Sach s[], int n){
		FILE *f=fopen(TL3,"w+");
		fprintf(f,"\nMaSach\tTenSach\tTacGia\t\tTheLoai\tNamXB\tGiaBan\n");
	for(int i = 0;i < n;++i)
	{
		fprintf(f,"%s\t%s\t%s\t\t%s\t%d\t%d",s[i].MaSach,s[i].TenSach,s[i].TacGia,s[i].TheLoai,s[i].NamXuatBan,s[i].GiaBan);
		fprintf(f,"\n");
	}fclose(f);
}