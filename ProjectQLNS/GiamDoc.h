#pragma once
#include "NhanSu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>

class GiamDoc : public NhanSu
{
private:
public:
  GiamDoc();
  GiamDoc(string maSo, string hoTen,
          string soDienThoai, float soNgayLamViec);
  void nhap();
  void xuat();
  void tinhLuong();
  // friend istream &operator>>(istream &is, GiamDoc &gd);
  friend ostream &operator<<(ostream &os, const GiamDoc &gd);
};