#include "XuLy.h"
#include "NhanVienThuong.h"
#include "GiamDoc.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <limits>
using namespace std;
#define WHITE 15

// Menu xử lý chung
void XuLy::XuLyChung()
{
  string taiKhoan;
  XuLyLogin(taiKhoan);

  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  string maTask;
  Task *task;

  SetConsoleTextAttribute(color, 14);
  cout << endl;
  int selectedOption = 1;
  bool exitMenu = false;
  bool printed = false;

  while (!exitMenu)
  {
    tatConTro();
    clearScreen();
    if (printed == false)
    {
      cout << endl;
      SetConsoleTextAttribute(color, 7);
      cout << "\t\t\t\t\t\tXin chao " << taiKhoan << " 👋 " << endl;
    }
    else
    {
      cout << endl;
      SetConsoleTextAttribute(color, 7);
      cout << "\t\t\t\t\t\t 🧑‍💼 " << taiKhoan << endl;
    }

    SetConsoleTextAttribute(color, 11);
    cout << endl;
    cout << "\t\t\t\t        ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═══════╟════ ";
    SetConsoleTextAttribute(color, 7);
    cout << " Menu Quan Ly Chung 🧑‍💻";
    SetConsoleTextAttribute(color, 11);
    cout << " ════║═════════╗\n";
    cout << "\t\t\t\t║       ╚═══════════════════════════════════╝         ║\n";
    cout << "\t\t\t\t║                                                     ║\n";
    for (int i = 1; i <= 4; i++)
    {
      if (i == selectedOption)
      {
        SetConsoleTextAttribute(color, 11);
        cout << "\t\t\t\t║";
        SetConsoleTextAttribute(color, 11);
        cout << "      👉    ";
      }
      else
      {
        SetConsoleTextAttribute(color, 11);
        cout << "\t\t\t\t║            ";
        SetConsoleTextAttribute(color, 7);
      }

      switch (i)
      {
      case 1:
        cout << std::left << std::setw(40) << "Quan ly nhan su" << std::right;
        break;
      case 2:
        cout << std::left << std::setw(40) << "Quan ly phong ban" << std::right;
        break;
      case 3:
        cout << std::left << std::setw(40) << "Quan ly task" << std::right;
        break;
      case 4:
        cout << std::left << std::setw(40) << "Thoat chuong trinh" << std::right;
        break;
      }
      SetConsoleTextAttribute(color, 11);
      cout << " ║\n";
    }
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\t║                                                     ║\n";
    cout << "\t\t\t\t╚═════════════════════════════════════════════════════╝\n";

    SetConsoleTextAttribute(color, 7);
    char input = getch();

    switch (input)
    {
    case 72:
      if (selectedOption > 1)
        selectedOption--;
      break;
    case 80:
      if (selectedOption < 4)
        selectedOption++;
      break;
    case 13:
      switch (selectedOption)
      {
      case 1:
        XuLyMenuNhanSu();
        break;
      case 2:
        xuLyMenuPhongBan();
        break;
      case 3:
        xuLyMenuTask();
        break;
      case 4:
        cout << endl;
        system("cls");
        tatConTro();
        SetConsoleTextAttribute(color, 3);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t\tSee you next time 😁" << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
        printGoodBye();
        system("pause > nul");
        exit(1);
        break;
      }
      printed = true;
      system("cls");
    }
  }
}

// Xử lý menu nhân sự
void XuLy::XuLyMenuNhanSu()
{
  bool flag = true;
  int chon;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  system("cls");
  do
  {
    InMenuQuanLyNhanSu(chon);
    switch (chon)
    {
    case 1:
      ds.nhap();
      break;
    case 2:
      cout << endl;
      cout << endl;
      cout << endl;
      ds.xuat();
      break;
    case 3:
      cout << endl;
      cout << endl;
      cout << endl;
      SapXepTheoTen();
      break;
    case 4:
      cout << endl;
      cout << endl;
      cout << endl;
      sapXepLuongGiamDan();
      break;
    case 5:
      cout << endl;
      cout << endl;
      cout << endl;
      timNhanSuTheoMaSo();
      break;
    case 6:
      cout << endl;
      cout << endl;
      cout << endl;
      timNhanSuTheoTen();
      break;
    case 7:
      cout << endl;
      cout << endl;
      cout << endl;
      timNVLuongCaoNhat();
      break;
    case 8:
      cout << endl;
      cout << endl;
      cout << endl;
      suaDoiThongTinNhanSu();
      break;
    case 9:
      cout << endl;
      cout << endl;
      cout << endl;
      xoaNhanSu();
      break;
    case 0:
      flag = false;
      break;
    default:
      break;
    }
  } while (flag);
}

// Xử lý menu phòng ban
void XuLy::xuLyMenuPhongBan()
{
  clearScreen();
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;

  int selectedOption = 1;
  bool exitMenu = false;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

  while (!exitMenu)
  {
    tatConTro();
    SetConsoleTextAttribute(color, 11);
    clearScreen();
    cout << endl;
    cout << "\t\t\t\t          ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═════════╟════ ";
    SetConsoleTextAttribute(color, 7);
    cout << "Menu Quan Ly Phong Ban 🏢";
    SetConsoleTextAttribute(color, 11);
    cout << " ════║═══════════╗\n";
    cout << "\t\t\t\t║         ╚═══════════════════════════════════╝           ║\n";
    cout << "\t\t\t\t║                                                         ║\n";

    for (int i = 1; i <= 12; i++)
    {
      if (i == selectedOption)
      {
        SetConsoleTextAttribute(color, 11);
        cout << "\t\t\t\t║";
        SetConsoleTextAttribute(color, 11);
        cout << " 👉   ";
      }
      else
      {
        SetConsoleTextAttribute(color, 11);
        cout << "\t\t\t\t║      ";
        SetConsoleTextAttribute(color, 7);
      }

      switch (i)
      {
      case 1:
        cout << std::left << std::setw(50) << "Them phong ban" << std::right;
        break;
      case 2:
        cout << std::left << std::setw(50) << "Xuat phong ban" << std::right;
        break;
      case 3:
        cout << std::left << std::setw(50) << "Phan bo nhan vien ve phong ban" << std::right;
        break;
      case 4:
        cout << std::left << std::setw(50) << "Chi dinh truong phong ve phong ban" << std::right;
        break;
      case 5:
        cout << std::left << std::setw(50) << "Phan bo nhan vien cho phong ban cu the" << std::right;
        break;
      case 6:
        cout << std::left << std::setw(50) << "Chi dinh truong phong cho phong ban cu the" << std::right;
        break;
      case 7:
        cout << std::left << std::setw(50) << "Xoa truong phong khoi phong ban" << std::right;
        break;
      case 8:
        cout << std::left << std::setw(50) << "Xoa nhan vien khoi phong ban" << std::right;
        break;
      case 9:
        cout << std::left << std::setw(50) << "Xoa phong ban" << std::right;
        break;
      case 10:
        cout << std::left << std::setw(50) << "Sap xep so luong nhan su theo thu tu giam dan" << std::right;
        break;
      case 11:
        cout << std::left << std::setw(50) << "Sap xep so luong nhan su theo thu tu tang dan" << std::right;
        break;
      case 12:
        cout << std::left << std::setw(50) << "Thoat khoi menu quan ly phong ban" << std::right;
        break;
      }
      SetConsoleTextAttribute(color, 11);
      cout << " ║\n";
    }
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\t║                                                         ║\n";
    cout << "\t\t\t\t╚═════════════════════════════════════════════════════════╝\n";

    SetConsoleTextAttribute(color, 7);
    char input = getch();

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    switch (input)
    {
    case 72:
      if (selectedOption > 1)
        selectedOption--;
      break;
    case 80:
      if (selectedOption < 12)
        selectedOption++;
      break;
    case 13:
      switch (selectedOption)
      {
      case 1:
        dsPB.nhapPB();
        break;
      case 2:
        dsPB.xuatPB();
        break;
      case 3:
        phanBoNhanVienThuongVaoPhongBan();
        break;
      case 4:
        chiDinhTruongPhong();
        break;
      case 5:
        phanBoCuTheNVT();
        break;
      case 6:
        chiDinhCuTheTruongPhong();
        break;
      case 7:
        xoaTPkhoiPB();
        break;
      case 8:
        xoaNVkhoiPB();
        break;
      case 9:
        xoaPB();
        break;
      case 10:
        sapXepSoLuongNhanSuPBGD();
        break;
      case 11:
        sapXepSoLuongNhanSuPBTD();
        break;
      case 12:
        exitMenu = true;
        break;
      }
      if (selectedOption != 12)
      {
        tatConTro();
        system("pause >nul");
      }
      system("cls");
    }
  }
}

// Xử lý menu Task
void XuLy::xuLyMenuTask()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;

  int selectedOption = 1;
  bool exitMenu = false;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

  while (!exitMenu)
  {
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    SetConsoleTextAttribute(color, 11);
    clearScreen();
    cout << endl;
    cout << "\t\t\t\t          ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═════════╟════ ";
    SetConsoleTextAttribute(color, 7);
    cout << "   Menu Quan Ly Task📋   ";
    SetConsoleTextAttribute(color, 11);
    cout << " ════║═══════════╗\n";
    cout << "\t\t\t\t║         ╚═══════════════════════════════════╝           ║\n";
    cout << "\t\t\t\t║                                                         ║\n";

    for (int i = 1; i <= 10; i++)
    {
      if (i == selectedOption)
      {
        SetConsoleTextAttribute(color, 11);
        cout << "\t\t\t\t║";
        SetConsoleTextAttribute(color, 11);
        cout << " 👉   ";
      }
      else
      {
        SetConsoleTextAttribute(color, 11);
        cout << "\t\t\t\t║      ";
        SetConsoleTextAttribute(color, 7);
      }

      switch (i)
      {
      case 1:
        cout << std::left << std::setw(50) << "Them Task" << std::right;
        break;
      case 2:
        cout << std::left << std::setw(50) << "Xuat Task" << std::right;
        break;
      case 3:
        cout << std::left << std::setw(50) << "Xoa task" << std::right;
        break;
      case 4:
        cout << std::left << std::setw(50) << "Phan bo task cho nhan vien" << std::right;
        break;
      case 5:
        cout << std::left << std::setw(50) << "Phan bo task cho nhan vien cu the" << std::right;
        break;
      case 6:
        cout << std::left << std::setw(50) << "Sap xep nhan vien hoan thanh nhieu task nhat" << std::right;
        break;
      case 7:
        cout << std::left << std::setw(50) << "Sap xep nhan vien co nhieu task nhat" << std::right;
        break;
      case 8:
        cout << std::left << std::setw(50) << "Xoa Task khoi nhan vien" << std::right;
        break;
      case 9:
        cout << std::left << std::setw(50) << "Danh gia task" << std::right;
        break;
      case 10:
        cout << std::left << std::setw(50) << "Thoat khoi menu quan ly task" << std::right;
        break;
      }
      SetConsoleTextAttribute(color, 11);
      cout << " ║\n";
    }
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\t║                                                         ║\n";
    cout << "\t\t\t\t╚═════════════════════════════════════════════════════════╝\n";

    SetConsoleTextAttribute(color, 7);
    char input = getch();

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    switch (input)
    {
    case 72:
      if (selectedOption > 1)
        selectedOption--;
      break;
    case 80:
      if (selectedOption < 10)
        selectedOption++;
      break;
    case 13:
      switch (selectedOption)
      {
      case 1:
        dsTask.nhapTask();
        break;
      case 2:
        dsTask.xuatTask();
        break;
      case 3:
        xoaTask();
        break;
      case 4:
        phanBoTask();
        break;
      case 5:
        phanBoTaskChoNhanVienCuThe();
        break;
      case 6:
        sapXepTaskHoanThanh();
        break;
      case 7:
        sapXepSoLuongTaskNV();
        break;
      case 8:
        xoaTaskKhoiNV();
        break;
      case 9:
        danhGiaTask();
        break;
      case 10:
        exitMenu = true;
        break;
      }
      if (selectedOption != 10)
      {
        tatConTro();
        system("pause >nul");
      }
      system("cls");
    }
  }
}

