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
}

void GiamDoc::tinhLuong()
{
  this->luong = NhanSu::luong1NgayGD * this->soNgayLamViec;
}