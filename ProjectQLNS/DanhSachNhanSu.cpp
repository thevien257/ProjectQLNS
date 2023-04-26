#include "DanhSachNhanSu.h"
#include "TruongPhong.h"
#include "GiamDoc.h"
#include "NhanVienThuong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include <set>
#include <windows.h>
using namespace std;

danhSachNhanSu::~danhSachNhanSu()
{
  delete[] ns;
}

// void danhSachNhanSu::ghiFile(string filename)
// {
//   ofstream file(filename);
//   if (file.is_open())
//   {
//     set<string> maSoSet; // tao set de du gia tri "Ma so"
//     for (NhanSu *ns : dsNhanSu)
//     {
//       // Kiem tra xem neu trong set co ma so roi thi ko xuat nua, con chua co thi xuat
//       if (maSoSet.count(ns->getMaSo()) == 0)
//       {
//         if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
//         {
//           if (nvt != nullptr)
//           {
//             file << *nvt << endl;
//             maSoSet.insert(nvt->getMaSo()); // them "Ma so moi xuat vao set"
//           }
//         }
//         else if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
//         {
//           if (tp != nullptr)
//           {
//             file << *tp << endl;
//             maSoSet.insert(tp->getMaSo()); // them "Ma so moi xuat vao set"
//           }
//         }
//         else if (GiamDoc *gd = dynamic_cast<GiamDoc *>(ns))
//         {
//           if (gd != nullptr)
//           {
//             file << *gd << endl;
//             maSoSet.insert(gd->getMaSo());
//           }
//         }
//       }
//     }
//     file.close();
//   }
//   else
//   {
//     cout << "Khong mo duoc file!" << endl;
//   }
// }

void danhSachNhanSu::ghiFile(string filename)
{
  ofstream file(filename);
  if (file.is_open())
  {
    set<string> maSoSet;         // tao set de du gia tri "Ma so"
    auto it = dsNhanSu.begin();  // tao iterator de duyet vector
    bool headerPrinted = false;  // flag to track if header has been printed
    while (it != dsNhanSu.end()) // duyet tu dau den cuoi vector
    {
      if (!headerPrinted) // if header has not been printed
      {
        file << "Ma so\t"
             << "Ho ten\t"
             << "So dien thoai\t"
             << "So ngay lam viec\t"
             << "Luong\t"
             << "Ma phong ban\t"
             << "Nguoi quan ly\t"
             << "Ma so\t"
             << "So luong nhan vien\t"
             << "Ho va ten\t"
             << "Ma so\t" << endl; // print header
        headerPrinted = true;      // set flag to true
      }
      NhanSu *ns = *it;
      // Kiem tra xem neu trong set co ma so roi thi ko xuat nua, con chua co thi xuat
      if (maSoSet.count(ns->getMaSo()) == 0)
      {
        if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
        {
          if (nvt != nullptr)
          {
            file << *nvt << endl;
            maSoSet.insert(nvt->getMaSo()); // them "Ma so moi xuat vao set"
            ++it;                           // tang iterator len 1
          }
        }
        else if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
        {
          if (tp != nullptr)
          {
            file << *tp << endl;
            maSoSet.insert(tp->getMaSo()); // them "Ma so moi xuat vao set"
            ++it;                          // tang iterator len 1
          }
        }
        else if (GiamDoc *gd = dynamic_cast<GiamDoc *>(ns))
        {
          if (gd != nullptr)
          {
            file << *gd << endl;
            maSoSet.insert(gd->getMaSo());
            ++it; // tang iterator len 1
          }
        }
      }
      else // neu ma so da ton tai trong set
      {
        it = dsNhanSu.erase(it); // xoa phan tu khoi vector
        delete ns;               // giai phong bo nho cua old data object
      }
    }
    file.close();
  }
  else
  {
    cout << "Khong mo duoc file!" << endl;
  }
}

danhSachNhanSu::danhSachNhanSu()
{
  docFileGD("GiamDoc.txt");
  docFileNVT("NVT.txt");
  docFileTP("TP.txt");
}

void danhSachNhanSu::docFileNVT(string filename)
{
  ifstream file(filename); // replace "ten_file.txt" with the name of your text file
  if (file.is_open())
  {
    while (file.good())
    {
      // read data from file and create new employee object
      NhanSu *ns = new NhanVienThuong(); // replace with appropriate subclass
      file >> *ns;
      ns->setViTriViecLam("Nhan vien thuong");
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
    }
    file.close();
  }
  else
  {
    cout << "Khong mo duoc file!" << endl;
  }
}

