#include "GiamDoc.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;
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
  ofstream output("DanhSachNhanVien.txt", ios::app);
  cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
  cout << "\t\t\t_________________________________________" << endl;

  output << "Luong:"
         << "\t" << this->luong << endl;
  output << endl;
}

void GiamDoc::tinhLuong()
{
  this->luong = luong1NgayGD * this->soNgayLamViec;
}