void XuLy::phanBoTaskChoNhanVienCuThe()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  bool check = checkCoTaskTrongListTaskHayKhong();
  bool checkNVT = checkCoNVTrongListNSHayKhong();
  if (checkNVT == false || check == false)
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t\tKhong co nhan vien hoac task nao trong danh sach" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }

  string maNV;
  string maTask;
  cout << endl;
  cout << "\t\t\t\t\tDay la danh sach task 📜 " << endl;
  dsTask.xuatTask();
  cout << "\t\t\t\t\tDay la danh sach nhan vien 📜 " << endl;
  ds.xuatMaSoVaTenNVTask();
  NhanVienThuong *nvt;
  Task *task = nullptr;

  do
  {
    cout << "\t\t\t\t📝 Phan bo task mang ma so:           cho nhan vien mang ma so:        ";
    SetConsoleTextAttribute(color, 11);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(color, &consoleInfo);
    COORD cursorPosition = consoleInfo.dwCursorPosition;
    cursorPosition.X -= 43;
    SetConsoleCursorPosition(color, cursorPosition);
    cin >> maTask;
    if (maTask == "0")
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\tBan da thoat khoi chuc nang phan bo task 🔓" << endl;
      SetConsoleTextAttribute(color, 7);
      return;
    }

    task = timTask(maTask);
    if (task == nullptr || task->getMaNV() != "")
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\t❌ Khong tim thay task co ma so nay hoac task nay da co nhan vien thuc hien." << endl;
      SetConsoleTextAttribute(color, 7);
    }
    else
    {
      SetConsoleTextAttribute(color, 11);
      CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
      GetConsoleScreenBufferInfo(color, &consoleInfo);
      COORD cursorPosition = consoleInfo.dwCursorPosition;
      cursorPosition.X += 96;
      cursorPosition.Y -= 1;
      SetConsoleCursorPosition(color, cursorPosition);
      cin >> maNV;
      if (maNV == "0")
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\tBan da thoat khoi chuc nang phan bo task 🔓" << endl;
        SetConsoleTextAttribute(color, 7);
        return;
      }
      nvt = timNVT(maNV);
      if (nvt == nullptr)
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\t❌ Khong tim thay nhan vien co ma so nay." << endl;
        SetConsoleTextAttribute(color, 7);
      }
    }
  } while (task == nullptr || nvt == nullptr || task->getMaNV() != "");

  task->setMaNV(nvt->getMaSo());
  nvt->getDSTask().push_back(task);
  nvt->tangSoLuongTask();

  cout << endl;
  SetConsoleTextAttribute(color, 10);
  cout << "\t\t\t\t✅ Da phan bo task ";
  SetConsoleTextAttribute(color, 7);
  cout << task->getTenTask();
  SetConsoleTextAttribute(color, 10);
  cout << " mang ma so ";
  SetConsoleTextAttribute(color, 7);
  cout << task->getMaTask();
  SetConsoleTextAttribute(color, 10);
  cout << " cho ";
  SetConsoleTextAttribute(color, 7);
  cout << nvt->getHoTen();
  SetConsoleTextAttribute(color, 10);
  cout << " mang ma so ";
  SetConsoleTextAttribute(color, 7);
  cout << nvt->getMaSo();
  cout << endl;
}

bool XuLy::existedCheck(string &kitu)
{
  for (NhanSu *ns : ds.getListNS())
  {
    if (ns->getHoTen().find(kitu) != string::npos)
    {
      return true;
    }
  }
  return false;
}

void XuLy::timNhanSuTheoTen()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkCoNhanSuHayKhong() == false)
  {
    return;
  }

  string kitu;
  vector<NhanSu *> listNSFound;
  cout << "\t\t\t\t 👉 Nhap ten muon tim kiem: ";

  SetConsoleTextAttribute(color, 11);
  cin.ignore();
  getline(cin, kitu);

  bool existed = existedCheck(kitu);
  if (existed == true)
  {
    cout << endl;
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\t\t\tDa tim thay nhan su ✅" << endl;
    SetConsoleTextAttribute(color, 7);
    cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═══║ ";
    SetConsoleTextAttribute(color, 11);
    cout << "       Thong tin nhan su  📂";
    SetConsoleTextAttribute(color, 7);
    cout << "      ║════╗\n";
    cout << "\t\t\t\t║   ╚═══════════════════════════════════╝    ║\n";
    SetConsoleTextAttribute(color, 7);
    for (NhanSu *ns : ds.getListNS())
    {
      if (ns->getHoTen().find(kitu) != string::npos)
      {
        listNSFound.push_back(ns);
      }
    }
    NhanSu *lastNS = listNSFound.back();
    for (NhanSu *ns : listNSFound)
    {
      ns->xuat();
      if (ns != lastNS)
      {
        cout << "\t\t\t\t╠═════════════════════╬══════════════════════╣\n";
      }
      else
      {
        cout << "\t\t\t\t╚═════════════════════╩══════════════════════╝\n";
      }
    }
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tOOPS! Khong tim thay nhan su voi ten " << kitu << " 🥲" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

void XuLy::thucHienPhanBoTruongPhong(PhongBan *pb, TruongPhong *tp, string maPB)
{
  if (pb != nullptr)
  {
    if (tp->getMaPhongBan() != "" && tp->getMaPhongBan() != pb->getMaPhongBan())
    {
      for (PhongBan *pb : dsPB.getDsPhongBan())
      {
        if (tp->getMaPhongBan() != "")
        {
          if (tp->getMaPhongBan() == pb->getMaPhongBan()) // Nếu trưởng phòng này bằng với một phòng ban nào đó -> Phải thực hiện xóa trưởng phòng khỏi phòng ban đó
          {
            pb->setTruongPhong(nullptr);
            pb->giamSoLuongNhanSu();
            if (pb->getDsNV().size() > 0)
            {
              for (NhanVienThuong *nv : pb->getDsNV())
              {
                if (nv != nullptr)
                {
                  if (nv->getMaPhongBan() == tp->getMaPhongBan())
                  {
                    nv->setTruongPhong(nullptr);
                    tp->giamNhanVien();
                    tp->getListNV().erase(remove(tp->getListNV().begin(), tp->getListNV().end(), nv), tp->getListNV().end());
                  }
                }
              }
            }
          }
        }
      }
    }
    tp->setMaPhongBan(maPB);
    pb->setTruongPhong(tp);
    pb->tangSoLuongNhanSu();

    if (pb->getDsNV().size() > 0)
    {
      for (NhanSu *ns : ds.getListNS())
      {
        if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
        {
          if (nvt != nullptr)
          {
            if (nvt->getMaPhongBan() == pb->getMaPhongBan())
            {
              tp->getListNV().push_back(nvt);
              tp->tangNhanVien();
              nvt->setTruongPhong(tp);
            }
          }
        }
      }
    }
  }
}

void XuLy::chiDinhCuTheTruongPhong()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  bool check = checkCoTPTrongListNSHayKhong();
  if (check)
  {
    string maTP;
    string maPB;
    cout << endl;
    cout << "\t\t\t\t\tDay la danh sach truong phong 📜 " << endl;
    ds.xuatMaSoVaTenTP();
    cout << "\t\t\t\t\tDay la danh sach phong ban 📜 " << endl;
    dsPB.xuatPB();
    TruongPhong *tp = nullptr;
    PhongBan *pb = nullptr;
    do
    {
      cout << "\t\t\t\t📝 Phan bo truong phong mang ma so:        den phong ban mang ma so:        ";
      SetConsoleTextAttribute(color, 11);
      CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
      GetConsoleScreenBufferInfo(color, &consoleInfo);
      COORD cursorPosition = consoleInfo.dwCursorPosition;
      cursorPosition.X -= 40;
      SetConsoleCursorPosition(color, cursorPosition);
      cin >> maTP;
      if (maTP == "0")
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\tBan da chon thoat khoi chuc nang phan bo truong phong 🔓" << endl;
        SetConsoleTextAttribute(color, 7);
        return;
      }
      tp = timTruongPhongTheoMa(maTP);
      if (tp == nullptr)
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\t❌ Ma truong phong khong ton tai. Moi nhap lai!" << endl;
        SetConsoleTextAttribute(color, 7);
      }
      else
      {
        SetConsoleTextAttribute(color, 11);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        GetConsoleScreenBufferInfo(color, &consoleInfo);
        COORD cursorPosition = consoleInfo.dwCursorPosition;
        cursorPosition.X += 101;
        cursorPosition.Y -= 1;
        SetConsoleCursorPosition(color, cursorPosition);
        cin >> maPB;
        if (maPB == "0")
        {
          SetConsoleTextAttribute(color, 12);
          cout << "\t\t\t\tBan da chon thoat khoi chuc nang phan bo truong phong 🔓" << endl;
          SetConsoleTextAttribute(color, 7);
          return;
        }

        pb = timPhongBan(maPB);
        if (pb == nullptr || pb->getTruongPhong() != nullptr)
        {
          SetConsoleTextAttribute(color, 12);
          cout << "\t\t\t\t❌ Ma phong ban khong ton tai hoac phong ban nay da co truong phong. Moi nhap lai!" << endl;
          SetConsoleTextAttribute(color, 7);
        }
      }
    } while (pb == nullptr || tp == nullptr || pb->getTruongPhong() != nullptr);

    thucHienPhanBoTruongPhong(pb, tp, maPB);

    cout << endl;
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\t✅ Da chuyen truong phong ";
    SetConsoleTextAttribute(color, 7);
    cout << tp->getHoTen();
    SetConsoleTextAttribute(color, 10);
    cout << " mang ma so ";
    SetConsoleTextAttribute(color, 7);
    cout << tp->getMaSo();
    SetConsoleTextAttribute(color, 10);
    cout << " den ";
    SetConsoleTextAttribute(color, 7);
    cout << pb->getTenPhongBan();
    SetConsoleTextAttribute(color, 10);
    cout << " mang ma so ";
    SetConsoleTextAttribute(color, 7);
    cout << pb->getMaPhongBan();
    cout << endl;
  }

  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Chua co truong phong trong he thong!" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

bool XuLy::checkCoNhanVienHayKhong()
{
  for (PhongBan *pb : dsPB.getDsPhongBan())
  {
    if (pb->getDsNV().size() > 0)
    {
      return true;
    }
  }
  return false;
}

bool XuLy::checkCoTruongPhongHayKhong()
{
  for (PhongBan *pb : dsPB.getDsPhongBan())
  {
    if (pb->getTruongPhong() != nullptr)
    {
      return true;
    }
  }
  return false;
}

bool XuLy::checkCoTaskHayKhong()
{

  for (Task *task : dsTask.getDSTask())
  {
    if (task->getMaNV() != "")
    {
      return true;
    }
  }
  return false;
}

