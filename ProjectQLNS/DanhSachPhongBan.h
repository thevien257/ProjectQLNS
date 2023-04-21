#pragma once
#include <iostream>
#include <vector>
#include "PhongBan.h"

class PhongBan;
class DanhSachPhongBan
{
private:
  vector<PhongBan *> dsPhongBan;

public:
  vector<PhongBan *> &getDsPhongBan();
  void setDsPhongBan(vector<PhongBan *> dsPhongBan);
  void nhapPB();
  void xuatPB();
  void docFilePB(string fileName);
  void ghiFilePB(string fileName);
  DanhSachPhongBan();
};