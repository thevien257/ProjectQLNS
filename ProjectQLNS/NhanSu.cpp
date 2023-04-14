#include "NhanSu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

ostream &operator<<(ostream &os, const NhanSu &ns)
{
  os << "Ho ten: " << ns.hoTen << endl;
  os << "Ma so: " << ns.maSo << endl;
  os << "Luong: " << ns.luong << endl;
  os << "So dien thoai: " << ns.soDienThoai << endl;
  os << "So ngay lam viec: " << ns.soNgayLamViec << endl;
  os << endl;
  return os;
}

istream &operator>>(istream &is, NhanSu &ns)
{
  // Read data from the input stream and populate the ns object
  is >> ns.hoTen >> ns.maSo >> ns.soDienThoai >> ns.soNgayLamViec;
  return is;
}

long NhanSu::getLuong()
{
  return luong;
}

string NhanSu::getHoTen()
{
  return hoTen;
}

string NhanSu::getMaSo()
{
  return maSo;
}

NhanSu::NhanSu()
{
}

NhanSu::NhanSu(string maSo,
               string hoTen,
               string soDienThoai,
               float soNgayLamViec)
{
  this->maSo = maSo;
  this->hoTen = hoTen;
  this->soDienThoai = soDienThoai;
  this->soNgayLamViec = soNgayLamViec;
}

void NhanSu::nhap()
{
  cout << endl;
  cout << "\t\t\t\tNhap ma so: ";
  cin.ignore();
  getline(cin, maSo);
  cout << "\t\t\t\tNhap ho ten: ";
  getline(cin, hoTen);
  cout << "\t\t\t\tNhap so dien thoai: ";
  cin >> soDienThoai;
  cin.ignore();
  cout << "\t\t\t\tSo ngay lam viec ";
  cin >> soNgayLamViec;
  cin.ignore();
}

void NhanSu::xuat()
{
  cout << "\t\t\t_________________________________________" << endl;
  cout << "\t\t\t|Ma so\t\t\t| " << this->maSo << "\t\t|" << endl;
  cout << "\t\t\t|Ho ten\t\t\t| " << this->hoTen << "\t\t|" << endl;
  cout << "\t\t\t|So dien thoai\t\t|" << this->soDienThoai << "   \t|" << endl;
  ofstream output("DanhSachNhanVien.txt", ios::app);
  output << "Ma so:"
         << "\t" << this->maSo << endl;
  output << "Ho ten:"
         << "\t" << this->hoTen << endl;
  output << "So dien thoai:"
         << "\t" << this->soDienThoai << endl;
}

void NhanSu::tinhLuong()
{
  this->luong = 0;
}