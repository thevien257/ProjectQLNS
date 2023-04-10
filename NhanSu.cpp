#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

const int luong1NgayNVT = 100;
const int luong1NgayTP = 200;
const int luong1NgayGD = 300;

class NhanSu
{
protected:
  string maSo;
  string hoTen;
  string soDienThoai;
  float soNgayLamViec;
  long luong;

public:
  NhanSu();
  NhanSu(string maSo,
         string hoTen,
         string soDienThoai,
         float soNgayLamViec);
  string getMaSo();
  string getHoTen();
  long getLuong();
  virtual void nhap();
  virtual void xuat();
  virtual void tinhLuong();
};

long NhanSu::getLuong()
{
  return luong;
}

string NhanSu::getHoTen()
{
  return hoTen;
}

string NhanSu::getMaSo()
{
  return maSo;
}

NhanSu::NhanSu()
{
}

NhanSu::NhanSu(string maSo,
               string hoTen,
               string soDienThoai,
               float soNgayLamViec)
{
  this->maSo = maSo;
  this->hoTen = hoTen;
  this->soDienThoai = soDienThoai;
  this->soNgayLamViec = soNgayLamViec;
}

void NhanSu::nhap()
{
  cout << endl;
  cout << "\t\t\t\tNhap ma so: ";
  cin >> maSo;
  cout << "\t\t\t\tNhap ho ten: ";
  cin >> hoTen;
  cout << "\t\t\t\tNhap so dien thoai: ";
  cin >> soDienThoai;
  cout << "\t\t\t\tSo ngay lam viec ";
  cin >> soNgayLamViec;
}

void NhanSu::xuat()
{
  cout << "\t\t\t_________________________________________" << endl;
  cout << "\t\t\t|Ma so\t\t\t| " << this->maSo << "\t\t|" << endl;
  cout << "\t\t\t|Ho ten\t\t\t| " << this->hoTen << "\t\t|" << endl;
  cout << "\t\t\t|So dien thoai\t\t|" << this->soDienThoai << "\t|" << endl;
  ofstream output("DanhSachNhanVien.txt", ios::app);
  output << "\t\t\t_________________________________________" << endl;
  output << "\t\t\t|Ma so\t\t\t| " << this->maSo << "\t\t|" << endl;
  output << "\t\t\t|Ho ten\t\t\t| " << this->hoTen << "\t\t|" << endl;
  output << "\t\t\t|So dien thoai\t\t|" << this->soDienThoai << "\t|" << endl;
}

void NhanSu::tinhLuong()
{
  this->luong = 0;
}

class TruongPhong : public NhanSu
{
private:
  int soLuongNhanVien;

public:
  TruongPhong();
  TruongPhong(string maSo,
              string hoTen,
              string soDienThoai,
              float soNgayLamViec);
  string getMaSo();
  string getTenTP();
  void nhap();
  void xuat();
  void tangNhanVien();
  void giamNhanVien();
  void tinhLuong();
};

TruongPhong::TruongPhong()
{
  this->soLuongNhanVien = 0;
}

TruongPhong::TruongPhong(string maSo,
                         string hoTen,
                         string soDienThoai,
                         float soNgayLamViec) : NhanSu(maSo, hoTen, soDienThoai, soNgayLamViec)
{
  this->soLuongNhanVien = 0;
}

string TruongPhong::getTenTP()
{
  return this->hoTen;
}

string TruongPhong::getMaSo()
{
  return this->maSo;
}

void TruongPhong::nhap()
{
  NhanSu::nhap();
}

void TruongPhong::xuat()
{
  NhanSu::xuat();
  ofstream output("DanhSachNhanVien.txt", ios::app);
  cout << "\t\t\t|So luong nhan vien\t| " << this->soLuongNhanVien << "\t\t|" << endl;
  cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
  cout << "\t\t\t_________________________________________" << endl;
  output << "\t\t\t|So luong nhan vien\t| " << this->soLuongNhanVien << "\t\t|" << endl;
  output << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
  output << "\t\t\t_________________________________________" << endl;
}

void TruongPhong::tangNhanVien()
{
  this->soLuongNhanVien++;
}

void TruongPhong::giamNhanVien()
{
  this->soLuongNhanVien--;
}

void TruongPhong::tinhLuong()
{
  this->luong = luong1NgayTP * this->soNgayLamViec + 100 * this->soLuongNhanVien;
}

class NhanVienThuong : public NhanSu
{
private:
  TruongPhong *tp;

public:
  NhanVienThuong();
  NhanVienThuong(string maSo, string hoTen, string soDienThoai, float soNgayLamViec);
  void tinhLuong();
  void setTruongPhong(TruongPhong *tp);
  void nhap();
  void xuat();
};

void NhanVienThuong::setTruongPhong(TruongPhong *tp)
{
  this->tp = tp;
}

NhanVienThuong::NhanVienThuong()
{
  tp = nullptr;
}

