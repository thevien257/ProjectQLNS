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
  cout << "\t\t\t\tNhap so luong phong ban: ";
  cin >> n;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  for (int i = 0; i < n; i++)
  {
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\tNhap phong ban thu " << i + 1 << " ✍️" << endl;
    SetConsoleTextAttribute(color, 7);
    PhongBan *pb = new PhongBan();
    pb->nhapPB();
    dsPhongBan.push_back(pb);
  }
  SetConsoleTextAttribute(color, 10);
  cout << "\t\t\t\tDa nhap xong phong ban ✅" << endl;
  SetConsoleTextAttribute(color, 7);
}

void DanhSachPhongBan::xuatPB()
{
  if (dsPhongBan.size() == 0)
  {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tChua co phong ban nao" << endl;
    SetConsoleTextAttribute(color, 7);
  }
  else
  {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═══║ ";
    SetConsoleTextAttribute(color, 11);
    cout << "      Thong tin phong ban  📂";
    SetConsoleTextAttribute(color, 7);
    cout << "     ║════╗\n";
    cout << "\t\t\t\t║   ╚═════════════════╦═════════════════╝    ║\n";

    PhongBan *lastPB = dsPhongBan.back();
    int j = 1;
    for (int i = 0; i < dsPhongBan.size(); i++)
    {
      if (dsPhongBan[i] != lastPB)
      {
        cout << "\t\t\t\t║";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // set color to yellow
        cout << "     So thu tu       ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // set color to white
        cout << "║ " << std::left << std::setw(20) << j << std::right << " ║" << endl;
        dsPhongBan[i]->xuatPB();
        cout << "\t\t\t\t╠═════════════════════╬══════════════════════╣\n";
        j++;
      }
      else
      {
        cout << "\t\t\t\t║";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // set color to yellow
        cout << "     So thu tu       ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // set color to white
        cout << "║ " << std::left << std::setw(20) << j << std::right << " ║" << endl;
        dsPhongBan[i]->xuatPB();
        cout << "\t\t\t\t╚═════════════════════╩══════════════════════╝\n";
      }
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