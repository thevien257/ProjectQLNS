#include "XuLy.h"
#include "NhanVienThuong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

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

  do
  {
    for (NhanSu *ns : ds.getListNS())
    {
      if (NhanVienThuong *newNV = dynamic_cast<NhanVienThuong *>(ns))
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
              cout << "\t\t\tNhap ma de tim truong phong: ";
              cin >> chonMa;
              tp = timTruongPhongTheoMa(chonMa);
            } while (tp == nullptr);
            newNV->setTruongPhong(tp);
            tp->tangNhanVien();
          }

          flag = false;
        }
        else
        {
          cout << "\t\t\tChi duoc chon 1 hoac 2" << endl;
          flag = true;
        }
      }
    }
  } while (flag);
}

void XuLy::inMenuLogin()
{
  cout << "\t\t\t\t ___________________________________\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|        Menu Dang Nhap 💻          |\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|___________________________________|\n";
  cout << endl;
  cout << "\t\t\t\t1. Dang nhap " << endl;
  cout << "\t\t\t\t2. Dang ky" << endl;
  cout << "\t\t\t\t3. Thoat" << endl;
  cout << "\t\t\t\t--------------------> Moi chon: ";
}

void XuLy::login()
{
  system("cls");
  string tk, mk, itk, imk;
  bool flag = false;
  do
  {
    cout << "\t\t\t\tTai khoan: ";
    cin >> tk;
    cout << "\t\t\t\tMat khau: ";
    cin >> mk;
    ifstream input;
    input.open("output.txt");
    while (input >> itk >> imk)
    {
      if (tk == itk && mk == imk)
      {
        flag = true;
      }
      input.close();
      if (flag == true)
      {
        cout << endl;
        cout << "\t\t\t\tDang nhap thanh cong ✅" << endl;
        cout << "\t\t\t\tXin chao " << itk << " 👋 " << endl;
      }
      else
      {
        cout << "❌ Sai tai khoan hoac mat khau! Vui long nhap lai 😚 " << endl;
      }
    }
  } while (flag == false);
}

void XuLy::signUp()
{
  string tk, mk, itk, imk;
  cout << "Tai khoan: ";
  cin >> tk;
  do
  {
    cout << "Nhap lai tai khoan: ";
    cin >> itk;

  } while (itk != tk);
  cout << "Mat khau: ";
  cin >> imk;
  ofstream output("output.txt", ios::app);
  output << itk << " "
         << imk << endl;
  cout << "Dang ky thanh cong ✅" << endl;
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
      login();
      flag = false;
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
  cout << "\t\t\t\t4. Tim nhan vien tre tuoi nhat" << endl;
  cout << "\t\t\t\t5. Tim nhan vien luong cao nhat" << endl;
  cout << "\t\t\t\t6. Sap xep luong giam dan" << endl;
  cout << "\t\t\t\t7. Sua doi thong tin nhan vien" << endl;
  cout << "\t\t\t\t8. Tim nhan vien" << endl;
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
    case 0:
      flag = false;
      break;
    default:
      break;
    }
  } while (flag);
}