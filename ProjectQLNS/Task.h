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
  string getMaTask();
  string getTenTask();
  float getGioLam();
  string getMaNV();
  void setMaNV(float maTask);
};