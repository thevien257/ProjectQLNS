#pragma once
#include "NhanSu.h"
#include "TruongPhong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>

class TruongPhong;
class NhanVienThuong : public NhanSu
{
private:
  TruongPhong *tp;

public:
  NhanVienThuong();
  NhanVienThuong(string maSo, string hoTen, string soDienThoai, float soNgayLamViec);
  void tinhLuong();
  void setTruongPhong(TruongPhong *tp);
  void nhap();
  void xuat();
  // friend istream &operator>>(istream &is, NhanVienThuong &nvt);
  friend ostream &operator<<(ostream &os, const NhanVienThuong &nvt);
};