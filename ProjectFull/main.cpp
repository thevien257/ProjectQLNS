#include "XuLy.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  XuLy xl;
  xl.XuLyLogin();
  xl.xuLyMenu();
  return 0;
}
