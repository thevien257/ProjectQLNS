#include "PhongBan.h"
#include <iostream>
using namespace std;

string PhongBan::getTenPhongBan()
{
  return tenPhongBan;
}

string PhongBan::getMaPhongBan()
{
  return maPhongBan;
}

vector<NhanVienThuong *> PhongBan::getDsNV()
{
  return dsNV;
}
