#include "Task.h"
#include <windows.h>
#include <limits>
#include <string.h>
#include <string>

using namespace std;

void Task::setTrangThaiTask(string trangThaiTask)
{
  this->trangThaiTask = trangThaiTask;
}

string Task::getTrangThaiTask()
{
  return trangThaiTask;
}

Task::Task()
{
  maNV = "";
  trangThaiTask = "";
}

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

string Task::getDeadLine()
{
  return deadLine;
}

void Task::setMaNV(string maNV)
{
  this->maNV = maNV;
}

ostream &operator<<(ostream &os, Task &task)
{
  os << "Ma task: " << task.maTask << endl;
  os << "Ten task: " << task.tenTask << endl;
  os << "Deadline: " << task.deadLine << endl;
  os << "Ma nhan vien: " << task.maNV << endl;
  return os;
}

void Task::nhapTask()
{
  std::cout << "\t\t\t\tNhap ten task: ";
  std::getline(std::cin, tenTask);

  std::cout << "\t\t\t\tNhap ma task: ";
  cin >> maTask;

  std::cout << "\t\t\t\tNhap deadline: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, deadLine);
}

void Task::xuatTask()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  int brightYellow = 14;
  int darkWhite = 7;
  cout << " " << setw(4 + maTask.size() / 2) << setfill(' ');
  SetConsoleTextAttribute(color, brightYellow);
  cout << maTask;
  SetConsoleTextAttribute(color, darkWhite);
  cout << setw(4 - maTask.size() / 2) << setfill(' ') << ""
       << "║";
  cout << " " << setw(8 + tenTask.size() / 2) << setfill(' ');
  SetConsoleTextAttribute(color, brightYellow);
  cout << tenTask;
  SetConsoleTextAttribute(color, darkWhite);
  cout << setw(8 - tenTask.size() / 2) << setfill(' ') << ""
       << " ║";
  cout << " " << setw(6 + deadLine.size() / 2) << setfill(' ');
  SetConsoleTextAttribute(color, brightYellow);
  cout << deadLine;
  SetConsoleTextAttribute(color, darkWhite);
  cout << setw(6 - deadLine.size() / 2) << setfill(' ') << ""
       << " ║";
  if (maNV != "")
  {
    cout << " " << setw(9 + maNV.size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << maNV;
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(9 - maNV.size() / 2) << setfill(' ') << ""
         << " ║";
  }
  else
  {
    string chuaCoNhanVien = "Chua co";
    cout << " " << setw(9 + chuaCoNhanVien.size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << "Chua co";
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(9 - chuaCoNhanVien.size() / 2) << setfill(' ') << ""
         << " ║";
  }
  if (trangThaiTask != "")
  {
    cout << " " << setw(9 + trangThaiTask.size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << trangThaiTask;
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(9 - trangThaiTask.size() / 2) << setfill(' ') << ""
         << "  ║";
  }
  else
  {
    string chuaDuocDanhGia = "Chua duoc danh gia";
    cout << " " << setw(7 + chuaDuocDanhGia.size() / 2) << setfill(' ');
    SetConsoleTextAttribute(color, brightYellow);
    cout << "Chua duoc danh gia";
    SetConsoleTextAttribute(color, darkWhite);
    cout << setw(7 - chuaDuocDanhGia.size() / 2) << setfill(' ') << ""
         << "  ║";
  }
}

// istream &operator>>(istream &is, Task &task)
// {
//   is >> task.maTask >> task.tenTask >> task.deadLine;
//   return is;
// }

istream &operator>>(istream &input, Task &task)
{
  char separator;
  getline(input, task.maTask, '#');
  getline(input, task.tenTask, '#');
  getline(input, task.deadLine, '#');
  input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return input;
}