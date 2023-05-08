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

ostream &operator<<(ostream &os, Task &task)
{
  os << "Ma task: " << task.maTask << endl;
  os << "Ten task: " << task.tenTask << endl;
  os << "Gio lam: " << task.gioLam << endl;
  os << "Ma nhan vien: " << task.maNV << endl;
  return os;
}

void Task::nhapTask()
{
  cout << "\t\t\tNhap ma task: ";
  cin >> maTask;
  cout << "\t\t\tNhap ten task: ";
  cin >> tenTask;
  cout << "\t\t\tNhap gio lam: ";
  cin >> gioLam;
}

void Task::xuatTask()
{
  cout << "\t\t\tMa task: " << maTask << endl;
  cout << "\t\t\tTen task: " << tenTask << endl;
  cout << "\t\t\tGio lam: " << gioLam << endl;
  if (maNV != "")
  {
    cout << "\t\t\tMa nhan vien: " << maNV << endl;
  }
  else
  {
    cout << "Chua co nhan vien thuc hien Task nay" << endl;
  }
}

istream &operator>>(istream &is, Task &task)
{
  is >> task.maTask >> task.tenTask >> task.gioLam;
  return is;
}