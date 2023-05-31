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
  DanhSachPhongBan();
  void checkNextAllNull(PhongBan *nextPB);
  void checkNextTPNull(PhongBan *nextPB);
  void checkNextNVNull(PhongBan *nextPB);
  void checkNextAllKhongNull(PhongBan *nextPB);
};