#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

class Task
{
private:
  string maTask;
  string tenTask;
  string deadLine;
  string maNV;
  string trangThaiTask;
  void setDeadLine(string deadLine);
  void setMaTask(string maTask);
  void setTenTask(string tenTask);

public:
  Task();
  void nhapTask();
  void xuatTask();
  string getMaTask();
  string getTenTask();
  string getDeadLine();
  string getMaNV();
  void setMaNV(string maNV);
  void setTrangThaiTask(string trangThaiTask);
  string getTrangThaiTask();
  friend ostream &operator<<(ostream &os, Task &task);
  friend istream &operator>>(istream &is, Task &task);
};