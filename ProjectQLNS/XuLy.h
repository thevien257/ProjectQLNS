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
  void XuLyLogin(string &taiKhoan);
  bool login(string &taiKhoan);
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
  void phanBoTask();
  void phanBoNhanVienThuongVaoPhongBan();
  PhongBan *timPhongBan(string maPhong);
  NhanVienThuong *timNVT(string maPhong);
  void chiDinhTruongPhong();
  void XuLyChung();
  void xoaTPkhoiPB();
  void xoaNVkhoiPB();
  void xoaPB();
  void sapXepSoLuongNhanSuPBGD();
  void sapXepSoLuongNhanSuPBTD();
  Task *timTask(string maTask);
  void xoaTask();
  void xoaTaskKhoiNV();
  void sapXepSoLuongTaskNV();
  void sapXepTaskHoanThanh();
  void danhGiaTask();
  void animationLoading(string taiKhoan);
  void tatConTro();
};