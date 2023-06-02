#include "NhanVienThuong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

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

ostream &operator<<(ostream &os, const NhanVienThuong &nvt)
{
  os << nvt.maSo << "\t" << nvt.hoTen << "\t" << nvt.soDienThoai << "\t" << nvt.viTriViecLam << "\t" << nvt.soNgayLamViec << "\t" << nvt.luong << "\t";
  if (nvt.maPhongBan != "")
  {
    os << nvt.maPhongBan << "\t";
  }
  else
  {
    os << "\t";
  }
  if (nvt.soLuongTask != 0)
  {
    os << nvt.soLuongTask << "\t";
    for (int i = 0; i < nvt.soLuongTask; i++)
    {
      Task *task = nvt.dsTask.at(i);
      os << nvt.dsTask[i]->getMaTask() << "\t";
      os << nvt.dsTask[i]->getTenTask() << "\t";
      os << nvt.dsTask[i]->getTrangThaiTask() << "\t";
      if (i == nvt.dsTask.size() - 1)
      {
        break;
      }
      else if (i != nvt.dsTask.size() - 1 && !os.fail())
      {
        os << endl;
        os << "\t\t\t\t\t\t\t\t";
      }
    }
  }
  else
  {
    os << "\t\t\t\t";
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
  this->luong = NhanSu::luong1NgayNVT * this->soNgayLamViec +
                NhanSu::phuCapNVT * hoanThanhTask - NhanSu::phuCapNVT * chuaHoanThanhTask;
}

void NhanVienThuong::nhap()
{
  NhanSu::nhap();
}

void NhanVienThuong::xuat()
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
  SetConsoleTextAttribute(color, 14);
  cout << "  So luong task      ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->soLuongTask << std::right << " ║" << endl;
  SetConsoleTextAttribute(color, 7);

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
      i++;
    }
  }
}

void NhanVienThuong::xuatMaVaTen()
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
}