void XuLy::thucHienPhanBoNhanVienThuong(PhongBan *pb, NhanVienThuong *nvt, string maPB)
{
  // Nếu nhân viên đang ở trong phòng ban nào đó, xóa nhân viên này khỏi phòng ban đó
  if (nvt->getMaPhongBan() != "")
  {
    for (PhongBan *pb : dsPB.getDsPhongBan())
    {
      if (nvt->getMaPhongBan() != "")
      {
        if (nvt->getMaPhongBan() == pb->getMaPhongBan())
        {
          pb->getDsNV().erase(remove(pb->getDsNV().begin(), pb->getDsNV().end(), nvt), pb->getDsNV().end());
          pb->giamSoLuongNhanSu();
        }
      }
      else
      {
        break;
      }
    }
  }

  // Nếu nhân viên đang được quản lý bởi trưởng phòng nào đó thì xóa nhân viên này khỏi danh sách nhân viên của trưởng phòng đó và setTP của nhân viên này thành nullptr
  if (nvt->getTruongPhong() != nullptr)
  {
    nvt->setTruongPhong(nullptr);
    for (NhanSu *ns : ds.getListNS())
    {
      if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
      {
        if (tp != nullptr)
        {
          if (tp->getMaPhongBan() == nvt->getMaPhongBan())
          {
            tp->getListNV().erase(remove(tp->getListNV().begin(), tp->getListNV().end(), nvt), tp->getListNV().end());
            tp->giamNhanVien();
          }
        }
      }
    }
  }

  // Thực hiện phân bổ lại nhân viên này vào phòng ban mới
  nvt->setMaPhongBan(maPB);
  pb->getDsNV().push_back(nvt);
  pb->tangSoLuongNhanSu();
  if (pb->getTruongPhong() != nullptr)
  {
    pb->getTruongPhong()->getListNV().push_back(nvt);
    pb->getTruongPhong()->tangNhanVien();
    nvt->setTruongPhong(pb->getTruongPhong());
  }
}

void XuLy::sapXepSoLuongNhanSuPBGD()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkCoNhanSuHayKhong() == false)
  {
    return;
  }

  vector<PhongBan *> sortedPB = dsPB.getDsPhongBan();

  if (dsPB.getDsPhongBan().size() > 0)
  {
    sort(sortedPB.begin(), sortedPB.end(), [](PhongBan *pb1, PhongBan *pb2)
         { return pb1->getSoluongNhanSu() > pb2->getSoluongNhanSu(); });

    dsPB.setDsPhongBan(sortedPB);

    bool isSorted = true;
    int n = sortedPB.size();
    for (int i = 0; i < n - 1; i++)
    {
      if (sortedPB.front()->getSoluongNhanSu() <= sortedPB.back()->getSoluongNhanSu())
      {
        isSorted = false;
        break;
      }
      if (sortedPB[i]->getSoluongNhanSu() > sortedPB[i + 1]->getSoluongNhanSu())
      {
        isSorted = true;
      }
      else if (sortedPB[i]->getSoluongNhanSu() < sortedPB[i + 1]->getSoluongNhanSu())
      {
        isSorted = false;
        break;
      }
    }

    if (isSorted)
    {
      SetConsoleTextAttribute(color, 10);
      cout << endl;
      cout << "\t\t\t\tDa sap xep theo thu tu giam dan ✅" << endl;
      SetConsoleTextAttribute(color, 7);
      dsPB.xuatPB();
    }
    else
    {
      SetConsoleTextAttribute(color, 12);
      cout << endl;
      cout << "\t\t\t\t\tDanh sach chua duoc sap xep ❌" << endl;
      SetConsoleTextAttribute(color, 7);
    }
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tDanh sach phong ban rong ❌" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

void XuLy::sapXepSoLuongNhanSuPBTD()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkCoNhanSuHayKhong() == false)
  {
    return;
  }
  vector<PhongBan *> sortedPB = dsPB.getDsPhongBan();
  if (dsPB.getDsPhongBan().size() > 0)
  {
    sort(sortedPB.begin(), sortedPB.end(), [](PhongBan *pb1, PhongBan *pb2)
         { return pb1->getSoluongNhanSu() < pb2->getSoluongNhanSu(); });

    dsPB.setDsPhongBan(sortedPB);

    bool isSorted = true;
    int n = sortedPB.size();
    for (int i = 0; i < n - 1; i++)
    {
      if (sortedPB.front()->getSoluongNhanSu() >= sortedPB.back()->getSoluongNhanSu())
      {
        isSorted = false;
        break;
      }
      if (sortedPB[i]->getSoluongNhanSu() < sortedPB[i + 1]->getSoluongNhanSu())
      {
        isSorted = true;
      }
      else if (sortedPB[i]->getSoluongNhanSu() > sortedPB[i + 1]->getSoluongNhanSu())
      {
        isSorted = false;
        break;
      }
    }

    if (isSorted)
    {
      SetConsoleTextAttribute(color, 10);
      cout << endl;
      cout << "\t\t\t\tDa sap xep theo thu tu tang dan ✅" << endl;
      SetConsoleTextAttribute(color, 7);
      dsPB.xuatPB();
    }
    else
    {
      SetConsoleTextAttribute(color, 12);
      cout << endl;
      cout << "\t\t\t\t\tDanh sach chua duoc sap xep ❌" << endl;
      SetConsoleTextAttribute(color, 7);
    }
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tDanh sach phong ban rong ❌" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

void XuLy::xoaPB()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkCoPhongBanHayKhong() == false)
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tDanh sach phong ban rong ❌" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }

  cout << endl;
  SetConsoleTextAttribute(color, 14);
  cout << "\t\t\t\t\tDay la danh sach phong ban 📜 " << endl;
  SetConsoleTextAttribute(color, 7);
  dsPB.xuatPB();

  string maPB;
  PhongBan *pb;
  do
  {
    cout << "\t\t\t\tNhap ma so phong ban hoac nhap 0 de thoat: ";
    cin >> maPB;
    pb = timPhongBan(maPB);
    if (maPB == "0")
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\tBan da thoat khoi chuc nang xoa phong ban 🔓" << endl;
      SetConsoleTextAttribute(color, 7);
      return;
    }
    if (pb == nullptr)
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\tPhong ban khong hop le! Nhap lai di anh ban! " << endl;
      SetConsoleTextAttribute(color, 7);
      cout << endl;
    }
  } while (pb == nullptr);

  for (NhanSu *ns : ds.getListNS())
  {
    if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
    {
      if (tp != nullptr && tp->getMaPhongBan() == maPB)
      {
        for (auto it = tp->getListNV().begin(); it != tp->getListNV().end();)
        {
          if ((*it)->getMaPhongBan() == tp->getMaPhongBan())
          {
            it = tp->getListNV().erase(it); // Gán lại cái it hiện tại (it đã xóa đi) để duyệt đến it tiếp theo
            tp->giamNhanVien();
          }
          else
          {
            ++it;
          }
        }
      }
    }
  }

  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nv = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nv != nullptr && nv->getMaPhongBan() == maPB)
      {
        nv->setMaPhongBan("");
        nv->setTruongPhong(nullptr);
      }
    }
  }

  for (NhanSu *ns : ds.getListNS())
  {
    if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
    {
      if (tp->getMaPhongBan() == pb->getMaPhongBan())
      {
        tp->setMaPhongBan("");
        pb->giamSoLuongNhanSu();
      }
    }
  }

  pb->setTruongPhong(nullptr);

  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nv = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nv != nullptr && nv->getMaPhongBan() == pb->getMaPhongBan())
      {
        pb->getDsNV().erase(remove(pb->getDsNV().begin(), pb->getDsNV().end(), nv), pb->getDsNV().end());
        pb->giamSoLuongNhanSu();
      }
    }
  }

  for (PhongBan *pb : dsPB.getDsPhongBan())
  {
    if (pb != nullptr && pb->getMaPhongBan() == maPB)
    {
      dsPB.getDsPhongBan().erase(remove(dsPB.getDsPhongBan().begin(), dsPB.getDsPhongBan().end(), pb), dsPB.getDsPhongBan().end());
    }
  }
  SetConsoleTextAttribute(color, 10);
  cout << "\t\t\t\tDa xoa " << pb->getTenPhongBan() << " mang ma so " << pb->getMaPhongBan() << " thanh cong ✅ " << endl;
  SetConsoleTextAttribute(color, 7);
}

bool XuLy::checkCoPhongBanHayKhong()
{

  if (dsPB.getDsPhongBan().size() == 0)
  {
    return false;
  }
  return true;
}

bool XuLy::checkCoNVTrongListNSHayKhong()
{
  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nv = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nv != nullptr)
      {
        return true;
      }
    }
  }
  return false;
}

void XuLy::xoaTPkhoiPB()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  TruongPhong *tp;
  string maTP;
  bool check = checkCoTruongPhongHayKhong();

  if (check)
  {
    cout << "\t\t\t\tDay la danh sach truong phong trong phong ban 📜 " << endl;
    dsPB.xuatPB();

    do
    {
      cout << endl;

      cout << "\t\t\t\tNhap ma so truong phong: ";
      cin >> maTP;

      tp = timTruongPhongTheoMa(maTP);
      if (tp == nullptr)
      {
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\t\t\t\tKhong tim thay Truong Phong co ma " << maTP << endl;
        SetConsoleTextAttribute(color, 7);
      }

    } while (tp == nullptr);

    for (PhongBan *pb : dsPB.getDsPhongBan())
    {
      if (pb != nullptr && pb->getMaPhongBan() == tp->getMaPhongBan())
      {
        pb->setTruongPhong(nullptr);
        pb->giamSoLuongNhanSu();
      }
    }

    for (NhanSu *ns : ds.getListNS())
    {
      if (NhanVienThuong *nv = dynamic_cast<NhanVienThuong *>(ns))
      {
        if (nv != nullptr && nv->getMaPhongBan() == tp->getMaPhongBan())
        {
          nv->setTruongPhong(nullptr);
        }
      }
    }

    for (auto it = tp->getListNV().begin(); it != tp->getListNV().end();)
    {
      if ((*it)->getMaPhongBan() == tp->getMaPhongBan())
      {
        it = tp->getListNV().erase(it);
        tp->giamNhanVien();
      }
      else
      {
        ++it;
      }
    }

    tp->setMaPhongBan("");
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\tDa xoa " << tp->getHoTen() << " mang ma so " << tp->getMaSo() << " thanh cong ✅ ";
    SetConsoleTextAttribute(color, 7);
    cout << endl;
  }
  else
  {
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t\t\t\tCac truong phong chua duoc phan bo de thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

void XuLy::xoaNVkhoiPB()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  string maNV;
  NhanVienThuong *nv = nullptr;
  bool check = checkCoNhanVienHayKhong();

  if (check)
  {
    cout << endl;
    cout << "\t\t\t\tDay la danh sach nhan vien trong phong ban 📜 " << endl;
    dsPB.xuatPB();
    do
    {
      cout << endl;
      cout << "\t\t\t\tNhap ma so nhan vien hoac nhap 0 de thoat: ";
      cin >> maNV;
      if (maNV == "0")
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\tBan da thoat khoi chuc nang xoa nhan vien khoi phong ban 🔓" << endl;
        SetConsoleTextAttribute(color, 7);
        return;
      }
      nv = timNVT(maNV);
      if (nv == nullptr)
      {
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\t\t\t\tKhong tim thay nhan vien co ma " << maNV << endl;
        SetConsoleTextAttribute(color, 7);
      }
    } while (nv == nullptr);
    for (PhongBan *pb : dsPB.getDsPhongBan())
    {
      if (nv != nullptr)
      {
        if (pb->getMaPhongBan() == nv->getMaPhongBan())
        {
          nv->setMaPhongBan("");
          nv->setTruongPhong(nullptr);
          pb->getDsNV().erase(remove(pb->getDsNV().begin(), pb->getDsNV().end(), nv), pb->getDsNV().end());
          pb->giamSoLuongNhanSu();
        }
      }
    }
    for (NhanSu *ns : ds.getListNS())
    {
      if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
      {
        if (tp != nullptr)
        {
          for (NhanVienThuong *nv : tp->getListNV())
          {
            if (nv != nullptr)
            {
              if (nv->getMaSo() == maNV)
              {
                tp->getListNV().erase(remove(tp->getListNV().begin(), tp->getListNV().end(), nv), tp->getListNV().end());
                tp->giamNhanVien();
              }
            }
          }
        }
      }
    }
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\tDa xoa " << nv->getHoTen() << " mang ma so " << nv->getMaSo() << " thanh cong ✅ " << endl;
    SetConsoleTextAttribute(color, 7);
    cout << endl;
  }
  else
  {
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t\t\t\tCac nhan vien chua duoc phan bo de thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

NhanVienThuong *XuLy::timNVT(string maNV)
{
  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nv = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nv != nullptr)
      {
        if (nv->getMaSo() == maNV)
        {
          return nv;
        }
      }
    }
  }
  return nullptr;
}

