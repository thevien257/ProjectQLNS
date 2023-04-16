#include "DanhSachPhongBan.h"
#include <iostream>
using namespace std;

vector<PhongBan *> DanhSachPhongBan::getDsPhongBan()
{
  return dsPhongBan;
}

void DanhSachPhongBan::setDsPhongBan(vector<PhongBan *> dsPhongBan)
{
  this->dsPhongBan = dsPhongBan;
}
