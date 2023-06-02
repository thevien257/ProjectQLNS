#include "PhongBan.h"
#include <iostream>
#include <limits>
using namespace std;

int PhongBan::getSoluongNhanSu()
{
  return soLuongNhanSu;
}

void PhongBan::tangSoLuongNhanSu()
{
  soLuongNhanSu++;
}

void PhongBan::giamSoLuongNhanSu()
{
  soLuongNhanSu--;
}

PhongBan::PhongBan()
{
  tp = nullptr;
  soLuongNhanSu = 0;
}

void PhongBan::setTruongPhong(TruongPhong *tp)
{
  this->tp = tp;
}

// istream &operator>>(istream &is, PhongBan &pb)
// {
//   is >> pb.maPhongBan >> pb.tenPhongBan;
//   return is;
// }

istream &operator>>(istream &input, PhongBan &pb)
{
  char separator;
  getline(input, pb.maPhongBan, '#');
  getline(input, pb.tenPhongBan, '#');
  input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return input;
}

TruongPhong *PhongBan::getTruongPhong()
{
  return tp;
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
  cout << "\t\t\t\tNhap ten phong ban: ";
  cin.ignore();
  getline(cin, tenPhongBan);
  cout << "\t\t\t\tNhap ma phong ban: ";
  cin >> maPhongBan;
}

void PhongBan::xuatPB()
{

  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  int brightYellow = 14;
  int darkWhite = 7;
  cout << " " << setw(6 + maPhongBan.size() / 2) << setfill(' ');
  SetConsoleTextAttribute(color, brightYellow);
  cout << maPhongBan;
  SetConsoleTextAttribute(color, darkWhite);
  cout << setw(6 - maPhongBan.size() / 2) << setfill(' ') << ""
       << " ║";

  cout << " " << setw(8 + tenPhongBan.size() / 2) << setfill(' ');
  SetConsoleTextAttribute(color, brightYellow);
  cout << tenPhongBan;
  SetConsoleTextAttribute(color, darkWhite);
  cout << setw(8 - tenPhongBan.size() / 2) << setfill(' ') << ""
       << " ║";

  cout << " " << setw(10 + 1 / 2) << setfill(' ');
  SetConsoleTextAttribute(color, brightYellow);
  cout << soLuongNhanSu;
  SetConsoleTextAttribute(color, darkWhite);
  cout << setw(10 - 1 / 2) << setfill(' ') << ""
       << " ║";

  if (tp != nullptr)
  {
    cout << " " << setw(5 + tp->getMaSo().size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << tp->getMaSo();
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(5 - tp->getMaSo().size() / 2) << setfill(' ') << ""
         << " ║";

    cout << " " << setw(10 + tp->getHoTen().size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << tp->getHoTen();
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(10 - tp->getHoTen().size() / 2) << setfill(' ') << ""
         << "  ║";
  }
  else
  {
    string chuaCoTP = "Chua co truong phong";
    cout << " " << setw(17 + chuaCoTP.size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << chuaCoTP;
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(17 - chuaCoTP.size() / 2) << setfill(' ') << ""
         << " ║";
  }
  if (dsNV.size() <= 0)
  {
    string chuaCoNV = "Chua co nhan vien";
    cout << " " << setw(22 + chuaCoNV.size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << chuaCoNV;
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(22 - chuaCoNV.size() / 2) << setfill(' ') << ""
         << " ║";
  }
  else
  {
    for (int i = 0; i < dsNV.size(); i++)
    {
      if (i >= 1)
      {
        if (tp != nullptr)
        {
          cout << "\n";
          cout << "║           ║              ║                  ║                      ║            ║                       ╠═════════╬════════════╬═══════════════════════╣\n";
          cout << "║           ║              ║                  ║                      ║            ║                       ║";
        }
        else
        {
          cout << "\n";
          cout << "║           ║              ║                  ║                      ║                                    ╠═════════╬════════════╬═══════════════════════╣\n";
          cout << "║           ║              ║                  ║                      ║                                    ║";
        }
      }
      cout << " " << setw(4 + 1.0 / 2) << setfill(' ');
      SetConsoleTextAttribute(color, brightYellow);
      cout << i + 1;
      SetConsoleTextAttribute(color, darkWhite);
      cout << setw(4 - 1.0 / 2) << setfill(' ') << ""
           << " ║";

      cout << " " << setw(5 + dsNV[i]->getMaSo().size() / 2) << setfill(' ');
      SetConsoleTextAttribute(color, brightYellow);
      cout << dsNV[i]->getMaSo();
      SetConsoleTextAttribute(color, darkWhite);
      cout << setw(5 - dsNV[i]->getMaSo().size() / 2) << setfill(' ') << ""
           << " ║";

      cout << " " << setw(10 + dsNV[i]->getHoTen().size() / 2) << setfill(' ');
      SetConsoleTextAttribute(color, brightYellow);
      cout << dsNV[i]->getHoTen();
      SetConsoleTextAttribute(color, darkWhite);
      cout << setw(10 - dsNV[i]->getHoTen().size() / 2) << setfill(' ') << ""
           << "  ║";
    }
  }
}