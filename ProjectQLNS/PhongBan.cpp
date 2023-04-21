#include "PhongBan.h"
#include <iostream>
using namespace std;

PhongBan::PhongBan()
{
  tp = nullptr;
}

void PhongBan::setTruongPhong(TruongPhong *tp)
{
  this->tp = tp;
}

istream &operator>>(istream &is, PhongBan &pb)
{
  is >> pb.maPhongBan >> pb.tenPhongBan;
  return is;
}

string PhongBan::getTenPhongBan()
{
  return tenPhongBan;
}

string PhongBan::getMaPhongBan()
{
  return maPhongBan;
}

vector<NhanVienThuong *> &PhongBan::getDsNV()
{
  return dsNV;
}

void PhongBan::nhapPB()
{
  cout << "\t\t\tNhap ten phong ban: ";
  cin.ignore();
  getline(cin, tenPhongBan);
  cout << "\t\t\tNhap ma phong ban: ";
  cin >> maPhongBan;
}

void PhongBan::xuatPB()
{
  cout << "\t\t\tTen phong ban: " << tenPhongBan << endl;
  cout << "\t\t\tMa phong ban: " << maPhongBan << endl;
  if (tp != nullptr)
  {
    cout << "\t\t\t\t Truong phong cua phong ban nay la: " << endl;
    cout << "Ma so: " << tp->getMaSo() << "\t"
         << "Ho ten: " << tp->getHoTen() << endl;
  }
  if (dsNV.size() == 0)
  {
    cout << "\t\t\t\tChua co nhan vien nao trong phong ban nay" << endl;
  }
  else
  {
    cout << "\t\t\tDanh sach nhan vien: " << endl;
    for (int i = 0; i < dsNV.size(); i++)
    {
      cout << "\t\t\tNhan vien thu " << i + 1 << endl;
      cout << *dsNV[i];
      cout << endl;
    }
  }
  cout << endl;
}