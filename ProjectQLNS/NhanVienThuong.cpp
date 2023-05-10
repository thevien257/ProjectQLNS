#include "NhanVienThuong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

// istream &operator>>(istream &is, NhanVienThuong &nvt)
// {
//   // Read data from the input stream and populate the ns object
//   is >> nvt.hoTen >> nvt.maSo >> nvt.soDienThoai >> nvt.soNgayLamViec;
//   return is;
// }

string NhanVienThuong::getMaPhongBan()
{
  return maPhongBan;
}

void NhanVienThuong::setMaPhongBan(string maPhongBan)
{
  this->maPhongBan = maPhongBan;
}

NhanVienThuong::~NhanVienThuong()
{
  delete[] tp;
}

TruongPhong *NhanVienThuong::getTruongPhong()
{
  return tp;
}

// ostream &operator<<(ostream &os, const NhanVienThuong &nvt)
// {
//   os << "Ho ten: " << nvt.hoTen << endl;
//   os << "Ma so: " << nvt.maSo << endl;
//   os << "So dien thoai: " << nvt.soDienThoai << endl;
//   os << "So ngay lam viec: " << nvt.soNgayLamViec << endl;
//   if (nvt.tp != nullptr)
//   {
//     os << "___________Thong tin nguoi quan ly__________" << endl;
//     os << "Ho ten truong phong: " << nvt.tp->getHoTen() << endl;
//     os << "Ma so truong phong: " << nvt.tp->getMaSo() << endl;
//   }
//   if (nvt.maPhongBan != "")
//   {
//     os << "Ma phong ban: " << nvt.maPhongBan << endl;
//   }
//   os << endl;
//   return os;
// }

ostream &operator<<(ostream &os, const NhanVienThuong &nvt)
{
  os << nvt.maSo << "\t" << nvt.hoTen << "\t" << nvt.soDienThoai << "\t" << nvt.soNgayLamViec << "\t" << nvt.luong << "\t";
  if (nvt.maPhongBan != "")
  {
    os << nvt.maPhongBan << "\t";
  }
  else
  {
    os << "\t";
  }
  if (nvt.tp != nullptr)
  {
    os << nvt.tp->getHoTen() << "\t" << nvt.tp->getMaSo() << "\t";
  }
  return os;
}

void NhanVienThuong::setTruongPhong(TruongPhong *tp)
{
  this->tp = tp;
}

NhanVienThuong::NhanVienThuong()
{
  tp = nullptr;
  maPhongBan = "";
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
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  NhanSu::xuat();
  // cout << "\t\t\t\t║  Luong              ║ " << std::left << std::setw(20) << this->luong << std::right << " ║" << endl;
  // if (maPhongBan != "")
  // {
  //   cout << "\t\t\t\t║  Ma phong ban       ║ " << std::left << std::setw(20) << this->maPhongBan << std::right << " ║" << endl;
  // }
  // if (tp != nullptr)
  // {
  //   cout << "\t\t\t\t║";
  //   SetConsoleTextAttribute(color, 11);
  //   cout << "          Thong tin nguoi quan ly";
  //   SetConsoleTextAttribute(color, 7);
  //   cout << "           ║\n";
  //   cout << "\t\t\t\t║  Ten truong phong   ║ " << std::left << std::setw(20) << tp->getHoTen() << std::right << " ║" << endl;
  //   cout << "\t\t\t\t║  Ma truong phong    ║ " << std::left << std::setw(20) << tp->getMaSo() << std::right << " ║" << endl;
  // }

  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 14);
<<<<<<< HEAD
  cout << "  So luong task      ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->soLuongTask << std::right << " ║" << endl;
||||||| 457744a
  cout << "  Luong              ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << formatLuong(this->luong) << std::right << " ║" << endl;
  SetConsoleTextAttribute(color, 7);
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 14);
  cout << "  So luong task      ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->soLuongTask << std::right << " ║" << endl;
=======
  cout << "  Luong              ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->luong << std::right << " ║" << endl;
>>>>>>> 8643634149765d053045f17711cb8b856c6e7ea5
  SetConsoleTextAttribute(color, 7);
  if (maPhongBan != "")
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "  Ma phong ban       ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << this->maPhongBan << std::right << " ║" << endl;
    SetConsoleTextAttribute(color, 7);
  }
  if (tp != nullptr)
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 3);
    cout << "          Thong tin nguoi quan ly";
    SetConsoleTextAttribute(color, 7);
    cout << "           ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "  Ten truong phong   ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << tp->getHoTen() << std::right << " ║" << endl;
    SetConsoleTextAttribute(color, 7);
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "  Ma truong phong    ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << tp->getMaSo() << std::right << " ║" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}
