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

void NhanVienThuong::giamSoLuongTask()
{
  this->soLuongTask--;
}

int NhanVienThuong::getSoLuongTask()
{
  return soLuongTask;
}

void NhanVienThuong::tangSoLuongTask()
{
  this->soLuongTask++;
}

int NhanVienThuong::getHoanThanhTask()
{
  return hoanThanhTask;
}

int NhanVienThuong::getChuaHoanThanhTask()
{
  return chuaHoanThanhTask;
}

void NhanVienThuong::tangTaskHoanThanh()
{
  this->hoanThanhTask++;
}

void NhanVienThuong::tangTaskChuaHoanThanh()
{
  this->chuaHoanThanhTask++;
}

vector<Task *> &
NhanVienThuong::getDSTask()
{
  return dsTask;
}

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
  hoanThanhTask = 0;
  chuaHoanThanhTask = 0;
  soLuongTask = 0;
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
  cout << "  Luong              ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->luong << std::right << " ║" << endl;
  SetConsoleTextAttribute(color, 7);
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 14);
  cout << "  So luong task      ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->soLuongTask << std::right << " ║" << endl;
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
  if (this->hoanThanhTask > 0)
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "  Hoan thanh task    ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << this->hoanThanhTask << std::right << " ║" << endl;
    SetConsoleTextAttribute(color, 7);
  }
  if (this->chuaHoanThanhTask > 0)
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "  K.Hoan Thanh Task  ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << this->chuaHoanThanhTask << std::right << " ║" << endl;
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
  if (dsTask.size() > 0)
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 3);
    cout << "               Danh sach task    ";
    SetConsoleTextAttribute(color, 7);
    cout << "           ║\n";
    int i = 1;
    for (Task *task : dsTask)
    {
      cout << "\t\t\t\t║";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); // set color to yellow
      cout << "                 Task thu " << i;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // set color to white
      cout << "                 ║\n";
      cout << "\t\t\t\t║";
      SetConsoleTextAttribute(color, 14);
      cout << "  Ten task           ";
      SetConsoleTextAttribute(color, 7);
      cout << "║ " << std::left << std::setw(20) << task->getTenTask() << std::right << " ║" << endl;
      SetConsoleTextAttribute(color, 7);
      cout << "\t\t\t\t║";
      SetConsoleTextAttribute(color, 14);
      cout << "  Ma task            ";
      SetConsoleTextAttribute(color, 7);
      cout << "║ " << std::left << std::setw(20) << task->getMaTask() << std::right << " ║" << endl;
      SetConsoleTextAttribute(color, 7);
      if (task->getTrangThaiTask() != "")
      {
        cout << "\t\t\t\t║";
        SetConsoleTextAttribute(color, 14);
        cout << "  Trang thai         ";
        SetConsoleTextAttribute(color, 7);
        cout << "║ " << std::left << std::setw(20) << task->getTrangThaiTask() << std::right << " ║" << endl;
        SetConsoleTextAttribute(color, 7);
      }
      // cout << "\t\t\t\t║";
      // SetConsoleTextAttribute(color, 14);
      // cout << "  Tinh trang         ";
      // SetConsoleTextAttribute(color, 7);
      // cout << "║ " << std::left << std::setw(20) << task->getTinhTrang() << std::right << " ║" << endl;
      // SetConsoleTextAttribute(color, 7);
      i++;
    }
    // if (this->getSoNgayLamViec() < 25)
    // {
    //   cout << "\t\t\t\t║";
    //   SetConsoleTextAttribute(color, 12);
    //   cout << "  Canh bao: Nhan vien nay co nguy co bi sa thai";
    //   SetConsoleTextAttribute(color, 7);
    //   cout << " ║" << endl;
    //   SetConsoleTextAttribute(color, 7);
    // }
  }
}