void XuLy::checkCin()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  SetConsoleTextAttribute(color, 12);
  cout << "\t\t\t\t❌ Chi duoc chon 1 hoac 2" << endl;
  SetConsoleTextAttribute(color, 7);
}

bool XuLy::checkCoTPTrongListNSHayKhong()
{
  for (NhanSu *ns : ds.getListNS())
  {
    if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
    {
      if (tp != nullptr)
      {
        return true;
      }
    }
  }
  return false;
}

void XuLy::chiDinhTruongPhong()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkCoTPTrongListNSHayKhong() == false)
  {
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t\t\t\tHien tai khong co truong phong nao trong he thong de thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }
  if (checkCoPhongBanHayKhong() == false)
  {
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t\t\t\tHien tai khong co phong ban nao trong he thong de thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }
  for (NhanSu *ns : ds.getListNS())
  {
    if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
    {
      if (tp != nullptr)
      {
        bool flag = true;
        do
        {
          cout << endl;
          SetConsoleTextAttribute(color, 11);
          cout << "\t\t\t\t📝 Dang phan bo truong phong: " << endl;
          cout << "\t\t\t\tMa so: " << tp->getMaSo() << "\t"
               << "Ho ten: " << tp->getHoTen() << endl;
          SetConsoleTextAttribute(color, 7);
          cout << "\t\t\t\tChon 1. de phan bo hoac chon 2. de di tiep: ";
          int chon;
          string maPB;
          PhongBan *pb = nullptr;
          cin >> chon;
          if (cin.fail())
          {
            checkCin();
            flag = true;
          }
          else
          {
            switch (chon)
            {
            case 1:
              cout << endl;
              cout << "\t\t\t\t\tDay la danh sach phong ban 📜 " << endl;
              dsPB.xuatPB();
              do
              {
                cout << "\t\t\t\tMoi chon ma phong hoac nhap 0 de thoat: ";
                cin >> maPB;
                if (maPB == "0")
                {
                  SetConsoleTextAttribute(color, 12);
                  cout << "\t\t\t\tDa thoat khoi chuc nang phan bo truong phong 🔓" << endl;
                  SetConsoleTextAttribute(color, 7);
                  return;
                }
                pb = timPhongBan(maPB);
                if (pb == nullptr || pb->getTruongPhong() != nullptr)
                {
                  SetConsoleTextAttribute(color, 12);
                  cout << "\t\t\t\t❌ Ma phong ban khong ton tai hoac phong ban nay da co truong phong. Moi nhap lai!" << endl;
                  SetConsoleTextAttribute(color, 7);
                }
              } while (pb == nullptr || pb->getTruongPhong() != nullptr);

              thucHienPhanBoTruongPhong(pb, tp, maPB);

              SetConsoleTextAttribute(color, 10);
              cout << "\t\t\t\tPhan bo ";
              SetConsoleTextAttribute(color, 7);
              cout << tp->getHoTen();
              SetConsoleTextAttribute(color, 10);
              cout << " mang ma so ";
              SetConsoleTextAttribute(color, 7);
              cout << tp->getMaSo();
              SetConsoleTextAttribute(color, 10);
              cout << " thanh cong ✅ ";
              SetConsoleTextAttribute(color, 7);
              cout << endl;
              flag = false;
              break;

            case 2:
              flag = false;
              break;

            default:
              SetConsoleTextAttribute(color, 12);
              cout << "\t\t\t\t🤬 Chi duoc chon 1 hoac 2" << endl;
              SetConsoleTextAttribute(color, 7);
              break;
            }
          }
        } while (flag);
      }
    }
  }
}

void XuLy::phanBoNhanVienThuongVaoPhongBan()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkCoNVTrongListNSHayKhong() == false)
  {
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t\t\t\tHien tai khong co nhan vien nao trong he thong de thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }
  if (checkCoPhongBanHayKhong() == false)
  {
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t\t\t\tHien tai khong co phong ban nao trong he thong de thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }
  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nvt != nullptr)
      {
        bool flag = true;
        do
        {
          HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
          cout << endl;
          SetConsoleTextAttribute(color, 11);
          cout << "\t\t\t\t📝 Dang phan bo cho nhan vien: " << endl;
          cout << "\t\t\t\tMa so: " << nvt->getMaSo() << "\t"
               << "Ho ten: " << nvt->getHoTen() << endl;
          SetConsoleTextAttribute(color, 7);
          int chon;
          cout << "\t\t\t\tChon 1. de phan bo hoac chon 2. de di tiep 👉 ";
          string maPhong;
          PhongBan *pb = nullptr;
          cin >> chon;
          if (cin.fail())
          {
            checkCin();
            flag = true;
          }
          else
          {
            switch (chon)
            {
            case 1:
              cout << endl;
              cout << "\t\t\t\t\tDay la danh sach phong ban 📜 " << endl;
              dsPB.xuatPB();
              do
              {
                cout << "\t\t\t\tMoi chon ma phong hoac nhap 0 de thoat: ";
                cin >> maPhong;
                if (maPhong == "0")
                {
                  SetConsoleTextAttribute(color, 12);
                  cout << "\t\t\t\tDa thoat khoi chuc nang phan bo nhan vien thuong 🔓" << endl;
                  SetConsoleTextAttribute(color, 7);
                  return;
                }
                pb = timPhongBan(maPhong);
                if (pb == nullptr || nvt->getMaPhongBan() == pb->getMaPhongBan())
                {
                  SetConsoleTextAttribute(color, 12);
                  cout << "\t\t\t\t❌ Ma phong ban khong ton tai hoac nhan vien da o trong phong ban nay. Moi nhap lai!" << endl;
                  SetConsoleTextAttribute(color, 7);
                }
              } while (pb == nullptr || nvt->getMaPhongBan() == pb->getMaPhongBan());

              thucHienPhanBoNhanVienThuong(pb, nvt, maPhong);

              SetConsoleTextAttribute(color, 10);
              cout << "\t\t\t\tPhan bo ";
              SetConsoleTextAttribute(color, 7);
              cout << nvt->getHoTen();
              SetConsoleTextAttribute(color, 10);
              cout << " mang ma so ";
              SetConsoleTextAttribute(color, 7);
              cout << nvt->getMaSo();
              SetConsoleTextAttribute(color, 10);
              cout << " thanh cong ✅ ";
              SetConsoleTextAttribute(color, 7);
              cout << endl;
              flag = false;
              break;

            case 2:
              flag = false;
              break;

            default:
              SetConsoleTextAttribute(color, 12);
              cout << "\t\t\t\t🤬 Chi duoc chon 1 hoac 2" << endl;
              SetConsoleTextAttribute(color, 7);
            }
          }
        } while (flag == true);
      }
    }
  }
}

PhongBan *XuLy::timPhongBan(string maPhong)
{
  for (PhongBan *pb : dsPB.getDsPhongBan())
  {
    if (pb->getMaPhongBan() == maPhong)
    {
      return pb;
    }
  }
  return nullptr;
}

void XuLy::sapXepTaskHoanThanh()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkCoNVTrongListNSHayKhong() == false)
  {
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t\t\t\tHien tai khong co nhan vien nao trong he thong de thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }
  if (checkCoTaskTrongListTaskHayKhong() == false)
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Hien tai khong co task nao trong he thong. Khong the thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }
  vector<NhanVienThuong *> sortedNS;
  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nvt != nullptr)
      {
        sortedNS.push_back(nvt);
      }
    }
  }
  sort(sortedNS.begin(), sortedNS.end(), [](NhanVienThuong *nvt1, NhanVienThuong *nvt2)
       { return nvt1->getHoanThanhTask() > nvt2->getHoanThanhTask(); });

  bool isSorted = true;
  int n = sortedNS.size();
  for (int i = 0; i < n - 1; i++)
  {
    if (sortedNS.front()->getHoanThanhTask() <= sortedNS.back()->getHoanThanhTask())
    {
      isSorted = false;
      break;
    }
    if (sortedNS[i]->getHoanThanhTask() > sortedNS[i + 1]->getHoanThanhTask())
    {
      isSorted = true;
    }
    else if (sortedNS[i]->getHoanThanhTask() < sortedNS[i + 1]->getHoanThanhTask())
    {
      isSorted = false;
      break;
    }
  }

  if (isSorted)
  {
    SetConsoleTextAttribute(color, 10);
    cout << endl;
    cout << "\t\t\t\t\tSap xep thanh cong 📈" << endl;
    SetConsoleTextAttribute(color, 7);
    ds.xuatNV(sortedNS);
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << endl;
    cout << "\t\t\t\t\tDanh sach chua duoc sap xep ❌" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

bool XuLy::checkCoNhanSuHayKhong()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (ds.getListNS().size() == 0)
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t\tHien tai khong co nhan su nao trong he thong ❌" << endl;
    SetConsoleTextAttribute(color, 7);
    return false;
  }
  return true;
}

bool XuLy::checkTaskDaDuocPhanBoChua()
{
  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nvt->getDSTask().size() > 0)
      {
        return true;
      }
    }
  }
  return false;
}

void XuLy::danhGiaTask()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkTaskDaDuocPhanBoChua() == false)
  {
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t\t\t\tChua co task nao duoc phan bo de danh gia. Khong the thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }
  if (checkCoTaskTrongListTaskHayKhong() == false)
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Hien tai khong co task nao trong he thong. Khong the thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }

  string maTask;
  Task *task;

  SetConsoleTextAttribute(color, 14);
  cout << endl;
  cout << "\t\t\t\t\tDay la danh sach nhan vien " << endl;
  SetConsoleTextAttribute(color, 7);
  ds.xuatNV();
  do
  {
    cout << endl;
    cout << "\t\t\t\tNhap ma task hoac nhap 0 de thoat: ";
    cin >> maTask;
    if (maTask == "0")
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\tBan da chon thoat khoi chuc nang danh gia task 🔓" << endl;
      SetConsoleTextAttribute(color, 7);
      return;
    }
    task = timTask(maTask);
    if (task == nullptr || task->getTrangThaiTask() != "" || task->getMaNV() == "")
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\t❌ Khong tim thay ma task phu hop. Vui long nhap lai!" << endl;
      SetConsoleTextAttribute(color, 7);
    }
  } while (task == nullptr || task->getTrangThaiTask() != "" || task->getMaNV() == "");

  int selectedOption = 1;
  bool exitMenu = false;
  tatConTro();

  while (!exitMenu)
  {
    bool daDanhGia = false;
    SetConsoleTextAttribute(color, 11);
    clearScreen();
    cout << endl;
    cout << "\t\t\t\t          ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═════════╟════ ";
    SetConsoleTextAttribute(color, 7);
    cout << " Chon danh gia ben duoi";
    SetConsoleTextAttribute(color, 11);
    cout << " ══════║═════════╗\n";
    cout << "\t\t\t\t║         ╚═══════════════════════════════════╝         ║\n";
    cout << "\t\t\t\t║                                                       ║\n";

    for (int i = 1; i <= 3; i++)
    {
      if (i == selectedOption)
      {
        SetConsoleTextAttribute(color, 11);
        cout << "\t\t\t\t║";
        SetConsoleTextAttribute(color, 11);
        cout << "      👉     ";
      }
      else
      {
        SetConsoleTextAttribute(color, 11);
        cout << "\t\t\t\t║             ";
        SetConsoleTextAttribute(color, 7);
      }

      switch (i)
      {
      case 1:
        cout << std::left << std::setw(41) << "Hoan thanh" << std::right;
        break;
      case 2:
        cout << std::left << std::setw(41) << "Chua hoan thanh" << std::right;
        break;
      case 3:
        cout << std::left << std::setw(41) << "Thoat" << std::right;
        break;
      }
      SetConsoleTextAttribute(color, 11);
      cout << " ║\n";
    }
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\t║                                                       ║\n";
    cout << "\t\t\t\t╚═══════════════════════════════════════════════════════╝\n";

    SetConsoleTextAttribute(color, 7);
    char input = getch();

    switch (input)
    {
    case 72:
      if (selectedOption > 1)
        selectedOption--;
      break;
    case 80:
      if (selectedOption < 3)
        selectedOption++;
      break;
    case 13:
      switch (selectedOption)
      {
      case 1:
        danhGiaTrangThaiTask(task, maTask, daDanhGia, "Hoan thanh", color);
        exitMenu = true;
        break;
      case 2:
        danhGiaTrangThaiTask(task, maTask, daDanhGia, "Khong hoan thanh", color);
        exitMenu = true;
        break;
      case 3:
        exitMenu = true;
        break;
      }
    }
  }
}

