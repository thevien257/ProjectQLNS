#include "TruongPhong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

TruongPhong::TruongPhong()
{
  this->soLuongNhanVien = 0;
}

TruongPhong::TruongPhong(string maSo,
                         string hoTen,
                         string soDienThoai,
                         float soNgayLamViec) : NhanSu(maSo, hoTen, soDienThoai, soNgayLamViec)
{
  this->soLuongNhanVien = 0;
}

string TruongPhong::getTenTP()
{
  return this->hoTen;
}

string TruongPhong::getMaSo()
{
  return this->maSo;
}

void TruongPhong::nhap()
{
  NhanSu::nhap();
}

void TruongPhong::xuat()
{
  NhanSu::xuat();
  ofstream output("DanhSachNhanVien.txt", ios::app);
  cout << "\t\t\t|So luong nhan vien\t| " << this->soLuongNhanVien << "\t\t|" << endl;
  cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
  cout << "\t\t\t_________________________________________" << endl;

  output << "So luong nhan vien:"
         << "\t" << this->soLuongNhanVien << endl;
  output << "Luong:"
         << "\t" << this->luong << endl;
  output << endl;
}

void TruongPhong::tangNhanVien()
{
  this->soLuongNhanVien++;
}

void TruongPhong::giamNhanVien()
{
  this->soLuongNhanVien--;
}

void TruongPhong::tinhLuong()
{
  this->luong = luong1NgayTP * this->soNgayLamViec + 100 * this->soLuongNhanVien;
}
