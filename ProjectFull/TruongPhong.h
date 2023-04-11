#pragma once
#include "NhanSu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;
class TruongPhong : public NhanSu
{
private:
  int soLuongNhanVien;

public:
  TruongPhong();
  TruongPhong(string maSo,
              string hoTen,
              string soDienThoai,
              float soNgayLamViec);
  string getMaSo();
  string getTenTP();
  void nhap();
  void xuat();
  void tangNhanVien();
  void giamNhanVien();
  void tinhLuong();
};