#pragma once
#include "NhanSu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
<<<<<<< HEAD

class NhanVienThuong;

||||||| 457744a

class NhanVienThuong;
=======
>>>>>>> 8643634149765d053045f17711cb8b856c6e7ea5
class danhSachNhanSu
{
private:
  vector<NhanSu *> dsNhanSu;
  NhanSu *ns;

public:
  vector<NhanSu *> &getListNS();
  danhSachNhanSu();
  void setListNS(vector<NhanSu *> listNS);
  void inMenu(int &chon);
  void nhap();
  void xuat();
  void docFileNVT(string filename);
  void docFileGD(string filename);
  void docFileTP(string filename);
  void ghiFile(string filename);
  ~danhSachNhanSu();
};