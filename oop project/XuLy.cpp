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
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

void XuLy::inMenuPhongBan()
{
  cout << endl;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 11);
  cout << "\t\t\t\t\t ___________________________________\n";
  cout << "\t\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t\t|    Menu Quan ly phong ban 🏢\t\t|\n";
  cout << "\t\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t\t|___________________________________|\n";
  cout << endl;
  SetConsoleTextAttribute(color, 7);
  cout << "\t\t\t\t\t1. Them phong ban " << endl;
  cout << "\t\t\t\t\t2. Xuat phong ban" << endl;
  cout << "\t\t\t\t\t3. Phan bo nhan vien ve phong ban" << endl;
  cout << "\t\t\t\t\t4. Chi dinh truong phong ve phong ban" << endl;
  cout << "\t\t\t\t\t0. Thoat khoi menu quan ly phong ban" << endl;
  cout << "\t\t\t\t\t--------------------> Moi chon 👉 ";
}

void XuLy::xuLyMenuPhongBan()
{
  bool flag = true;
  int chon;
  system("cls");
  do
  {
    inMenuPhongBan();
    cin >> chon;
    if (chon != 2)
    {
      system("cls");
    }
    switch (chon)
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
    case 0:
      flag = false;
      break;
    default:
      cout << "\t\t\t\t\tChi duoc chon 1, 2, 3 hoac 0" << endl;
      break;
    }
  } while (flag);
}

// TruongPhong *XuLy::timTP(string maTP)
// {
//   for (NhanSu *ns : ds.getListNS())
//   {
//     if (TruongPhong *tp = dynamic_cast<TruongPhong *>(tp))
//     {
//       if (tp != nullptr)
//       {
//         if (tp->getMaSo() == maTP)
//         {
//           return tp;
//         }
//       }
//     }
//   }
//   return nullptr;
// }

void XuLy::chiDinhTruongPhong()
{
  for (NhanSu *ns : ds.getListNS())
  {
    if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ns))
    {
      if (tp != nullptr)
      {
        bool flag = true;
        do
        {

          cout << "\t\t\tDang phan bo truong phong: " << endl;
          cout << "\t\t\tMa so: " << tp->getMaSo() << "\t"
               << "Ho ten: " << tp->getHoTen() << endl;
          cout << "\t\t\tChon 1. de phan bo hoac chon 2. de di tiep: ";
          int chon;
          string maPB;
          PhongBan *pb = nullptr;
          cin >> chon;
          switch (chon)
          {
          case 1:
            cout << endl;
            cout << "\t\t\tDay la danh sach phong ban: " << endl;
            dsPB.xuatPB();
            cout << "\t\t\tMoi chon ma phong: ";
            cin >> maPB;
            pb = timPhongBan(maPB);
            if (pb != nullptr)
            {
              tp->setMaPhongBan(maPB);
              pb->setTruongPhong(tp);
            }
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
            flag = false;
            break;
          case 2:
            flag = false;
            break;

          default:
            cout << "\t\t\t Chi duoc chon 1 hoac 2" << endl;
            break;
          }
        } while (flag);
      }
    }
  }
}

