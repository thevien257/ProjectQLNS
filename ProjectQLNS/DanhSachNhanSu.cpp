#include "DanhSachNhanSu.h"
#include "TruongPhong.h"
#include "GiamDoc.h"
#include "NhanVienThuong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

void danhSachNhanSu::docFileNVT(string filename)
{
  ifstream file(filename); // replace "ten_file.txt" with the name of your text file
  if (file.is_open())
  {
    while (file.good())
    {
      // read data from file and create new employee object
      NhanSu *ns = new NhanVienThuong(); // replace with appropriate subclass
      file >> *ns;
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
    }
    file.close();
  }
  else
  {
    cout << "Khong mo duoc file!" << endl;
  }
}

void danhSachNhanSu::docFileGD(string filename)
{
  ifstream file(filename); // replace "ten_file.txt" with the name of your text file
  if (file.is_open())
  {
    while (file.good())
    {
      // read data from file and create new employee object
      NhanSu *ns = new GiamDoc(); // replace with appropriate subclass
      file >> *ns;
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
    }
    file.close();
  }
  else
  {
    cout << "Khong mo duoc file!" << endl;
  }
}

void danhSachNhanSu::docFileTP(string filename)
{
  ifstream file(filename); // replace "ten_file.txt" with the name of your text file
  if (file.is_open())
  {
    while (file.good())
    {
      // read data from file and create new employee object
      NhanSu *ns = new TruongPhong(); // replace with appropriate subclass
      file >> *ns;
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
    }
    file.close();
  }
  else
  {
    cout << "Khong mo duoc file!" << endl;
  }
}

void danhSachNhanSu::setListNS(vector<NhanSu *> listNS)
{
  this->dsNhanSu = listNS;
}

vector<NhanSu *> danhSachNhanSu::getListNS()
{
  return this->dsNhanSu;
}

void danhSachNhanSu::inMenu()
{
  std::system("cls");
  cout << "\t\t\t\t ___________________________________\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|        Menu Them nhan su          |\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|___________________________________|\n";
  cout << endl;
  cout << "\t\t\t\t1. Them truong phong " << endl;
  cout << "\t\t\t\t2. Them nhan vien thuong" << endl;
  cout << "\t\t\t\t3. Them giam doc" << endl;
  cout << "\t\t\t\t--------------------> Moi chon: ";
}

void danhSachNhanSu::nhap()
{
  bool flag = true;
  int chon;
  docFileGD("GiamDoc.txt");
  docFileNVT("NVT.txt");
  docFileTP("TP.txt");
  do
  {
    inMenu();
    cin >> chon;
    switch (chon)
    {
    case 1:
      ns = new TruongPhong();
      ns->nhap();
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
      break;
    case 2:
      ns = new NhanVienThuong();
      ns->nhap();
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
      break;
    case 3:
      ns = new GiamDoc();
      ns->nhap();
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
      break;
    case 0:
      flag = false;
      break;
    default:
      break;
    }
    std::system("cls");
  } while (flag);
}

void danhSachNhanSu::xuat()
{
  docFileGD("GiamDoc.txt");
  docFileNVT("NVT.txt");
  docFileTP("TP.txt");
  for (NhanSu *ns : dsNhanSu)
  {
    ns->xuat();
  }
}