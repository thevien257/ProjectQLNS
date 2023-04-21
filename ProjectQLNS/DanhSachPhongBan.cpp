#include "DanhSachPhongBan.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;

vector<PhongBan *> &DanhSachPhongBan::getDsPhongBan()
{
  return dsPhongBan;
}

void DanhSachPhongBan::setDsPhongBan(vector<PhongBan *> dsPhongBan)
{
  this->dsPhongBan = dsPhongBan;
}

void DanhSachPhongBan::nhapPB()
{
  int n;
  cout << "\t\tNhap so luong phong ban: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    PhongBan *pb = new PhongBan();
    pb->nhapPB();
    dsPhongBan.push_back(pb);
  }
}

void DanhSachPhongBan::xuatPB()
{
  if (dsPhongBan.size() == 0)
  {
    cout << "\t\t\tChua co phong ban nao" << endl;
  }
  else
  {
    for (int i = 0; i < dsPhongBan.size(); i++)
    {
      cout << "\t\tPhong ban thu " << i + 1 << endl;
      dsPhongBan[i]->xuatPB();
      cout << endl;
    }
  }
}

void DanhSachPhongBan::docFilePB(string fileName)
{
  ifstream file(fileName);
  if (file.is_open())
  {
    while (file.good())
    {
      PhongBan *pb = new PhongBan();
      file >> *pb;
      this->dsPhongBan.push_back(pb);
    }
    file.close();
  }
  else
  {
    cout << "Khong mo duoc file!" << endl;
  }
}

DanhSachPhongBan::DanhSachPhongBan()
{
  docFilePB("PhongBan.txt");
}