void XuLy::phanBoNhanVienThuongVaoPhongBan()
{
  for (NhanSu *ns : ds.getListNS())
  {
    if (NhanVienThuong *nvt = dynamic_cast<NhanVienThuong *>(ns))
    {
      if (nvt != nullptr)
      {
        bool flag = true;
        do
        {

          cout << "\t\t\tDang phan bo cho nhan vien: " << endl;
          cout << "\t\t\tMa so: " << nvt->getMaSo() << "\t"
               << "Ho ten: " << nvt->getHoTen() << endl;
          cout << "\t\t\tChon 1. de phan bo hoac chon 2. de di tiep: ";
          int chon;
          string maPhong;
          PhongBan *pb = nullptr;
          cin >> chon;
          switch (chon)
          {
          case 1:
            cout << endl;
            cout << "\t\t\tDay la danh sach phong ban: " << endl;
            dsPB.xuatPB();
            cout << "\t\t\tMoi chon ma phong: ";
            cin >> maPhong;
            pb = timPhongBan(maPhong);
            if (pb != nullptr)
            {
              nvt->setMaPhongBan(maPhong);
              pb->getDsNV().push_back(nvt);
            }
            flag = false;
            break;
          case 2:
            flag = false;
            break;

          default:
            cout << "\t\t\t Chi duoc chon 1 hoac 2" << endl;
            break;
          }
        } while (flag);
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

void XuLy::inMenuTask()
{
  cout << endl;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 11);
  cout << "\t\t\t\t\t ___________________________________\n";
  cout << "\t\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t\t|      Menu Quan Ly Task 📋\t\t|\n";
  cout << "\t\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t\t|___________________________________|\n";
  cout << endl;
  SetConsoleTextAttribute(color, 7);
  cout << "\t\t\t\t\t1. Them task " << endl;
  cout << "\t\t\t\t\t2. Xuat task" << endl;
  cout << "\t\t\t\t\t3. Xoa task" << endl;
  cout << "\t\t\t\t\t4. Phan bo task cho nhan vien" << endl;
  cout << "\t\t\t\t\t0. Thoat khoi menu quan ly Task" << endl;
  cout << "\t\t\t\t\t--------------------> Moi chon 👉 ";
}

void XuLy::xuLyMenuTask()
{
  bool flag = true;
  int chon;
  system("cls");
  do
  {
    inMenuTask();
    cin >> chon;
    switch (chon)
    {
    case 1:
      dsTask.nhapTask();
      break;
    case 2:
      dsTask.xuatTask();
    case 3:
      break;
    case 4:
      break;
    case 0:
      flag = false;
      cout << "Da thoat khoi menu quan ly Task ✅" << endl;
      cout << endl;
      break;
    default:
      break;
    }

  } while (flag);
}

void XuLy::phanBoTask()
{
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
  string maSo;
  cout << "\t\t\t\tNhap ma so de xoa nhan su: ";
  cin >> maSo;
  bool foundNS = found(maSo);
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (foundNS)
  {
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t\t\tDa tim thay nhan su ✅" << endl;
    Sleep(1000);
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
            cout << "\t\t\t\tDa xoa truong phong mang ma so " << tp->getMaSo() << "- co ten " << tp->getHoTen() << " ✅" << endl;
            cout << endl;
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
            cout << "\t\t\t\tDa xoa giam doc mang ma so " << giamDoc->getHoTen() << " - co ten " << giamDoc->getHoTen() << " ✅" << endl;
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
            cout << "\t\t\t\tDa xoa nhan vien thuong mang ma so " << nvt->getMaSo() << " - co ten " << nvt->getHoTen() << " ✅" << endl;
            cout << endl;
          }
        }
      }
    }
  }
  else
  {
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\tOOPS! Khong tim thay nhan su voi ma so " << maSo << " 🥲" << endl;
  }
  SetConsoleTextAttribute(color, 7);
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
  }
}

void XuLy::timNhanSu()
{
  string maSo;
  cout << "\t\t\t\tNhap ma so nhan su can tim               🔎";
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 11);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  GetConsoleScreenBufferInfo(color, &consoleInfo);
  COORD cursorPosition = consoleInfo.dwCursorPosition;
  // Move the cursor to the right by incrementing X coordinate
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
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  string ma;
  cout << "\t\t\t\tNhap ma nhan su can sua doi: ";
  cin >> ma;
  for (NhanSu *ns : ds.getListNS())
  {
    if (ma == ns->getMaSo())
    {
      SetConsoleTextAttribute(color, 10);
      cout << "\t\t\t\tDa tim thay nhan su voi ma so " << ma << " ✅" << endl;
      cout << "\t\t\t\tVui long nhap cac thong tin sau de sua doi " << endl;
      cout << endl;
      SetConsoleTextAttribute(color, 7);
      ns->nhap();
    }
  }
}

void XuLy::sapXepLuongGiamDan()
{
  vector<NhanSu *> nsList = ds.getListNS();
  sort(nsList.begin(), nsList.end(), [](NhanSu *ns1, NhanSu *ns2)
       { return ns1->getLuong() > ns2->getLuong(); });
  ds.setListNS(nsList);
}

void XuLy::SapXepTheoTen()
{
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
}

void XuLy::timNVLuongCaoNhat()
{
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

        if (chon == 1 || chon == 2)
        {
          if (chon == 1)
          {

            do
            {
              string chonMa;
              cout << "\t\t\tNhap ma de tim truong phong 🔍 ";
              cin >> chonMa;
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
      } while (flag);
    }
  }
}

// void XuLy::inMenuLogin()
// {
//   system("cls");
//   HANDLE colorReal = GetStdHandle(STD_OUTPUT_HANDLE);
//   SetConsoleTextAttribute(colorReal, 14);
//   printWelcome();
//   HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//   SetConsoleTextAttribute(color, 11);
//   cout << "\033[H";   // move cursor to top-left corner
//   cout << "\033[35C"; // move cursor to right
//   cout << " ___________________________________\n";
//   cout << "\033[35C";
//   cout << "|                                   |\n";
//   cout << "\033[35C";
//   cout << "|        Menu Dang Nhap 💻          |\n";
//   cout << "\033[35C";
//   cout << "|                                   |\n";
//   cout << "\033[35C";
//   cout << "|___________________________________|\n";
//   cout << endl;
//   SetConsoleTextAttribute(color, 7);
//   cout << "\033[35C"; // move cursor to right
//   cout << "1. Dang nhap " << endl;
//   cout << "\033[35C"; // move cursor to right
//   cout << "2. Dang ky" << endl;
//   cout << "\033[35C"; // move cursor to right
//   cout << "3. Thoat" << endl;
//   cout << "\033[35C"; // move cursor to right
//   cout << "--------------------> Moi chon 👉 ";
//   SetConsoleTextAttribute(colorReal, 7);
// }