void XuLy::danhGiaTrangThaiTask(Task *task, string maTask, bool daDanhGia, string trangThai, HANDLE color)
{
  for (int i = 0; i < ds.getListNS().size(); i++)
  {
    if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ds.getListNS()[i]))
    {
      if (nvt != nullptr)
      {
        for (int j = 0; j < nvt->getDSTask().size(); j++)
        {
          if (nvt->getDSTask()[j]->getMaTask() == maTask)
          {
            task->setTrangThaiTask(trangThai);
            if (trangThai == "Hoan thanh")
            {
              nvt->tangTaskHoanThanh();
            }
            else
            {
              nvt->tangTaskChuaHoanThanh();
            }
            daDanhGia = true;
            SetConsoleTextAttribute(color, 10);
            cout << "\t\t\t\tDanh gia thanh cong ✅" << endl;
            SetConsoleTextAttribute(color, 7);
            break;
          }
        }
      }
    }
  }
  if (!daDanhGia)
  {
    cout << "\t\t\t\tKhong tim thay nhan vien nao co ma task " << maTask << endl;
  }
}

void XuLy::xoaTaskKhoiNV()
{
  bool check = checkCoTaskHayKhong();
  if (check)
  {
    string maNV;
    NhanVienThuong *nvt;
    Task *task;
    string maTask;
    bool hopLy = true;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(color, 14);
    cout << endl;
    cout << "\t\t\t\t\tDay la danh sach nhan vien: " << endl;
    SetConsoleTextAttribute(color, 7);
    ds.xuatNV();
    do
    {
      cout << "\t\t\t\tNhap ma nhan vien hoac nhap 0 de thoat: ";
      SetConsoleTextAttribute(color, 11);
      cin >> maNV;
      SetConsoleTextAttribute(color, 7);
      nvt = timNVT(maNV);
      if (maNV == "0")
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\tBan da thoat khoi chuc nang xoa task khoi nhan vien 🔓" << endl;
        SetConsoleTextAttribute(color, 7);
        return;
      }
      if (nvt == nullptr || nvt->getDSTask().size() == 0)
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\t❌ Khong tim thay ma nhan vien phu hop. Vui long nhap lai!" << endl;
        SetConsoleTextAttribute(color, 7);
      }
    } while (nvt == nullptr || nvt->getDSTask().size() == 0);

    do
    {
      cout << "\t\t\t\tNhap ma task: ";
      SetConsoleTextAttribute(color, 11);
      cin >> maTask;
      SetConsoleTextAttribute(color, 7);
      task = timTask(maTask);
      for (int i = 0; i < nvt->getDSTask().size(); i++)
      {
        if (nvt->getDSTask()[i]->getMaTask() == maTask)
        {
          hopLy = false;
        }
      }
      if (task == nullptr || hopLy)
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\t❌ Khong tim thay ma task phu hop. Vui long nhap lai!" << endl;
        SetConsoleTextAttribute(color, 7);
      }

    } while (task == nullptr || hopLy);

    nvt->getDSTask().erase(remove(nvt->getDSTask().begin(), nvt->getDSTask().end(), task), nvt->getDSTask().end());
    nvt->giamSoLuongTask();
    task->setMaNV("");
    task->setTrangThaiTask("");
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\tXoa task khoi nhan vien thanh cong ✅" << endl;
    SetConsoleTextAttribute(color, 7);
    ds.xuatNV();
  }
  else
  {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Chua co task nao duoc phan bo cho nhan vien. Khong the thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

void XuLy::sapXepSoLuongTaskNV()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkCoNVTrongListNSHayKhong() == false)
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Hien tai khong co nhan vien nao trong he thong. Khong the thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }
  if (checkCoTaskTrongListTaskHayKhong() == false)
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Hien tai khong co task nao trong he thong. Khong the thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }
  vector<NhanVienThuong *> sortedNS;
  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nvt != nullptr)
      {
        sortedNS.push_back(nvt);
      }
    }
  }
  sort(sortedNS.begin(), sortedNS.end(), [](NhanVienThuong *nvt1, NhanVienThuong *nvt2)
       { return nvt1->getDSTask().size() > nvt2->getDSTask().size(); });

  bool isSorted = true;
  int n = sortedNS.size();
  for (int i = 0; i < n - 1; i++)
  {
    if (sortedNS.front()->getSoLuongTask() <= sortedNS.back()->getSoLuongTask())
    {
      isSorted = false;
      break;
    }
    if (sortedNS[i]->getSoLuongTask() > sortedNS[i + 1]->getSoLuongTask())
    {
      isSorted = true;
    }
    else if (sortedNS[i]->getSoLuongTask() < sortedNS[i + 1]->getSoLuongTask())
    {
      isSorted = false;
      break;
    }
  }

  if (isSorted)
  {
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\tSap xep thanh cong 📈" << endl;
    SetConsoleTextAttribute(color, 7);
    ds.xuatNV(sortedNS);
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << endl;
    cout << "\t\t\t\t\tDanh sach chua duoc sap xep ❌" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

bool XuLy::checkCoTaskTrongListTaskHayKhong()
{
  if (dsTask.getDSTask().size() == 0)
  {
    return false;
  }
  return true;
}

void XuLy::xoaTask()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

  if (checkCoTaskTrongListTaskHayKhong() == false)
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Hien tai khong co task nao trong he thong. Khong the thuc hien chuc nang nay!" << endl;
    SetConsoleTextAttribute(color, 7);
    return;
  }

  Task *task;
  string maTask;

  cout << endl;
  SetConsoleTextAttribute(color, 14);
  cout << "\t\t\t\t\tDay la danh sach task " << endl;
  SetConsoleTextAttribute(color, 7);
  dsTask.xuatTask();
  do
  {
    cout << endl;
    cout << "\t\t\t\tNhap ma task can xoa: ";
    cin >> maTask;
    task = timTask(maTask);
    if (task == nullptr)
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\tKhong tim thay ma task phu hop. Vui long nhap lai!" << endl;
      SetConsoleTextAttribute(color, 7);
    }
  } while (task == nullptr);

  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nvt != nullptr)
      {
        if (nvt->getDSTask().size() > 0)
        {
          for (Task *task : nvt->getDSTask())
          {
            if (task->getMaTask() == maTask)
            {
              nvt->getDSTask().erase(remove(nvt->getDSTask().begin(), nvt->getDSTask().end(), task), nvt->getDSTask().end());
              nvt->giamSoLuongTask();
              break;
            }
          }
        }
      }
    }
  }

  for (Task *task : dsTask.getDSTask())
  {
    if (task->getMaTask() == maTask)
    {
      task->setMaNV("");
      dsTask.getDSTask().erase(remove(dsTask.getDSTask().begin(), dsTask.getDSTask().end(), task), dsTask.getDSTask().end());
      task = nullptr;
      delete task;
      SetConsoleTextAttribute(color, 10);
      cout << "\t\t\t\tXoa task thanh cong ✅" << endl;
      SetConsoleTextAttribute(color, 7);
      return;
    }
  }
}

void XuLy::phanBoTask()
{
  if (ds.getListNS().size() > 0)
  {
    bool flag = true;
    string maTask;
    Task *task;
    int chon;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    for (NhanSu *ns : ds.getListNS())
    {
      if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
      {
        do
        {
          cout << endl;
          SetConsoleTextAttribute(color, 11);
          cout << "\t\t\t\tDang phan bo task cho nhan vien: " << endl;
          cout << "\t\t\t\t" << nvt->getMaSo() << "\t" << nvt->getHoTen() << endl;
          SetConsoleTextAttribute(color, 7);
          cout << "\t\t\t\tChon 1. de phan bo hoac chon 2. de di tiep: ";
          cin >> chon;
          if (cin.fail())
          {
            checkCin();
            flag = true;
          }
          else
          {
            switch (chon)
            {
            case 1:
              cout << endl;
              SetConsoleTextAttribute(color, 14);
              cout << "\t\t\t\t\tDay la danh sach task " << endl;
              SetConsoleTextAttribute(color, 7);
              dsTask.xuatTask();
              do
              {
                cout << endl;
                cout << "\t\t\t\tNhap ma task can phan bo hoac nhap 0 de thoat: ";
                cin >> maTask;
                if (maTask == "0")
                {
                  SetConsoleTextAttribute(color, 12);
                  cout << "\t\t\t\tBan da thoat khoi chuc nang phan bo task 🔓" << endl;
                  SetConsoleTextAttribute(color, 7);
                  return;
                }
                task = timTask(maTask);
                if (task == nullptr || task->getMaNV() != "")
                {
                  SetConsoleTextAttribute(color, 12);
                  cout << "\t\t\t\t❌ Khong tim thay task co ma so nay hoac task nay da co nhan vien thuc hien." << endl;
                  SetConsoleTextAttribute(color, 7);
                }
              } while (task == nullptr || task->getMaNV() != "");

              for (int i = 0; i < nvt->getDSTask().size(); i++)
              {
                Task *taskNV = nvt->getDSTask().at(i);
                if (taskNV->getMaTask() == maTask)
                {
                  SetConsoleTextAttribute(color, 12);
                  cout << "\t\t\t\t❌ Task nay da duoc phan bo cho nhan vien nay roi." << endl;
                  SetConsoleTextAttribute(color, 7);
                  flag = true;
                  break;
                }
              }

              if (task != nullptr)
              {
                task->setMaNV(nvt->getMaSo());
                nvt->getDSTask().push_back(task);
                nvt->tangSoLuongTask();
                flag = false;
              }
              SetConsoleTextAttribute(color, 10);
              cout << "\t\t\t\tPhan bo ";
              SetConsoleTextAttribute(color, 7);
              cout << nvt->getHoTen();
              SetConsoleTextAttribute(color, 10);
              cout << " mang ma so ";
              SetConsoleTextAttribute(color, 7);
              cout << nvt->getMaSo();
              SetConsoleTextAttribute(color, 10);
              cout << " thanh cong ✅ ";
              SetConsoleTextAttribute(color, 7);
              cout << endl;

              break;
            case 2:
              flag = false;
              break;
            default:
              SetConsoleTextAttribute(color, 12);
              cout << "\t\t\t\tChi duoc chon 1 hoac 2 ❌" << endl;
              SetConsoleTextAttribute(color, 7);
              flag = true;
              break;
            }
          }
        } while (flag);
      }
    }
  }
  else
  {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Danh sach nhan su hien dang rong." << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

Task *XuLy::timTask(string maTask)
{
  for (Task *task : dsTask.getDSTask())
  {
    if (task->getMaTask() == maTask)
    {
      return task;
    }
  }
  return nullptr;
}

bool XuLy::found(string maSo)
{
  for (NhanSu *ns : ds.getListNS())
  {
    if (maSo == ns->getMaSo())
    {
      return true;
    }
  }
  return false;
}

void XuLy::xoaNhanSu()
{

  if (checkCoNhanSuHayKhong() == false)
  {
    return;
  }

  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 14);
  cout << "\t\t\t\t\tDay la danh sach nhan su hien co 📜 " << endl;
  SetConsoleTextAttribute(color, 7);
  ds.xuat();

  string maSo;
  bool foundNS;
  do
  {
    cout << endl;
    cout << "\t\t\t\tNhap ma so de xoa nhan su hoac nhap 0 de thoat: ";
    cin >> maSo;
    foundNS = found(maSo);
    if (maSo == "0")
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\tBan da thoat khoi chuc nang xoa nhan su 🔓" << endl;
      SetConsoleTextAttribute(color, 7);
      return;
    }
    if (foundNS == false)
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\t❌ Khong tim thay nhan su co ma so nay." << endl;
      SetConsoleTextAttribute(color, 7);
    }
  } while (foundNS == false);
  if (foundNS)
  {
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\tDa tim thay nhan su ✅" << endl;
    SetConsoleTextAttribute(color, 7);
    for (int i = 0; i < ds.getListNS().size(); i++)
    {
      if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ds.getListNS()[i]))
      {
        if (tp != nullptr)
        {
          if (tp->getMaSo() == maSo)
          {
            xoaTruongPhong(tp);
            SetConsoleTextAttribute(color, 10);
            cout << "\t\t\t\tDa xoa truong phong mang ma so " << tp->getMaSo() << " - co ten " << tp->getHoTen() << " ✅" << endl;
            SetConsoleTextAttribute(color, 7);
            cout << endl;
            for (PhongBan *pb : dsPB.getDsPhongBan())
            {
              if (pb->getMaPhongBan() == tp->getMaPhongBan())
              {
                pb->giamSoLuongNhanSu();
              }
            }
          }
        }
      }
      if (GiamDoc *giamDoc = dynamic_cast<GiamDoc *>(ds.getListNS()[i]))
      {
        if (giamDoc != nullptr)
        {
          if (giamDoc->getMaSo() == maSo)
          {
            ds.getListNS().erase(ds.getListNS().begin() + i);
            SetConsoleTextAttribute(color, 10);
            cout << "\t\t\t\tDa xoa giam doc mang ma so " << giamDoc->getMaSo() << " - co ten " << giamDoc->getHoTen() << " ✅" << endl;
            SetConsoleTextAttribute(color, 7);
            cout << endl;
          }
        }
      }
      if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ds.getListNS()[i]))
      {
        if (nvt != nullptr)
        {
          if (nvt->getMaSo() == maSo)
          {
            xoaNhanVienThuong(nvt, maSo);
            SetConsoleTextAttribute(color, 10);
            cout << "\t\t\t\tDa xoa nhan vien thuong mang ma so " << nvt->getMaSo() << " - co ten " << nvt->getHoTen() << " ✅" << endl;
            SetConsoleTextAttribute(color, 7);
            cout << endl;
            for (PhongBan *pb : dsPB.getDsPhongBan())
            {
              if (pb->getMaPhongBan() == nvt->getMaPhongBan())
              {
                pb->giamSoLuongNhanSu();
              }
            }
          }
        }
      }
    }
  }
  SetConsoleTextAttribute(color, 7);
  ds.xuat();
}

