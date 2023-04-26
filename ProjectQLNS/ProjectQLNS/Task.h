#pragma once
#include <iostream>
using namespace std;

class Task
{
private:
  string maTask;
  string tenTask;
  float gioLam;
  string maNV;

public:
  void nhapTask();
  void xuatTask();
  string getMaTask();
  string getTenTask();
  float getGioLam();
  string getMaNV();
  void setMaNV(float maTask);
  friend ostream &operator<<(ostream &os, Task &task);
  friend istream &operator>>(istream &is, Task &task);
};