void XuLy::inMenuLogin(int &chon)
{
  system("cls");
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  // cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
  // cout << "\t\t\t\t╔═══╟════ Menu Quan Ly Nhan Su 🧑‍💻════║═══╗\n";
  // cout << "\t\t\t\t║   ╚═══════════════════════════════════╝   ║\n";
  // cout << "\t\t\t\t║                                           ║\n";
  // cout << "\t\t\t\t║";
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

  // cout << "\033[17;55H";
  // cin >> chon;
  // Get the current cursor position
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  GetConsoleScreenBufferInfo(color, &consoleInfo);
  COORD cursorPosition = consoleInfo.dwCursorPosition;
  // Move the cursor to the right by incrementing X coordinate
  cursorPosition.X += 67;
  cursorPosition.Y -= 4;
  SetConsoleCursorPosition(color, cursorPosition);
  cin >> chon;

  SetConsoleTextAttribute(color, 7);
}

bool XuLy::login()
{
  system("cls");

  string tk, mk, itk, imk;
  bool flag = false;

  ifstream input("output.txt");
  // cout << "\t\t\t\tTai khoan: ";
  // cin >> tk;
  // cout << "\t\t\t\tMat khau: ";
  // cin >> mk;

  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << "\t\t\t\t\t╔════════════════════════════════════╗\n";
  // cout << "\t\t\t\t\t║          LOGIN FORM                ║\n";
  // cout << "\t\t\t\t\t╟────────────────────────────────────╢\n";
  // cout << "\t\t\t\t\t║                                    ║\n";
  // cout << "\t\t\t\t\t║  Tai khoan:                         ║\n";
  // cout << "\t\t\t\t\t║  Mat khau:                          ║\n";
  // cout << "\t\t\t\t\t║                                    ║\n";
  // cout << "\t\t\t\t\t╚════════════════════════════════════╝\n\n";

  // // get user input for tai khoan
  // cin >> tk;

  // // get user input for mat khau
  // cin >> mk;

  // // print table footer
  // cout << "\n\n\t\t\t\t";
  // cout << "\033[7B"; // move cursor up 7 lines
  // cout << "╟────────────────────────────────────╢\n";
  // cout << "\t\t\t\t║                                    ║\n";
  // cout << "\t\t\t\t╚════════════════════════════════════╝\n\n";

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
  cout << "\t\t\t\t\t╚════════════════════════════════════╝\n\n";

  SetConsoleTextAttribute(color, 7);
  cout << "\033[6;55H"; // Move the cursor to the position after "Tai khoan:"

  // get user input for tai khoan
  cin >> tk;

  cout << "\033[7;55H"; // Move the cursor to the position after "Mat khau:"

  // get user input for mat khau
  cin >> mk;

  while (input >> itk >> imk)
  {

    if (tk == itk && mk == imk)
    {
      flag = true;
      cout << endl;
      cout << endl;
      cout << endl;
      HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(color, 10);
      cout << "\n\t\t\t\t\t\tDang nhap thanh cong ✅" << endl;
      SetConsoleTextAttribute(color, 7);
      cout << "\t\t\t\t\t\tXin chao " << itk << " 👋 " << endl;
      Sleep(2000);
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
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\t❌ Sai tai khoan hoac mat khau! Vui long nhap lai 😚 " << endl;
    Sleep(1500);
    // cout << "\t\t\tHoac ban chua dang ky tai khoan, vui long dang ky truoc khi dang nhap 🧐" << endl;
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
  system("cls");
  string tk, mk, itk, imk;
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
  cout << "\t\t\t\t\t╚════════════════════════════════════╝\n\n";

  cout << "\033[6;55H"; // Move the cursor to the position after "Tai khoan:"
  SetConsoleTextAttribute(color, 7);
  // get user input for tai khoan
  cin >> itk;
  cout << "\033[7;55H"; // Move the cursor to the position after "Mat khau:"

  // get user input for mat khau
  cin >> mk;
  do
  {
    cout << "\033[8;63H";
    cin >> imk;
    if (imk != mk)
    {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << endl;
      cout << endl;
      cout << endl;
      HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(color, 12);
      cout << "\t\t\t\t❌ Mat khau ban da nhap khong giong voi mat khau truoc 😚 " << endl;
      SetConsoleTextAttribute(color, 7);
    }
  } while (imk != mk);

  ofstream output("output.txt", ios::app);
  output << itk << " "
         << imk << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << "\033[K" << endl;
  SetConsoleTextAttribute(color, 10);
  cout << "\t\t\t\t\t\tDang ky thanh cong ✅" << endl;
  SetConsoleTextAttribute(color, 7);
  Sleep(1500);
  system("cls");
}

void XuLy::XuLyLogin()
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
      flag = login();
      break;
    case 2:
      signUp();
      break;

    default:
      break;
    }
  } while (flag);
}

