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
    bool headerPrinted = false;  // check xem header da duoc in hay chua
    while (it != dsNhanSu.end()) // duyet tu dau den cuoi vector
    {
      if (!headerPrinted) // neu header chua in
      {
        file << "Ma so\t"
             << "Ho ten\t"
             << "So dien thoai\t"
             << "Vi tri viec lam\t"
             << "So ngay lam viec\t"
             << "Luong\t"
             << "Ma phong ban\t"
             << "So luong task\t"
             << "Ma task\t"
             << "Ten task\t"
             << "Trang thai Task\t"
             << "Nguoi quan ly\t"
             << "Ma so\t"
             << "So luong nhan vien\t"
             << "Ho va ten nhan vien\t"
             << "Ma so nhan vien\t" << endl; // print header
        headerPrinted = true;                // set flag to true
      }
      NhanSu *ns = *it;
      // Kiem tra xem neu trong set co ma so roi thi ko xuat nua, con chua co thi xuat
      if (maSoSet.count(ns->getMaSo()) == 0) // neu ma so chua ton tai trong set
      {
        if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
        {
          if (nvt != nullptr)
          {
            nvt->tinhLuong();
            file << *nvt << endl;
            maSoSet.insert(nvt->getMaSo()); // them "Ma so moi xuat vao set"
            ++it;                           // tang iterator len 1
          }
        }
        else if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
        {
          if (tp != nullptr)
          {
            tp->tinhLuong();
            file << *tp << endl;
            maSoSet.insert(tp->getMaSo()); // them "Ma so moi xuat vao set"
            ++it;                          // tang iterator len 1
          }
        }
        else if (GiamDoc *gd = dynamic_cast<GiamDoc *>(ns))
        {
          if (gd != nullptr)
          {
            gd->tinhLuong();
            file << *gd << endl;
            maSoSet.insert(gd->getMaSo());
            ++it; // tang iterator len 1
          }
        }
      }
      // else // neu ma so da ton tai trong set
      // {
      //   it = dsNhanSu.erase(it); // xoa phan tu khoi vector
      //   delete ns;               // giai phong bo nho cua old data object
      // }
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

void danhSachNhanSu::inMenu(int &chon)
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = true; // set the cursor visibility
  SetConsoleCursorInfo(hConsole, &cursorInfo);

  cout << endl;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 11);
  cout << endl;
  cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
  cout << "\t\t\t\t╔═══╟════   Menu them nhan su  🧑‍💻════║═══╗\n";
  cout << "\t\t\t\t║   ╚═══════════════════════════════════╝   ║\n";
  cout << "\t\t\t\t║                                           ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "     1. Them truong phong";
  SetConsoleTextAttribute(color, 11);
  cout << "                  ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "     2. Them nhan vien thuong";
  SetConsoleTextAttribute(color, 11);
  cout << "              ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "     3. Them giam doc";
  SetConsoleTextAttribute(color, 11);
  cout << "                      ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "     0. Thoat khoi menu them nhan su";
  SetConsoleTextAttribute(color, 11);
  cout << "       ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "     > Moi chon 👉";
  SetConsoleTextAttribute(color, 11);
  cout << "                         ║\n";
  cout << "\t\t\t\t║                                           ║\n";
  cout << "\t\t\t\t╚═══════════════════════════════════════════╝\n\n";

  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  GetConsoleScreenBufferInfo(color, &consoleInfo);
  COORD cursorPosition = consoleInfo.dwCursorPosition;
  // Move the cursor to the right by incrementing X coordinate
  cursorPosition.X += 52;
  cursorPosition.Y -= 4;
  SetConsoleCursorPosition(color, cursorPosition);
  cin >> chon;

  SetConsoleTextAttribute(color, 7);
}

void danhSachNhanSu::nhap()
{
  bool flag = true;
  int chon;
  do
  {
    inMenu(chon);
    switch (chon)
    {
    case 1:
      ns = new TruongPhong();
      ns->setViTriViecLam("Truong Phong");
      ns->nhap();
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
      system("pause >nul");
      break;
    case 2:
      ns = new NhanVienThuong();
      ns->setViTriViecLam("Nhan Vien Thuong");
      ns->nhap();
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
      system("pause >nul");
      break;
    case 3:
      ns = new GiamDoc();
      ns->setViTriViecLam("Giam Doc");
      ns->nhap();
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
      system("pause >nul");
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
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  ghiFile("DanhSachNhanSu.txt");
  if (this->dsNhanSu.size() > 0)
  {

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
        ns->tinhLuong();
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
        ns->tinhLuong();
        ns->xuat();
        cout << "\t\t\t\t╚═════════════════════╩══════════════════════╝\n";
      }
    }
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tOOPS!!! Chua co nhan vien nao trong cong ty ❌\n";
    SetConsoleTextAttribute(color, 7);
    cout << endl;
  }
}

void danhSachNhanSu::xuatNV()
{
  vector<NhanVienThuong *> listNVT;
  for (NhanSu *ns : dsNhanSu)
  {
    if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nvt != nullptr)
      {
        listNVT.push_back(nvt);
      }
    }
  }
  bool flag = true;
  int chon;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
  cout << "\t\t\t\t╔═══║ ";
  SetConsoleTextAttribute(color, 11);
  cout << "  Nhan vien hoan thanh task    📂";
  SetConsoleTextAttribute(color, 7);
  cout << " ║════╗\n";
  cout << "\t\t\t\t║   ╚═════════════════╦═════════════════╝    ║\n";

  int j = 1;
  NhanVienThuong *lastNV = listNVT.back();
  for (NhanVienThuong *nvt : listNVT)
  {
    cout << "\t\t\t\t║  ";
    SetConsoleTextAttribute(color, 14);
    cout << "So thu tu          ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << j << std::right << " ║" << endl;
    nvt->xuat();
    if (nvt != lastNV)
    {
      cout << "\t\t\t\t╠═════════════════════╬══════════════════════╣\n";
    }
    else
    {
      cout << "\t\t\t\t╚═════════════════════╩══════════════════════╝\n";
    }
    j++;
  }
}

void danhSachNhanSu::xuatNV(vector<NhanVienThuong *> listNVT)
{
  bool flag = true;
  int chon;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
  cout << "\t\t\t\t╔═══║ ";
  SetConsoleTextAttribute(color, 11);
  cout << "     Danh sach nhan vien       📂";
  SetConsoleTextAttribute(color, 7);
  cout << " ║════╗\n";
  cout << "\t\t\t\t║   ╚═════════════════╦═════════════════╝    ║\n";

  int j = 1;
  NhanVienThuong *lastNV = listNVT.back();
  for (NhanVienThuong *nvt : listNVT)
  {
    cout << "\t\t\t\t║  ";
    SetConsoleTextAttribute(color, 14);
    cout << "So thu tu          ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << j << std::right << " ║" << endl;
    nvt->xuat();
    if (nvt != lastNV)
    {
      cout << "\t\t\t\t╠═════════════════════╬══════════════════════╣\n";
    }
    else
    {
      cout << "\t\t\t\t╚═════════════════════╩══════════════════════╝\n";
    }
    j++;
  }
}
