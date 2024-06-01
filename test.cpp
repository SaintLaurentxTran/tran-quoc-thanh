#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


typedef struct {
    char ma_sach[20];
    char ten_sach[100];
    char ten_tac_gia[100];
    char loai_sach[20];
    int nam_xuat_ban;
    float gia_tien;
    int so_luong;
} Sach;


Sach danh_sach_sach[MAX];
int so_luong_sach = 0;


void nhapSach() {
    if (so_luong_sach < MAX) {
        Sach sach;
        printf("Nhap ma sach: ");
        scanf("%s", sach.ma_sach);
        printf("Nhap ten sach: ");
        scanf(" %[^\n]s", sach.ten_sach);
        printf("Nhap ten tac gia: ");
        scanf(" %[^\n]s", sach.ten_tac_gia);
        printf("Nhap loai sach (Tu nhien hoac Xa hoi): ");
        scanf("%s", sach.loai_sach);
        printf("Nhap nam xuat ban: ");
        scanf("%d", &sach.nam_xuat_ban);
        printf("Nhap gia tien: ");
        scanf("%f", &sach.gia_tien);
        printf("Nhap so luong: ");
        scanf("%d", &sach.so_luong);

        danh_sach_sach[so_luong_sach++] = sach;
        printf("Da them sach thanh cong.\n");
    } else {
        printf("Danh sach da day, khong the them sach moi.\n");
    }
}

// Hàm xu?t thông tin c?a m?t cu?n sách
void xuatSach(Sach sach) {
    printf("Ma sach: %s\n", sach.ma_sach);
    printf("Ten sach: %s\n", sach.ten_sach);
    printf("Ten tac gia: %s\n", sach.ten_tac_gia);
    printf("Loai sach: %s\n", sach.loai_sach);
    printf("Nam xuat ban: %d\n", sach.nam_xuat_ban);
    printf("Gia tien: %.2f\n", sach.gia_tien);
    printf("So luong: %d\n", sach.so_luong);
    printf("\n");
}


void xuatDanhSachSach() {
    printf("Danh sach sach:\n");
    for (int i = 0; i < so_luong_sach; i++) {
        printf("Sach %d:\n", i + 1);
        xuatSach(danh_sach_sach[i]);
    }
}


float tinhTongThanhTien() {
    float tong = 0;
    for (int i = 0; i < so_luong_sach; i++) {
        tong += danh_sach_sach[i].gia_tien * danh_sach_sach[i].so_luong;
    }
    return tong;
}


void sapXepTheoMaSach() {
    for (int i = 0; i < so_luong_sach - 1; i++) {
        for (int j = i + 1; j < so_luong_sach; j++) {
            if (strcmp(danh_sach_sach[i].ma_sach, danh_sach_sach[j].ma_sach) > 0) {
                Sach temp = danh_sach_sach[i];
                danh_sach_sach[i] = danh_sach_sach[j];
                danh_sach_sach[j] = temp;
            }
        }
    }
}

void timSachTheoTen() {
    char ten_sach[100];
    printf("Nhap ten sach can tim: ");
    scanf(" %[^\n]s", ten_sach);

    int tim_thay = 0;
    printf("Cac sach co ten \"%s\":\n", ten_sach);
    for (int i = 0; i < so_luong_sach; i++) {
        if (strstr(danh_sach_sach[i].ten_sach, ten_sach) != NULL) {
            xuatSach(danh_sach_sach[i]);
            tim_thay = 1;
        }
    }
    if (!tim_thay) {
        printf("Khong tim thay sach nao.\n");
    }
}

void xuatSachTruocNam2000() {
    printf("Cac sach co nam xuat ban truoc nam 2000:\n");
    for (int i = 0; i < so_luong_sach; i++) {
        if (danh_sach_sach[i].nam_xuat_ban < 2000) {
            xuatSach(danh_sach_sach[i]);
        }
    }
}


int demSachGiaTienLonHon50000() {
    int dem = 0;
    for (int i = 0; i < so_luong_sach; i++) {
        if (danh_sach_sach[i].gia_tien > 50000) {
            dem++;
        }
    }
    return dem;
}


void xuatSachTheoLoai() {
    char loai[20];
    printf("Nhap loai sach muon xuat (Tu nhien hoac Xa hoi): ");
    scanf("%s", loai);

    printf("Cac sach thuoc loai \"%s\":\n", loai);
    for (int i = 0; i < so_luong_sach; i++) {
        if (strcmp(danh_sach_sach[i].loai_sach, loai) == 0) {
            xuatSach(danh_sach_sach[i]);
        }
    }
}

int main() {
    char lua_chon;
    do {
        printf("MENU:\n");
        printf("a. Nhap sach\n");
        printf("b. Xuat sach\n");
        printf("c. Them mot cuon sach\n");
        printf("d. Tinh tong thanh tien cac cuon sach\n");
        printf("e. Sap xep cac cuon sach theo ma sach\n");
        printf("f. Tim sach theo ten sach\n");
        printf("g. Xuat cac cuon sach co nam xuat ban truoc nam 2000\n");
        printf("h. Dem so luong sach co gia lon hon 50000\n");
        printf("i. Xuat cac cuon sach theo loai\n");
        printf("x. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf(" %c", &lua_chon);

        switch (lua_chon) {
            case 'a':
                printf("Nhap thong tin cac cuon sach:\n");
                nhapSach();
                break;
            case 'b':
                xuatDanhSachSach();
                break;
            case 'c':
                printf("Nhap thong tin mot cuon sach:\n");
                nhapSach();
                break;
            case 'd':
                printf("Tong thanh tien cua tat ca cac cuon sach la: %.2f\n", tinhTongThanhTien());
                break;
            case 'e':
                sapXepTheoMaSach();
                printf("Da sap xep cac cuon sach theo ma sach.\n");
                break;
            case 'f':
                timSachTheoTen();
                break;
            case 'g':
                xuatSachTruocNam2000();
                break;
            case 'h':
                printf("So luong sach co gia lon hon 50000 la: %d\n", demSachGiaTienLonHon50000());
                break;
            case 'i':
                xuatSachTheoLoai();
                break;
            case 'x':
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (lua_chon != 'x');

    return 0;
}