void XuLy::xoaNhanVienThuong(NhanVienThuong *nvt, string maSo)
{
  for (int i = 0; i < ds.getListNS().size(); i++)
  {
    if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ds.getListNS()[i]))
    {
      if (tp != nullptr)
      {
        int j = 0;
        while (j < tp->getListNV().size())
        {
          if (tp->getListNV()[j]->getMaSo() == maSo)
          {
            tp->getListNV().erase(tp->getListNV().begin() + j);
            tp->giamNhanVien();
            break;
          }
          else
          {
            j++;
          }
        }
      }
    }
  }

  for (Task *task : dsTask.getDSTask())
  {
    if (task->getMaNV() == maSo)
    {
      task->setMaNV("");
    }
  }

  for (int i = 0; i < dsPB.getDsPhongBan().size(); i++)
  {
    int j = 0;
    while (j < dsPB.getDsPhongBan()[i]->getDsNV().size())
    {
      if (dsPB.getDsPhongBan()[i]->getDsNV()[j]->getMaSo() == maSo)
      {
        dsPB.getDsPhongBan()[i]->getDsNV().erase(dsPB.getDsPhongBan()[i]->getDsNV().begin() + j);
        dsPB.getDsPhongBan()[i]->getDsNV();
        break;
      }
      else
      {
        j++;
      }
    }
  }

  auto it = std::find(ds.getListNS().begin(), ds.getListNS().end(), nvt);
  if (it != ds.getListNS().end())
  {
    ds.getListNS().erase(it);
    nvt = nullptr;
    delete nvt;
  }
}

void XuLy::xoaTruongPhong(TruongPhong *truongPhong)
{
  for (int i = 0; i < ds.getListNS().size(); i++)
  {
    if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ds.getListNS()[i]))
    {
      if (nvt != nullptr)
      {
        if (nvt->getTruongPhong() != nullptr)
        {
          if (nvt->getTruongPhong()->getMaSo() == truongPhong->getMaSo())
          {
            nvt->setTruongPhong(nullptr); // Set hết các nhân viên thường có trưởng phòng này thành nullptr
          }
        }
      }
    }
  }

  for (int i = 0; i < dsPB.getDsPhongBan().size(); i++)
  {
    if (dsPB.getDsPhongBan()[i]->getTruongPhong() != nullptr)
    {
      if (dsPB.getDsPhongBan()[i]->getTruongPhong()->getMaSo() == truongPhong->getMaSo())
      {
        dsPB.getDsPhongBan()[i]->setTruongPhong(nullptr); // Set hết các phòng ban có trưởng phòng này thành nullptr
      }
    }
  }

  auto it = std::find(ds.getListNS().begin(), ds.getListNS().end(), truongPhong);
  if (it != ds.getListNS().end())
  {
    ds.getListNS().erase(it);
    truongPhong = nullptr;
    delete truongPhong;
  }
}

void XuLy::timNhanSuTheoMaSo()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (checkCoNhanSuHayKhong() == false)
  {
    return;
  }
  string maSo;
  cout << "\t\t\t\tNhap ma so nhan su can tim               🔎";
  SetConsoleTextAttribute(color, 11);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  GetConsoleScreenBufferInfo(color, &consoleInfo);
  COORD cursorPosition = consoleInfo.dwCursorPosition;
  cursorPosition.X -= 15;
  cursorPosition.Y += 0;
  SetConsoleCursorPosition(color, cursorPosition);
  cin >> maSo;

  bool foundNS = found(maSo);
  if (foundNS == true)
  {
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\tDa tim thay nhan su ✅" << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 7);
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═══║ ";
    SetConsoleTextAttribute(color, 11);
    cout << "       Thong tin nhan su  📂";
    SetConsoleTextAttribute(color, 7);
    cout << "      ║════╗\n";
    cout << "\t\t\t\t║   ╚═══════════════════════════════════╝    ║\n";
    SetConsoleTextAttribute(color, 7);
    for (NhanSu *ns : ds.getListNS())
    {
      if (maSo == ns->getMaSo())
      {
        ns->xuat();
      }
    }
    cout << "\t\t\t\t╚═════════════════════╩══════════════════════╝\n";
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tOOPS! Khong tim thay nhan su voi ma so " << maSo << " 🥲" << endl;
  }
  SetConsoleTextAttribute(color, 7);
}

void XuLy::suaDoiThongTinNhanSu()
{
  if (checkCoNhanSuHayKhong() == false)
  {
    return;
  }

  bool foundNS = false;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 14);
  cout << "\t\t\t\t\tDay la danh sach nhan su hien co 📜 " << endl;
  SetConsoleTextAttribute(color, 7);
  ds.xuat();
  cout << endl;
  string ma;

  do
  {
    cout << "\t\t\t\tVui long nhap lai ma so nhan su can sua doi hoac nhap 0 de thoat: ";
    cin >> ma;
    for (NhanSu *ns : ds.getListNS())
    {
      if (ma == "0")
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\tBan da chon thoat khoi chuc nang sua doi thong tin nhan su 🔓" << endl;
        SetConsoleTextAttribute(color, 7);
        return;
      }
      if (ma == ns->getMaSo())
      {
        foundNS = true;
        system("cls");
        SetConsoleTextAttribute(color, 10);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\tDa tim thay nhan su voi ma so " << ma << " ✅" << endl;
        SetConsoleTextAttribute(color, 11);
        cout << "\t\t\t\tVui long nhap cac thong tin sau de sua doi " << endl;
        SetConsoleTextAttribute(color, 7);
        ns->nhap();
        break;
      }
    }
    if (foundNS == false)
    {
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\tOOPS! Khong tim thay nhan su voi ma so " << ma << " 🥲" << endl;
      SetConsoleTextAttribute(color, 7);
    }
  } while (foundNS == false);
}

