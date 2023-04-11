#include "NhanVienThuong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

void NhanVienThuong::setTruongPhong(TruongPhong *tp)
{
  this->tp = tp;
}

NhanVienThuong::NhanVienThuong()
{
  tp = nullptr;
}

NhanVienThuong::NhanVienThuong(string maSo, string hoTen, string soDienThoai, float soNgayLamViec) : NhanSu(maSo, hoTen, soDienThoai, soNgayLamViec)
{
}

void NhanVienThuong::tinhLuong()
{
  this->luong = luong1NgayNVT * this->soNgayLamViec;
}

void NhanVienThuong::nhap()
{
  NhanSu::nhap();
}

void NhanVienThuong::xuat()
{
  if (tp != nullptr)
  {
    NhanSu::xuat();
    ofstream output("DanhSachNhanVien.txt", ios::app);
    cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
    cout << "\t\t\t|____Day la thong tin nguoi quan ly____"
         << "\t|" << endl;
    cout << "\t\t\t|Ten truong phong\t| " << tp->getHoTen() << "\t\t|" << endl;
    cout << "\t\t\t|Ma truong phong\t| " << tp->getMaSo() << "\t\t|" << endl;
    cout << "\t\t\t_________________________________________" << endl;

    output << "Luong:"
           << "\t" << this->luong << endl;
    output << "___________Thong tin nguoi quan ly__________" << endl;
    output << "Ten truong phong: "
           << "\t" << this->hoTen << endl;
    output << "Ma truong phong:"
           << "\t" << this->getMaSo() << endl;
    output << endl;
  }
  else if (tp == nullptr)
  {
    NhanSu::xuat();
    ofstream output("DanhSachNhanVien.txt", ios::app);
    cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
    cout << "\t\t\t_________________________________________" << endl;

    output << "Luong:"
           << "\t" << this->luong << endl;
    output << endl;
  }
}
