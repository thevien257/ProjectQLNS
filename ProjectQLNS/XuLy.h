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
  // Phần xử lý chung
  void XuLyChung();

  // Phần nhân sự
  void XuLyMenuNhanSu();
  void phanBoNhanVienThuong();
  void lietKeDanhSachTruongPhong();
  void SapXepTheoTen();
  void sapXepLuongGiamDan();
  void timNVLuongCaoNhat();
  void InMenuQuanLyNhanSu(int &chon);
  void suaDoiThongTinNhanSu();
  bool found(string maSo);
  void timNhanSuTheoMaSo();
  void xoaNhanSu();
  void xoaTruongPhong(TruongPhong *truongPhong);
  void xoaNhanVienThuong(NhanVienThuong *nvt, string maSo);
  void timNhanSuTheoTen();
  bool existedCheck(string &);

  // Phần phòng ban
  void xuLyMenuPhongBan();
  void phanBoNhanVienThuongVaoPhongBan();
  PhongBan *timPhongBan(string maPhong);
  NhanVienThuong *timNVT(string maPhong);
  TruongPhong *timTruongPhongTheoMa(string ma);
  void chiDinhTruongPhong();
  void xoaTPkhoiPB();
  void xoaNVkhoiPB();
  void xoaPB();
  void sapXepSoLuongNhanSuPBGD();
  void sapXepSoLuongNhanSuPBTD();
  void diChuyenTPDenPBMoi();
  void diChuyenNVTDenPBMoi();
  bool checkCoNhanVienHayKhong();
  bool checkCoTruongPhongHayKhong();
  void thucHienPhanBoTruongPhong(PhongBan *pb, TruongPhong *tp, string maPB);
  void thucHienPhanBoNhanVienThuong(PhongBan *pb, NhanVienThuong *nvt, string maPB);

  // Phần task
  void xuLyMenuTask();
  void phanBoTask();
  Task *timTask(string maTask);
  void xoaTask();
  void xoaTaskKhoiNV();
  void sapXepSoLuongTaskNV();
  void sapXepTaskHoanThanh();
  void danhGiaTask();
  void danhGiaTrangThaiTask(Task *task, string maTask, bool daDanhGia, string trangThai, HANDLE color);
  bool checkCoTaskHayKhong();

  // Phần login và một số chức năng khác
  void inMenuLogin(int &chon);
  void XuLyLogin(string &taiKhoan);
  bool login(string &taiKhoan);
  void signUp();
  void printWelcome();
  void printGoodBye();
  void printASCII(string fileName);
  void animationLoading(string taiKhoan);
  void tatConTro();
  void clearScreen();
  void checkCin();
  bool checkCoNhanSuHayKhong();
  bool checkCoPhongBanHayKhong();
  bool checkCoTPTrongListNSHayKhong();
  bool checkCoNVTrongListNSHayKhong();
  bool checkTaskDaDuocPhanBoChua();
  bool checkCoTaskTrongListTaskHayKhong();
};