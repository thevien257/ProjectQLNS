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
  system("cls");
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
    system("cls");
  } while (flag);
}

void danhSachNhanSu::xuat()
{
  for (NhanSu *ns : dsNhanSu)
  {
    ns->xuat();
  }
}