void XuLy::sapXepLuongGiamDan()
{
  if (checkCoNhanSuHayKhong() == false)
  {
    return;
  }
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  vector<NhanSu *> nsList = ds.getListNS();
  sort(nsList.begin(), nsList.end(), [](NhanSu *ns1, NhanSu *ns2)
       { return ns1->getLuong() > ns2->getLuong(); });
  ds.setListNS(nsList);

  bool isSorted = true;
  int n = nsList.size();
  for (int i = 0; i < n - 1; i++)
  {
    if (nsList.front()->getLuong() <= nsList.back()->getLuong())
    {
      isSorted = false;
      break;
    }
    if (nsList[i]->getLuong() > nsList[i + 1]->getLuong())
    {
      isSorted = true;
    }
    else if (nsList[i]->getLuong() < nsList[i + 1]->getLuong())
    {
      isSorted = false;
      break;
    }
  }

  if (isSorted)
  {
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\tSap xep thanh cong 📈" << endl;
    SetConsoleTextAttribute(color, 7);
    ds.xuat();
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << endl;
    cout << "\t\t\t\t\tDanh sach chua duoc sap xep ❌" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

void XuLy::SapXepTheoTen()
{
  if (checkCoNhanSuHayKhong() == false)
  {
    return;
  }
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  vector<NhanSu *> nsList = ds.getListNS();
  sort(
      nsList.begin(), nsList.end(), [](NhanSu *ns1, NhanSu *ns2)
      {
    string ten1 = ns1->getHoTen();
    string ten2 = ns2->getHoTen();
    string lastName1 = ten1.substr(ten1.find_last_of(' ') + 1);
    string lastName2 = ten2.substr(ten2.find_last_of(' ') + 1);
    return lastName1 < lastName2; });
  ds.setListNS(nsList);

  bool isSorted = true;
  int n = nsList.size();
  for (int i = 0; i < n - 1; i++)
  {
    string tenFront = nsList.front()->getHoTen();
    string tenBack = nsList.back()->getHoTen();
    string lastNameFront = tenFront.substr(tenFront.find_last_of(' ') + 1);
    string lastNameBack = tenBack.substr(tenBack.find_last_of(' ') + 1);
    string ten1 = nsList[i]->getHoTen();
    string ten2 = nsList[i + 1]->getHoTen();
    string lastName1 = ten1.substr(ten1.find_last_of(' ') + 1);
    string lastName2 = ten2.substr(ten2.find_last_of(' ') + 1);

    if (lastNameFront >= lastNameBack)
    {
      isSorted = false;
      break;
    }
    if (lastName1 < lastName2)
    {
      isSorted = true;
    }
    else if (lastName1 > lastName2)
    {
      isSorted = false;
      break;
    }
  }

  if (isSorted)
  {
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\tSap xep thanh cong 📈" << endl;
    SetConsoleTextAttribute(color, 7);
    ds.xuat();
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << endl;
    cout << "\t\t\t\t\tDanh sach chua duoc sap xep ❌" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

void XuLy::timNVLuongCaoNhat()
{
  if (checkCoNhanSuHayKhong() == false)
  {
    return;
  }
  vector<NhanSu *> listMax;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
  cout << "\t\t\t\t╔═══║ ";
  SetConsoleTextAttribute(color, 11);
  cout << " Nhan su co muc luong cao nhat  📂";
  SetConsoleTextAttribute(color, 7);
  cout << "║════╗\n";
  cout << "\t\t\t\t║   ╚═════════════════╦═════════════════╝    ║\n";
  float max = ds.getListNS()[0]->getLuong();
  for (NhanSu *ns : ds.getListNS())
  {
    if (max < ns->getLuong())
    {
      max = ns->getLuong();
    }
  }

  for (NhanSu *ns : ds.getListNS())
  {
    if (max == ns->getLuong())
    {
      listMax.push_back(ns);
    }
  }
  NhanSu *lastNS = listMax.back();
  for (NhanSu *ns : listMax)
  {
    if (ns != lastNS)
    {
      ns->xuat();
      cout << "\t\t\t\t╠═════════════════════╬══════════════════════╣\n";
    }
    else
    {
      ns->xuat();
      cout << "\t\t\t\t╚═════════════════════╩══════════════════════╝\n";
    }
  }
}

void XuLy::lietKeDanhSachTruongPhong()
{
  for (NhanSu *ns : ds.getListNS())
  {
    if (TruongPhong *newTP = dynamic_cast<TruongPhong *>(ns))
    {
      cout << endl;
      newTP->xuat();
    }
  }
}

void XuLy::phanBoCuTheNVT()
{
  bool check = checkCoNVTrongListNSHayKhong();
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (check)
  {
    string maNV;
    string maPB;
    cout << endl;
    cout << "\t\t\t\t\tDay la danh sach nhan vien 📜 " << endl;
    ds.xuatMaSoVaTenNV();
    cout << "\t\t\t\t\tDay la danh sach phong ban 📜 " << endl;
    dsPB.xuatPB();
    NhanVienThuong *nvt;
    PhongBan *pb = nullptr;
    do
    {
      cout << "\t\t\t\t📝 Phan bo nhan vien mang ma so:        den phong ban mang ma so:        ";
      SetConsoleTextAttribute(color, 11);
      CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
      GetConsoleScreenBufferInfo(color, &consoleInfo);
      COORD cursorPosition = consoleInfo.dwCursorPosition;
      cursorPosition.X -= 40;
      SetConsoleCursorPosition(color, cursorPosition);
      cin >> maNV;
      if (maNV == "0")
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\tBan da chon thoat phan bo nhan vien 🔓" << endl;
        SetConsoleTextAttribute(color, 7);
        return;
      }

      nvt = timNVT(maNV);
      if (nvt == nullptr)
      {
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\t❌ Ma nhan vien khong ton tai. Moi nhap lai!" << endl;
        SetConsoleTextAttribute(color, 7);
      }
      else
      {
        SetConsoleTextAttribute(color, 11);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        GetConsoleScreenBufferInfo(color, &consoleInfo);
        COORD cursorPosition = consoleInfo.dwCursorPosition;
        cursorPosition.X += 98;
        cursorPosition.Y -= 1;
        SetConsoleCursorPosition(color, cursorPosition);

        cin >> maPB;
        if (maPB == "0")
        {
          SetConsoleTextAttribute(color, 12);
          cout << "\t\t\t\tBan da chon thoat phan bo nhan vien 🔓" << endl;
          SetConsoleTextAttribute(color, 7);
          return;
        }

        pb = timPhongBan(maPB);
        if (pb == nullptr || nvt->getMaPhongBan() == pb->getMaPhongBan())
        {
          SetConsoleTextAttribute(color, 12);
          cout << "\t\t\t\t❌ Ma phong ban khong ton tai hoac nhan vien da o trong phong ban nay. Moi nhap lai!" << endl;
          SetConsoleTextAttribute(color, 7);
        }
      }
    } while (nvt == nullptr || pb == nullptr || nvt->getMaPhongBan() == pb->getMaPhongBan());

    thucHienPhanBoNhanVienThuong(pb, nvt, maPB);

    cout << endl;
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\t✅ Da phan bo nhan vien ";
    SetConsoleTextAttribute(color, 7);
    cout << nvt->getHoTen();
    SetConsoleTextAttribute(color, 10);
    cout << " mang ma so ";
    SetConsoleTextAttribute(color, 7);
    cout << nvt->getMaSo();
    SetConsoleTextAttribute(color, 10);
    cout << " den ";
    SetConsoleTextAttribute(color, 7);
    cout << pb->getTenPhongBan();
    SetConsoleTextAttribute(color, 10);
    cout << " mang ma so ";
    SetConsoleTextAttribute(color, 7);
    cout << pb->getMaPhongBan();
    cout << endl;
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Chua co nhan vien trong he thong!" << endl;
    SetConsoleTextAttribute(color, 7);
  }
}

TruongPhong *XuLy::timTruongPhongTheoMa(string ma)
{
  TruongPhong *tp = nullptr;

  for (NhanSu *ns : ds.getListNS())
  {
    if (TruongPhong *newNS = dynamic_cast<TruongPhong *>(ns))
    {
      if (newNS->getMaSo() == ma)
      {
        tp = newNS;
      }
    }
  }
  return tp;
}

void XuLy::phanBoNhanVienThuong()
{
  system("cls");
  lietKeDanhSachTruongPhong();
  bool flag = true;
  int chon;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *newNV = dynamic_cast<NhanVienThuong *>(ns))
    {
      do
      {
        TruongPhong *tp = nullptr;
        cout << "\t\t\tDang phan bo: " << ns->getHoTen() << endl;
        cout << "\t\t\tChon 1. de phan bo hoac chon 2. de di tiep: ";
        cin >> chon;
        if (cin.fail())
        {
          checkCin();
          flag = true;
        }
        else
        {
          if (chon == 1 || chon == 2)
          {
            if (chon == 1)
            {

              do
              {
                string chonMa;
                cout << "\t\t\tNhap ma de tim truong phong hoac nhap 0 de thoat 🔍 ";
                cin >> chonMa;
                if (chonMa == "0")
                {
                  SetConsoleTextAttribute(color, 12);
                  cout << "\t\t\tBan da chon thoat phan bo nhan vien 🔓" << endl;
                  SetConsoleTextAttribute(color, 7);
                  return;
                }
                tp = timTruongPhongTheoMa(chonMa);
              } while (tp == nullptr);
              newNV->setTruongPhong(tp);
              tp->tangNhanVien();
              tp->getListNV().push_back(newNV);
              cout << "\t\t\tDa phan bo " << newNV->getHoTen() << " cho " << tp->getHoTen() << " ✅ " << endl;
              cout << endl;
            }

            flag = false;
          }
          else
          {
            cout << "\t\t\t👀 Chi duoc chon 1 hoac 2❗ " << endl;
            cout << endl;
            flag = true;
          }
        }
      } while (flag);
    }
  }
}

void XuLy::inMenuLogin(int &chon)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = true;
  SetConsoleCursorInfo(hConsole, &cursorInfo);
  system("cls");
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 14);
  printWelcome();
  SetConsoleTextAttribute(color, 11);
  std::cout << "\033[6;0H";
  cout << "\t\t\t\t\t    ╔═══════════════════════════════════╗\n";
  cout << "\t\t\t\t\t╔═══╟═════════ Menu Dang nhap 💻════════║═══╗\n";
  cout << "\t\t\t\t\t║   ╚═══════════════════════════════════╝   ║\n";
  cout << "\t\t\t\t\t║                                           ║\n";
  cout << "\t\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "           1. Dang nhap";
  SetConsoleTextAttribute(color, 11);
  cout << "                    ║\n";
  cout << "\t\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "           2. Dang ky";
  SetConsoleTextAttribute(color, 11);
  cout << "                      ║\n";
  cout << "\t\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "           0. Thoat";
  SetConsoleTextAttribute(color, 11);
  cout << "                        ║\n";
  cout << "\t\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "           > Moi chon 👉";
  SetConsoleTextAttribute(color, 11);
  cout << "                   ║\n";
  cout << "\t\t\t\t\t║                                           ║\n";
  cout << "\t\t\t\t\t╚═══════════════════════════════════════════╝\n\n";

  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  GetConsoleScreenBufferInfo(color, &consoleInfo);
  COORD cursorPosition = consoleInfo.dwCursorPosition;
  cursorPosition.X += 67;
  cursorPosition.Y -= 4;
  SetConsoleCursorPosition(color, cursorPosition);
  cin >> chon;

  SetConsoleTextAttribute(color, 7);
}

void XuLy::animationLoading(string taiKhoan)
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 11);
  int animationMovement = 17;

  int bar1 = 177,
      bar2 = 219;
  cout << "\n\n\n\t\t\tDang tai.......";
  cout << "\n\n\t\t";

  for (int i = 0; i < 50; i++)
  {
    cout << "\r";
    cout << "\t\t\t";
    for (int j = 0; j < 50; j++)
    {
      SetConsoleOutputCP(CP_UTF8);

      if (j == i)
      {
        cout << "  🌟";
      }
      else if (j <= i - 5)
      {
        SetConsoleCP(437);
        SetConsoleOutputCP(437);
        SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | 11);
        cout << (char)bar2;
        SetConsoleTextAttribute(color, 11);
        if (j == 10)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "D";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 11)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "A";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 12)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "N";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 13)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "G";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 14)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << " ";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 15)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "D";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 16)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "A";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 17)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "N";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 18)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "G";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 19)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << " ";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 20)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "N";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 21)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "H";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 22)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "A";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 23)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << "P";
          SetConsoleTextAttribute(color, 11);
          continue;
        }
        else if (j == 24)
        {
          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << " ";
          SetConsoleTextAttribute(color, 11);

          SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
          cout << " ";
          SetConsoleTextAttribute(color, 11);

          string taiKhoanUppercase = taiKhoan;
          transform(taiKhoan.begin(), taiKhoan.end(), taiKhoanUppercase.begin(), ::toupper);

          for (int k = 0; k < taiKhoanUppercase.length(); k++)
          {
            SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE);
            cout << taiKhoanUppercase[k] << " ";
            SetConsoleTextAttribute(color, 11);
            Sleep(0.8);
          }
          continue;
        }
      }
    }
    Sleep(animationMovement);
  }
  SetConsoleOutputCP(CP_UTF8);
}

