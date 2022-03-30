#include<stdio.h>//tin
#include<string.h>
typedef struct{
	int ngay,thang,nam;
}date;
void NhapNgaySinh(date &ngaysinh)
{
	scanf("%d%d%d",&ngaysinh.ngay,&ngaysinh.thang,&ngaysinh.nam);	
}

void outputDate(date date1)
{
	printf("\nNgay sinh: %d/%d/%d", date1.ngay, date1.thang, date1.nam);
}

typedef struct sinhvien{
	char masv[10];
	char hoten[100];
	float diemTHDC,diemKTLT;
	date ngaysinh;
}S;
struct giangvien{
	char magv[10];
	char hoten[100];
	date ngaysinh;
};
struct monhoc{
	char mamonhoc[10];
	char tenmonhoc[15];
	int TC;
};
void Nhap(struct sinhvien &a){
	printf("Nhap ten sinh vien: ");
	fflush(stdin);
	gets(a.hoten);
	printf("\nNhap ma sinh vien: ");
	fflush(stdin);
	scanf("%s", &a.masv);
	printf("\nNhap ngay sinh: ");
	NhapNgaySinh(a.ngaysinh);
	printf("\nNhap diem TDHC: ");
	scanf("%f",&a.diemTHDC);
	printf("\nNhap diem KTLT: ");
	scanf("%f",&a.diemKTLT);
}
void NhapDanhSach(struct sinhvien DS[], int n){
	for(int i=0; i<n; i++){
		printf("\nNhap sinh vien thu %d: \n", i+1);
		Nhap(DS[i]);
	}
}
void Xuat(struct sinhvien a){
	printf("\tTen sinh vien: %s\n", a.hoten);
	printf("\tMa so sinh vien: %s\n\t", a.masv);
	outputDate(a.ngaysinh);
	printf("\tDiem THDC va KTLT: %.2f  %.2f",a.diemTHDC,a.diemKTLT);
}
void XuatDanhSach(struct sinhvien DS[], int n){
	printf("\n*****************************\n");
	for(int i=0; i<n; i++){
		printf("\nThong tin sinh vien thu %d:\n",i+1);
		Xuat(DS[i]);
	}
}
void Nhap2(struct giangvien &b){
	printf("\nNhap ten giang vien: ");
	fflush(stdin);
	gets(b.hoten);
	printf("\nNhap ma giang vien: ");
	fflush(stdin);
	scanf("%s", &b.magv);
	printf("\nNhap ngay sinh: ");
	NhapNgaySinh(b.ngaysinh);
}
void NhapDanhSach2(struct giangvien DS2[], int n){
	for(int i=0; i<n; i++){
		printf("Nhap giang vien thu %d: \n", i+1);
		Nhap2(DS2[i]);
	}
}
void Xuat2(struct giangvien b){
	printf("\tTen giang vien: %s\n", b.hoten);
	printf("\tMa so giang vien: %s\n", b.magv);
	outputDate(b.ngaysinh);
}
void XuatDanhSach2(struct giangvien DS2[], int n){
	printf("\n*****************************\n");
	for(int i=0; i<n; i++){
		printf("Thong tin giang vien thu %d:\n",i+1);
		Xuat2(DS2[i]);
	}
}
void Nhap3(struct monhoc &c){
	printf("Nhap ten mon hoc: ");
	fflush(stdin);
	gets(c.mamonhoc);
	printf("Nhap ma mon hoc: ");
	fflush(stdin);
	scanf("%s",&c.tenmonhoc);
	printf("Nhap so tin chi: ");
	scanf("%d",&c.TC);
}
void NhapDanhSach3(struct monhoc DS3[], int n){
	for(int i=0; i<n; i++){
		printf("Nhap mon hoc thu %d: \n", i+1);
		Nhap3(DS3[i]);
	}
}
void Xuat3(struct monhoc c){
	printf("\tTen mon hoc: %s\n", c.tenmonhoc);
	printf("\tMa mon hoc: %s\n", c.mamonhoc);
	printf("\tSo tin chi: %d\n", c.TC);
}
void XuatDanhSach3(struct monhoc DS3[], int n){
	printf("\n*****************************\n");
	for(int i=0; i<n; i++){
		printf("Thong mon hoc thu %d:\n",i+1);
		Xuat3(DS3[i]);
	}
}
void DoiCho(int &a,int &b){
	int hoandoi=a;
	a=b;
	b=hoandoi;
}
// sap xep theo nam sinh
void sx(sinhvien a[100],int n){
	for(int i = 0;i < n - 1;i++){
		for(int j = i+1;j < n;j++){
			if(a[i].ngaysinh.nam > a[j].ngaysinh.nam)
				DoiCho(a[i].ngaysinh.nam,a[j].ngaysinh.nam);
			else if (a[i].ngaysinh.nam = a[j].ngaysinh.nam){
				if(a[i].ngaysinh.thang > a[j].ngaysinh.thang)
					DoiCho(a[i].ngaysinh.thang,a[j].ngaysinh.thang);
				else if(a[i].ngaysinh.thang=a[i].ngaysinh.thang){
					if(a[i].ngaysinh.ngay>a[j].ngaysinh.ngay){
						DoiCho(a[i].ngaysinh.ngay,a[j].ngaysinh.ngay);
					}
				}
			}
	}
		
}
}
int main(){
	struct sinhvien a[100];
	struct giangvien b[100];
	struct monhoc c[50];
	int d,e,f;
	/*printf("Nhap so sinh vien: ");
	scanf("%d",&d);
	NhapDanhSach(a,d);
    XuatDanhSach(a,d);
    */
    printf("\nNhap so giang vien: ");
    scanf("%d",&e);
    NhapDanhSach2(b,e);
    XuatDanhSach2(b,e);
	printf("Nhap so mon hoc: ");
    scanf("%d",&f);
    //NhapDanhSach3(c,f);
	//XuatDanhSach3(c,f);
}
//caoductin
//anhhao
