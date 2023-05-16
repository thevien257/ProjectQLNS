#include "DanhSachTask.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

vector<Task *> &DanhSachTask::getDSTask()
{
  return dsTask;
}

void DanhSachTask::setDSTask(vector<Task *> task)
{
  this->dsTask = task;
}

void DanhSachTask::xuatTask()
{
  if (dsTask.size() == 0)
  {
    cout << endl;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tChua co task nao trong cong ty ❌" << endl;
    SetConsoleTextAttribute(color, 7);
  }
  else
  {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═══║ ";
    SetConsoleTextAttribute(color, 11);
    cout << "       Thong tin Task  📂    ";
    SetConsoleTextAttribute(color, 7);
    cout << "     ║════╗\n";
    cout << "\t\t\t\t║   ╚═════════════════╦═════════════════╝    ║\n";

    Task *lastTask = dsTask.back();
    int j = 1;
    for (int i = 0; i < dsTask.size(); i++)
    {
      if (dsTask[i] != lastTask)
      {
        cout << "\t\t\t\t║";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "     So thu tu       ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "║ " << std::left << std::setw(20) << j << std::right << " ║" << endl;
        dsTask[i]->xuatTask();
        cout << "\t\t\t\t╠═════════════════════╬══════════════════════╣\n";
        j++;
      }
      else
      {
        cout << "\t\t\t\t║";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "     So thu tu       ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "║ " << std::left << std::setw(20) << j << std::right << " ║" << endl;
        dsTask[i]->xuatTask();
        cout << "\t\t\t\t╚═════════════════════╩══════════════════════╝\n";
      }
    }
  }
}

void DanhSachTask::nhapTask()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  int n;
  cout << endl;
  cout << "\t\t\t\tNhap so luong task: ";
  cin >> n;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // add this line
  for (int i = 0; i < n; i++)
  {
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\tNhap task thu " << i + 1 << " ✍️" << endl;
    SetConsoleTextAttribute(color, 7);
    Task *task = new Task();
    task->nhapTask();
    dsTask.push_back(task);
  }
}

void DanhSachTask::docFileTask(string fileName)
{
  ifstream file(fileName);
  if (file.is_open())
  {
    while (file.good())
    {
      Task *task = new Task();
      file >> *task;
      dsTask.push_back(task);
    }
    file.close();
  }
  else
  {
    cout << "Khong the mo file" << endl;
  }
}

DanhSachTask::DanhSachTask()
{
  docFileTask("Task.txt");
}