void XuLy::anHienMatKhau(string &mk)
{
  char c;
  string prevMk = "";
  bool hidePassword = true;

  while (true)
  {
    c = getch(); // Lay ki tu tu ban phim

    if (c == '\r') // Nut enter
    {
      break;
    }
    else if (c == '\b') // Neu nhan Nut backspace
    {
      if (mk.length() > 0)
      {
        cout << "\b \b"; // Xoa 1 ki tu truoc vua nhap
        mk.pop_back();   // Xoa ki tu do khoi mk
      }
    }
    else if (c >= 32 && c <= 126) // Neu la ki tu in duoc
    {

      if (hidePassword && c != '[' && c != ']')
      {
        if (c != ']' && c != '[')
        {
          cout << "*"; // An cac ky tu tren man hinh tru ky tu "[", "]"
        }
      }
      else if (!hidePassword || (hidePassword && c != '[' && c != ']'))
      {
        if (c != ']' && c != '[')
        {
          cout << c; // hien ky tu
        }
      }
      if (!hidePassword || (hidePassword && c != '[' && c != ']')) // Neu khong an mat khau hoac an mat khau nhung khong phai la ky tu "[", "]"
      {
        if (c != ']' && c != '[')
        {
          mk.push_back(c); // them ky tu vua nhap vao mk
        }
      }
      // Neu an ky tu ] thi an mat khau
      if (c == ']')
      {
        if (hidePassword == false)
        {
          hidePassword = true;
          // Xoa cac ky tu chua an truoc tien
          for (int i = 0; i < mk.length(); i++)
          {
            // if (i == 0)
            // {
            //   cout << "\b \b";
            // }
            cout << "\b \b";
          }

          // In ra cac ky tu * thay cho mat khau
          for (int i = 0; i < mk.length(); i++)
          {
            if (mk[i] == '[' || mk[i] == ']')
            {
            }
            else
            {
              cout << "*";
            }
          }
        }
      }
      // Neu an ky tu [ thi hien mat khau
      else if (c == '[')
      {
        if (hidePassword == true)
        {
          hidePassword = false;
          prevMk = mk; // Luu cac mat khau da nhap truoc khi an

          // Xoa cac ky tu chua * truoc tien
          for (int i = 0; i < mk.length(); i++)
          {
            cout << "\b \b";
          }

          // In ra cac ky tu da nhap truoc do
          for (int i = 0; i < prevMk.length(); i++)
          {
            if (prevMk[i] == '[' || prevMk[i] == ']')
            {
            }
            else
            {
              cout << prevMk[i];
            }
          }
        }
      }
    }
  }
}

bool XuLy::login(string &tk)
{
  system("cls");

  string mk, itk, imk;
  bool flag = false;
  bool printed = false;

  ifstream input("output.txt");

  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 11);
  cout << endl;
  cout << "\t\t\t\t\t╔════════════════════════════════════╗\n";
  cout << "\t\t\t\t\t║          LOGIN FORM                ║\n";
  cout << "\t\t\t\t\t╟────────────────────────────────────╢\n";
  cout << "\t\t\t\t\t║                                    ║\n";
  cout << "\t\t\t\t\t║  Tai khoan:                        ║\n";
  cout << "\t\t\t\t\t║  Mat khau:                         ║\n";
  cout << "\t\t\t\t\t║                                    ║\n";
  cout << "\t\t\t\t\t║  Ấn '[' để hiện mật khẩu           ║\n";
  cout << "\t\t\t\t\t║  Ấn ']' để ẩn mật khẩu             ║\n";
  cout << "\t\t\t\t\t║                                    ║\n";
  cout << "\t\t\t\t\t╚════════════════════════════════════╝\n\n";

  SetConsoleTextAttribute(color, 14);
  // 27: Là hàng thứ 27, 95: Là cột thứ 95
  cout << "\033[27;95H";
  cout << "Duoc thuc hien boi nhom 7" << endl;
  SetConsoleTextAttribute(color, 15);
  cout << "\033[28;95H";
  cout << "The Vien & Xuan Truong 😁" << endl;
  SetConsoleTextAttribute(color, 7);
  cout << "\033[6;55H";
  cin >> tk;

  cout << "\033[7;55H";
  // cin >> mk;
  mk = "";
  anHienMatKhau(mk);
  for (int i = 0; i < mk.length(); i++)
  {
    cout << "\b \b";
  }
  for (int i = 0; i < mk.length(); i++)
  {
    cout << "*";
  }

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(hConsole, &cursorInfo);

  while (input >> itk >> imk)
  {

    if (tk == itk && mk == imk)
    {
      flag = true;
      cout << endl;
      cout << endl;
      cout << endl;
      cout << endl
           << endl
           << endl
           << endl;
      HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

      animationLoading(tk);
      SetConsoleTextAttribute(color, 10);
      cout << endl;
      cout << "\n\t\t\tDang nhap thanh cong ✅" << endl;

      tatConTro();

      system("pause > nul");
      system("cls");

      break;
    }
  }

  input.close();

  if (!flag)
  {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl
         << endl
         << endl
         << endl;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Sai tai khoan hoac mat khau! Vui long nhap lai 😚 " << endl;
    system("pause >nul");
    SetConsoleTextAttribute(color, 7);
  }

  if (flag == true)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void XuLy::signUp()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  system("cls");

  string tk = "", mk = "", imk = "", itk = "";
  string viTriHienTaiTK, viTriHienTaiMK, viTriHienTaiIMK;
  cout << endl;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 11);
  cout << "\t\t\t\t\t╔════════════════════════════════════╗\n";
  cout << "\t\t\t\t\t║          SIGNUP FORM               ║\n";
  cout << "\t\t\t\t\t╟────────────────────────────────────╢\n";
  cout << "\t\t\t\t\t║                                    ║\n";
  cout << "\t\t\t\t\t║  Tai khoan:                        ║\n";
  cout << "\t\t\t\t\t║  Mat khau:                         ║\n";
  cout << "\t\t\t\t\t║  Nhap lai mat khau:                ║\n";
  cout << "\t\t\t\t\t║                                    ║\n";
  cout << "\t\t\t\t\t║  Ấn '[' để hiện mật khẩu           ║\n";
  cout << "\t\t\t\t\t║  Ấn ']' để ẩn mật khẩu             ║\n";
  cout << "\t\t\t\t\t║                                    ║\n";
  cout << "\t\t\t\t\t╚════════════════════════════════════╝\n\n";

  do
  {
    ifstream input("taiKhoan.txt");
    viTriHienTaiTK = "\033[6;55H" + itk;
    viTriHienTaiMK = "\033[7;55H" + mk;
    viTriHienTaiIMK = "\033[8;63H" + imk;

    cout << "\033[18;5H";
    cout << "\033[K";
    cout << "\033[19;0H";
    cout << "\033[K";

    if (itk != "")
    {
      cout << viTriHienTaiTK;
      for (int i = 0; i < itk.length(); i++)
      {
        cout << "\b \b";
      }
    }
    if (mk != "")
    {
      cout << viTriHienTaiMK;
      for (int i = 0; i < mk.length(); i++)
      {
        cout << "\b \b";
      }
    }
    if (imk != "")
    {
      cout << viTriHienTaiIMK;
      for (int i = 0; i < imk.length(); i++)
      {
        cout << "\b \b";
      }
    }

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    cout << "\033[6;55H";
    SetConsoleTextAttribute(color, 7);

    cin >> itk;

    cout << "\033[7;55H";
    mk = "";
    anHienMatKhau(mk);
    for (int i = 0; i < mk.length(); i++)
    {
      cout << "\b \b";
    }
    for (int i = 0; i < mk.length(); i++)
    {
      cout << "*";
    }

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    cout << "\033[8;63H";
    // cin >> imk;
    imk = "";
    anHienMatKhau(imk);
    if (imk != mk)
    {
      cout << "\033[18;5H";
      HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
      GetConsoleCursorInfo(hConsole, &cursorInfo);
      cursorInfo.bVisible = false;
      SetConsoleCursorInfo(hConsole, &cursorInfo);
      SetConsoleTextAttribute(color, 12);

      cout << "\t\t\t\t❌ Mat khau ban da nhap khong giong voi mat khau truoc 😚 " << endl;
      SetConsoleTextAttribute(color, 7);
    }
    if (imk == mk)
    {
      for (int i = 0; i < imk.length(); i++)
      {
        cout << "\b \b";
      }
      for (int i = 0; i < imk.length(); i++)
      {
        cout << "*";
      }
    }

    while (!input.eof())
    {
      input >> tk;
      if (tk == itk)
      {
        cout << "\033[19;0H";
        HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(color, 12);
        cout << "\t\t\t\t\t Tai khoan ban dang ky da ton tai!" << endl;
        tatConTro();
        itk = tk;
        break;
      }
    }
    if (imk != mk || tk == itk)
    {
      system("pause > nul");
    }
  } while (imk != mk || tk == itk);

  ofstream output("output.txt", ios::app);
  output << itk << " "
         << imk << endl;
  ofstream outputTK("taiKhoan.txt", ios::app);
  outputTK << itk << endl;
  cout << "\033[18;5H";
  cout << "\033[K";
  cout << "\033[19;0H";
  cout << "\033[K";
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(hConsole, &cursorInfo);
  SetConsoleTextAttribute(color, 10);

  cout << "\t\t\t\t\t\tDang ky thanh cong ✅" << endl;
  SetConsoleTextAttribute(color, 7);
  system("pause >nul");
  system("cls");
}

void XuLy::XuLyLogin(string &taiKhoan)
{
  bool flag = true;
  int chon;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  do
  {
    inMenuLogin(chon);
    SetConsoleTextAttribute(color, 7);
    switch (chon)
    {
    case 1:
      flag = login(taiKhoan);
      break;
    case 2:
      signUp();
      break;
    case 0:
      system("cls");
      tatConTro();
      SetConsoleTextAttribute(color, 3);
      cout << endl;
      cout << endl;
      cout << endl;
      cout << "\t\t\t\t\t\tSee you next time 😁" << endl;
      cout << endl;
      cout << endl;
      SetConsoleTextAttribute(color, 14);
      printGoodBye();
      system("pause >nul");
      exit(1);
      break;

    default:
      break;
    }
  } while (flag);
}

void XuLy::InMenuQuanLyNhanSu(int &chon)
{
  bool flag = true;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  do
  {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << endl;
    cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═══╟════ Menu Quan Ly Nhan Su 🧑‍💻════║═══╗\n";
    cout << "\t\t\t\t║   ╚═══════════════════════════════════╝   ║\n";
    cout << "\t\t\t\t║                                           ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     1. Them nhan su";
    SetConsoleTextAttribute(color, 11);
    cout << "                       ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     2. Xuat nhan su";
    SetConsoleTextAttribute(color, 11);
    cout << "                       ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     3. Sap xep nhan su theo ten A-Z";
    SetConsoleTextAttribute(color, 11);
    cout << "       ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     4. Sap xep theo luong giam dan";
    SetConsoleTextAttribute(color, 11);
    cout << "        ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     5. Tim kiem theo ma so";
    SetConsoleTextAttribute(color, 11);
    cout << "                ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     6. Tim kiem theo ten  ";
    SetConsoleTextAttribute(color, 11);
    cout << "                ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     7. Tim nhan su co muc luong cao nhat";
    SetConsoleTextAttribute(color, 11);
    cout << "  ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     8. Sua doi thong tin nhan su";
    SetConsoleTextAttribute(color, 11);
    cout << "          ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     9. Xoa nhan su";
    SetConsoleTextAttribute(color, 11);
    cout << "                        ║\n";
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 7);
    cout << "     0. Thoat khoi menu QLNS";
    SetConsoleTextAttribute(color, 11);
    cout << "               ║\n";
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
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\t❌ Lua chon cua ban khong hop le. Vui long chon lai!" << endl;
      SetConsoleTextAttribute(color, 7);
      flag = true;
    }
    else
    {
      flag = false;
    }
  } while (flag);

  SetConsoleTextAttribute(color, 7);
}

void XuLy::printASCII(string fileName)
{
  string line = "";
  ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    while (getline(inFile, line))
    {
      cout << "\t\t\t\t" << line << endl;
    }
    inFile.close();
  }
  else
  {
    cout << "File failed to load" << endl;
  }
  inFile.close();
}

void XuLy::printGoodBye()
{
  string fileName = "goodBye.txt";
  printASCII(fileName);
}

void XuLy::printWelcome()
{
  string fileName = "WelcomeNew.txt";
  printASCII(fileName);
}

void XuLy::clearScreen()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD coordScreen = {0, 0};
  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD dwConSize;

  if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
  {
    throw runtime_error("Loi: GetConsoleScreenBufferInfo");
    return;
  }
  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

  if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten))
  {
    throw runtime_error("Loi: FillConsoleOutputCharacter");
    return;
  }
  if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten))
  {
    throw runtime_error("Loi: FillConsoleOutputAttribute");
    return;
  }
  SetConsoleCursorPosition(hConsole, coordScreen);
}

void XuLy::tatConTro()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(hConsole, &cursorInfo);
}
