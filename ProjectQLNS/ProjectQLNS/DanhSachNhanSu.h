#pragma once
#include "NhanSu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>

class NhanVienThuong;

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
  void xuatNV();
  void xuatNV(vector<NhanVienThuong *> listNV);
  void xuatMaSoVaTenNV();
  void xuatMaSoVaTenTP();
  void docFileNVT(string filename);
  void docFileGD(string filename);
  void docFileTP(string filename);
  void ghiFile(string filename);
  ~danhSachNhanSu();
};