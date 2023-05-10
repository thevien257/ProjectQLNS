#include "PhongBan.h"
#include <iostream>
using namespace std;

int PhongBan::getSoluongNhanSu()
{
  return soLuongNhanSu;
}

void PhongBan::tangSoLuongNhanSu()
{
  soLuongNhanSu++;
}

void PhongBan::giamSoLuongNhanSu()
{
  soLuongNhanSu--;
}

PhongBan::PhongBan()
{
  tp = nullptr;
  soLuongNhanSu = 0;
}

void PhongBan::setTruongPhong(TruongPhong *tp)
{
  this->tp = tp;
}

istream &operator>>(istream &is, PhongBan &pb)
{
  is >> pb.maPhongBan >> pb.tenPhongBan;
  return is;
}

TruongPhong *PhongBan::getTruongPhong()
{
  return tp;
}

string PhongBan::getTenPhongBan()
{
  return tenPhongBan;
}

string PhongBan::getMaPhongBan()
{
  return maPhongBan;
}

vector<NhanVienThuong *> &PhongBan::getDsNV()
{
  return dsNV;
}

void PhongBan::nhapPB()
{
  cout << "\t\t\t\tNhap ten phong ban: ";
  cin.ignore();
  getline(cin, tenPhongBan);
  cout << "\t\t\t\tNhap ma phong ban: ";
  cin >> maPhongBan;
}

void PhongBan::xuatPB()
{

  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\t\t\t\t║  ";
  SetConsoleTextAttribute(color, 14);
  cout << "Ma phong ban    ";
  SetConsoleTextAttribute(color, 7);
  cout << "   ║ " << std::left << std::setw(20) << this->maPhongBan << std::right << " ║" << endl;

  cout << "\t\t\t\t║  ";
  SetConsoleTextAttribute(color, 14);
  cout << "Ten phong ban   ";
  SetConsoleTextAttribute(color, 7);
  cout << "   ║ " << std::left << std::setw(20) << this->tenPhongBan << std::right << " ║" << endl;

  cout << "\t\t\t\t║  ";
  SetConsoleTextAttribute(color, 14);
  cout << "So luong nhan su";
  SetConsoleTextAttribute(color, 7);
  cout << "   ║ " << std::left << std::setw(20) << this->soLuongNhanSu << std::right << " ║" << endl;

  if (tp != nullptr)
  {
    cout << "\t\t\t\t║";
    cout << "──────────";
    SetConsoleTextAttribute(color, 3);
    cout << "Thong tin nguoi quan ly";
    SetConsoleTextAttribute(color, 7);
    cout << "───────────║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "  Ma truong phong    ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << tp->getMaSo() << std::right << " ║" << endl;
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "  Ten truong phong   ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << tp->getHoTen() << std::right << " ║" << endl;
    SetConsoleTextAttribute(color, 7);
    SetConsoleTextAttribute(color, 7);
  }
  else
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "             Chua co truong phong";
    SetConsoleTextAttribute(color, 7);
    cout << "           ║\n";
  }
  if (dsNV.size() <= 0)
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "             Chua co nhan vien";
    SetConsoleTextAttribute(color, 7);
    cout << "              ║\n";
  }
  else
  {
    // cout << "\t\t\t\t║";
    // cout << "             ";
    // cout << "                   ";
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // set color to white
    // cout << "            ║\n";
    cout << "\t\t\t\t║";
    cout << "─────────────";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); // set color to bright cyan
    cout << "Thong tin nhan vien";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // set color to white
    cout << "────────────║\n";
    int i = 1;
    for (NhanVienThuong *nv : dsNV)
    {
      cout << "\t\t\t\t║";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); // set color to yellow
      cout << "              Nhan vien thu " << i;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // set color to white
      cout << "               ║\n";
      cout << "\t\t\t\t║";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // set color to yellow
      cout << "  Ten nhan vien      ";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // set color to white
      cout << "║ " << std::left << std::setw(20) << nv->getHoTen() << std::right << " ║" << endl;
      cout << "\t\t\t\t║";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // set color to yellow
      cout << "  Ma so nhan vien    ";
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // set color to white
      cout << "║ " << std::left << std::setw(20) << nv->getMaSo() << std::right << " ║" << endl;
      i++;
    }
  }
}