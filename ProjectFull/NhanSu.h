#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

const int luong1NgayNVT = 100;
const int luong1NgayTP = 200;
const int luong1NgayGD = 300;

class NhanSu
{
protected:
  string maSo;
  string hoTen;
  string soDienThoai;
  float soNgayLamViec;
  long luong;

public:
  NhanSu();
  NhanSu(string maSo,
         string hoTen,
         string soDienThoai,
         float soNgayLamViec);
  string getMaSo();
  string getHoTen();
  long getLuong();
  virtual void nhap();
  virtual void xuat();
  virtual void tinhLuong();
};