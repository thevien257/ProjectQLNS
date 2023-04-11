#include "NhanSu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

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
  cin >> maSo;
  cout << "\t\t\t\tNhap ho ten: ";
  cin >> hoTen;
  cout << "\t\t\t\tNhap so dien thoai: ";
  cin >> soDienThoai;
  cout << "\t\t\t\tSo ngay lam viec ";
  cin >> soNgayLamViec;
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