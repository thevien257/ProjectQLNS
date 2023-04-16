#pragma once
#include <iostream>
#include <vector>
#include "PhongBan.h"

class DanhSachPhongBan
{
private:
  vector<PhongBan *> dsPhongBan;

public:
  vector<PhongBan *> getDsPhongBan();
  void setDsPhongBan(vector<PhongBan *> dsPhongBan);
};