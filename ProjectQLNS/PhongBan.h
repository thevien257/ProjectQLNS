#pragma once
#include <iostream>
#include "NhanVienThuong.h"
using namespace std;

class PhongBan
{
private:
  string tenPhongBan;
  string maPhongBan;
  vector<NhanVienThuong *> dsNV;

public:
  string getTenPhongBan();
  string getMaPhongBan();
  vector<NhanVienThuong *> getDsNV();
};
