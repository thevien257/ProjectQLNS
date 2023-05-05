#include "GiamDoc.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <locale>
#include <math.h>
#include <sstream>
using namespace std;

ostream &operator<<(ostream &os, const GiamDoc &gd)
{
  os << gd.maSo << "\t";
  os << gd.hoTen << "\t";
  os << gd.soDienThoai << "\t";
  os << gd.viTriViecLam << "\t";
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
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 14);
  cout << "  Luong";
  SetConsoleTextAttribute(color, 7);
  cout << "              ║ " << std::left << std::setw(20) << formatLuong(this->luong) << std::right << " ║" << endl;

  // cout << "              ║ " << std::left << std::setw(20) << this->luong << std::right << " ║" << endl;
}

void GiamDoc::tinhLuong()
{
  this->luong = NhanSu::luong1NgayGD * this->soNgayLamViec;
}