#pragma once
#include "NhanSu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
class danhSachNhanSu
{
private:
  vector<NhanSu *> dsNhanSu;
  NhanSu *ns;

public:
  vector<NhanSu *> getListNS();
  void setListNS(vector<NhanSu *> listNS);
  void inMenu();
  void nhap();
  void xuat();
  void docFileNVT(string filename);
  void docFileGD(string filename);
  void docFileTP(string filename);
};