void danhSachNhanSu::docFileGD(string filename)
{
  ifstream file(filename); // replace "ten_file.txt" with the name of your text file
  if (file.is_open())
  {
    while (file.good())
    {
      // read data from file and create new employee object
      NhanSu *ns = new GiamDoc(); // replace with appropriate subclass
      file >> *ns;
      ns->setViTriViecLam("Giam doc");
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
    }
    file.close();
  }
  else
  {
    cout << "Khong mo duoc file!" << endl;
  }
}

void danhSachNhanSu::docFileTP(string filename)
{
  ifstream file(filename); // replace "ten_file.txt" with the name of your text file
  if (file.is_open())
  {
    while (file.good())
    {
      // read data from file and create new employee object
      NhanSu *ns = new TruongPhong(); // replace with appropriate subclass
      file >> *ns;
      ns->setViTriViecLam("Truong phong");
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
    }
    file.close();
  }
  else
  {
    cout << "Khong mo duoc file!" << endl;
  }
}

void danhSachNhanSu::setListNS(vector<NhanSu *> listNS)
{
  this->dsNhanSu = listNS;
}

vector<NhanSu *> &danhSachNhanSu::getListNS()
{
  return this->dsNhanSu;
}

void danhSachNhanSu::inMenu()
{
  std::system("cls");
  cout << "\t\t\t\t ___________________________________\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|        Menu Them nhan su          |\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|___________________________________|\n";
  cout << endl;
  cout << "\t\t\t\t1. Them truong phong " << endl;
  cout << "\t\t\t\t2. Them nhan vien thuong" << endl;
  cout << "\t\t\t\t3. Them giam doc" << endl;
  cout << "\t\t\t\t4. Thoat" << endl;
  cout << "\t\t\t\t--------------------> Moi chon: ";
}

void danhSachNhanSu::nhap()
{
  bool flag = true;
  int chon;
  do
  {
    inMenu();
    cin >> chon;
    switch (chon)
    {
    case 1:
      ns = new TruongPhong();
      ns->nhap();
      ns->tinhLuong();
      ns->setViTriViecLam("Truong Phong");
      this->dsNhanSu.push_back(ns);
      break;
    case 2:
      ns = new NhanVienThuong();
      ns->nhap();
      ns->tinhLuong();
      ns->setViTriViecLam("Nhan Vien Thuong");
      this->dsNhanSu.push_back(ns);
      break;
    case 3:
      ns = new GiamDoc();
      ns->nhap();
      ns->tinhLuong();
      ns->setViTriViecLam("Giam Doc");
      this->dsNhanSu.push_back(ns);
      break;
    case 0:
      flag = false;
      break;
    default:
      break;
    }
    std::system("cls");
  } while (flag);
}

void danhSachNhanSu::xuat()
{
  bool flag = true;
  int chon;
  ghiFile("DanhSachNhanSu.txt");
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
  cout << "\t\t\t\t╔═══║ ";
  SetConsoleTextAttribute(color, 11);
  cout << "Thong tin nhan su cua cong ty  📂";
  SetConsoleTextAttribute(color, 7);
  cout << " ║════╗\n";
  cout << "\t\t\t\t║   ╚═════════════════╦═════════════════╝    ║\n";

  int j = 1;
  NhanSu *lastNS = dsNhanSu.back();
  for (NhanSu *ns : dsNhanSu)
  {
    if (ns != lastNS)
    {
      cout << "\t\t\t\t║  ";
      SetConsoleTextAttribute(color, 14);
      cout << "So thu tu          ";
      SetConsoleTextAttribute(color, 7);
      cout << "║ " << std::left << std::setw(20) << j << std::right << " ║" << endl;
      ns->xuat();
      cout << "\t\t\t\t╠═════════════════════╬══════════════════════╣\n";
      j++;
    }
    else
    {
      cout << "\t\t\t\t║  ";
      SetConsoleTextAttribute(color, 14);
      cout << "So thu tu          ";
      SetConsoleTextAttribute(color, 7);
      cout << "║ " << std::left << std::setw(20) << j << std::right << " ║" << endl;
      ns->xuat();
      cout << "\t\t\t\t╚═════════════════════╩══════════════════════╝\n";
    }
  }
}