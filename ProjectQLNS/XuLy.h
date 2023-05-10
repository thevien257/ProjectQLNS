#pragma once
#include "DanhSachNhanSu.h"
#include "DanhSachPhongBan.h"
#include "DanhSachTask.h"
#include "TruongPhong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
class XuLy
{
private:
  danhSachNhanSu ds;
  DanhSachPhongBan dsPB;
  DanhSachTask dsTask;

public:
  void lietKeDanhSachTruongPhong();
  TruongPhong *timTruongPhongTheoMa(string ma);
  void phanBoNhanVienThuong();
  void SapXepTheoTen();
  void sapXepLuongGiamDan();
  void timNVLuongCaoNhat();
  void inMenu(int &chon);
  void XuLyMenuNhanSu();
  void suaDoiThongTinNhanSu();
  void inMenuLogin(int &chon);
  void XuLyLogin();
  bool login();
  void signUp();
  bool found(string maSo);
  void timNhanSu();
  void xoaNhanSu();
  void xoaTruongPhong(TruongPhong *truongPhong);
  void xoaNhanVienThuong(NhanVienThuong *nvt, string maSo);
  void printWelcome();
  void printGoodBye();
  void printASCII(string fileName);
  void xuLyMenuPhongBan();
  void xuLyMenuTask();
  // void inMenuTask();
  void phanBoTask();
  // void inMenuPhongBan();
  void phanBoNhanVienThuongVaoPhongBan();
  PhongBan *timPhongBan(string maPhong);
  NhanVienThuong *timNVT(string maPhong);
  void chiDinhTruongPhong();
  void XuLyChung();
<<<<<<< HEAD
  // void inMenuChung();
  // void gotoxy(int x, int y);
||||||| 457744a
  void inMenuChung();
  void gotoxy(int x, int y);
=======
  void inMenuChung();
<<<<<<< HEAD:ProjectQLNS/XuLy.h
  void gotoxy(int x, int y);
>>>>>>> 8643634149765d053045f17711cb8b856c6e7ea5
  void xoaTPkhoiPB();
  void xoaNVkhoiPB();
  void xoaPB();
  void sapXepSoLuongNhanSuPBGD();
  void sapXepSoLuongNhanSuPBTD();
=======
  void coLor(int color);
  void gotoxy(int x, int y);
>>>>>>> origin:ProjectQLNS/ProjectQLNS/XuLy.h
};