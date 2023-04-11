#pragma once
#include "DanhSachNhanSu.h"
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