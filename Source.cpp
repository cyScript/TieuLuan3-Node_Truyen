#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct QLTruyen
{
	char MaTruyen[13];
	char TenTruyen[41];
	char TacGia[31];
	char TheLoai[25];
	int SoLuong;
	float GiaThue;
	char NgayThue[11];
} Tr;

void Nhap(Tr &s)
{
	fflush(stdin);
	printf("\nNhap ma truyen: ");
	gets(s.MaTruyen);
	printf("Nhap ten truyen: ");
	gets(s.TenTruyen);
	printf("Nhap ten tac gia: ");
	gets(s.TacGia);
	printf("Nhap the loai: ");
	gets(s.TheLoai);
	printf("Nhap gia ban: ");
	scanf("%f", &s.GiaThue);
	printf("Nhap so luong: ");
	scanf("%d", &s.SoLuong);
	printf("Nhap ngay thue:\n");
	fflush(stdin);
	gets(s.NgayThue);
}
void Xuat(Tr t)
{
	printf("%-12s", t.MaTruyen);
	printf("%-41s", t.TenTruyen);
	printf("%-31s", t.TacGia);
	printf("%-25s", t.TheLoai);
	printf("%-12d", t.SoLuong);
	printf("%-14.2f", t.GiaThue);
	printf("%-13s\n", t.NgayThue);
}
struct Stack
{
	Tr info; //so phan tu n
	struct Stack *next;
};
typedef Stack *S;
void Init(S &s)
{
	s = NULL;
}
bool IsEmpty(S s)
{
	return s == NULL;
}
S CreateNode(Tr x)
{
	S p = new Stack;
	p->info = x;
	p->next = NULL;
	return p;
}
void InsertFirst(S &s, S pNew)
{
	if (IsEmpty(s))
		s = pNew;
	else
	{
		pNew->next = s;
		s = pNew;
	}
}

bool Push(S &s, Tr newItem)
{
	S pNew = CreateNode(newItem);
	InsertFirst(s, pNew);
}
bool Pop(S &s, Tr &outItem)
{
	if (s == NULL)
		return false;
	S pTop = s;
	s = s->next;
	outItem = pTop->info;
	delete pTop;
	return true;
}
bool Top(S &s, Tr &outItem)
{
	if (s == NULL)
		return false;
	S pTop = s;
	s = s->next;
	outItem = pTop->info;
	return true;
}
void Swap(Tr &x, Tr &y)
{
	Tr t = x;
	x = y;
	y = t;
}
S SearchNode(S s, char x[11])
{
	S pTop = s;
	while (pTop != NULL)
	{
		if (strcmp(pTop->info.TenTruyen, x) == 0)
		{
			return pTop;
			break;
		}
		pTop = pTop->next;
	}
	return NULL;
}

void Them_Truyen(S &s)
{
	int n;
	Tr t;
	printf("\nSo truyen can them: ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		Nhap(t);
		S pTmp = CreateNode(t);
		InsertFirst(s, pTmp);
	}
}
// Tim truyen theo ten tac gia
void Tim_Truyen_Theo_TG(S s, char x[21])
{
	S pTop = s;
	while (pTop != NULL)
	{
		if (strcmp(pTop->info.TacGia, x) == 0)
		{
			Xuat(pTop->info);
		}
		pTop = pTop->next;
	}
}
// Tim truyen theo ten X
S Tim_Truyen_Co_TenX(S s, char X[])
{
	S pTop = s;
	while (pTop != NULL)
	{
		if (strcmp(pTop->info.TenTruyen, X) == 0)
			return pTop;
		pTop = pTop->next;
	}
	return NULL;
}
// Tim truyen co gia thue dat nhat
S TimTruyenGiaMax(S s)
{
	S pTop = s;
	S pM = pTop;
	S pi = pTop->next;
	while (pi != NULL) //while(i<n)
	{
		if (pi->info.GiaThue > pM->info.GiaThue)
		{
			pM = pi;
		}
		pi = pi->next;
	}
	return pM;
}
// Tim truyen co gia thue re nhat
S TimTruyenGiaMin(S s)
{
	S pTop = s;
	S pM = pTop;
	S pi = pTop->next;
	while (pi != NULL) //while(i<n)
	{
		if (pi->info.GiaThue < pM->info.GiaThue)
		{
			pM = pi;
		}
		pi = pi->next;
	}
	return pM;
}
// Dem tong so luong truyen
int TongSLTruyen(S s)
{
	S p;
	int dem = 0;
	p = s;
	while (p->next != NULL)
	{
		dem += p->info.SoLuong;
		p = p->next;
	}
	return dem;
}
// Xoa phan tu cuoi
void Xoa_Sau_Node(S &s, S p)
{
	S pSau1 = p->next;
	if (pSau1 == NULL)
		p = NULL; //p la phan tu Last or DS chi co 1 phan tu duy nhat
	S pSau2 = pSau1->next;
	Swap(p->info, pSau1->info);
	p->next = pSau2;
	delete pSau1;
}
// Xoa 1 quyen truyen theo ten X
bool Xoa_1_Truyen(S &s, char x[11])
{
	S p = SearchNode(s, x);
	if (p == NULL)
		return false;
	Xoa_Sau_Node(s, p);
	return true;
}
// Tim truyen co so luong max
int Tim_Truyen_SL_Max(S s)
{
	S pTop = s;
	S pM = pTop;
	S pi = pTop->next;
	while (pi->next != NULL)
	{
		if (pi->info.SoLuong > pM->info.SoLuong)
		{
			pM = pi;
			Xuat(pM->info);
		}
		pi = pi->next;
	}
}
void Input(S &s)
{
	Tr t;
	Init(s);
	int n;
	printf("\nMoi nhap so truyen n= ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\n Nhap thong tin truyen thu %d: ", i + 1);
		Nhap(t);
		Push(s, t);
	}
}

