#pragma once
#include <iostream>
#include "Task.h"
#include <vector>
#include <windows.h>
#include <iomanip>
#include <fstream>

class DanhSachTask
{
private:
  vector<Task *> dsTask;

public:
  vector<Task *> &getDSTask();
  DanhSachTask();
  void setDSTask(vector<Task *> dsTask);
  void nhapTask();
  void xuatTask();
  void docFileTask(string fileName);
};