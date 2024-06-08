#include<stdio.h>
#include<string.h>
#define MAX 100
//typedef struct date{
//	int ngay;
//	int thang;
//	int nam;
//}DATE;
typedef struct sinhvien{
	char HoTen[50];
	char MaSo[20];
	char ngaysinh[15];
	char GioiTinh[5];
	char Lop[5];
	float DiemToan;
	float DiemLy;
	float DiemTin;
}SV;
void nhap1SV(SV *x) {
    printf("\nNhap ho ten: ");
    scanf("%s", x->HoTen);
    printf("\nNhap ma so: ");
    scanf("%s", &x->MaSo);
    printf("\nNhap ngay thang nam sinh: ");
    scanf("%s", x->ngaysinh);
    printf("\nNhap gioi tinh: ");
    scanf("%s", x->GioiTinh);
    printf("\nNhap lop: ");
    scanf("%s", x->Lop);
    printf("\nNhap diem toan: ");
    scanf("%f", &x->DiemToan);
    printf("\nNhap diem ly: ");
    scanf("%f", &x->DiemLy);
    printf("\nNhap diem tin: ");
    scanf("%f", &x->DiemTin);
}

void xuat1SV(SV x) {
    printf("Ho ten: %s\n", x.HoTen);
    printf("Ma so: %s\n", x.MaSo);
    printf("Ngay thang nam sinh: %s\n", x.ngaysinh);
    printf("Gioi tinh: %s\n", x.GioiTinh);
    printf("Lop: %s\n", x.Lop);
    printf("Diem toan: %.2f\n", x.DiemToan);
    printf("Diem ly: %.2f\n", x.DiemLy);
    printf("Diem tin: %.2f\n", x.DiemTin);
}
void nhapDS(SV a[], int *n) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        nhap1SV(&a[i]);
    }
}
void xuatDS(SV a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nThong tin sinh vien thu %d:\n", i + 1);
        xuat1SV(a[i]);
    }
}
void xuatSVtheomaso(SV a[], int n, char *MaSo) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].MaSo , MaSo) == 0) {
            printf("\nThong tin sinh vien co ma so %s:\n", MaSo);
            xuat1SV(a[i]);
            return;
        }
    }
    printf("\nKhong tim thay sinh vien co ma so %s.\n", MaSo);
}
void xuatDSsinhvienCNTT(SV a[], int n) {
    printf("\nDanh sach sinh vien nganh Cong nghe Thong tin:\n");
    for (int i = 0; i < n; i++) {
        if (strstr(a[i].Lop, "CNTT") != NULL) {
            xuat1SV(a[i]);
        }
    }
}
void xuatDSsinhviennuCNTT(SV a[], int n) {
    printf("\nDanh sach sinh vien nu nganh Cong nghe Thong tin:\n");
    for (int i = 0; i < n; i++) {
        if (strstr(a[i].Lop, "CNTT") != NULL && strcmpi(a[i].GioiTinh, "nu") == 0) {
            xuat1SV(a[i]);
        }
    }
}
void timSVtheoten(SV a[], int n, char *ten) {
    printf("\nKet qua tim kiem sinh vien co ten chua \"%s\":\n", ten);
    for (int i = 0; i < n; i++) {
        if (strstr(a[i].HoTen, ten) != NULL) {
            xuat1SV(a[i]);
        }
    }
}

int main(){
	SV a[MAX];
	int n;
	nhapDS(a,&n);
	xuatDS(a,n);
	char masotimkiem[20];
    printf("\nNhap ma so sinh vien can tim kiem: ");
    scanf("%s", masotimkiem);
	xuatSVtheomaso(a,n,masotimkiem);
	xuatDSsinhvienCNTT(a,n);
	xuatDSsinhviennuCNTT(a,n);
	char tentimkiem[50];
    printf("\nNhap ten sinh vien can tim kiem: ");
    scanf("%s", tentimkiem);
    timSVtheoten(a, n, tentimkiem);
	return 0;
}