NhanVienThuong::NhanVienThuong(string maSo, string hoTen, string soDienThoai, float soNgayLamViec) : NhanSu(maSo, hoTen, soDienThoai, soNgayLamViec)
{
}

void NhanVienThuong::tinhLuong()
{
  this->luong = luong1NgayNVT * this->soNgayLamViec;
}

void NhanVienThuong::nhap()
{
  NhanSu::nhap();
}

void NhanVienThuong::xuat()
{
  if (tp != nullptr)
  {
    NhanSu::xuat();
    ofstream output("DanhSachNhanVien.txt", ios::app);
    cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
    cout << "\t\t\t|____Day la thong tin nguoi quan ly____"
         << "\t|" << endl;
    cout << "\t\t\t|Ten truong phong\t| " << tp->getHoTen() << "\t\t|" << endl;
    cout << "\t\t\t|Ma truong phong\t| " << tp->getMaSo() << "\t\t|" << endl;
    cout << "\t\t\t_________________________________________" << endl;

    output << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
    output << "\t\t\t|____Day la thong tin nguoi quan ly____"
           << "\t|" << endl;
    output << "\t\t\t|Ten truong phong\t| " << tp->getHoTen() << "\t\t|" << endl;
    output << "\t\t\t|Ma truong phong\t| " << tp->getMaSo() << "\t\t|" << endl;
    output << "\t\t\t_________________________________________" << endl;
  }
  else if (tp == nullptr)
  {
    NhanSu::xuat();
    ofstream output("DanhSachNhanVien.txt", ios::app);
    cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
    cout << "\t\t\t_________________________________________" << endl;

    output << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
    output << "\t\t\t_________________________________________" << endl;
  }
}

class GiamDoc : public NhanSu
{
private:
public:
  GiamDoc();
  GiamDoc(string maSo, string hoTen, string soDienThoai, float soNgayLamViec);
  void nhap();
  void xuat();
  void tinhLuong();
};

GiamDoc::GiamDoc()
{
}

GiamDoc::GiamDoc(string maSo, string hoTen, string soDienThoai, float soNgayLamViec) : NhanSu(maSo, hoTen, soDienThoai, soNgayLamViec)
{
}

void GiamDoc::nhap()
{
  NhanSu::nhap();
}

void GiamDoc::xuat()
{
  NhanSu::xuat();
  ofstream output("DanhSachNhanVien.txt", ios::app);
  cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
  cout << "\t\t\t_________________________________________" << endl;

  output << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;
  output << "\t\t\t_________________________________________" << endl;
}

void GiamDoc::tinhLuong()
{
  this->luong = luong1NgayGD * this->soNgayLamViec;
}

class danhSachNhanSu
{
private:
  vector<NhanSu *> dsNhanSu;
  NhanSu *ns;

public:
  vector<NhanSu *> getListNS();
  void setListNS(vector<NhanSu *> listNS);
  void inMenu();
  void nhap();
  void xuat();
};

void danhSachNhanSu::setListNS(vector<NhanSu *> listNS)
{
  this->dsNhanSu = listNS;
}

vector<NhanSu *> danhSachNhanSu::getListNS()
{
  return this->dsNhanSu;
}

void danhSachNhanSu::inMenu()
{
  system("cls");
  cout << "\t\t\t\t ___________________________________\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|        Menu Them nhan su          |\n";
  cout << "\t\t\t\t|                                   |\n";
  cout << "\t\t\t\t|___________________________________|\n";
  cout << endl;
  cout << "\t\t\t\t1. Them truong phong " << endl;
  cout << "\t\t\t\t2. Them nhan vien thuong" << endl;
  cout << "\t\t\t\t3. Them giam doc" << endl;
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
      this->dsNhanSu.push_back(ns);
      break;
    case 2:
      ns = new NhanVienThuong();
      ns->nhap();
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
      break;
    case 3:
      ns = new GiamDoc();
      ns->nhap();
      ns->tinhLuong();
      this->dsNhanSu.push_back(ns);
      break;
    case 0:
      flag = false;
      break;
    default:
      break;
    }
    system("cls");
  } while (flag);
}

void danhSachNhanSu::xuat()
{
  for (NhanSu *ns : dsNhanSu)
  {
    ns->xuat();
  }
}

class XuLy
{
private:
  danhSachNhanSu ds;

public:
  void lietKeDanhSachTruongPhong();
  TruongPhong *timTruongPhongTheoMa(string ma);
  void phanBoNhanVienThuong();
  void sapXepNVTreTuoiNhat();
  void sapXepLuongGiamDan();
  void timNVLuongCaoNhat();
  void inMenu();
  void xuLyMenu();
  void suaDoiThongTinNhanSu();
  void inMenuLogin();
  void XuLyLogin();
  void login();
  void signUp();
};

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
          }

          newNV->setTruongPhong(tp);
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

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  XuLy xl;
  xl.XuLyLogin();
  xl.xuLyMenu();
  return 0;
}