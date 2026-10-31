#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

struct cuaHang{
    int maHang;
    char tenMatHang[50];
    int soLuong;
    float donGia;
};



int main(){
    struct cuaHang khoHang[MAX_SIZE];
    
    int n = 0; // bien tam dem phan tu cua mang
    int chon;

    while(1){
        printf("\n==== QUAN LY MAT HANG =====\n");
        printf("1. Them mat hang\n");
        printf("2. Hien thi danh sach mat hang\n");
        printf("3. Cap nhat hang theo ma\n");
        printf("4. Xoa mat hang theo ma\n");
        printf("5. Tim kiem mat hang theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");
        printf("==============================\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);

        switch(chon){
            case 1:{
                int maHangThem;
                char tenMatHangThem[50];
                int soLuongThem;
                float donGiaThem;
            
                printf("Them mat hang\n");
                
                if (n >= MAX_SIZE){
                    printf("Danh sach da day\n");
                    return 0;
                }

                printf("Nhap ma mat hang: ");
                scanf("%d", &maHangThem);
                getchar();

                printf("Nhap ten mat hang: ");
                fgets(tenMatHangThem, sizeof(tenMatHangThem), stdin);
                tenMatHangThem[strcspn(tenMatHangThem, "\n")] = '\0';

                printf("Nhap so luong mat hang: ");
                scanf("%d", &soLuongThem);

                printf("Nhap don gia mat hang: ");
                scanf("%f", &donGiaThem);

                khoHang[n].maHang = maHangThem;
                strcpy(khoHang[n].tenMatHang, tenMatHangThem);
                khoHang[n].soLuong = soLuongThem;
                khoHang[n].donGia = donGiaThem;
                n++;

                printf("Them mat hang thanh cong\n");

                break;
            }
            case 2:{
                printf("Hien thi danh sach mat hang\n");
                if (n == 0){
                    printf("Danh sach rong");
                    return 0;
                }
                printf("----------------------------------\n");
                for ( int i=0; i < n; i++){
                    printf("Ma mat hang: %d\n", khoHang[i].maHang);
                    printf("Ten mat hang: %s\n", khoHang[i].tenMatHang);
                    printf("So luong hang: %d\n", khoHang[i].soLuong);
                    printf("Don gia: %.2f\n",khoHang[i].donGia);
                    printf("----------------------------------\n");
                }

                break;
            }
            case 3:{
                int maHang_cn;
                char tenMH_moi[50];
                int soLuong_moi;
                float donGia_moi;
                int flag_cn = 0;
                printf("Cap nhat hang theo ma\n");
                if (n == 0){
                    printf("Danh sach rong");
                    printf("----------------------------------\n");
                    return 0;
                }

                printf("Nhap ma mat hang can sua: ");
                scanf("%d", &maHang_cn);
                for ( int i = 0; i< n; i++){
                    if ( khoHang[i].maHang == maHang_cn){
                        flag_cn = 1;
                        printf("Tim thay mat hang can cap nhat:");
                        printf("-----------------------------\n");
                        getchar();
                        printf("Nhap ten mat hang moi: ");
                        fgets(tenMH_moi, sizeof(tenMH_moi), stdin);
                        tenMH_moi[strcspn(tenMH_moi, "\n")] = '\0';

                        printf("Nhap so luong mat hang moi: ");
                        scanf("%d", &soLuong_moi);

                        printf("Nhap don gia moi: ");
                        scanf("%f", &donGia_moi);

                        strcpy(khoHang[i].tenMatHang,tenMH_moi);
                        khoHang[i].soLuong = soLuong_moi;
                        khoHang[i].donGia = donGia_moi;

                        printf("Cap nhat thanh cong\n");
                        break;
                    }
                }

                if(flag_cn == 0){
                    printf("Khong tim thay mat hang\n");
                    break;
                }
                break;
            }
            case 4:{
                int maMH_xoa;
                int flag_xoa = 0;
                printf("Xoa mat hang theo ma\n");
                if (n == 0){
                    printf("Danh sach rong");
                    printf("----------------------------------\n");
                    return 0;
                }
                printf("Nhap mang ma can xoa: ");
                scanf("%d", &maMH_xoa);

                for (int i = 0; i < n; i++){
                    if ( khoHang[i].maHang == maMH_xoa){
                        flag_xoa = 1;
                        for( int j = i; j < n -1; j++){
                            khoHang[j] = khoHang[j-1];
                            printf("Xoa thanh cong");
                            n--;
                        }
                    }
                }
                if (!flag_xoa){
                    printf("Khong tim thay ma can xoa\n");
                }

                break;
            }
            case 5:{
                char ten_tim[50];
                int flag = 0;
                printf("Tim kiem mat hang theo ten\n");
                if (n == 0){
                    printf("Danh sach rong");
                    printf("----------------------------------\n");
                    return 0;
                }
                getchar();
                printf("Nhap ten mat hang can tim: ");
                fgets(ten_tim,sizeof(ten_tim), stdin);
                ten_tim[strcspn(ten_tim, "\n")] = '\0';

                for(int i = 0 ; i < n ; i++){
                    if(strstr(khoHang[i].tenMatHang, ten_tim) != NULL){
                        flag = 1;
                        printf("Da tim thay!\n");
                        printf("Ma mat hang: %d\n", khoHang[i].maHang);
                        printf("Ten mat hang: %s\n", khoHang[i].tenMatHang);
                        printf("So luong hang: %d\n", khoHang[i].soLuong);
                        printf("Don gia: %.2f\n",khoHang[i].donGia);
                        printf("----------------------------------\n");
                        break;
                    }
                }
                if ( !flag){
                    printf("Khong tim thay ma hang hop le\n");
                    break;
                }

                break;
            }
            case 6:{
                printf("Thong ke kho hang\n");
                break;
            }
            case 0:{
                printf("Tam biet!\n");
                return 0;
            }
            default:
            printf("Lua chon khong hop le\n");
            break;
        }
    }

    return 0;
};
