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
using namespace std;

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
  cout << "\t\t\tNhap ma so de xoa nhan su: ";
  cin >> maSo;
  bool foundNS = found(maSo);
  if (foundNS)
  {
    cout << "\t\t\t\tDa tim thay nhan su ✅" << endl;
    Sleep(1000);
    cout << "\t\t\t\tDa xoa nhan su mang ma so " << maSo << " ✅" << endl;
    for (int i = 0; i < ds.getListNS().size(); i++)
    {
      if (TruongPhong *tp = dynamic_cast<TruongPhong *>(ds.getListNS()[i]))
      {
        if (tp != nullptr)
        {
          if (tp->getMaSo() == maSo)
          {
            xoaTruongPhong(tp);
            cout << "\t\t\t\tDa xoa truong phong co ten " << tp->getHoTen() << " ✅" << endl;
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
            cout << "\t\t\t\tDa xoa giam doc co ten " << giamDoc->getHoTen() << " ✅" << endl;
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
            cout << "\t\t\t\tDa xoa nhan vien thuong co ten " << nvt->getHoTen() << " ✅" << endl;
          }
        }
      }
    }
  }
  else
  {
    cout << "\t\t\tOOPS! Khong tim thay nhan su voi ma so " << maSo << " 🥲" << endl;
  }
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
  auto it = std::find(ds.getListNS().begin(), ds.getListNS().end(), truongPhong);
  if (it != ds.getListNS().end())
  {
    ds.getListNS().erase(it);
  }
}

void XuLy::timNhanSu()
{
  string maSo;
  cout << "\t\t\tNhap ma so nhan su can tim";
  cin >> maSo;
  bool foundNS = found(maSo);
  if (foundNS == true)
  {
    cout << "\t\t\tDa tim thay nhan su ✅" << endl;
    cout << endl;
    for (NhanSu *ns : ds.getListNS())
    {
      if (maSo == ns->getMaSo())
      {
        ns->xuat();
      }
    }
  }
  else
  {
    cout << "\t\t\tOOPS! Khong tim thay nhan su voi ma so " << maSo << " 🥲" << endl;
  }
}

void XuLy::suaDoiThongTinNhanSu()
{
  string ma;
  cout << "\t\t\tNhap ma nhan su can sua doi: ";
  cin >> ma;
  for (NhanSu *ns : ds.getListNS())
  {
    if (ma == ns->getMaSo())
    {
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

void XuLy::sapXepNVTreTuoiNhat()
{
  vector<NhanSu *> nsList = ds.getListNS();
  sort(nsList.begin(), nsList.end(), [](NhanSu *ns1, NhanSu *ns2)
       { return ns1->getHoTen() < ns2->getHoTen(); });
  ds.setListNS(nsList);
}

void XuLy::timNVLuongCaoNhat()
{
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
      cout << endl;
      cout << "\t\t\tDay la nhan su co muc luong cao nhat" << endl;
      ns->xuat();
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

void XuLy::inMenuLogin()
{
  cout << endl;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, 11);
  cout << "\t\t\t\t\t ___________________________________\n";
  cout << "\t\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t\t|        Menu Dang Nhap 💻          |\n";
  cout << "\t\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t\t|___________________________________|\n";
  cout << endl;
  SetConsoleTextAttribute(color, 7);
  cout << "\t\t\t\t\t1. Dang nhap " << endl;
  cout << "\t\t\t\t\t2. Dang ky" << endl;
  cout << "\t\t\t\t\t3. Thoat" << endl;
  cout << "\t\t\t\t\t--------------------> Moi chon 👉 ";
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

  cout << "\033[6;55H"; // Move the cursor to the position after "Tai khoan:"

  // get user input for tai khoan
  SetConsoleTextAttribute(color, 7);
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
  do
  {
    inMenuLogin();
    cin >> chon;
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

void XuLy::inMenu()
{
  cout << endl;
  cout << "\t\t\t\t ___________________________________\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|     Menu Quan Ly Nhan Su 🧑‍💻    |\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|___________________________________|\n";
  cout << endl;
  cout << "\t\t\t\t1. Them nhan su " << endl;
  cout << "\t\t\t\t2. Xuat nhan su" << endl;
  cout << "\t\t\t\t3. Phan bo truong phong" << endl;
  cout << "\t\t\t\t4. Sap xep nhan vien theo ten A-Z" << endl;
  cout << "\t\t\t\t5. Tim nhan vien luong cao nhat" << endl;
  cout << "\t\t\t\t6. Sap xep luong giam dan" << endl;
  cout << "\t\t\t\t7. Sua doi thong tin nhan vien" << endl;
  cout << "\t\t\t\t8. Tim nhan vien" << endl;
  cout << "\t\t\t\t9. Xoa nhan su" << endl;
  cout << "\t\t\t\t--------------------> Moi chon: ";
}

void XuLy::xuLyMenu()
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
      ds.nhap();
      break;
    case 2:
      ds.xuat();
      break;
    case 3:
      phanBoNhanVienThuong();
      break;
    case 4:
      sapXepNVTreTuoiNhat();
      ds.xuat();
      break;
    case 5:
      timNVLuongCaoNhat();
      break;
    case 6:
      sapXepLuongGiamDan();
      ds.xuat();
      break;
    case 7:
      suaDoiThongTinNhanSu();
      break;
    case 8:
      timNhanSu();
      break;
    case 9:
      xoaNhanSu();
      break;
    case 0:
      cout << endl;
      cout << "\t\t\t\t\tSee you next time 😁" << endl;
      Sleep(2000);
      flag = false;
      break;
    default:
      break;
    }
  } while (flag);
}