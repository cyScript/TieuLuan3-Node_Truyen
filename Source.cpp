#include <stdio.h>
#include <stdlib.h>
#define TL3 "D:\\QuanLySach.txt"
#define MAX 100

typedef struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct QLSach
{
	char MaSach[21];
	char TenSach[51];
	char TacGia[21];
	char TheLoai[16];
	int NamXuatBan;
	int GiaBan;
	Date NgayThue;
	Date NgayTra;
} Sach;

void NhapDate(Date &d)
{
	// int ngay, thang, nam;
	printf("Nhap ngay,thang,nam: ");
	scanf("%d%d%d", &d.Ngay, &d.Thang, &d.Nam);
	switch (d.Thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:

		if (d.Ngay > 0 && d.Ngay <= 31)
		{

			printf("Ngay %d thang %d nam %d hop le\n", d.Ngay, d.Thang, d.Nam);
			break;
		}

		else

		{
			printf("Ngay %d thang %d nam %d ko hop le\n", d.Ngay, d.Thang, d.Nam);
			break;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		if (d.Ngay <= 30 && d.Ngay > 0)
		{
			printf("Ngay %d thang %d nam %d hop le\n", d.Ngay, d.Thang, d.Nam);
			break;
		}
		else
		{
			printf("Ngay %d thang %d nam %d ko hop le\n", d.Ngay, d.Thang, d.Nam);
			break;
		}
	case 2:
		if (d.Ngay <= 28 && d.Ngay > 0)
		{
			printf("Ngay %d thang %d nam %d hop le\n", d.Ngay, d.Thang, d.Nam);
			break;
		}
		else
		{
			printf("Ngay %d thang %d nam %d ko hop le\n", d.Ngay, d.Thang, d.Nam);
			break;
		}
	default:
		printf("Ngay %d thang %d nam ko hop le\n", d.Ngay, d.Thang, d.Nam);
		break;
	}
	// if (d.Nam % 400 == 0)
	// 	printf("Nam %d la nam nhuan", d.Nam);
	// else
	// {
	// 	if (d.Nam % 4 == 0 && d.Nam % 100 != 0)
	// 		printf("Nam %d la nam nhuan", d.Nam);
	// 	else
	// 		printf("Nam %d ko phai la nam nhuan", d.Nam);
	// }
}

void Nhap(Sach &s)
{
	fflush(stdin);
	printf("Nhap ma sach: ");
	gets(s.MaSach);
	printf("Nhap ten sach: ");
	gets(s.TenSach);
	printf("Nhap ten tac gia: ");
	gets(s.TacGia);
	printf("Nhap the loai sach: ");
	gets(s.TheLoai);
	printf("Nhap nam xuat ban: ");
	scanf("%d", &s.NamXuatBan);
	printf("Nhap gia ban: ");
	scanf("%d", &s.GiaBan);
	printf("Nhap ngay thue:\n");
	NhapDate(s.NgayThue);
	printf("\nNhap ngay tra:\n");
	NhapDate(s.NgayTra);
}
void Xuat(Sach &s)
{
	printf("\nMa sach: %s", s.MaSach);
	printf("\nTen sach: %s", s.TenSach);
	printf("\nTen tac gia: %s", s.TacGia);
	printf("\nThe loai sach: %s", s.TheLoai);
	printf("\nNam xuat ban: %d", s.NamXuatBan);
	printf("\nGia ban: %d", s.GiaBan);
}
void NhapDs(Sach s[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap thong tin quyen sach thu %d: \n", i + 1);
		Nhap(s[i]);
	}
}
void XuatDs(Sach s[], int n)
{
	for (int i = 0; i < n; i++)
		Xuat(s[i]);
}
struct Node
{
	Sach info;
	Node *next;
};
typedef struct Node *Stack;
// struct Stack
// {
// 	Node *pHead;
// 	Node *pTail;
// };

//Khoi tao ngan xep
// void Init(Stack &s)
// {
// 	S = NULL;
// }
//Kiem tra ngan xep rong
// bool IsEmpty(Stack s)
// {
// 	return (s == NULL);
// }
// Node *CreateNode(Sach info)
// {
// 	Node *p = new Node();
// 	if (p == NULL)
// 	{
// 		return NULL;
// 	}
// 	p->info = info;
// 	p->next = NULL;
// 	return p;
// }
// void InsertFirst(Stack &S, Stack pNew)
// {
// 	if (IsEmpty(S))
// 		S = pNew;
// 	else
// 	{
// 		pNew->next = S;
// 		S = pNew;
// 	}
// }

// // Them du lieu ngan xep
// bool Push(Stack &S, int newItem)
// {
// 	Stack pNew = CreateNode(newItem);
// 	InsertFirst(S, pNew);
// }

// // Lay du lieu ra khoi ngan xep
// bool Pop(Stack &S, int &outItem)
// {
// 	if (s == NULL)
// 		return false;
// 	Stack pTop = S;
// 	S = S->next;
// 	outItem = pTop->info;
// 	delete pTop;
// 	return true;
// }
// void DocFile(Sach s[], int n)
// {
// 	FILE *f = fopen(TL3, "r");
// 	if (f == NULL)
// 		printf("\nDoc file that bai!");
// 	char tmp[3];
// 	fscanf(f, "%s", &tmp);
// 	for (int i = 0; i <= MAX; i++)
// 	{
// 		fscanf(f, "%s\t%s\t%s\t\t%s\t%d\t%d", &s[i].MaSach, &s[i].TenSach, &s[i].TacGia, &s[i].TheLoai, &s[i].NamXuatBan, &s[i].GiaBan);
// 	}
// 	fclose(f);
// }
void GhiFile(Sach s[], int n)
{
	FILE *f = fopen(TL3, "w+");
	if (f == NULL)
		printf("\nGhi file that bai!");
	fprintf(f, "MaSach\tTenSach\tTacGia\t\tTheLoai\tNamXB\tGiaBan\n");
	for (int i = 0; i < n; ++i)
	{
		fprintf_s(f, "%s\t%s\t%s\t\t%s\t%d\t%d", s[i].MaSach, s[i].TenSach, s[i].TacGia, s[i].TheLoai, s[i].NamXuatBan, s[i].GiaBan);
		fprintf(f, "\n");
	}
	fclose(f);
}
int main()
{
	Stack *s;
	Sach x[MAX];
	int n = 3;
	NhapDs(x, n);
	GhiFile(x, n);
	// DocFile(x, n);
	XuatDs(x, n);
}