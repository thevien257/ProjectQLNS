#include "TruongPhong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

// istream &operator>>(istream &is, TruongPhong &tp)
// {
//   // Read data from the input stream and populate the ns object
//   is >> tp.hoTen >> tp.maSo >> tp.luong >> tp.soDienThoai >> tp.soNgayLamViec;
//   return is;
// }

void TruongPhong::setListNV(std::vector<NhanVienThuong *> listNV)
{
  this->listNV = listNV;
}

string TruongPhong::getMaPhongBan()
{
  return maPhongBan;
}

ostream &operator<<(ostream &os, const TruongPhong &tp)
{
  os << "Ho ten: " << tp.hoTen << endl;
  os << "Ma so: " << tp.maSo << endl;
  os << "So dien thoai: " << tp.soDienThoai << endl;
  os << "Ngay lam viec: " << tp.soNgayLamViec << endl;
  if (tp.soLuongNhanVien > 0)
  {
    os << "So luong nhan vien: " << tp.soLuongNhanVien << endl;
    os << "___________Dang quan ly cac nhan vien sau:__________" << endl;
    for (NhanVienThuong *nvt : tp.listNV)
    {
      os << "Ho va ten: " << nvt->getHoTen() << endl;
      os << "Ma so: " << nvt->getMaSo() << endl;
    }
  }
  os << endl;
  return os;
}

vector<NhanVienThuong *> &TruongPhong::getListNV() // Dùng & vì ở class khác nhau mới thay đổi được và để tránh tạo bản copy
{
  return listNV;
}

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
  // ofstream output("DanhSachNhanVien.txt", ios::app);
  if (soLuongNhanVien <= 0)
  {
    cout << "\t\t\t|So luong nhan vien\t| " << this->soLuongNhanVien << "\t\t|" << endl;
    cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
    cout << "\t\t\t_________________________________________" << endl;
  }
  else
  {
    cout << "\t\t\t|So luong nhan vien\t| " << this->soLuongNhanVien << "\t\t|" << endl;
    cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
    cout << "\t\t\t|____DANG QUAN LY CAC NHAN VIEN____"
         << "\t|" << endl;
    for (NhanVienThuong *nv : listNV)
    {
      cout << "\t\t\t|Ten nhan vien\t| " << nv->getHoTen() << "\t|" << endl;
      cout << "\t\t\t|Ma so nhan vien\t| " << nv->getMaSo() << "\t|" << endl;
    }
    cout << "\t\t\t_________________________________________" << endl;
  }
  // output << "So luong nhan vien:"
  //        << "\t" << this->soLuongNhanVien << endl;
  // output << "Luong:"
  //        << "\t" << this->luong << endl;
  // output << endl;
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
