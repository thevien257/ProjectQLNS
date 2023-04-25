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

string NhanSu::getViTriViecLam()
{
  return viTriViecLam;
}

void NhanSu::setViTriViecLam(string viTriViecLam)
{
  this->viTriViecLam = viTriViecLam;
}

vector<Task *> NhanSu::getDSTask()
{
  return dsTask;
}

// ostream &operator<<(ostream &os, const NhanSu &ns)
// {
//   os << "Ho ten: " << ns.hoTen << endl;
//   os << "Ma so: " << ns.maSo << endl;
//   os << "Luong: " << ns.luong << endl;
//   os << "So dien thoai: " << ns.soDienThoai << endl;
//   os << "So ngay lam viec: " << ns.soNgayLamViec << endl;
//   os << endl;
//   return os;
// }

ostream &operator<<(ostream &os, const NhanSu &ns)
{
  os << ns.hoTen << "\t" << ns.maSo << "\t" << ns.luong << "\t" << ns.soDienThoai << "\t" << ns.soNgayLamViec << endl;
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
  // cout << "\t\t\t\t║  Ma so              ║ " << std::left << std::setw(20) << this->maSo << std::right << " ║" << endl;
  // cout << "\t\t\t\t║  Ho ten             ║ " << std::left << std::setw(20) << this->hoTen << std::right << " ║" << endl;
  // if (viTriViecLam == "Nhan vien thuong")
  // {
  //   cout << "\t\t\t\t║  Vi tri viec lam    ║ " << std::left << std::setw(20) << viTriViecLam << std::right << " ║" << endl;
  // }
  // else if (viTriViecLam == "Truong phong")
  // {
  //   cout << "\t\t\t\t║  Vi tri viec lam    ║ " << std::left << std::setw(20) << this->viTriViecLam << std::right << " ║" << endl;
  // }
  // else
  // {
  //   cout << "\t\t\t\t║  Vi tri viec lam    ║ " << std::left << std::setw(20) << this->viTriViecLam << std::right << " ║" << endl;
  // }
  // cout << "\t\t\t\t║  So dien thoai      ║ " << std::left << std::setw(20) << this->soDienThoai << std::right << " ║" << endl;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\t\t\t\t║  ";
  SetConsoleTextAttribute(color, 14);
  cout << "Ma so              ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->maSo << std::right << " ║" << endl;

  cout << "\t\t\t\t║  ";
  SetConsoleTextAttribute(color, 14);
  cout << "Ho ten             ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->hoTen << std::right << " ║" << endl;

  if (viTriViecLam == "Nhan vien thuong")
  {
    cout << "\t\t\t\t║  ";
    SetConsoleTextAttribute(color, 14);
    cout << "Vi tri viec lam    ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << viTriViecLam << std::right << " ║" << endl;
  }
  else if (viTriViecLam == "Truong phong")
  {
    cout << "\t\t\t\t║  ";
    SetConsoleTextAttribute(color, 14);
    cout << "Vi tri viec lam    ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << this->viTriViecLam << std::right << " ║" << endl;
  }
  else
  {
    cout << "\t\t\t\t║  ";
    SetConsoleTextAttribute(color, 14);
    cout << "Vi tri viec lam    ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << this->viTriViecLam << std::right << " ║" << endl;
  }

  cout << "\t\t\t\t║  ";
  SetConsoleTextAttribute(color, 14);
  cout << "So dien thoai      ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->soDienThoai << std::right << " ║" << endl;
}

void NhanSu::tinhLuong()
{
  this->luong = 0;
}