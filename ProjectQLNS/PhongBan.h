#pragma once
#include <iostream>
#include "NhanVienThuong.h"
#include "TruongPhong.h"
using namespace std;

class NhanVienThuong;
class TruongPhong;
class PhongBan
{
private:
  string tenPhongBan;
  string maPhongBan;
  TruongPhong *tp;
  vector<NhanVienThuong *> dsNV;

public:
  string getTenPhongBan();
  string getMaPhongBan();
  PhongBan();
  void setTruongPhong(TruongPhong *tp);
  vector<NhanVienThuong *> &getDsNV();
  void nhapPB();
  void xuatPB();
  friend istream &operator>>(istream &is, PhongBan &pb);
};
