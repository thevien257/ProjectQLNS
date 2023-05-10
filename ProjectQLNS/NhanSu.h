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

const int luong1NgayNVT = 100;
const int luong1NgayTP = 200;
const int luong1NgayGD = 300;

class NhanSu
{
protected:
  string maSo;
  string hoTen;
  string soDienThoai;
  string viTriViecLam;
  float soNgayLamViec;
  long luong;
<<<<<<< HEAD
  static long luong1NgayNVT;
  static long luong1NgayTP;
  static long luong1NgayGD;
  static long phuCapNVT;
  static long phuCapTP;
||||||| 457744a
  vector<Task *> dsTask;
  static long luong1NgayNVT;
  static long luong1NgayTP;
  static long luong1NgayGD;
  static long phuCapNVT;
  static long phuCapTP;
=======
  vector<Task *> dsTask;
>>>>>>> 8643634149765d053045f17711cb8b856c6e7ea5

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
<<<<<<< HEAD
  string formatLuong(double amount);
||||||| 457744a
  vector<Task *> getDSTask();
  string formatLuong(double amount);
=======
  vector<Task *> getDSTask();
>>>>>>> 8643634149765d053045f17711cb8b856c6e7ea5
};