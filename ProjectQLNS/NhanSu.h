#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include "Task.h"
using namespace std;

class NhanSu
{
protected:
  string maSo;
  string hoTen;
  string soDienThoai;
  string viTriViecLam;
  float soNgayLamViec;
  long luong;
  static long luong1NgayNVT;
  static long luong1NgayTP;
  static long luong1NgayGD;
  static long phuCapNVT;
  static long phuCapTP;

public:
  NhanSu();
  NhanSu(string maSo,
         string hoTen,
         string soDienThoai,
         float soNgayLamViec);
  string getMaSo();
  string getHoTen();
  string getViTriViecLam();
  void setViTriViecLam(string viTriViecLam);
  long getLuong();
  virtual void nhap();
  virtual void xuat();
  virtual void tinhLuong();
  friend istream &operator>>(istream &is, NhanSu &ns);
  friend ostream &operator<<(ostream &os, const NhanSu &ns);
  string formatLuong(double amount);
};