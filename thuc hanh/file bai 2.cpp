#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct ngay{
	int ngay;
	int thang;
	int nam;
}DATE;
typedef struct sinhvien{
	double masv;
	char hoten[50];
	char gt;
	DATE ngaysinh;
	char lop[7];
	float dtb;
}SV;
//Ham nhap 01 sinh vien
void Nhap1SV(SV &x)
{
	printf("\nNhap ma sinh vien: ");
	scanf("%lf", &x.masv);
	fflush(stdin);
	printf("\nNhap ho ten: ");
	gets(x.hoten);
	printf("\nNhap gioi tinh: ");
	scanf("%c", &x.gt);
	printf("\nNhap ngay sinh: ");
	scanf("%d %d %d", &x.ngaysinh.ngay, &x.ngaysinh.thang, &x.ngaysinh.nam);
	fflush(stdin);
	printf("\nNhap lop: ");
	gets(x.lop);
	printf("\nNhap dtb: ");
	scanf("%f", &x.dtb);
}
//Nhap danh sach sinh vien
void NhapDSSV(SV a[], int &n)
{
	printf("\nNhap so sinh vien: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		Nhap1SV(a[i]);
	}
}
//Ham xuat 01 sinh vien
void Xuat1SV(SV x)
{
	printf("\nMa sinh vien: %.0lf", x.masv);
	printf("\nHo ten: %s", x.hoten);
	if(x.gt == 'x')
	{
		printf("\nGioi tinh: Nu");
	}
	else printf("\nGioi tinh: Nam");
	printf("\nNgay sinh: %d/%d/%d", x.ngaysinh.ngay, x.ngaysinh.thang, x.ngaysinh.nam);
	printf("\nLop: %s", x.lop);
	printf("\nDtb: %.1f", x.dtb);
}
//Ham xuat danh sach sinh vien
void XuatDSSV(SV a[], int n)
{
	printf("\n***DANH SACH SINH VIEN***");
	for(int i=0; i<n; i++)
	{
		printf("\nThong tin cua sinh vien %d", i+1);
		Xuat1SV(a[i]);
	}
}
//Xuat sinh vien co dtb > 5
void XuatSV_DTB5(SV a[], int n)
{
	for(int i=0; i<n; i++)
	{
		if(a[i].dtb > 5)
			Xuat1SV(a[i]);
	}
}
//Xuat sinh vien cua Nganh CNTT
void XuatSV_CNTT(SV a[], int n)
{
	for(int i=0; i<n; i++)
	{
		if(strstr(a[i].lop,"TH")!= NULL)
			Xuat1SV(a[i]);
	}
}
//Ham tra ve DTB MAX
float DTB_MAX(SV a[], int n)
{
	float max = a[0].dtb;
	for(int i=1; i<n; i++)
	{
		if(a[i].dtb > max)
			max = a[i].dtb;
	}
	return max;
}
int main()
{
	SV a[MAX];
	int n;
	NhapDSSV(a,n);
	XuatDSSV(a,n);
	XuatSV_CNTT(a,n);
	return 0;
}
