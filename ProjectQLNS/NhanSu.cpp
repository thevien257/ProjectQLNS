#include "NhanSu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <limits>
using namespace std;

long NhanSu::luong1NgayNVT = 200000;
long NhanSu::luong1NgayTP = 300000;
long NhanSu::luong1NgayGD = 1000000;
long NhanSu::phuCapNVT = 100000;
long NhanSu::phuCapTP = 200000;

string NhanSu::getSoDienThoai()
{
  return soDienThoai;
}

void NhanSu::setSoDienThoai(string soDienThoai)
{
  this->soDienThoai = soDienThoai;
}

void NhanSu::setHoTen(string hoTen)
{
  this->hoTen = hoTen;
}

void NhanSu::setMaSo(string maSo)
{
  this->maSo = maSo;
}

void NhanSu::setSoNgayLamViec(float soNgayLamViec)
{
  this->soNgayLamViec = soNgayLamViec;
}

void NhanSu::setLuong(long luong)
{
  this->luong = luong;
}

string NhanSu::formatLuong(double amount)
{
  int luong = (int)amount; // cast sang int de khong co dau phay
  stringstream ss;
  ss << fixed << setprecision(0) << luong; // set precision to 0 nen se khong co dau phay
  string str = ss.str();
  int len = str.length();
  for (int i = len - 3; i > 0; i -= 3)
  {
    str.insert(i, ".");
  }
  return str;
}

string NhanSu::getViTriViecLam()
{
  return viTriViecLam;
}

void NhanSu::setViTriViecLam(string viTriViecLam)
{
  this->viTriViecLam = viTriViecLam;
}

ostream &operator<<(ostream &os, const NhanSu &ns)
{
  os << ns.hoTen << "\t" << ns.maSo << "\t" << ns.luong << "\t" << ns.soDienThoai << "\t" << ns.soNgayLamViec << endl;
  return os;
}

// istream &operator>>(istream &is, NhanSu &ns)
// {
//   is >> ns.hoTen >> ns.maSo >> ns.soDienThoai >> ns.soNgayLamViec;
//   return is;
// }

istream &operator>>(istream &input, NhanSu &ns)
{
  char separator;
  getline(input, ns.hoTen, '#');
  getline(input, ns.maSo, '#');
  getline(input, ns.soDienThoai, '#');
  input >> ns.soNgayLamViec >> separator;
  input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return input;
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
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;

  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = true; // set the cursor visibility
  SetConsoleCursorInfo(hConsole, &cursorInfo);

  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;

  if (viTriViecLam == "Giam doc")
  {
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\t╔═════════════════════════════════════════════╗\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "          Nhap thong tin giam doc";
    SetConsoleTextAttribute(color, 11);
    cout << "            ║\n";
    cout << "\t\t\t\t╟─────────────────────────────────────────────╢\n";
  }
  else if (viTriViecLam == "Truong phong")
  {
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\t╔═════════════════════════════════════════════╗\n";
    cout << "\t\t\t\t║        ";
    SetConsoleTextAttribute(color, 7);
    cout << "Nhap thong tin truong phong";
    SetConsoleTextAttribute(color, 11);
    cout << "          ║\n";
    cout << "\t\t\t\t╟─────────────────────────────────────────────╢\n";
  }
  else if (viTriViecLam == "Nhan vien thuong")
  {
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\t╔═════════════════════════════════════════════╗\n";
    cout << "\t\t\t\t║      ";
    SetConsoleTextAttribute(color, 7);
    cout << "Nhap thong tin nhan vien thuong";
    SetConsoleTextAttribute(color, 11);
    cout << "        ║\n";
    cout << "\t\t\t\t╟─────────────────────────────────────────────╢\n";
  }

  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "  Ma so:";
  SetConsoleTextAttribute(color, 11);
  cout << "                                     ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "  Ho ten:";
  SetConsoleTextAttribute(color, 11);
  cout << "                                    ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "  So dien thoai:";
  SetConsoleTextAttribute(color, 11);
  cout << "                             ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "  So ngay lam viec:";
  SetConsoleTextAttribute(color, 11);
  cout << "                          ║\n";
  cout << "\t\t\t\t╚═════════════════════════════════════════════╝\n\n";

  // cout << endl;
  // cout << "\t\t\t\tNhap ma so: ";
  cout << "\033[19;55H";
  cin.ignore();
  getline(cin, maSo);
  // cout << "\t\t\t\tNhap ho ten: ";
  cout << "\033[20;55H";
  getline(cin, hoTen);
  // cout << "\t\t\t\tNhap so dien thoai: ";
  cout << "\033[21;55H";
  cin >> soDienThoai;
  cout << "\033[22;55H";
  cin.ignore();
  // cout << "\t\t\t\tSo ngay lam viec ";
  cin >> soNgayLamViec;
  cin.ignore();
  cout << "\033[25;44H";

  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = false; // set the cursor visibility
  SetConsoleCursorInfo(hConsole, &cursorInfo);
  SetConsoleTextAttribute(color, 10);
  cout << "Nhap thong tin thanh cong ✅" << endl;
  SetConsoleTextAttribute(color, 7);
}

void NhanSu::xuat()
{
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

  cout << "\t\t\t\t║  ";
  SetConsoleTextAttribute(color, 14);
  cout << "So dien thoai      ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << this->soDienThoai << std::right << " ║" << endl;

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

  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 14);
  cout << "  Luong              ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << formatLuong(this->luong) + " d" << std::right << " ║" << endl;
}
