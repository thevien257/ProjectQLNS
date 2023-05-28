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
  string maPhongBan;
  vector<Task *> dsTask;
  int hoanThanhTask;
  int chuaHoanThanhTask;
  int soLuongTask;

public:
  NhanVienThuong();
  NhanVienThuong(string maSo, string hoTen,
                 string soDienThoai, float soNgayLamViec);
  void tinhLuong();
  void setTruongPhong(TruongPhong *tp);
  void setMaPhongBan(string maPhongBan);
  vector<Task *> &getDSTask();
  string getMaPhongBan();
  TruongPhong *getTruongPhong();
  void nhap();
  void xuat();
  void xuatMaVaTen();
  ~NhanVienThuong();
  // friend istream &operator>>(istream &is, NhanVienThuong &nvt);
  friend ostream &operator<<(ostream &os, const NhanVienThuong &nvt);
  void tangTaskHoanThanh();
  void tangTaskChuaHoanThanh();
  int getHoanThanhTask();
  int getChuaHoanThanhTask();
  void tangSoLuongTask();
  void giamSoLuongTask();
  int getSoLuongTask();
};