void Output(S s)
{
	while (!IsEmpty(s))
	{
		Tr t;
		Top(s, t);
		Xuat(t);
	}
}
// Ham xoa khoang trang
void DellSpace(char s[])
{
	while (s[0] == ' ')
		strcpy(&s[0], &s[1]);
	while (s[strlen(s) - 1] == ' ')
		s[strlen(s) - 1] = '\0';
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
}

// Ghi du lieu vao file
int DocFile(S &s)
{
	FILE *f = fopen("Truyen.inp", "r");
	if (f == NULL)
		return 0;
	int i = 0;
	while (1)
	{
		if (feof(f) != 0)
			break;

		Tr t;
		fscanf(f, "%13s", t.MaTruyen);
		DellSpace(t.MaTruyen);
		fscanf(f, "%41[^\n]", t.TenTruyen);
		DellSpace(t.TenTruyen);
		fscanf(f, "%31[^\n]", t.TacGia);
		DellSpace(t.TacGia);
		fscanf(f, "%25[^\n]", t.TheLoai);
		DellSpace(t.TheLoai);

		fscanf(f, "%12d\n ", &t.SoLuong);
		fscanf(f, "%14f\n ", &t.GiaThue);
		fscanf(f, "%12s", t.NgayThue);
		DellSpace(t.NgayThue);

		Push(s, t);
	}
	fclose(f);
	return 1;
}

void DongDauTienMenu()
{
	printf("\n%c", 218);
	for (int i = 0; i < 60; i++)
		printf("%c", 196);
	printf("%c", 191);
}
void DongGiuaMenu()
{
	printf("%c", 195);
	for (int i = 0; i < 60; i++)
		printf("%c", 196);
	printf("%c", 180);
}
void DongCuoiMenu()
{
	printf("\n%c", 192);
	for (int i = 0; i < 60; i++)
		printf("%c", 196);
	printf("%c", 217);
}

int Menu()
{

	DongDauTienMenu();
	printf("\n%c============================= MENU =========================%c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c 1 - Them thong tin truyen vao danh sach.                   %c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c 2 - Xoa thong tin 1 quyen truyen trong danh sach.          %c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c 3 - Tim truyen theo ten.                                   %c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c 4 - Tim truyen theo ten tac gia.                           %c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c 5 - Dem tong so luong truyen co trong kho.                 %c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c 6 - Tim truyen co so luong nhieu nhat.                     %c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c 7 - Tim truyen co gia thue re nhat.                        %c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c 8 - Tim truyen co gia thue dat nhat.                       %c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c 9 - Thoat.                                                 %c\n", 179, 179);
	DongGiuaMenu();
	printf("\n%c============================================================%c", 179, 179);
	DongCuoiMenu();
	printf(" \n>> Chon chuc nang: ");
	int chon;
	scanf("%d", &chon);
	return chon;
}

void Xuly(S s, int chon)
{
	char x[21], c[21];
	S t, g, tmax, tmin;
	switch (chon)
	{
	case 1:
		printf("Nhap thong tin Truyen can them:\n");
		Them_Truyen(s);
		Output(s);
		break;
	case 2:
		printf("\nnhap ten can xoa");
		rewind(stdin);
		gets(x);
		if (Xoa_1_Truyen(s, x) == true)
			Output(s);
		else
			printf("\nko co ten can xoa trong danh sach");
		break;
	case 3:
		printf("Nhap ten truyen can tim:");
		rewind(stdin);
		gets(c);
		g = Tim_Truyen_Co_TenX(s, c);
		Xuat(g->info);
		break;
	case 4:
		printf("\nNhap ten tac gia can tim: ");
		rewind(stdin);
		gets(x);
		Tim_Truyen_Theo_TG(s, x);
		break;
	case 5:
		printf("Tong so luong truyen co trong kho:%d", TongSLTruyen(s));
		break;
	case 6:
		printf("Truyen co so luong lon nhat la:\n");
		Tim_Truyen_SL_Max(s);
		break;
	case 7:
		tmin = TimTruyenGiaMin(s);
		printf("\nTruyen co gia thue re nhat la:\n ");
		Xuat(tmin->info);
		break;
		break;
	case 8:
		tmax = TimTruyenGiaMax(s);
		printf("\nTruyen co gia thue cao nhat la:\n ");
		Xuat(tmax->info);
		break;
	default:
		printf("Nhap chuc nang sai. Vui long nhap lai!\n");
	}
}
int main()
{
	S s;
	Init(s);
	if (DocFile(s) == 0)
		printf("Doc file that bai!");
	else
		Output(s);
	while (true)
	{
		int chon = Menu();
		if (chon == 9)
			break;
		Xuly(s, chon);
	}
	return 0;
}
