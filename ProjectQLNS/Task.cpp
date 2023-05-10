#include "Task.h"
#include <windows.h>
#include <limits>

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
  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 14);
  cout << "     Ma task         ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << maTask << std::right << " ║" << endl;

  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 14);
  cout << "     Ten task        ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << tenTask << std::right << " ║" << endl;

  cout << "\t\t\t\t║";
  SetConsoleTextAttribute(color, 14);
  cout << "     Deadline        ";
  SetConsoleTextAttribute(color, 7);
  cout << "║ " << std::left << std::setw(20) << deadLine << std::right << " ║" << endl;

  if (maNV != "")
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "     Ma nhan vien    ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << maNV << std::right << " ║" << endl;
  }
  else
  {
    cout << "\t\t\t\t║   Chua co nhan vien thuc hien Task nay     ║\n";
  }

  if (trangThaiTask != "")
  {
    cout << "\t\t\t\t║";
    SetConsoleTextAttribute(color, 14);
    cout << "     Trang thai task ";
    SetConsoleTextAttribute(color, 7);
    cout << "║ " << std::left << std::setw(20) << trangThaiTask << std::right << " ║" << endl;
  }
}

istream &operator>>(istream &is, Task &task)
{
  is >> task.maTask >> task.tenTask >> task.deadLine;
  return is;
}