#include "TruongPhong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

void TruongPhong::setMaPhongBan(string maPhongBan)
{
  this->maPhongBan = maPhongBan;
}

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
  os << tp.maSo << "\t";
  os << tp.hoTen << "\t";
  os << tp.soDienThoai << "\t";
  os << tp.viTriViecLam << "\t";
  os << tp.soNgayLamViec << "\t";
  os << tp.luong << "\t";
  if (tp.maPhongBan != "")
  {
    os << tp.maPhongBan << "\t\t\t\t\t\t\t";
  }
  else
  {
    os << "\t\t\t\t\t\t\t";
  }
  if (tp.soLuongNhanVien > 0)
  {
    os << tp.soLuongNhanVien << "\t";

    for (int i = 0; i < tp.listNV.size(); ++i)
    {
      NhanVienThuong *nvt = tp.listNV.at(i);
      os << nvt->getHoTen() << "\t";
      os << nvt->getMaSo() << "\t";

      if (i == tp.listNV.size() - 1)
      {
        break;
      }
      else if (i != tp.listNV.size() - 1 && !os.fail())
      {
        os << endl;
        os << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
      }
    }
  }
  return os;
}

vector<NhanVienThuong *> &TruongPhong::getListNV() // Dùng & vì ở class khác nhau mới thay đổi được và để tránh tạo bản copy
{
  return listNV;
}

TruongPhong::TruongPhong()
{
  this->soLuongNhanVien = 0;
  this->maPhongBan = "";
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
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  NhanSu::xuat();

  if (maPhongBan != "")
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "  Ma phong ban       ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << this->maPhongBan << std::right << " ║" << endl;
    SetConsoleTextAttribute(color, 7);
  }

  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
  cout << "  So luong nhan vien ";
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
  cout << "║ " << std::left << std::setw(20) << this->soLuongNhanVien << std::right << " ║" << endl;

  if (soLuongNhanVien > 0)
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "             Thong tin nhan vien";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "            ║\n";
    int i = 1;
    for (NhanVienThuong *nv : listNV)
    {
      cout << "\t\t\t\t║";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
      cout << "              Nhan vien thu " << i;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
      cout << "               ║\n";
      cout << "\t\t\t\t║";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
      cout << "  Ten nhan vien      ";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
      cout << "║ " << std::left << std::setw(20) << nv->getHoTen() << std::right << " ║" << endl;
      cout << "\t\t\t\t║";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
      cout << "  Ma so nhan vien    ";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
      cout << "║ " << std::left << std::setw(20) << nv->getMaSo() << std::right << " ║" << endl;
      i++;
    }
  }
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
  this->luong = NhanSu::luong1NgayTP * this->soNgayLamViec + NhanSu::phuCapTP * this->soLuongNhanVien;
}

void TruongPhong::xuatMaVaTen()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  int brightYellow = 14;
  int darkWhite = 7;
  cout << " " << setw(7 + maSo.size() / 2) << setfill(' ');
  SetConsoleTextAttribute(color, brightYellow);
  cout << maSo;
  SetConsoleTextAttribute(color, darkWhite);
  cout << setw(7 - maSo.size() / 2) << setfill(' ') << ""
       << "║";

  cout << setw(14 + hoTen.size() / 2) << setfill(' ');
  SetConsoleTextAttribute(color, brightYellow);
  cout << hoTen;
  SetConsoleTextAttribute(color, darkWhite);
  cout << setw(14 - hoTen.size() / 2) << setfill(' ') << ""
       << "║";

  if (maPhongBan != "")
  {
    cout << setw(14 + maPhongBan.size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << maPhongBan;
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(14 - maPhongBan.size() / 2) << setfill(' ') << ""
         << "║";
  }
  else
  {
    string empty = "Chua co ma phong ban";
    cout << setw(14 + empty.size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << empty;
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(14 - empty.size() / 2) << setfill(' ') << ""
         << "║";
  }
}
