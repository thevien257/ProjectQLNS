#include "GiamDoc.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

// istream &operator>>(istream &is, GiamDoc &gd)
// {
//   // Read data from the input stream and populate the ns object
//   is >> gd.hoTen >> gd.maSo >> gd.soDienThoai >> gd.soNgayLamViec;
//   return is;
// }

// ostream &operator<<(ostream &os, const GiamDoc &gd)
// {
//   os << "Ho ten: " << gd.hoTen << endl;
//   os << "Ma so: " << gd.maSo << endl;
//   os << "Luong: " << gd.luong << endl;
//   os << "So dien thoai: " << gd.soDienThoai << endl;
//   os << "So ngay lam viec: " << gd.soNgayLamViec << endl;
//   os << endl;
//   return os;
// }

ostream &operator<<(ostream &os, const GiamDoc &gd)
{
  os << gd.maSo << "\t";
  os << gd.hoTen << "\t";
  os << gd.soDienThoai << "\t";
  os << gd.soNgayLamViec << "\t";
  os << gd.luong << "\t";
  return os;
}

GiamDoc::GiamDoc()
{
}

GiamDoc::GiamDoc(string maSo, string hoTen, string soDienThoai, float soNgayLamViec) : NhanSu(maSo, hoTen, soDienThoai, soNgayLamViec)
{
}

void GiamDoc::nhap()
{
  NhanSu::nhap();
}

void GiamDoc::xuat()
{
  NhanSu::xuat();
  // ofstream output("DanhSachNhanVien.txt", ios::app);
  cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
  cout << "\t\t\t_________________________________________" << endl;

  // output << "Luong:"
  //        << "\t" << this->luong << endl;
  // output << endl;
}

void GiamDoc::tinhLuong()
{
  this->luong = luong1NgayGD * this->soNgayLamViec;
}