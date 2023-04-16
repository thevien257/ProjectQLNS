#include "Task.h"
#include <iostream>
using namespace std;

string Task::getMaNV()
{
  return maNV;
}

string Task::getMaTask()
{
  return maTask;
}
string Task::getTenTask()
{
  return tenTask;
}

float Task::getGioLam()
{
  return gioLam;
}

void Task::setMaNV(float maNV)
{
  this->maNV = maNV;
}