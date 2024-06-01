#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct thongTinSach {
	int maSach;
	char tenSach[50];
	char tenTacGia[50];
	char loaiSach[10];
	int namXuatBan;
	int giaTien;
}TTSACH;

void nhap1Sach(TTSACH &x)
{
	printf("\nNhap ma sach: ");
	scanf("%d", &x.maSach);
	fflush(stdin);
	printf("\nNhap ten sach: ");
	gets(x.tenSach);
	fflush(stdin);
	printf("\nNhap ten tac gia: ");
	gets(x.tenTacGia);
	fflush(stdin);
	printf("\nNhap loai sach: ");
	gets(x.loaiSach);
	printf("\nNhap nam xuat ban: ");
	scanf("%d", &x.namXuatBan);
	printf("\nNhap gia tien: ");
	scanf("%d", &x.giaTien);
}

void nhapDSS(TTSACH a[], int &n)
{
	printf("\nNhap so luong sach: ");
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		nhap1Sach(a[i]);
	}
}

void xuat1Sach(TTSACH x)
{
	printf("\nMa sach: %d", x.maSach);
	printf("\nTen sach: %s", x.tenSach);
	printf("\nTen tac gia: %s", x.tenTacGia);
	printf("\nLoai sach: %s", x.loaiSach);
	printf("\nNam xuat ban: %d", x.namXuatBan);
	printf("\nGia tien: %d", x.giaTien);
}

void xuatDSS(TTSACH a[], int n)
{
	printf("\n*****Danh sach sach trong cua hang*****");
	for (int i=0; i<n; i++)
	{
		printf("\nThong tin cua sach %d", i+1);
		xuat1Sach(a[i]);
	}
}

int tongTienSach(TTSACH a[], int n)
{
	int totalPrice = 0;
	for (int i=0; i<n; i++)
	{
		totalPrice = totalPrice + a[i].giaTien;
	}
	return totalPrice;
}

void xbTruoc2000(TTSACH a[], int n)
{
  int dem = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i].namXuatBan < 2000)
	{
	  dem++;
      printf("\nSach xuat ban truoc nam 2000");
      printf("\nMa sach: %d", a[i].maSach);
      printf("\nTen sach: %s", a[i].tenSach);
      printf("\nTen tac gia: %s", a[i].tenTacGia);
      printf("\nNam xuat ban: %d", a[i].namXuatBan);
      printf("\nGia tien: %.d", a[i].giaTien);
    }
  }

  if (dem == 0)
  {
    printf("\nKhong co sach nao duoc xuat ban truoc nam 2000.");
  }
}

int slSachHon50000(TTSACH a[], int n)
{
	int dem = 0;
	for (int i=0; i<n; i++)
	{
		if (a[i].giaTien > 50000)
			dem++;
	}
	return dem;
}

int main()
{
	TTSACH a[MAX];
	int n;
	nhapDSS(a,n);
	xuatDSS(a,n);
	printf("%.2f", tongTienSach(a,n));
	xbTruoc2000(a,n);
	printf("\nSo luong sach co gia tien hon 50000: %d", slSachHon50000(a,n));
	
	

	return 0;
}