void XuLy::inMenu(int &chon)
{

  cout << endl;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
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
  cout << "     5. Tim nhan vien";
  SetConsoleTextAttribute(color, 11);
  cout << "                      ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "     6. Tim nhan vien muc luong cao nhat";
  SetConsoleTextAttribute(color, 11);
  cout << "   ║\n";
  // cout << "       ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "     7. Sua doi thong tin nhan vien";
  SetConsoleTextAttribute(color, 11);
  cout << "        ║\n";
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 7);
  cout << "     8. Xoa nhan su";
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

  // cout << "\033[17;55H";
  // cin >> chon;
  // Get the current cursor position
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

void XuLy::gotoxy(int x, int y) // function to move cursor position to (x,y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // set console cursor position
}

// void XuLy::inMenu(int &chon)
// {
//   // ...menu output...
//   HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//   cout << "\t\t\t\t║";
//   SetConsoleTextAttribute(color, 7);
//   cout << "     > Moi chon 👉";
//   SetConsoleTextAttribute(color, 11);
//   cout << "                         ║\n";
//   cout << "\t\t\t\t║                                           ║\n";
//   cout << "\t\t\t\t╚═══════════════════════════════════════════╝\n\n";

// COORD coord;
// coord.X = 0;
// coord.Y = 0;

// SMALL_RECT Rect;
// Rect.Top = 0;
// Rect.Left = 0;
// Rect.Bottom = 50; // Increase the console window height here
// Rect.Right = 100;

// HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Get handle to console window
// SetConsoleScreenBufferSize(ConsoleHandle, coord);       // Set the screen buffer size
// SetConsoleWindowInfo(ConsoleHandle, TRUE, &Rect);       // Set the console window size

// SetConsoleCursorPosition(ConsoleHandle, {25, 0}); // Position cursor at the top-left corner of the console window
// cin >> chon;
// }

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

void XuLy::XuLyMenuNhanSu()
{
  bool flag = true;
  int chon;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  system("cls");
  do
  {
    inMenu(chon);
    // SetConsoleTextAttribute(color, 11);
    // cin>>chon;
    // SetConsoleTextAttribute(color, 7);
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
      ds.xuat();
      break;
    case 4:
      cout << endl;
      cout << endl;
      cout << endl;
      sapXepLuongGiamDan();
      ds.xuat();
      break;
    case 5:
      cout << endl;
      cout << endl;
      cout << endl;
      timNhanSu();
      break;
    case 6:
      cout << endl;
      cout << endl;
      cout << endl;
      timNVLuongCaoNhat();
      break;
    case 7:
      cout << endl;
      cout << endl;
      cout << endl;
      suaDoiThongTinNhanSu();
      break;
    case 8:
      cout << endl;
      cout << endl;
      cout << endl;
      xoaNhanSu();
      ds.xuat();
      break;
    case 0:
      flag = false;
      break;
    default:
      break;
    }
  } while (flag);
}

void XuLy::inMenuChung()
{
  system("cls");
  cout << endl;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 11);
  cout << "\t\t\t\t ________________________________\n";
  cout << "\t\t\t\t|                          \t|\n";
  cout << "\t\t\t\t|     Menu Quan Ly Chung 🧑‍💻\t|\n";
  cout << "\t\t\t\t|                           \t|\n";
  cout << "\t\t\t\t|_______________________________|\n";
  cout << endl;
  SetConsoleTextAttribute(color, 7);
  cout << "\t\t\t\t1. Quan ly nhan su " << endl;
  cout << "\t\t\t\t2. Quan ly phong ban" << endl;
  cout << "\t\t\t\t3. Quan ly Task" << endl;
  cout << "\t\t\t\t0. Thoat" << endl;
  cout << "\t\t\t\t--------------------> Moi chon 👉 ";
}

void XuLy::XuLyChung()
{
  bool flag = true;
  int chon;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  do
  {
    inMenuChung();
    cin >> chon;
    switch (chon)
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
    case 0:
      cout << endl;
      system("cls");
      SetConsoleTextAttribute(color, 3);
      cout << endl;
      cout << endl;
      cout << endl;
      cout << "\t\t\t\t\t\tSee you next time 😁" << endl;
      cout << endl;
      cout << endl;
      SetConsoleTextAttribute(color, 14);
      printGoodBye();
      Sleep(2000);
      flag = false;
      break;

    default:
      break;
    }

  } while (flag);
}